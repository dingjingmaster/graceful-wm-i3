//
// Created by dingjing on 23-7-7.
//

#include "utils.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <xcb/xcb_xrm.h>

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


