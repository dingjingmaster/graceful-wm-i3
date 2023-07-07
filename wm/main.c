//
// Created by dingjing on 23-7-7.
//

#include <ev.h>
#include <glib.h>
#include <stdio.h>
#include <xcb/xkb.h>
#include <xcb/shape.h>
#include <xcb/randr.h>
#include <glib/gi18n.h>
#include <xcb/bigreq.h>
#include <xcb/xcb_aux.h>
#include <sys/resource.h>
#include <xcb/xcb_atom.h>
#include <unistd.h>

#include "xkb.h"
#include "utils.h"
#include "config.h"
#include "xcursor.h"
#include "common/log.h"
#include "command-line.h"
#include "restore-layout.h"
#include "atoms-rest.xmacro.h"
#include "atoms-NET-SUPPORTED-xmacro.h"


int main (int argc, char* argv[])
{
    textdomain (APP_NAME);
    bindtextdomain (APP_NAME, INSTALL_DIR);
    bind_textdomain_codeset (APP_NAME, "UTF-8");

    g_set_application_name (APP_NAME);

    g_log_set_writer_func(log_handler, NULL, NULL);

    parse_commandline (argc, argv);

    srand (time(NULL));

    LOG_INFO(APP_NAME " " APP_VERSION " starting");

    gConn = xcb_connect (NULL, &gConnScreen);
    if (xcb_connection_has_error (gConn)) {
        fprintf (stdout, _("Cannot open display."));
        exit (-1);
    }

    gSndisplay = sn_xcb_display_new (gConn, NULL, NULL);

    gMainLoop = EV_DEFAULT;
    if (NULL == gMainLoop) {
        LOG_ERROR("Could not initialize libev.");
        exit (-1);
    }

    gRootScreen = xcb_aux_get_screen(gConn, gConnScreen);
    gRoot = gRootScreen->root;

    /* 预取我们感兴趣的X11扩展 */
    xcb_prefetch_extension_data (gConn, &xcb_xkb_id);
    xcb_prefetch_extension_data (gConn, &xcb_shape_id);
    xcb_prefetch_extension_data (gConn, &xcb_big_requests_id);
    xcb_prefetch_extension_data (gConn, &xcb_randr_id);

    xcb_change_window_attributes (gConn, gRoot, XCB_CW_EVENT_MASK, (uint32_t[]){XCB_EVENT_MASK_PROPERTY_CHANGE});
    xcb_change_property (gConn, XCB_PROP_MODE_APPEND, gRoot, XCB_ATOM_SUPERSCRIPT_X, XCB_ATOM_CARDINAL, 32, 0, "");

#define xmacro(atom) \
    xcb_intern_atom_cookie_t atom##_cookie = xcb_intern_atom(gConn, 0, strlen(#atom), #atom);
    GRACEFUL_WM_NET_SUPPORTED_ATOMS_XMACRO
        GRACEFUL_WM_REST_ATOMS_XMACRO
#undef xmacro

    gRootDepth = gRootScreen->root_depth;
    gColormap = gRootScreen->default_colormap;
    gVisualType = xcb_aux_find_visual_by_attrs (gRootScreen, -1, 32);
    if (NULL != gVisualType) {
        gRootDepth = xcb_aux_get_depth_of_visual(gRootScreen, gVisualType->visual_id);
        gColormap = xcb_generate_id(gConn);

        xcb_void_cookie_t cm_cookie = xcb_create_colormap_checked(gConn, XCB_COLORMAP_ALLOC_NONE, gColormap, gRoot, gVisualType->visual_id);
        xcb_generic_error_t *error = xcb_request_check(gConn, cm_cookie);
        if (error != NULL) {
            LOG_ERROR("Could not create colormap. Error code: %d\n", error->error_code);
            exit(EXIT_FAILURE);
        }
    }
    else {
        gVisualType = get_visual_type (gRootScreen);
    }

    xcb_prefetch_maximum_request_length (gConn);

    init_dpi();

    LOG_DEBUG("root_depth = %d, visual_id = 0x%08x.", gRootDepth, gVisualType->visual_id);
    LOG_DEBUG("root_screen->height_in_pixels = %d, root_screen->height_in_millimeters = %d", gRootScreen->height_in_pixels, gRootScreen->height_in_millimeters);
    LOG_DEBUG("One logical pixel corresponds to %d physical pixels on this display.", logical_px(1));

    xcb_get_geometry_cookie_t gcookie = xcb_get_geometry (gConn, gRoot);
    xcb_query_pointer_cookie_t pointercookie = xcb_query_pointer (gConn, gRoot);

    /* Get the PropertyNotify event we caused above */
    xcb_flush(gConn);
    {
        LOG_DEBUG("waiting for PropertyNotify event");
        xcb_generic_event_t* event;
        while ((event = xcb_wait_for_event(gConn)) != NULL) {
            if (event->response_type == XCB_PROPERTY_NOTIFY) {
                gLastTimestamp = ((xcb_property_notify_event_t *)event)->time;
                free(event);
                break;
            }
            free(event);
        }
        LOG_DEBUG("got timestamp %d", gLastTimestamp);
    }

    /* Setup NetWM atoms */
#define xmacro(name)                                                                        \
    do {                                                                                    \
        xcb_intern_atom_reply_t *reply = xcb_intern_atom_reply(gConn, name##_cookie, NULL); \
        if (!reply) {                                                                       \
            LOG_ERROR("Could not get atom " #name);                                         \
            exit(-1);                                                                       \
        }                                                                                   \
        A_##name = reply->atom;                                                             \
        free(reply);                                                                        \
    } while (0);
    GRACEFUL_WM_NET_SUPPORTED_ATOMS_XMACRO
        GRACEFUL_WM_REST_ATOMS_XMACRO
#undef xmacro

    /* load configure */

    /* Acquire the WM_Sn selection. */
    {
        /* Get the WM_Sn atom */
        char* atomName = xcb_atom_name_by_screen("WM", gConnScreen);
        gWMSnSelectionOwner = xcb_generate_id(gConn);

        if (NULL == atomName) {
            LOG_ERROR("xcb_atom_name_by_screen(\"WM\", %d) failed, exiting", gConnScreen);
            return 1;
        }

        xcb_intern_atom_reply_t* atomReply = xcb_intern_atom_reply(gConn, xcb_intern_atom_unchecked(gConn, 0, strlen(atomName), atomName), NULL);
        free(atomName);
        if (NULL == atomReply) {
            LOG_ERROR("Failed to intern the WM_Sn atom, exiting");
            return 1;
        }
        gWMSn = atomReply->atom;
        free(atomReply);

        /* Check if the selection is already owned */
        xcb_get_selection_owner_reply_t* selectionReply = xcb_get_selection_owner_reply(gConn, xcb_get_selection_owner(gConn, gWMSn), NULL);
        if (selectionReply && selectionReply->owner != XCB_NONE && !gReplaceWM) {
            LOG_ERROR("Another window manager is already running (WM_Sn is owned)");
            return 1;
        }

        /* Become the selection owner */
        xcb_create_window(gConn,
                          gRootScreen->root_depth,
                          gWMSnSelectionOwner,      /* window id */
                          gRootScreen->root,        /* parent */
                          -1, -1, 1, 1,             /* geometry */
                          0,                        /* border width */
                          XCB_WINDOW_CLASS_INPUT_OUTPUT,
                          gRootScreen->root_visual,
                          0, NULL);
        xcb_change_property(gConn,
                            XCB_PROP_MODE_REPLACE,
                            gWMSnSelectionOwner,
                            XCB_ATOM_WM_CLASS,
                            XCB_ATOM_STRING,
                            8,
                            (strlen("Graceful-WM_Sn") + 1) * 2,
                            "Graceful-WM_Sn\0Graceful-WM_Sn\0");

        xcb_set_selection_owner(gConn, gWMSnSelectionOwner, gWMSn, gLastTimestamp);

        if (selectionReply && selectionReply->owner != XCB_NONE) {
            unsigned int usleepTime = 100000;   /* 0.1 seconds */
            int checkRounds = 150;              /* Wait for a maximum of 15 seconds */
            xcb_get_geometry_reply_t* geomReply = NULL;

            LOG_DEBUG("waiting for old WM_Sn selection owner to exit");
            do {
                free(geomReply);
                usleep(usleepTime);
                if (checkRounds-- == 0) {
                    LOG_DEBUG("The old window manager is not exiting");
                    return 1;
                }
                geomReply = xcb_get_geometry_reply(gConn, xcb_get_geometry(gConn, selectionReply->owner), NULL);
            } while (geomReply != NULL);
        }
        free(selectionReply);

        /* Announce that we are the new owner */
        /* Every X11 event is 32 bytes long. Therefore, XCB will copy 32 bytes.
         * In order to properly initialize these bytes, we allocate 32 bytes even
         * though we only need less for an xcb_client_message_event_t */
        union {
            xcb_client_message_event_t message;
            char storage[32];
        } event;
        memset (&event, 0, sizeof(event));
        event.message.response_type = XCB_CLIENT_MESSAGE;
        event.message.window = gRootScreen->root;
        event.message.format = 32;
        event.message.type = A_MANAGER;
        event.message.data.data32[0] = gLastTimestamp;
        event.message.data.data32[1] = gWMSn;
        event.message.data.data32[2] = gWMSnSelectionOwner;

        xcb_send_event (gConn, 0, gRootScreen->root, XCB_EVENT_MASK_STRUCTURE_NOTIFY, event.storage);
    }

    xcb_void_cookie_t cookie;
    cookie = xcb_change_window_attributes_checked(gConn, gRoot, XCB_CW_EVENT_MASK, (uint32_t[]){ROOT_EVENT_MASK});
    xcb_generic_error_t *error = xcb_request_check(gConn, cookie);
    if (error != NULL) {
        LOG_ERROR("Another window manager seems to be running (X error %d)", error->error_code);
        return 1;
    }

    xcb_get_geometry_reply_t* greply = xcb_get_geometry_reply(gConn, gcookie, NULL);
    if (greply == NULL) {
        LOG_ERROR("Could not get geometry of the root window, exiting");
        return 1;
    }
    LOG_ERROR("root geometry reply: (%d, %d) %d x %d", greply->x, greply->y, greply->width, greply->height);

    xcursor_load_cursors();

    xcursor_set_root_cursor(XCURSOR_CURSOR_POINTER);

    const xcb_query_extension_reply_t* extReply = xcb_get_extension_data(gConn, &xcb_xkb_id);
    gXkbSupported = extReply->present;
    if (!extReply->present) {
        LOG_DEBUG("xkb is not present on this server");
    }
    else {
        LOG_DEBUG("initializing xcb-xkb");
        xcb_xkb_use_extension(gConn, XCB_XKB_MAJOR_VERSION, XCB_XKB_MINOR_VERSION);
        xcb_xkb_select_events(gConn,
                              XCB_XKB_ID_USE_CORE_KBD,
                              XCB_XKB_EVENT_TYPE_STATE_NOTIFY | XCB_XKB_EVENT_TYPE_MAP_NOTIFY | XCB_XKB_EVENT_TYPE_NEW_KEYBOARD_NOTIFY,
                              0,
                              XCB_XKB_EVENT_TYPE_STATE_NOTIFY | XCB_XKB_EVENT_TYPE_MAP_NOTIFY | XCB_XKB_EVENT_TYPE_NEW_KEYBOARD_NOTIFY,
                              0xff,
                              0xff,
                              NULL);

        /* Setting both, XCB_XKB_PER_CLIENT_FLAG_GRABS_USE_XKB_STATE and
         * XCB_XKB_PER_CLIENT_FLAG_LOOKUP_STATE_WHEN_GRABBED, will lead to the
         * X server sending us the full XKB state in KeyPress and KeyRelease:
         * https://cgit.freedesktop.org/xorg/xserver/tree/xkb/xkbEvents.c?h=xorg-server-1.20.0#n927
         *
         * XCB_XKB_PER_CLIENT_FLAG_DETECTABLE_AUTO_REPEAT enable detectable autorepeat:
         * https://www.x.org/releases/current/doc/kbproto/xkbproto.html#Detectable_Autorepeat
         * This affects bindings using the --release flag: instead of getting multiple KeyRelease
         * events we get only one event when the key is physically released by the user.
         */
        const uint32_t mask = XCB_XKB_PER_CLIENT_FLAG_GRABS_USE_XKB_STATE |
                              XCB_XKB_PER_CLIENT_FLAG_LOOKUP_STATE_WHEN_GRABBED |
                              XCB_XKB_PER_CLIENT_FLAG_DETECTABLE_AUTO_REPEAT;

        /**
         * The last three parameters are unset because they are only relevant
         * when using a feature called “automatic reset of boolean controls”:
         * https://www.x.org/releases/X11R7.7/doc/kbproto/xkbproto.html#Automatic_Reset_of_Boolean_Controls
         * */
        xcb_xkb_per_client_flags_reply_t* pcfReply = xcb_xkb_per_client_flags_reply(gConn,
                            xcb_xkb_per_client_flags(gConn,
                                            XCB_XKB_ID_USE_CORE_KBD,
                                            mask,
                                            mask,
                                            0 /* uint32_t ctrlsToChange */,
                                            0 /* uint32_t autoCtrls */,
                                            0 /* uint32_t autoCtrlsValues */),
                            NULL);
#define PCF_REPLY_ERROR(_value)                                     \
    do {                                                            \
        if (pcfReply == NULL || !(pcfReply->value & (_value))) {    \
            LOG_DEBUG("Could not set " #_value "\n");               \
        }                                                           \
    } while (0)

        PCF_REPLY_ERROR(XCB_XKB_PER_CLIENT_FLAG_GRABS_USE_XKB_STATE);
        PCF_REPLY_ERROR(XCB_XKB_PER_CLIENT_FLAG_LOOKUP_STATE_WHEN_GRABBED);
        PCF_REPLY_ERROR(XCB_XKB_PER_CLIENT_FLAG_DETECTABLE_AUTO_REPEAT);

        free(pcfReply);
        gXkbBase = extReply->first_event;
    }


    /* Check for Shape extension. We want to handle input shapes which is
     * introduced in 1.1. */
    extReply = xcb_get_extension_data(gConn, &xcb_shape_id);
    if (extReply->present) {
        gShapeBase = extReply->first_event;
        xcb_shape_query_version_cookie_t cookie = xcb_shape_query_version(gConn);
        xcb_shape_query_version_reply_t* version = xcb_shape_query_version_reply(gConn, cookie, NULL);
        gShapeSupported = version && version->minor_version >= 1;
        free(version);
    }
    else {
        gShapeSupported = false;
    }

    if (!gShapeSupported) {
        LOG_DEBUG("shape 1.1 is not present on this server");
    }


    restore_connect();

    property_handlers_init();

    ewmh_setup_hints();

    keysyms = xcb_key_symbols_alloc(conn);

    xcb_numlock_mask = aio_get_mod_mask_for(XCB_NUM_LOCK, keysyms);

    if (!load_keymap()) {
        die("Could not load keymap\n");
    }

    translate_keysyms();
    grab_all_keys(conn);

    bool needs_tree_init = true;
    if (layout_path != NULL) {
        LOG("Trying to restore the layout from \"%s\".\n", layout_path);
        needs_tree_init = !tree_restore(layout_path, greply);
        if (delete_layout_path) {
            unlink(layout_path);
            const char *dir = dirname(layout_path);
            /* possibly fails with ENOTEMPTY if there are files (or
             * sockets) left. */
            rmdir(dir);
        }
    }
    if (needs_tree_init) {
        tree_init(greply);
    }

    free(greply);

    /* Setup fake outputs for testing */
    if (fake_outputs == NULL && config.fake_outputs != NULL) {
        fake_outputs = config.fake_outputs;
    }

    if (fake_outputs != NULL) {
        fake_outputs_init(fake_outputs);
        FREE(fake_outputs);
        config.fake_outputs = NULL;
    }
    else if (force_xinerama) {
        /* Force Xinerama (for drivers which don't support RandR yet, esp. the
         * nVidia binary graphics driver), when specified either in the config
         * file or on command-line */
        xinerama_init();
    }
    else {
        DLOG("Checking for XRandR...\n");
        randr_init(&randr_base, disable_randr15 || config.disable_randr15);
    }

    /* We need to force disabling outputs which have been loaded from the
     * layout file but are no longer active. This can happen if the output has
     * been disabled in the short time between writing the restart layout file
     * and restarting i3. See #2326. */
    if (layout_path != NULL && randr_base > -1) {
        Con *con;
        TAILQ_FOREACH (con, &(croot->nodes_head), nodes) {
            Output *output;
            TAILQ_FOREACH (output, &outputs, outputs) {
                if (output->active || strcmp(con->name, output_primary_name(output)) != 0)
                    continue;

                /* This will correctly correlate the output with its content
                 * container. We need to make the connection to properly
                 * disable the output. */
                if (output->con == NULL) {
                    output_init_con(output);
                    output->changed = false;
                }

                output->to_be_disabled = true;
                randr_disable_output(output);
            }
        }
    }
    FREE(layout_path);

    scratchpad_fix_resolution();

    xcb_query_pointer_reply_t *pointerreply;
    Output *output = NULL;
    if (!(pointerreply = xcb_query_pointer_reply(conn, pointercookie, NULL))) {
        ELOG("Could not query pointer position, using first screen\n");
    }
    else {
        DLOG("Pointer at %d, %d\n", pointerreply->root_x, pointerreply->root_y);
        output = get_output_containing(pointerreply->root_x, pointerreply->root_y);
        if (!output) {
            ELOG("ERROR: No screen at (%d, %d), starting on the first screen\n",
                 pointerreply->root_x, pointerreply->root_y);
        }
    }
    if (!output) {
        output = get_first_output();
    }
    con_activate(con_descend_focused(output_get_content(output->con)));
    free(pointerreply);

    tree_render();

    /* Listen to the IPC socket for clients */
    struct ev_io *ipc_io = scalloc(1, sizeof(struct ev_io));
    ev_io_init(ipc_io, ipc_new_client, ipc_socket, EV_READ);
    ev_io_start(main_loop, ipc_io);

    /* Chose a file name in /tmp/ based on the PID */
    char *log_stream_socket_path = get_process_filename("log-stream-socket");
    int log_socket = create_socket(log_stream_socket_path, &current_log_stream_socket_path);
    free(log_stream_socket_path);
    if (log_socket == -1) {
        ELOG("Could not create the log socket, i3-dump-log -f will not work\n");
    }
    else {
        struct ev_io *log_io = scalloc(1, sizeof(struct ev_io));
        ev_io_init(log_io, log_new_client, log_socket, EV_READ);
        ev_io_start(main_loop, log_io);
    }

    /* Also handle the UNIX domain sockets passed via socket
     * activation. The parameter 0 means "do not remove the
     * environment variables", we need to be able to reexec. */
    listen_fds = sd_listen_fds(0);
    if (listen_fds < 0) {
        ELOG("socket activation: Error in sd_listen_fds\n");
    }
    else if (listen_fds == 0) {
        DLOG("socket activation: no sockets passed\n");
    }
    else {
        int flags;
        for (int fd = SD_LISTEN_FDS_START; fd < (SD_LISTEN_FDS_START + listen_fds); fd++) {
            DLOG("socket activation: also listening on fd %d\n", fd);

            /* sd_listen_fds() enables FD_CLOEXEC by default.
             * However, we need to keep the file descriptors open for in-place
             * restarting, therefore we explicitly disable FD_CLOEXEC. */
            if ((flags = fcntl(fd, F_GETFD)) < 0 ||
                fcntl(fd, F_SETFD, flags & ~FD_CLOEXEC) < 0) {
                ELOG("Could not disable FD_CLOEXEC on fd %d\n", fd);
            }

            struct ev_io *ipc_io = scalloc(1, sizeof(struct ev_io));
            ev_io_init(ipc_io, ipc_new_client, fd, EV_READ);
            ev_io_start(main_loop, ipc_io);
        }
    }

    {
        const int restart_fd = parse_restart_fd();
        if (restart_fd != -1) {
            DLOG("serving restart fd %d", restart_fd);
            ipc_client *client = ipc_new_client_on_fd(main_loop, restart_fd);
            ipc_confirm_restart(client);
            unsetenv("_I3_RESTART_FD");
        }
    }


    /* Set up i3 specific atoms like I3_SOCKET_PATH and I3_CONFIG_PATH */
    x_set_i3_atoms();
    ewmh_update_workarea();

    /* Set the ewmh desktop properties. */
    ewmh_update_desktop_properties();

    struct ev_io *xcb_watcher = scalloc(1, sizeof(struct ev_io));
    xcb_prepare = scalloc(1, sizeof(struct ev_prepare));

    ev_io_init(xcb_watcher, xcb_got_event, xcb_get_file_descriptor(conn), EV_READ);
    ev_io_start(main_loop, xcb_watcher);

    ev_prepare_init(xcb_prepare, xcb_prepare_cb);
    ev_prepare_start(main_loop, xcb_prepare);

    xcb_flush(conn);

    /* What follows is a fugly consequence of X11 protocol race conditions like
     * the following: In an i3 in-place restart, i3 will reparent all windows
     * to the root window, then exec() itself. In the new process, it calls
     * manage_existing_windows. However, in case any application sent a
     * generated UnmapNotify message to the WM (as GIMP does), this message
     * will be handled by i3 *after* managing the window, thus i3 thinks the
     * window just closed itself. In reality, the message was sent in the time
     * period where i3 wasn’t running yet.
     *
     * To prevent this, we grab the server (disables processing of any other
     * connections), then discard all pending events (since we didn’t do
     * anything, there cannot be any meaningful responses), then ungrab the
     * server. */
    xcb_grab_server(conn);
    {
        xcb_aux_sync(conn);
        xcb_generic_event_t *event;
        while ((event = xcb_poll_for_event(conn)) != NULL) {
            if (event->response_type == 0) {
                free(event);
                continue;
            }

            /* Strip off the highest bit (set if the event is generated) */
            int type = (event->response_type & 0x7F);

            /* We still need to handle MapRequests which are sent in the
             * timespan starting from when we register as a window manager and
             * this piece of code which drops events. */
            if (type == XCB_MAP_REQUEST)
                handle_event(type, event);

            free(event);
        }
        manage_existing_windows(root);
    }
    xcb_ungrab_server(conn);

    if (autostart) {
        /* When the root's window background is set to NONE, that might mean
         * that old content stays visible when a window is closed. That has
         * unpleasant effect of "my terminal (does not seem to) close!".
         *
         * There does not seem to be an easy way to query for this problem, so
         * we test for it: Open & close a window and check if the background is
         * redrawn or the window contents stay visible.
         */
        LOG("This is not an in-place restart, checking if a wallpaper is set.\n");

        xcb_screen_t *root = xcb_aux_get_screen(conn, conn_screen);
        if (is_background_set(conn, root)) {
            LOG("A wallpaper is set, so no screenshot is necessary.\n");
        } else {
            LOG("No wallpaper set, copying root window contents to a pixmap\n");
            set_screenshot_as_wallpaper(conn, root);
        }
    }

#if defined(__OpenBSD__)
    if (pledge("stdio rpath wpath cpath proc exec unix", NULL) == -1)
        err(EXIT_FAILURE, "pledge");
#endif

    if (!disable_signalhandler)
        setup_signal_handler();
    else {
        struct sigaction action;

        action.sa_sigaction = handle_core_signal;
        action.sa_flags = SA_NODEFER | SA_RESETHAND | SA_SIGINFO;
        sigemptyset(&action.sa_mask);

        /* Catch all signals with default action "Core", see signal(7) */
        if (sigaction(SIGQUIT, &action, NULL) == -1 ||
            sigaction(SIGILL, &action, NULL) == -1 ||
            sigaction(SIGABRT, &action, NULL) == -1 ||
            sigaction(SIGFPE, &action, NULL) == -1 ||
            sigaction(SIGSEGV, &action, NULL) == -1)
            ELOG("Could not setup signal handler.\n");
    }

    setup_term_handlers();
    /* Ignore SIGPIPE to survive errors when an IPC client disconnects
     * while we are sending them a message */
    signal(SIGPIPE, SIG_IGN);

    /* Autostarting exec-lines */
    if (autostart) {
        while (!TAILQ_EMPTY(&autostarts)) {
            struct Autostart *exec = TAILQ_FIRST(&autostarts);

            LOG("auto-starting %s\n", exec->command);
            start_application(exec->command, exec->no_startup_id);

            FREE(exec->command);
            TAILQ_REMOVE(&autostarts, exec, autostarts);
            FREE(exec);
        }
    }

    /* Autostarting exec_always-lines */
    while (!TAILQ_EMPTY(&autostarts_always)) {
        struct Autostart *exec_always = TAILQ_FIRST(&autostarts_always);

        LOG("auto-starting (always!) %s\n", exec_always->command);
        start_application(exec_always->command, exec_always->no_startup_id);

        FREE(exec_always->command);
        TAILQ_REMOVE(&autostarts_always, exec_always, autostarts_always);
        FREE(exec_always);
    }

    /* Start i3bar processes for all configured bars */
    Barconfig *barconfig;
    TAILQ_FOREACH (barconfig, &barconfigs, configs) {
        char *command = NULL;
        sasprintf(&command, "%s %s --bar_id=%s --socket=\"%s\"",
                  barconfig->i3bar_command ? barconfig->i3bar_command : "exec i3bar",
                  barconfig->verbose ? "-V" : "",
                  barconfig->id, current_socketpath);
        LOG("Starting bar process: %s\n", command);
        start_application(command, true);
        free(command);
    }

    /* Make sure to destroy the event loop to invoke the cleanup callbacks
     * when calling exit() */
    atexit(i3_exit);

    sd_notify(1, "READY=1");
    ev_loop(gMainLoop, 0);

    return 0;
}