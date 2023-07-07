//
// Created by dingjing on 23-7-7.
//

#ifndef GRACEFUL_XF_WM_DATA_H
#define GRACEFUL_XF_WM_DATA_H

#define PCRE2_CODE_UNIT_WIDTH 8
#define SN_API_NOT_YET_FROZEN 1

#include <libsn/sn-launcher.h>

#include <pcre2.h>
#include <stdbool.h>
#include <sys/time.h>
#include <xcb/randr.h>
#include <cairo/cairo.h>

#include "types.h"

/*
 * To get the big concept: There are helper structures like struct
 * Workspace_Assignment. Every struct which is also defined as type (see
 * forward definitions) is considered to be a major structure, thus important.
 *
 * The following things are all stored in a 'Con', from very high level (the
 * biggest Cons) to very small (a single window):
 *
 * 1) X11 root window (as big as all your outputs combined)
 * 2) output (like LVDS1)
 * 3) content container, dockarea containers
 * 4) workspaces
 * 5) split containers
 * ... (you can arbitrarily nest split containers)
 * 6) X11 window containers
 *
 */

/* Forward definitions */



#endif //GRACEFUL_XF_WM_DATA_H
