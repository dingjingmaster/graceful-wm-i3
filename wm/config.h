//
// Created by dingjing on 23-7-7.
//

#ifndef GRACEFUL_XF_WM_CONFIG_H
#define GRACEFUL_XF_WM_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include <xcb/xcb.h>
#include <libsn/sn-common.h>
#include <xcb/xcb_keysyms.h>

#include "types.h"


/**
 * @brief
 *  保存命令行参数和配置文件中的值
 */

extern const char*              gLogPath;               // 日志输出路径
extern xcb_connection_t*        gConn;                  // xcb 连接
extern int                      gConnScreen;            //
extern xcb_screen_t*            gRootScreen;            //
extern SnDisplay*               gSnDisplay;
extern struct ev_loop*          gMainLoop;
extern xcb_window_t             gRoot;
extern uint8_t                  gRootDepth;
extern xcb_colormap_t           gColormap;
extern xcb_visualtype_t*        gVisualType;
extern xcb_timestamp_t          gLastTimestamp;
extern xcb_window_t             gWMSnSelectionOwner;
extern xcb_atom_t               gWMSn;
extern int                      gXkbBase;
extern int                      gShapeBase;
extern bool                     gShapeSupported;
extern bool                     gXkbSupported;
extern unsigned int             gXcbNumLockMask;
extern xcb_key_symbols_t*       gKeySyms;
extern Con*                     gConnRoot;
extern Con*                     gFocused;
extern struct AllConHead        gAllCons;
extern xcb_window_t             gFocusedID;


/* commandline -- start */
extern bool gReplaceWM;
extern bool gVersion;
/* commandline -- end */

/* configure file -- start */

/* configure file -- end */

#endif //GRACEFUL_XF_WM_CONFIG_H
