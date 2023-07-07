#pragma once
typedef enum {
    RENAME_WORKSPACE_LIKELY_TO_NEW_NAME = 0,
    MOVE_WORKSPACE_TO_OUTPUT_WORD = 1,
    RENAME_WORKSPACE_TO_NEW_NAME = 2,
    RENAME_WORKSPACE_LIKELY_TO = 3,
    MOVE_TO_ABSOLUTE_POSITION = 4,
    TITLE_WINDOW_ICON_PADDING = 5,
    CRITERION_FROM_STR_START = 6,
    MOVE_WORKSPACE_TO_OUTPUT = 7,
    RESIZE_HEIGHT_GET_NUMBER = 8,
    CRITERION_FROM_STR_END = 9,
    MOVE_DIRECTION_NUMBER = 10,
    MOVE_WORKSPACE_NUMBER = 11,
    BAR_HIDDEN_STATE_ID = 12,
    RENAME_WORKSPACE_TO = 13,
    RESIZE_TILING_FINAL = 14,
    CRITERION_FROM_STR = 15,
    MOVE_TO_POSITION_X = 16,
    MOVE_TO_POSITION_Y = 17,
    FULLSCREEN_COMPAT = 18,
    TITLE_WINDOW_ICON = 19,
    BAR_HIDDEN_STATE = 20,
    MOVE_TO_POSITION = 21,
    RENAME_WORKSPACE = 22,
    RESIZE_DIRECTION = 23,
    RESIZE_TILING_OR = 24,
    WORKSPACE_NUMBER = 25,
    FULLSCREEN_MODE = 26,
    GAPS_WITH_SCOPE = 27,
    CRITERION_FROM = 28,
    GAPS_WITH_MODE = 29,
    GAPS_WITH_TYPE = 30,
    MOVE_DIRECTION = 31,
    MOVE_TO_OUTPUT = 32,
    MOVE_WORKSPACE = 33,
    APPEND_LAYOUT = 34,
    CRITERION_STR = 35,
    LAYOUT_TOGGLE = 36,
    RESIZE_HEIGHT = 37,
    RESIZE_TILING = 38,
    SWAP_ARGUMENT = 39,
    BORDER_WIDTH = 40,
    FOCUS_OUTPUT = 41,
    MOVE_TO_MARK = 42,
    RESIZE_WIDTH = 43,
    TITLE_FORMAT = 44,
    BAR_MODE_ID = 45,
    FOCUS_AUTO = 46,
    FULLSCREEN = 47,
    RESIZE_SET = 48,
    SCRATCHPAD = 49,
    CRITERION = 50,
    RESIZE_PX = 51,
    WORKSPACE = 52,
    BAR_MODE = 53,
    CRITERIA = 54,
    DEBUGLOG = 55,
    FLOATING = 56,
    GAPS_END = 57,
    INITIAL = 58,
    BORDER = 59,
    LAYOUT = 60,
    RENAME = 61,
    RESIZE = 62,
    SHMLOG = 63,
    STICKY = 64,
    UNMARK = 65,
    FOCUS = 66,
    SPLIT = 67,
    EXEC = 68,
    GAPS = 69,
    KILL = 70,
    MARK = 71,
    MODE = 72,
    MOVE = 73,
    SWAP = 74,
    BAR = 75,
    NOP = 76,
    __CALL = 77
} cmdp_state;