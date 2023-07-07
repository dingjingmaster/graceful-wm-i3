file(GLOB MAIN_SRC
        ${CMAKE_SOURCE_DIR}/app/x.h
        ${CMAKE_SOURCE_DIR}/app/x.c

        ${CMAKE_SOURCE_DIR}/app/log.h
        ${CMAKE_SOURCE_DIR}/app/log.c

        ${CMAKE_SOURCE_DIR}/app/xcb.h
        ${CMAKE_SOURCE_DIR}/app/xcb.c

        ${CMAKE_SOURCE_DIR}/app/ipc.c
        ${CMAKE_SOURCE_DIR}/app/dpi.c

        ${CMAKE_SOURCE_DIR}/app/move.h
        ${CMAKE_SOURCE_DIR}/app/move.c

        ${CMAKE_SOURCE_DIR}/app/gaps.h
        ${CMAKE_SOURCE_DIR}/app/gaps.c

        ${CMAKE_SOURCE_DIR}/app/util.h
        ${CMAKE_SOURCE_DIR}/app/util.c

        ${CMAKE_SOURCE_DIR}/app/sync.h
        ${CMAKE_SOURCE_DIR}/app/sync.c

        ${CMAKE_SOURCE_DIR}/app/ewmh.h
        ${CMAKE_SOURCE_DIR}/app/ewmh.c

        ${CMAKE_SOURCE_DIR}/app/tree.h
        ${CMAKE_SOURCE_DIR}/app/tree.c

        ${CMAKE_SOURCE_DIR}/app/drag.h
        ${CMAKE_SOURCE_DIR}/app/drag.c

        ${CMAKE_SOURCE_DIR}/app/randr.h
        ${CMAKE_SOURCE_DIR}/app/randr.c

        ${CMAKE_SOURCE_DIR}/app/match.h
        ${CMAKE_SOURCE_DIR}/app/match.c

        ${CMAKE_SOURCE_DIR}/app/regex.h
        ${CMAKE_SOURCE_DIR}/app/regex.c

        ${CMAKE_SOURCE_DIR}/app/click.h
        ${CMAKE_SOURCE_DIR}/app/click.c

        ${CMAKE_SOURCE_DIR}/app/render.h
        ${CMAKE_SOURCE_DIR}/app/render.c

        ${CMAKE_SOURCE_DIR}/app/window.h
        ${CMAKE_SOURCE_DIR}/app/window.c

        ${CMAKE_SOURCE_DIR}/app/manage.h
        ${CMAKE_SOURCE_DIR}/app/manage.c

        ${CMAKE_SOURCE_DIR}/app/mkdirp.h
        ${CMAKE_SOURCE_DIR}/app/mkdirp.c

        ${CMAKE_SOURCE_DIR}/app/output.h
        ${CMAKE_SOURCE_DIR}/app/output.c

        ${CMAKE_SOURCE_DIR}/app/startup.h
        ${CMAKE_SOURCE_DIR}/app/startup.c

        ${CMAKE_SOURCE_DIR}/app/xcursor.h
        ${CMAKE_SOURCE_DIR}/app/xcursor.c

        ${CMAKE_SOURCE_DIR}/app/message.h
        ${CMAKE_SOURCE_DIR}/app/message.c

        ${CMAKE_SOURCE_DIR}/app/bindings.h
        ${CMAKE_SOURCE_DIR}/app/bindings.c

        ${CMAKE_SOURCE_DIR}/app/handlers.h
        ${CMAKE_SOURCE_DIR}/app/handlers.c

        ${CMAKE_SOURCE_DIR}/app/floating.h
        ${CMAKE_SOURCE_DIR}/app/floating.c

        ${CMAKE_SOURCE_DIR}/app/commands.h
        ${CMAKE_SOURCE_DIR}/app/commands.c

        ${CMAKE_SOURCE_DIR}/app/xinerama.h
        ${CMAKE_SOURCE_DIR}/app/xinerama.c

        ${CMAKE_SOURCE_DIR}/app/workspace.h
        ${CMAKE_SOURCE_DIR}/app/workspace.c

        ${CMAKE_SOURCE_DIR}/app/key_press.h
        ${CMAKE_SOURCE_DIR}/app/key_press.c

        ${CMAKE_SOURCE_DIR}/app/sd-daemon.h
        ${CMAKE_SOURCE_DIR}/app/sd-daemon.c

        ${CMAKE_SOURCE_DIR}/app/sighandler.h
        ${CMAKE_SOURCE_DIR}/app/sighandler.c

        ${CMAKE_SOURCE_DIR}/app/scratchpad.h
        ${CMAKE_SOURCE_DIR}/app/scratchpad.c

        ${CMAKE_SOURCE_DIR}/app/tiling_drag.h
        ${CMAKE_SOURCE_DIR}/app/tiling_drag.c

        ${CMAKE_SOURCE_DIR}/app/assignments.h
        ${CMAKE_SOURCE_DIR}/app/assignments.c

        ${CMAKE_SOURCE_DIR}/app/load_layout.h
        ${CMAKE_SOURCE_DIR}/app/load_layout.c

        ${CMAKE_SOURCE_DIR}/app/fake_outputs.h
        ${CMAKE_SOURCE_DIR}/app/fake_outputs.c

        ${CMAKE_SOURCE_DIR}/app/config_parser.h
        ${CMAKE_SOURCE_DIR}/app/config_parser.c

        ${CMAKE_SOURCE_DIR}/app/restore_layout.h
        ${CMAKE_SOURCE_DIR}/app/restore_layout.c

        ${CMAKE_SOURCE_DIR}/app/commands_parser.h
        ${CMAKE_SOURCE_DIR}/app/commands_parser.c

        ${CMAKE_SOURCE_DIR}/app/config_directives.h
        ${CMAKE_SOURCE_DIR}/app/config_directives.c

        ${CMAKE_SOURCE_DIR}/app/configuration.h
        ${CMAKE_SOURCE_DIR}/app/config.c

        ${CMAKE_SOURCE_DIR}/app/con.c
        ${CMAKE_SOURCE_DIR}/app/font.c
        ${CMAKE_SOURCE_DIR}/app/resize.c
        ${CMAKE_SOURCE_DIR}/app/string.c
        ${CMAKE_SOURCE_DIR}/app/boolstr.c
        ${CMAKE_SOURCE_DIR}/app/nonblock.c
        ${CMAKE_SOURCE_DIR}/app/draw_util.c
        ${CMAKE_SOURCE_DIR}/app/ipc_connect.c
        ${CMAKE_SOURCE_DIR}/app/path_exists.c
        ${CMAKE_SOURCE_DIR}/app/safewrappers.c
        ${CMAKE_SOURCE_DIR}/app/get_mod_mask.c
        ${CMAKE_SOURCE_DIR}/app/resolve_tilde.c
        ${CMAKE_SOURCE_DIR}/app/create_socket.c
        ${CMAKE_SOURCE_DIR}/app/is_debug_build.c
        ${CMAKE_SOURCE_DIR}/app/get_colorpixel.c
        ${CMAKE_SOURCE_DIR}/app/get_visualtype.c
        ${CMAKE_SOURCE_DIR}/app/get_config_path.c
        ${CMAKE_SOURCE_DIR}/app/ucs2_conversion.c
        ${CMAKE_SOURCE_DIR}/app/display_version.c
        ${CMAKE_SOURCE_DIR}/app/ipc_send_message.c
        ${CMAKE_SOURCE_DIR}/app/ipc_recv_message.c
        ${CMAKE_SOURCE_DIR}/app/is_background_set.c
        ${CMAKE_SOURCE_DIR}/app/root_atom_contents.c
        ${CMAKE_SOURCE_DIR}/app/format_placeholders.c
        ${CMAKE_SOURCE_DIR}/app/get_process_filename.c
        ${CMAKE_SOURCE_DIR}/app/screenshot_wallpaper.c
        ${CMAKE_SOURCE_DIR}/app/fake_configure_notify.c
        )


add_executable(graceful-wm main.c ${MAIN_SRC})
target_include_directories(graceful-wm PUBLIC
        ${SN_INCLUDE_DIRS}
        ${GIO_INCLUDE_DIRS}
        ${XCB_INCLUDE_DIRS}
        ${XKB_INCLUDE_DIRS}
        ${YAJL_INCLUDE_DIRS}
        ${PCRE_INCLUDE_DIRS}
        ${PANGO_INCLUDE_DIRS}
        ${CAIRO_INCLUDE_DIRS})
target_link_libraries(graceful-wm
        -lm -lrt -lev
        ${SN_LIBRARIES}
        ${GIO_LIBRARIES}
        ${XCB_LIBRARIES}
        ${XKB_LIBRARIES}
        ${YAJL_LIBRARIES}
        ${PCRE_LIBRARIES}
        ${PANGO_LIBRARIES}
        ${CAIRO_LIBRARIES})