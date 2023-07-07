//
// Created by dingjing on 23-7-7.
//

#ifndef GRACEFUL_XF_WM_DRAW_UTILS_H
#define GRACEFUL_XF_WM_DRAW_UTILS_H
#include <xcb/xcb.h>

#include "types.h"

void draw_util_surface_free     (xcb_connection_t* conn, surface_t* surface);
void draw_util_surface_set_size (surface_t* surface, int width, int height);
color_t draw_util_hex_to_color  (const char *color);
void draw_util_set_source_color (surface_t *surface, color_t color);
void draw_util_clear_surface    (surface_t *surface, color_t color);
void draw_util_rectangle        (surface_t *surface, color_t color, double x, double y, double w, double h);
void draw_util_image            (cairo_surface_t *image, surface_t *surface, int x, int y, int width, int height);
void draw_util_surface_init     (xcb_connection_t* conn, surface_t* surface, xcb_drawable_t drawable, xcb_visualtype_t* visual, int width, int height);
void draw_util_copy_surface     (surface_t* src, surface_t* dest, double src_x, double src_y, double dest_x, double dest_y, double width, double height);

#endif //GRACEFUL_XF_WM_DRAW_UTILS_H
