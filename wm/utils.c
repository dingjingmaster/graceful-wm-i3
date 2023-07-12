//
// Created by dingjing on 23-7-7.
//

#include "utils.h"

#include <ev.h>
#include <math.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <libgen.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <inttypes.h>
#include <sys/wait.h>
#include <xcb/xcb_xrm.h>

#if defined(__OpenBSD__)
#include <sys/cdefs.h>
#endif

#include "config.h"
#include "common/log.h"


static long init_dpi_fallback (void);


static long dpi;

void init_dpi (void)
{
    xcb_xrm_database_t *database = NULL;
    char *resource = NULL;

    if (NULL == gConn) {
        goto init_dpi_end;
    }

    database = xcb_xrm_database_from_default(gConn);
    if (database == NULL) {
        LOG_ERROR("Failed to open the resource database.");
        goto init_dpi_end;
    }

    xcb_xrm_resource_get_string(database, "Xft.dpi", NULL, &resource);
    if (resource == NULL) {
        LOG_ERROR("Resource Xft.dpi not specified, skipping.");
        goto init_dpi_end;
    }

    char *endptr;
    double in_dpi = strtod(resource, &endptr);
    if (in_dpi == HUGE_VAL || dpi < 0 || *endptr != '\0' || endptr == resource) {
        LOG_ERROR("Xft.dpi = %s is an invalid number and couldn't be parsed.", resource);
        dpi = 0;
        goto init_dpi_end;
    }
    dpi = lround(in_dpi);

    LOG_ERROR("Found Xft.dpi = %ld.", dpi);

init_dpi_end:
    free(resource);

    if (database != NULL) {
        xcb_xrm_database_free(database);
    }

    if (dpi == 0) {
        LOG_ERROR("Using fallback for calculating DPI.");
        dpi = init_dpi_fallback();
        LOG_ERROR("Using dpi = %ld", dpi);
    }
}

int logical_px(int logical)
{
    if (NULL == gRootScreen) {
        /* Dpi info may not be available when parsing a config without an X
         * server, such as for config file validation. */
        return logical;
    }

    /* There are many misconfigurations out there, i.e. systems with screens
     * whose dpi is in fact higher than 96 dpi, but not significantly higher,
     * so software was never adapted. We could tell people to reconfigure their
     * systems to 96 dpi in order to get the behavior they expect/are used to,
     * but since we can easily detect this case in code, let’s do it for them.
     */
    if (((double) dpi / 96.0) < 1.25) {
        return logical;
    }

    return ceil(((double) dpi / 96.0) * logical);
}

xcb_visualtype_t *get_visual_type(xcb_screen_t *screen)
{
    for (xcb_depth_iterator_t depth_iter = xcb_screen_allowed_depths_iterator(screen); depth_iter.rem; xcb_depth_next(&depth_iter)) {
        xcb_visualtype_iterator_t visual_iter;
        for (visual_iter = xcb_depth_visuals_iterator(depth_iter.data); visual_iter.rem; xcb_visualtype_next(&visual_iter)) {
            if (screen->root_visual == visual_iter.data->visual_id) {
                return visual_iter.data;
            }
        }
    }

    return NULL;
}


/*
 * The s* functions (safe) are wrappers around malloc, strdup, …, which exits if one of
 * the called functions returns NULL, meaning that there is no more memory available
 *
 */
void* smalloc (size_t size)
{
    void *result = malloc (size);
    if (result == NULL) {
        LOG_ERROR ("malloc(%zd)", size);
        exit (EXIT_FAILURE);
    }
    return result;
}

void* scalloc (size_t num, size_t size)
{
    void *result = calloc (num, size);
    if (result == NULL) {
        LOG_ERROR ("calloc(%zd, %zd)", num, size);
        exit (EXIT_FAILURE);
    }
    return result;
}

void* srealloc (void* ptr, size_t size)
{
    void *result = realloc (ptr, size);
    if (result == NULL && size > 0) {
        LOG_ERROR ("realloc(%zd)", size);
        exit (EXIT_FAILURE);
    }
    return result;
}

char* sstrdup (const char* str)
{
    char *result = strdup (str);
    if (result == NULL) {
        LOG_ERROR("strdup()");
        exit (EXIT_FAILURE);
    }
    return result;
}

