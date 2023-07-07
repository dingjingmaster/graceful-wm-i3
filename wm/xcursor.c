//
// Created by dingjing on 23-7-7.
//

#include "xcursor.h"


#include <err.h>
#include <assert.h>
#include <xcb/xcb_cursor.h>

#include "config.h"
#include "common/log.h"


static xcb_cursor_context_t *ctx;
static xcb_cursor_t cursors[XCURSOR_CURSOR_MAX];


void xcursor_load_cursors(void)
{
    if (xcb_cursor_context_new(gConn, gRootScreen, &ctx) < 0) {
        LOG_ERROR("Cannot allocate xcursor context");
        exit (EXIT_FAILURE);
    }
#define LOAD_CURSOR(constant, name)                            \
    do {                                                       \
        cursors[constant] = xcb_cursor_load_cursor(ctx, name); \
    } while (0)
    LOAD_CURSOR(XCURSOR_CURSOR_POINTER, "left_ptr");
    LOAD_CURSOR(XCURSOR_CURSOR_RESIZE_HORIZONTAL, "sb_h_double_arrow");
    LOAD_CURSOR(XCURSOR_CURSOR_RESIZE_VERTICAL, "sb_v_double_arrow");
    LOAD_CURSOR(XCURSOR_CURSOR_WATCH, "watch");
    LOAD_CURSOR(XCURSOR_CURSOR_MOVE, "fleur");
    LOAD_CURSOR(XCURSOR_CURSOR_TOP_LEFT_CORNER, "top_left_corner");
    LOAD_CURSOR(XCURSOR_CURSOR_TOP_RIGHT_CORNER, "top_right_corner");
    LOAD_CURSOR(XCURSOR_CURSOR_BOTTOM_LEFT_CORNER, "bottom_left_corner");
    LOAD_CURSOR(XCURSOR_CURSOR_BOTTOM_RIGHT_CORNER, "bottom_right_corner");
#undef LOAD_CURSOR
}

/*
 * Sets the cursor of the root window to the 'pointer' cursor.
 *
 * This function is called when i3 is initialized, because with some login
 * managers, the root window will not have a cursor otherwise.
 *
 */
void xcursor_set_root_cursor (int cursorID)
{
    xcb_change_window_attributes(gConn, gRoot, XCB_CW_CURSOR, (uint32_t[]){xcursor_get_cursor(cursorID)});
}

xcb_cursor_t xcursor_get_cursor (enum xcursor_cursor_t c)
{
    assert(c < XCURSOR_CURSOR_MAX);
    return cursors[c];
}
