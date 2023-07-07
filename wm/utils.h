//
// Created by dingjing on 23-7-7.
//

#ifndef GRACEFUL_XF_WM_UTILS_H
#define GRACEFUL_XF_WM_UTILS_H

#include <xcb/xcb.h>

void                init_dpi        (void);
int                 logical_px      (int logical);
xcb_visualtype_t*   get_visual_type (xcb_screen_t *screen);

void*               smalloc         (size_t size);
void*               scalloc         (size_t num, size_t size);
void*               srealloc        (void* ptr, size_t size);
char*               sstrdup         (const char* str);
char*               sstrndup        (const char* str, size_t size);

#endif //GRACEFUL_XF_WM_UTILS_H
