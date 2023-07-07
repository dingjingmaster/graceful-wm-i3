#pragma once
static cmdp_token tokens_RENAME_WORKSPACE_LIKELY_TO_NEW_NAME[2] = {
    { "string", "new_name", __CALL, { 0 } },
    { "end", NULL, __CALL, { 1 } },
};
static cmdp_token tokens_MOVE_WORKSPACE_TO_OUTPUT_WORD[2] = {
    { "word", "output", __CALL, { 2 } },
    { "end", NULL, __CALL, { 3 } },
};
static cmdp_token tokens_RENAME_WORKSPACE_TO_NEW_NAME[1] = {
    { "string", "new_name", __CALL, { 4 } },
};
static cmdp_token tokens_RENAME_WORKSPACE_LIKELY_TO[2] = {
    { "'to ", NULL, RENAME_WORKSPACE_LIKELY_TO_NEW_NAME, { 0 } },
    { "word", "new_name", __CALL, { 5 } },
};
static cmdp_token tokens_MOVE_TO_ABSOLUTE_POSITION[1] = {
    { "'position", NULL, MOVE_TO_POSITION, { 0 } },
};
static cmdp_token tokens_TITLE_WINDOW_ICON_PADDING[3] = {
    { "end", NULL, __CALL, { 6 } },
    { "'px", NULL, __CALL, { 7 } },
    { "number", "padding", TITLE_WINDOW_ICON_PADDING, { 0 } },
};
static cmdp_token tokens_CRITERION_FROM_STR_START[3] = {
    { "'\"", NULL, CRITERION_FROM_STR, { 0 } },
    { "'auto", "kind", __CALL, { 8 } },
    { "'user", "kind", __CALL, { 9 } },
};
static cmdp_token tokens_MOVE_WORKSPACE_TO_OUTPUT[1] = {
    { "'output", NULL, MOVE_WORKSPACE_TO_OUTPUT_WORD, { 0 } },
};
static cmdp_token tokens_RESIZE_HEIGHT_GET_NUMBER[1] = {
    { "number", "height", RESIZE_HEIGHT, { 0 } },
};
static cmdp_token tokens_CRITERION_FROM_STR_END[1] = {
    { "'\"", NULL, __CALL, { 10 } },
};
static cmdp_token tokens_MOVE_DIRECTION_NUMBER[3] = {
    { "'px", "mode", __CALL, { 11 } },
    { "'ppt", "mode", __CALL, { 12 } },
    { "end", NULL, __CALL, { 13 } },
};
static cmdp_token tokens_MOVE_WORKSPACE_NUMBER[1] = {
    { "string", "number", __CALL, { 14 } },
};
static cmdp_token tokens_BAR_HIDDEN_STATE_ID[2] = {
    { "word", "bar_id", BAR_HIDDEN_STATE_ID, { 0 } },
    { "end", NULL, __CALL, { 15 } },
};
static cmdp_token tokens_RENAME_WORKSPACE_TO[1] = {
    { "'to", NULL, RENAME_WORKSPACE_TO_NEW_NAME, { 0 } },
};
static cmdp_token tokens_RESIZE_TILING_FINAL[2] = {
    { "'ppt", NULL, __CALL, { 16 } },
    { "end", NULL, __CALL, { 17 } },
};
static cmdp_token tokens_CRITERION_FROM_STR[2] = {
    { "'auto", "kind", CRITERION_FROM_STR_END, { 0 } },
    { "'user", "kind", CRITERION_FROM_STR_END, { 0 } },
};
static cmdp_token tokens_MOVE_TO_POSITION_X[3] = {
    { "'px", "mode_x", MOVE_TO_POSITION_X, { 0 } },
    { "'ppt", "mode_x", MOVE_TO_POSITION_X, { 0 } },
    { "number", "coord_y", MOVE_TO_POSITION_Y, { 0 } },
};
static cmdp_token tokens_MOVE_TO_POSITION_Y[3] = {
    { "'px", "mode_y", __CALL, { 18 } },
    { "'ppt", "mode_y", __CALL, { 19 } },
    { "end", NULL, __CALL, { 20 } },
};
static cmdp_token tokens_FULLSCREEN_COMPAT[2] = {
    { "'global", "mode", __CALL, { 21 } },
    { "end", NULL, __CALL, { 22 } },
};
static cmdp_token tokens_TITLE_WINDOW_ICON[14] = {
    { "'padding", NULL, TITLE_WINDOW_ICON_PADDING, { 0 } },
    { "'toggle", "enable", TITLE_WINDOW_ICON_PADDING, { 0 } },
    { "'1", "enable", __CALL, { 23 } },
    { "'yes", "enable", __CALL, { 24 } },
    { "'true", "enable", __CALL, { 25 } },
    { "'on", "enable", __CALL, { 26 } },
    { "'enable", "enable", __CALL, { 27 } },
    { "'active", "enable", __CALL, { 28 } },
    { "'0", "enable", __CALL, { 29 } },
    { "'no", "enable", __CALL, { 30 } },
    { "'false", "enable", __CALL, { 31 } },
    { "'off", "enable", __CALL, { 32 } },
    { "'disable", "enable", __CALL, { 33 } },
    { "'inactive", "enable", __CALL, { 34 } },
};
static cmdp_token tokens_BAR_HIDDEN_STATE[3] = {
    { "'hide", "bar_value", BAR_HIDDEN_STATE_ID, { 0 } },
    { "'show", "bar_value", BAR_HIDDEN_STATE_ID, { 0 } },
    { "'toggle", "bar_value", BAR_HIDDEN_STATE_ID, { 0 } },
};
static cmdp_token tokens_MOVE_TO_POSITION[5] = {
    { "'center", NULL, __CALL, { 35 } },
    { "'mouse", NULL, __CALL, { 36 } },
    { "'cursor", NULL, __CALL, { 37 } },
    { "'pointer", NULL, __CALL, { 38 } },
    { "number", "coord_x", MOVE_TO_POSITION_X, { 0 } },
};
static cmdp_token tokens_RENAME_WORKSPACE[2] = {
    { "'to", NULL, RENAME_WORKSPACE_LIKELY_TO, { 0 } },
    { "word", "old_name", RENAME_WORKSPACE_TO, { 0 } },
};
static cmdp_token tokens_RESIZE_DIRECTION[6] = {
    { "'up", "direction", RESIZE_PX, { 0 } },
    { "'down", "direction", RESIZE_PX, { 0 } },
    { "'left", "direction", RESIZE_PX, { 0 } },
    { "'right", "direction", RESIZE_PX, { 0 } },
    { "'width", "direction", RESIZE_PX, { 0 } },
    { "'height", "direction", RESIZE_PX, { 0 } },
};
static cmdp_token tokens_RESIZE_TILING_OR[1] = {
    { "number", "resize_ppt", RESIZE_TILING_FINAL, { 0 } },
};
static cmdp_token tokens_WORKSPACE_NUMBER[1] = {
    { "string", "workspace", __CALL, { 39 } },
};
static cmdp_token tokens_FULLSCREEN_MODE[2] = {
    { "'global", "mode", __CALL, { 40 } },
    { "end", NULL, __CALL, { 41 } },
};
static cmdp_token tokens_GAPS_WITH_SCOPE[4] = {
    { "'plus", "mode", GAPS_WITH_MODE, { 0 } },
    { "'minus", "mode", GAPS_WITH_MODE, { 0 } },
    { "'set", "mode", GAPS_WITH_MODE, { 0 } },
    { "'toggle", "mode", GAPS_WITH_MODE, { 0 } },
};
static cmdp_token tokens_CRITERION_FROM[1] = {
    { "'=", NULL, CRITERION_FROM_STR_START, { 0 } },
};
static cmdp_token tokens_GAPS_WITH_MODE[1] = {
    { "word", "value", GAPS_END, { 0 } },
};
static cmdp_token tokens_GAPS_WITH_TYPE[2] = {
    { "'current", "scope", GAPS_WITH_SCOPE, { 0 } },
    { "'all", "scope", GAPS_WITH_SCOPE, { 0 } },
};
static cmdp_token tokens_MOVE_DIRECTION[2] = {
    { "number", "amount", MOVE_DIRECTION_NUMBER, { 0 } },
    { "end", NULL, __CALL, { 42 } },
};
static cmdp_token tokens_MOVE_TO_OUTPUT[2] = {
    { "word", "output", __CALL, { 43 } },
    { "end", NULL, __CALL, { 44 } },
};
static cmdp_token tokens_MOVE_WORKSPACE[9] = {
    { "'to ", NULL, MOVE_WORKSPACE_TO_OUTPUT, { 0 } },
    { "'next_on_output", "workspace", __CALL, { 45 } },
    { "'prev_on_output", "workspace", __CALL, { 46 } },
    { "'next", "workspace", __CALL, { 47 } },
    { "'prev", "workspace", __CALL, { 48 } },
    { "'current", "workspace", __CALL, { 49 } },
    { "'back_and_forth", NULL, __CALL, { 50 } },
    { "'number", NULL, MOVE_WORKSPACE_NUMBER, { 0 } },
    { "string", "workspace", __CALL, { 51 } },
};
static cmdp_token tokens_APPEND_LAYOUT[1] = {
    { "string", "path", __CALL, { 52 } },
};
static cmdp_token tokens_CRITERION_STR[1] = {
    { "word", "cvalue", __CALL, { 53 } },
};
static cmdp_token tokens_LAYOUT_TOGGLE[2] = {
    { "end", NULL, __CALL, { 54 } },
    { "string", "toggle_mode", __CALL, { 55 } },
};
static cmdp_token tokens_RESIZE_HEIGHT[3] = {
    { "'px", "mode_height", RESIZE_HEIGHT, { 0 } },
    { "'ppt", "mode_height", RESIZE_HEIGHT, { 0 } },
    { "end", NULL, __CALL, { 56 } },
};
static cmdp_token tokens_RESIZE_TILING[3] = {
    { "'px", NULL, RESIZE_TILING, { 0 } },
    { "'or", NULL, RESIZE_TILING_OR, { 0 } },
    { "end", NULL, __CALL, { 57 } },
};
static cmdp_token tokens_SWAP_ARGUMENT[1] = {
    { "string", "arg", __CALL, { 58 } },
};
static cmdp_token tokens_BORDER_WIDTH[2] = {
    { "end", NULL, __CALL, { 59 } },
    { "number", "border_width", __CALL, { 60 } },
};
static cmdp_token tokens_FOCUS_OUTPUT[2] = {
    { "word", "output", __CALL, { 61 } },
    { "end", NULL, __CALL, { 62 } },
};
static cmdp_token tokens_MOVE_TO_MARK[1] = {
    { "string", "mark", __CALL, { 63 } },
};
static cmdp_token tokens_RESIZE_WIDTH[5] = {
    { "'px", "mode_width", RESIZE_WIDTH, { 0 } },
    { "'ppt", "mode_width", RESIZE_WIDTH, { 0 } },
    { "end", NULL, __CALL, { 64 } },
    { "'height", NULL, RESIZE_HEIGHT_GET_NUMBER, { 0 } },
    { "number", "height", RESIZE_HEIGHT, { 0 } },
};
static cmdp_token tokens_TITLE_FORMAT[1] = {
    { "string", "format", __CALL, { 65 } },
};
static cmdp_token tokens_BAR_MODE_ID[2] = {
    { "word", "bar_id", BAR_MODE_ID, { 0 } },
    { "end", NULL, __CALL, { 66 } },
};
static cmdp_token tokens_FOCUS_AUTO[2] = {
    { "'sibling", NULL, __CALL, { 67 } },
    { "end", NULL, __CALL, { 68 } },
};
static cmdp_token tokens_FULLSCREEN[4] = {
    { "'disable", "action", __CALL, { 69 } },
    { "'enable", "action", FULLSCREEN_MODE, { 0 } },
    { "'toggle", "action", FULLSCREEN_MODE, { 0 } },
    { "'", "action", FULLSCREEN_COMPAT, { 0 } },
};
static cmdp_token tokens_RESIZE_SET[3] = {
    { "'height", NULL, RESIZE_HEIGHT_GET_NUMBER, { 0 } },
    { "'width", NULL, RESIZE_SET, { 0 } },
    { "number", "width", RESIZE_WIDTH, { 0 } },
};
static cmdp_token tokens_SCRATCHPAD[1] = {
    { "'show", NULL, __CALL, { 70 } },
};
static cmdp_token tokens_CRITERION[1] = {
    { "'=", NULL, CRITERION_STR, { 0 } },
};
static cmdp_token tokens_RESIZE_PX[2] = {
    { "number", "resize_px", RESIZE_TILING, { 0 } },
    { "end", NULL, __CALL, { 71 } },
};
static cmdp_token tokens_WORKSPACE[8] = {
    { "'--no-auto-back-and-forth", "no_auto_back_and_forth", WORKSPACE, { 0 } },
    { "'next_on_output", "direction", __CALL, { 72 } },
    { "'prev_on_output", "direction", __CALL, { 73 } },
    { "'next", "direction", __CALL, { 74 } },
    { "'prev", "direction", __CALL, { 75 } },
    { "'back_and_forth", NULL, __CALL, { 76 } },
    { "'number", NULL, WORKSPACE_NUMBER, { 0 } },
    { "string", "workspace", __CALL, { 77 } },
};
static cmdp_token tokens_BAR_MODE[4] = {
    { "'dock", "bar_value", BAR_MODE_ID, { 0 } },
    { "'hide", "bar_value", BAR_MODE_ID, { 0 } },
    { "'invisible", "bar_value", BAR_MODE_ID, { 0 } },
    { "'toggle", "bar_value", BAR_MODE_ID, { 0 } },
};
static cmdp_token tokens_CRITERIA[17] = {
    { "'class", "ctype", CRITERION, { 0 } },
    { "'instance", "ctype", CRITERION, { 0 } },
    { "'window_role", "ctype", CRITERION, { 0 } },
    { "'con_id", "ctype", CRITERION, { 0 } },
    { "'id", "ctype", CRITERION, { 0 } },
    { "'window_type", "ctype", CRITERION, { 0 } },
    { "'con_mark", "ctype", CRITERION, { 0 } },
    { "'title", "ctype", CRITERION, { 0 } },
    { "'urgent", "ctype", CRITERION, { 0 } },
    { "'workspace", "ctype", CRITERION, { 0 } },
    { "'machine", "ctype", CRITERION, { 0 } },
    { "'floating_from", "ctype", CRITERION_FROM, { 0 } },
    { "'tiling_from", "ctype", CRITERION_FROM, { 0 } },
    { "'tiling", "ctype", __CALL, { 78 } },
    { "'floating", "ctype", __CALL, { 79 } },
    { "'all", "ctype", __CALL, { 80 } },
    { "']", NULL, __CALL, { 81 } },
};
static cmdp_token tokens_DEBUGLOG[3] = {
    { "'toggle", "argument", __CALL, { 82 } },
    { "'on", "argument", __CALL, { 83 } },
    { "'off", "argument", __CALL, { 84 } },
};
static cmdp_token tokens_FLOATING[3] = {
    { "'enable", "floating", __CALL, { 85 } },
    { "'disable", "floating", __CALL, { 86 } },
    { "'toggle", "floating", __CALL, { 87 } },
};
static cmdp_token tokens_GAPS_END[2] = {
    { "'px", NULL, GAPS_END, { 0 } },
    { "end", NULL, __CALL, { 88 } },
};
static cmdp_token tokens_INITIAL[32] = {
    { "end", NULL, INITIAL, { 0 } },
    { "'[", NULL, __CALL, { 89 } },
    { "'move", NULL, MOVE, { 0 } },
    { "'exec", NULL, EXEC, { 0 } },
    { "'exit", NULL, __CALL, { 90 } },
    { "'restart", NULL, __CALL, { 91 } },
    { "'reload", NULL, __CALL, { 92 } },
    { "'shmlog", NULL, SHMLOG, { 0 } },
    { "'debuglog", NULL, DEBUGLOG, { 0 } },
    { "'border", NULL, BORDER, { 0 } },
    { "'layout", NULL, LAYOUT, { 0 } },
    { "'append_layout", NULL, APPEND_LAYOUT, { 0 } },
    { "'workspace", NULL, WORKSPACE, { 0 } },
    { "'focus", NULL, FOCUS, { 0 } },
    { "'kill", NULL, KILL, { 0 } },
    { "'open", NULL, __CALL, { 93 } },
    { "'fullscreen", NULL, FULLSCREEN, { 0 } },
    { "'sticky", NULL, STICKY, { 0 } },
    { "'split", NULL, SPLIT, { 0 } },
    { "'floating", NULL, FLOATING, { 0 } },
    { "'mark", NULL, MARK, { 0 } },
    { "'unmark", NULL, UNMARK, { 0 } },
    { "'resize", NULL, RESIZE, { 0 } },
    { "'rename", NULL, RENAME, { 0 } },
    { "'nop", NULL, NOP, { 0 } },
    { "'scratchpad", NULL, SCRATCHPAD, { 0 } },
    { "'swap", NULL, SWAP, { 0 } },
    { "'title_format", NULL, TITLE_FORMAT, { 0 } },
    { "'title_window_icon", NULL, TITLE_WINDOW_ICON, { 0 } },
    { "'mode", NULL, MODE, { 0 } },
    { "'bar", NULL, BAR, { 0 } },
    { "'gaps", NULL, GAPS, { 0 } },
};
static cmdp_token tokens_BORDER[5] = {
    { "'normal", "border_style", BORDER_WIDTH, { 0 } },
    { "'pixel", "border_style", BORDER_WIDTH, { 0 } },
    { "'toggle", "border_style", BORDER_WIDTH, { 0 } },
    { "'none", "border_style", __CALL, { 94 } },
    { "'1pixel", NULL, __CALL, { 95 } },
};
static cmdp_token tokens_LAYOUT[7] = {
    { "'default", "layout_mode", __CALL, { 96 } },
    { "'stacked", "layout_mode", __CALL, { 97 } },
    { "'stacking", "layout_mode", __CALL, { 98 } },
    { "'tabbed", "layout_mode", __CALL, { 99 } },
    { "'splitv", "layout_mode", __CALL, { 100 } },
    { "'splith", "layout_mode", __CALL, { 101 } },
    { "'toggle", NULL, LAYOUT_TOGGLE, { 0 } },
};
static cmdp_token tokens_RENAME[1] = {
    { "'workspace", NULL, RENAME_WORKSPACE, { 0 } },
};
static cmdp_token tokens_RESIZE[3] = {
    { "'grow", "way", RESIZE_DIRECTION, { 0 } },
    { "'shrink", "way", RESIZE_DIRECTION, { 0 } },
    { "'set", "set", RESIZE_SET, { 0 } },
};
static cmdp_token tokens_SHMLOG[1] = {
    { "string", "argument", __CALL, { 102 } },
};
static cmdp_token tokens_STICKY[3] = {
    { "'enable", "action", __CALL, { 103 } },
    { "'disable", "action", __CALL, { 104 } },
    { "'toggle", "action", __CALL, { 105 } },
};
static cmdp_token tokens_UNMARK[2] = {
    { "end", NULL, __CALL, { 106 } },
    { "string", "mark", __CALL, { 107 } },
};
static cmdp_token tokens_FOCUS[13] = {
    { "'left", "direction", __CALL, { 108 } },
    { "'right", "direction", __CALL, { 109 } },
    { "'up", "direction", __CALL, { 110 } },
    { "'down", "direction", __CALL, { 111 } },
    { "'prev", "direction", FOCUS_AUTO, { 0 } },
    { "'next", "direction", FOCUS_AUTO, { 0 } },
    { "'output", NULL, FOCUS_OUTPUT, { 0 } },
    { "'tiling", "window_mode", __CALL, { 112 } },
    { "'floating", "window_mode", __CALL, { 113 } },
    { "'mode_toggle", "window_mode", __CALL, { 114 } },
    { "'parent", "level", __CALL, { 115 } },
    { "'child", "level", __CALL, { 116 } },
    { "end", NULL, __CALL, { 117 } },
};
static cmdp_token tokens_SPLIT[6] = {
    { "'horizontal", "direction", __CALL, { 118 } },
    { "'vertical", "direction", __CALL, { 119 } },
    { "'toggle", "direction", __CALL, { 120 } },
    { "'v", "direction", __CALL, { 121 } },
    { "'h", "direction", __CALL, { 122 } },
    { "'t", "direction", __CALL, { 123 } },
};
static cmdp_token tokens_EXEC[2] = {
    { "'--no-startup-id", "nosn", EXEC, { 0 } },
    { "string", "command", __CALL, { 124 } },
};
static cmdp_token tokens_GAPS[8] = {
    { "'inner", "type", GAPS_WITH_TYPE, { 0 } },
    { "'outer", "type", GAPS_WITH_TYPE, { 0 } },
    { "'horizontal", "type", GAPS_WITH_TYPE, { 0 } },
    { "'vertical", "type", GAPS_WITH_TYPE, { 0 } },
    { "'top", "type", GAPS_WITH_TYPE, { 0 } },
    { "'right", "type", GAPS_WITH_TYPE, { 0 } },
    { "'bottom", "type", GAPS_WITH_TYPE, { 0 } },
    { "'left", "type", GAPS_WITH_TYPE, { 0 } },
};
static cmdp_token tokens_KILL[3] = {
    { "'window", "kill_mode", __CALL, { 125 } },
    { "'client", "kill_mode", __CALL, { 126 } },
    { "end", NULL, __CALL, { 127 } },
};
static cmdp_token tokens_MARK[4] = {
    { "'--add", "mode", MARK, { 0 } },
    { "'--replace", "mode", MARK, { 0 } },
    { "'--toggle", "toggle", MARK, { 0 } },
    { "string", "mark", __CALL, { 128 } },
};
static cmdp_token tokens_MODE[1] = {
    { "string", "mode", __CALL, { 129 } },
};
static cmdp_token tokens_MOVE[14] = {
    { "'window", NULL, MOVE, { 0 } },
    { "'container", NULL, MOVE, { 0 } },
    { "'to", NULL, MOVE, { 0 } },
    { "'--no-auto-back-and-forth", "no_auto_back_and_forth", MOVE, { 0 } },
    { "'workspace", NULL, MOVE_WORKSPACE, { 0 } },
    { "'output", NULL, MOVE_TO_OUTPUT, { 0 } },
    { "'mark", NULL, MOVE_TO_MARK, { 0 } },
    { "'scratchpad", NULL, __CALL, { 130 } },
    { "'left", "direction", MOVE_DIRECTION, { 0 } },
    { "'right", "direction", MOVE_DIRECTION, { 0 } },
    { "'up", "direction", MOVE_DIRECTION, { 0 } },
    { "'down", "direction", MOVE_DIRECTION, { 0 } },
    { "'position", "method", MOVE_TO_POSITION, { 0 } },
    { "'absolute", "method", MOVE_TO_ABSOLUTE_POSITION, { 0 } },
};
static cmdp_token tokens_SWAP[5] = {
    { "'container", NULL, SWAP, { 0 } },
    { "'with", NULL, SWAP, { 0 } },
    { "'id", "mode", SWAP_ARGUMENT, { 0 } },
    { "'con_id", "mode", SWAP_ARGUMENT, { 0 } },
    { "'mark", "mode", SWAP_ARGUMENT, { 0 } },
};
static cmdp_token tokens_BAR[2] = {
    { "'hidden_state", NULL, BAR_HIDDEN_STATE, { 0 } },
    { "'mode", NULL, BAR_MODE, { 0 } },
};
static cmdp_token tokens_NOP[2] = {
    { "string", "comment", __CALL, { 131 } },
    { "end", NULL, __CALL, { 132 } },
};
static cmdp_token_ptr tokens[77] = {
    { tokens_RENAME_WORKSPACE_LIKELY_TO_NEW_NAME, 2 },
    { tokens_MOVE_WORKSPACE_TO_OUTPUT_WORD, 2 },
    { tokens_RENAME_WORKSPACE_TO_NEW_NAME, 1 },
    { tokens_RENAME_WORKSPACE_LIKELY_TO, 2 },
    { tokens_MOVE_TO_ABSOLUTE_POSITION, 1 },
    { tokens_TITLE_WINDOW_ICON_PADDING, 3 },
    { tokens_CRITERION_FROM_STR_START, 3 },
    { tokens_MOVE_WORKSPACE_TO_OUTPUT, 1 },
    { tokens_RESIZE_HEIGHT_GET_NUMBER, 1 },
    { tokens_CRITERION_FROM_STR_END, 1 },
    { tokens_MOVE_DIRECTION_NUMBER, 3 },
    { tokens_MOVE_WORKSPACE_NUMBER, 1 },
    { tokens_BAR_HIDDEN_STATE_ID, 2 },
    { tokens_RENAME_WORKSPACE_TO, 1 },
    { tokens_RESIZE_TILING_FINAL, 2 },
    { tokens_CRITERION_FROM_STR, 2 },
    { tokens_MOVE_TO_POSITION_X, 3 },
    { tokens_MOVE_TO_POSITION_Y, 3 },
    { tokens_FULLSCREEN_COMPAT, 2 },
    { tokens_TITLE_WINDOW_ICON, 14 },
    { tokens_BAR_HIDDEN_STATE, 3 },
    { tokens_MOVE_TO_POSITION, 5 },
    { tokens_RENAME_WORKSPACE, 2 },
    { tokens_RESIZE_DIRECTION, 6 },
    { tokens_RESIZE_TILING_OR, 1 },
    { tokens_WORKSPACE_NUMBER, 1 },
    { tokens_FULLSCREEN_MODE, 2 },
    { tokens_GAPS_WITH_SCOPE, 4 },
    { tokens_CRITERION_FROM, 1 },
    { tokens_GAPS_WITH_MODE, 1 },
    { tokens_GAPS_WITH_TYPE, 2 },
    { tokens_MOVE_DIRECTION, 2 },
    { tokens_MOVE_TO_OUTPUT, 2 },
    { tokens_MOVE_WORKSPACE, 9 },
    { tokens_APPEND_LAYOUT, 1 },
    { tokens_CRITERION_STR, 1 },
    { tokens_LAYOUT_TOGGLE, 2 },
    { tokens_RESIZE_HEIGHT, 3 },
    { tokens_RESIZE_TILING, 3 },
    { tokens_SWAP_ARGUMENT, 1 },
    { tokens_BORDER_WIDTH, 2 },
    { tokens_FOCUS_OUTPUT, 2 },
    { tokens_MOVE_TO_MARK, 1 },
    { tokens_RESIZE_WIDTH, 5 },
    { tokens_TITLE_FORMAT, 1 },
    { tokens_BAR_MODE_ID, 2 },
    { tokens_FOCUS_AUTO, 2 },
    { tokens_FULLSCREEN, 4 },
    { tokens_RESIZE_SET, 3 },
    { tokens_SCRATCHPAD, 1 },
    { tokens_CRITERION, 1 },
    { tokens_RESIZE_PX, 2 },
    { tokens_WORKSPACE, 8 },
    { tokens_BAR_MODE, 4 },
    { tokens_CRITERIA, 17 },
    { tokens_DEBUGLOG, 3 },
    { tokens_FLOATING, 3 },
    { tokens_GAPS_END, 2 },
    { tokens_INITIAL, 32 },
    { tokens_BORDER, 5 },
    { tokens_LAYOUT, 7 },
    { tokens_RENAME, 1 },
    { tokens_RESIZE, 3 },
    { tokens_SHMLOG, 1 },
    { tokens_STICKY, 3 },
    { tokens_UNMARK, 2 },
    { tokens_FOCUS, 13 },
    { tokens_SPLIT, 6 },
    { tokens_EXEC, 2 },
    { tokens_GAPS, 8 },
    { tokens_KILL, 3 },
    { tokens_MARK, 4 },
    { tokens_MODE, 1 },
    { tokens_MOVE, 14 },
    { tokens_SWAP, 5 },
    { tokens_BAR, 2 },
    { tokens_NOP, 2 },
};