char* sstrndup (const char* str, size_t size)
{
    char *result = strndup(str, size);
    if (result == NULL) {
        LOG_ERROR("strndup()");
        exit (EXIT_FAILURE);
    }
    return result;
}

int sasprintf(char** strp, const char *fmt, ...)
{
    va_list args;
    int result;

    va_start(args, fmt);
    if ((result = vasprintf(strp, fmt, args)) == -1) {
        LOG_ERROR ("asprintf(%s)", fmt);
        exit (EXIT_FAILURE);
    }
    va_end(args);
    return result;
}

ssize_t writeall(int fd, const void *buf, size_t count)
{
    size_t written = 0;

    while (written < count) {
        const ssize_t n = write (fd, ((char*) buf) + written, count - written);
        if (n == -1) {
            if (errno == EINTR || errno == EAGAIN) {
                continue;
            }
            return n;
        }
        written += (size_t)n;
    }

    return (ssize_t) written;
}

ssize_t writeall_nonblock(int fd, const void *buf, size_t count)
{
    size_t written = 0;

    while (written < count) {
        const ssize_t n = write(fd, ((char *)buf) + written, count - written);
        if (n == -1) {
            if (errno == EAGAIN) {
                return written;
            }
            else if (errno == EINTR) {
                continue;
            }
            else {
                return n;
            }
        }
        written += (size_t)n;
    }
    return written;
}

ssize_t swrite (int fd, const void *buf, size_t count)
{
    ssize_t n;

    n = writeall (fd, buf, count);
    if (n == -1) {
        LOG_ERROR("Failed to write %d", fd);
        exit (EXIT_FAILURE);
    }
    else {
        return n;
    }
}

/*
 * Like strcasecmp but considers the case where either string is NULL.
 *
 */
int strcasecmp_nullable(const char *a, const char *b)
{
    if (a == b) {
        return 0;
    }
    if (a == NULL) {
        return -1;
    }
    if (b == NULL) {
        return 1;
    }
    return strcasecmp(a, b);
}

// static
static long init_dpi_fallback (void)
{
    return (long) ((double) gRootScreen->height_in_pixels * 25.4 / (double) gRootScreen->height_in_millimeters);
}




