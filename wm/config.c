//
// Created by dingjing on 23-7-7.
//
#include "config.h"


int                         gConnScreen = 0;
bool                        gVersion = false;
bool                        gReplaceWM = false;
xcb_connection_t*           gConn = NULL;
xcb_screen_t*               gRootScreen = NULL;
struct ev_loop*             gMainLoop = NULL;
xcb_window_t                gRoot;
uint8_t                     gRootDepth;
xcb_colormap_t              gColormap;
xcb_visualtype_t*           gVisualType = NULL;
SnDisplay*                  gSnDisplay = NULL;
xcb_timestamp_t             gLastTimestamp = XCB_CURRENT_TIME;
xcb_window_t                gWMSnSelectionOwner;
xcb_atom_t                  gWMSn;
bool                        gXkbSupported = true;
int                         gXkbBase;
int                         gShapeBase;
bool                        gShapeSupported;
unsigned int                gXcbNumLockMask;
xcb_key_symbols_t*          gKeySyms = NULL;
Con*                        gConnRoot = NULL;
Con*                        gFocused = NULL;
const char*                 gLogPath = "/tmp/" APP_NAME ".log";
xcb_window_t                gFocusedID = XCB_NONE;

struct AllConHead           gAllCons;
struct AllConHead           gAllConns = TAILQ_HEAD_INITIALIZER(gAllCons);