int min(int a, int b)
{
    return (a < b ? a : b);
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

bool rect_contains(Rect rect, uint32_t x, uint32_t y)
{
    return (x >= rect.x &&
            x <= (rect.x + rect.width) &&
            y >= rect.y &&
            y <= (rect.y + rect.height));
}

Rect rect_add(Rect a, Rect b)
{
    return (Rect){a.x + b.x,
                  a.y + b.y,
                  a.width + b.width,
                  a.height + b.height};
}

Rect rect_sub(Rect a, Rect b)
{
    return (Rect){a.x - b.x,
                  a.y - b.y,
                  a.width - b.width,
                  a.height - b.height};
}

Rect rect_sanitize_dimensions(Rect rect)
{
    rect.width = (int32_t)rect.width <= 0 ? 1 : rect.width;
    rect.height = (int32_t)rect.height <= 0 ? 1 : rect.height;
    return rect;
}

bool rect_equals(Rect a, Rect b)
{
    return a.x == b.x && a.y == b.y && a.width == b.width && a.height == b.height;
}

/*
 * Returns true if the name consists of only digits.
 *
 */
__attribute__((pure)) bool name_is_digits(const char *name)
{
    /* positive integers and zero are interpreted as numbers */
    for (size_t i = 0; i < strlen(name); i++)
        if (!isdigit(name[i]))
            return false;

    return true;
}

/*
 * Set 'out' to the layout_t value for the given layout. The function
 * returns true on success or false if the passed string is not a valid
 * layout name.
 *
 */
bool layout_from_name(const char *layout_str, layout_t *out)
{
    if (strcmp(layout_str, "default") == 0) {
        *out = L_DEFAULT;
        return true;
    } else if (strcasecmp(layout_str, "stacked") == 0 ||
               strcasecmp(layout_str, "stacking") == 0) {
        *out = L_STACKED;
        return true;
    } else if (strcasecmp(layout_str, "tabbed") == 0) {
        *out = L_TABBED;
        return true;
    } else if (strcasecmp(layout_str, "splitv") == 0) {
        *out = L_SPLITV;
        return true;
    } else if (strcasecmp(layout_str, "splith") == 0) {
        *out = L_SPLITH;
        return true;
    }

    return false;
}

/*
 * Parses the workspace name as a number. Returns -1 if the workspace should be
 * interpreted as a "named workspace".
 *
 */
int ws_name_to_number(const char *name)
{
    /* positive integers and zero are interpreted as numbers */
    char *endptr = NULL;
    errno = 0;
    long long parsed_num = strtoll(name, &endptr, 10);
    if (errno != 0 || parsed_num > INT32_MAX || parsed_num < 0 || endptr == name) {
        parsed_num = -1;
    }

    return parsed_num;
}

/*
 * Updates *destination with new_value and returns true if it was changed or false
 * if it was the same
 *
 */
bool update_if_necessary(uint32_t *destination, const uint32_t new_value)
{
    uint32_t old_value = *destination;

    return ((*destination = new_value) != old_value);
}

/*
 * exec()s an i3 utility, for example the config file migration script or
 * i3-nagbar. This function first searches $PATH for the given utility named,
 * then falls back to the dirname() of the i3 executable path and then falls
 * back to the dirname() of the target of /proc/self/exe (on linux).
 *
 * This function should be called after fork()ing.
 *
 * The first argument of the given argv vector will be overwritten with the
 * executable name, so pass NULL.
 *
 * If the utility cannot be found in any of these locations, it exits with
 * return code 2.
 *
 */
void exec_i3_utility(char *name, char *argv[])
{
    /* start the migration script, search PATH first */
    char *migratepath = name;
    argv[0] = migratepath;
    execvp(migratepath, argv);

    /* if the script is not in path, maybe the user installed to a strange
     * location and runs the i3 binary with an absolute path. We use
     * argv[0]’s dirname */
    char *pathbuf = sstrdup(start_argv[0]);
    char *dir = dirname(pathbuf);
    sasprintf(&migratepath, "%s/%s", dir, name);
    argv[0] = migratepath;
    execvp(migratepath, argv);

#if defined(__linux__)
    /* on linux, we have one more fall-back: dirname(/proc/self/exe) */
    char buffer[BUFSIZ];
    if (readlink("/proc/self/exe", buffer, BUFSIZ) == -1) {
        warn("could not read /proc/self/exe");
        _exit(EXIT_FAILURE);
    }
    dir = dirname(buffer);
    sasprintf(&migratepath, "%s/%s", dir, name);
    argv[0] = migratepath;
    execvp(migratepath, argv);
#endif

    warn("Could not start %s", name);
    _exit(2);
}

/*
 * Goes through the list of arguments (for exec()) and add/replace the given option,
 * including the option name, its argument, and the option character.
 */
static char **add_argument(char **original, char *opt_char, char *opt_arg, char *opt_name)
{
    int num_args;
    for (num_args = 0; original[num_args] != NULL; num_args++)
        ;
    char **result = scalloc(num_args + 3, sizeof(char *));

    /* copy the arguments, but skip the ones we'll replace */
    int write_index = 0;
    bool skip_next = false;
    for (int i = 0; i < num_args; ++i) {
        if (skip_next) {
            skip_next = false;
            continue;
        }
        if (!strcmp(original[i], opt_char) ||
            (opt_name && !strcmp(original[i], opt_name))) {
            if (opt_arg)
                skip_next = true;
            continue;
        }
        result[write_index++] = original[i];
    }

    /* add the arguments we'll replace */
    result[write_index++] = opt_char;
    result[write_index] = opt_arg;

    return result;
}


#define y(x, ...) yajl_gen_##x(gen, ##__VA_ARGS__)
#define ystr(str) yajl_gen_string(gen, (unsigned char *)str, strlen(str))

static char *store_restart_layout(void)
{
    setlocale(LC_NUMERIC, "C");
    yajl_gen gen = yajl_gen_alloc(NULL);

    dump_node(gen, gConnRoot, true);

    setlocale(LC_NUMERIC, "");

    const unsigned char *payload;
    size_t length;
    y(get_buf, &payload, &length);

    /* create a temporary file if one hasn't been specified, or just
     * resolve the tildes in the specified path */
    char *filename;
    if (config.restart_state_path == NULL) {
        filename = get_process_filename("restart-state");
        if (!filename)
            return NULL;
    } else {
        filename = resolve_tilde(config.restart_state_path);
    }

    /* create the directory, it could have been cleaned up before restarting or
     * may not exist at all in case it was user-specified. */
    char *filenamecopy = sstrdup(filename);
    char *base = dirname(filenamecopy);
    DEBUG ("Creating \"%s\" for storing the restart layout\n", base);
    if (mkdirp(base, DEFAULT_DIR_MODE) != 0)
        ERROR("Could not create \"%s\" for storing the restart layout, layout will be lost.", base);
    free(filenamecopy);

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open()");
        free(filename);
        return NULL;
    }

    if (writeall(fd, payload, length) == -1) {
        ERROR("Could not write restart layout to \"%s\", layout will be lost: %s\n", filename, strerror(errno));
        free(filename);
        close(fd);
        return NULL;
    }

    close(fd);

    if (length > 0) {
        DEBUG("layout: %.*s\n", (int)length, payload);
    }

    y(free);

    return filename;
}

/*
 * Restart i3 in-place
 * appends -a to argument list to disable autostart
 *
 */
void i3_restart(bool forget_layout)
{
    char *restart_filename = forget_layout ? NULL : store_restart_layout();

    kill_nagbar(config_error_nagbar_pid, true);
    kill_nagbar(command_error_nagbar_pid, true);

    restore_geometry();

    ipc_shutdown(SHUTDOWN_REASON_RESTART, -1);

    DEBUG("restarting \"%s\"...\n", start_argv[0]);
    /* make sure -a is in the argument list or add it */
    start_argv = add_argument(start_argv, "-a", NULL, NULL);

    /* make debuglog-on persist */
    if (get_debug_logging()) {
        start_argv = add_argument(start_argv, "-d", "all", NULL);
    }

    /* replace -r <file> so that the layout is restored */
    if (restart_filename != NULL) {
        start_argv = add_argument(start_argv, "--restart", restart_filename, "-r");
    }

    execvp(start_argv[0], start_argv);

    /* not reached */
}

/*
 * Escapes the given string if a pango font is currently used.
 * If the string has to be escaped, the input string will be free'd.
 *
 */
char *pango_escape_markup(char *input)
{
    if (!font_is_pango())
        return input;

    char *escaped = g_markup_escape_text(input, -1);
    FREE(input);

    return escaped;
}

/*
 * Handler which will be called when we get a SIGCHLD for the nagbar, meaning
 * it exited (or could not be started, depending on the exit code).
 *
 */
static void nagbar_exited(EV_P_ ev_child *watcher, int revents)
{
    ev_child_stop(EV_A_ watcher);

    int exitcode = WEXITSTATUS(watcher->rstatus);

    if (!WIFEXITED(watcher->rstatus)) {
        ERROR("i3-nagbar (%d) did not exit normally. This is not an error if the config was reloaded while a nagbar was active.\n", watcher->pid);
    }
    else if (exitcode != 0) {
        ERROR("i3-nagbar (%d) process exited with status %d\n", watcher->pid, exitcode);
    }
    else {
        ERROR("i3-nagbar (%d) process exited with status %d\n", watcher->pid, exitcode);
    }

    pid_t *nagbar_pid = watcher->data;
    if (*nagbar_pid == watcher->pid) {
        /* Only reset if the watched nagbar is the active nagbar */
        *nagbar_pid = -1;
    }
}

/*
 * Starts an i3-nagbar instance with the given parameters. Takes care of
 * handling SIGCHLD and killing i3-nagbar when i3 exits.
 *
 * The resulting PID will be stored in *nagbar_pid and can be used with
 * kill_nagbar() to kill the bar later on.
 *
 */
void start_nagbar(pid_t *nagbar_pid, char *argv[])
{
    if (*nagbar_pid != -1) {
        DEBUG("i3-nagbar already running (PID %d), not starting again.\n", *nagbar_pid);
        return;
    }

    *nagbar_pid = fork();
    if (*nagbar_pid == -1) {
        warn("Could not fork()");
        return;
    }

    /* child */
    if (*nagbar_pid == 0)
        exec_i3_utility("i3-nagbar", argv);

    DEBUG("Starting i3-nagbar with PID %d\n", *nagbar_pid);

    /* parent */
    /* install a child watcher */
    ev_child *child = smalloc(sizeof(ev_child));
    ev_child_init(child, &nagbar_exited, *nagbar_pid, 0);
    child->data = nagbar_pid;
    ev_child_start(gMainLoop, child);
}

/*
 * Kills the i3-nagbar process, if nagbar_pid != -1.
 *
 * If wait_for_it is set (restarting i3), this function will waitpid(),
 * otherwise, ev is assumed to handle it (reloading).
 *
 */
void kill_nagbar(pid_t nagbar_pid, bool wait_for_it)
{
    if (nagbar_pid == -1)
        return;

    if (kill(nagbar_pid, SIGTERM) == -1)
        warn("kill(configerror_nagbar) failed");

    if (!wait_for_it)
        return;

    /* When restarting, we don’t enter the ev main loop anymore and after the
     * exec(), our old pid is no longer watched. So, ev won’t handle SIGCHLD
     * for us and we would end up with a <defunct> process. Therefore we
     * waitpid() here. */
    waitpid(nagbar_pid, NULL, 0);
}

/*
 * Converts a string into a long using strtol().
 * This is a convenience wrapper checking the parsing result. It returns true
 * if the number could be parsed.
 */
bool parse_long(const char *str, long *out, int base)
{
    char *end = NULL;
    long result = strtol(str, &end, base);
    if (result == LONG_MIN || result == LONG_MAX || result < 0 || (end != NULL && *end != '\0')) {
        *out = result;
        return false;
    }

    *out = result;
    return true;
}

/*
 * Slurp reads path in its entirety into buf, returning the length of the file
 * or -1 if the file could not be read. buf is set to a buffer of appropriate
 * size, or NULL if -1 is returned.
 *
 */
ssize_t slurp(const char *path, char **buf)
{
    FILE *f;
    if ((f = fopen(path, "r")) == NULL) {
        ERROR("Cannot open file \"%s\": %s\n", path, strerror(errno));
        return -1;
    }
    struct stat stbuf;
    if (fstat(fileno(f), &stbuf) != 0) {
        ERROR("Cannot fstat() \"%s\": %s\n", path, strerror(errno));
        fclose(f);
        return -1;
    }
    /* Allocate one extra NUL byte to make the buffer usable with C string
     * functions. yajl doesn’t need this, but this makes slurp safer. */
    *buf = scalloc(stbuf.st_size + 1, 1);
    size_t n = fread(*buf, 1, stbuf.st_size, f);
    fclose(f);
    if ((ssize_t)n != stbuf.st_size) {
        ERROR("File \"%s\" could not be read entirely: got %zd, want %" PRIi64 "\n", path, n, (int64_t)stbuf.st_size);
        FREE(*buf);
        return -1;
    }
    return (ssize_t)n;
}

/*
 * Convert a direction to its corresponding orientation.
 *
 */
orientation_t orientation_from_direction(direction_t direction)
{
    return (direction == D_LEFT || direction == D_RIGHT) ? HORIZ : VERT;
}

/*
 * Convert a direction to its corresponding position.
 *
 */
position_t position_from_direction(direction_t direction)
{
    return (direction == D_LEFT || direction == D_UP) ? BEFORE : AFTER;
}

/*
 * Convert orientation and position to the corresponding direction.
 *
 */
direction_t direction_from_orientation_position(orientation_t orientation, position_t position)
{
    if (orientation == HORIZ) {
        return position == BEFORE ? D_LEFT : D_RIGHT;
    }
    else {
        return position == BEFORE ? D_UP : D_DOWN;
    }
}

/*
 * Converts direction to a string representation.
 *
 */
const char *direction_to_string(direction_t direction)
{
    switch (direction) {
        case D_LEFT:
            return "left";
        case D_RIGHT:
            return "right";
        case D_UP:
            return "up";
        case D_DOWN:
            return "down";
    }
    return "invalid";
}

/*
 * Converts position to a string representation.
 *
 */
const char *position_to_string(position_t position)
{
    switch (position) {
        case BEFORE:
            return "before";
        case AFTER:
            return "after";
    }
    return "invalid";
}

