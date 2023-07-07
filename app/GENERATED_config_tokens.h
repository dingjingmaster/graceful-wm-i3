#pragma once
static cmdp_token tokens_FORCE_DISPLAY_URGENCY_HINT_MS[2] = {
    { "'ms", NULL, FORCE_DISPLAY_URGENCY_HINT_MS, { 0 } },
    { "end", NULL, __CALL, { 0 } },
};
static cmdp_token tokens_FLOATING_MAXIMUM_SIZE_HEIGHT[1] = {
    { "number", "height", __CALL, { 1 } },
};
static cmdp_token tokens_FLOATING_MINIMUM_SIZE_HEIGHT[1] = {
    { "number", "height", __CALL, { 2 } },
};
static cmdp_token tokens_BAR_STRIP_WORKSPACE_NUMBERS[1] = {
    { "word", "value", __CALL, { 3 } },
};
static cmdp_token tokens_FLOATING_MAXIMUM_SIZE_WIDTH[1] = {
    { "number", "width", FLOATING_MAXIMUM_SIZE_X, { 0 } },
};
static cmdp_token tokens_FLOATING_MINIMUM_SIZE_WIDTH[1] = {
    { "number", "width", FLOATING_MINIMUM_SIZE_X, { 0 } },
};
static cmdp_token tokens_BAR_BINDING_MODE_INDICATOR[1] = {
    { "word", "value", __CALL, { 4 } },
};
static cmdp_token tokens_BAR_WORKSPACE_MIN_WIDTH_PX[2] = {
    { "'px", NULL, BAR_WORKSPACE_MIN_WIDTH_PX, { 0 } },
    { "end", NULL, __CALL, { 5 } },
};
static cmdp_token tokens_FOCUS_ON_WINDOW_ACTIVATION[1] = {
    { "word", "mode", __CALL, { 6 } },
};
static cmdp_token tokens_FORCE_DISPLAY_URGENCY_HINT[1] = {
    { "number", "duration_ms", FORCE_DISPLAY_URGENCY_HINT_MS, { 0 } },
};
static cmdp_token tokens_BAR_STRIP_WORKSPACE_NAME[1] = {
    { "word", "value", __CALL, { 7 } },
};
static cmdp_token tokens_CRITERION_FROM_STR_START[3] = {
    { "'\"", NULL, CRITERION_FROM_STR, { 0 } },
    { "'auto", "kind", __CALL, { 8 } },
    { "'user", "kind", __CALL, { 9 } },
};
static cmdp_token tokens_DEFAULT_BORDER_PIXELS_PX[2] = {
    { "'px", NULL, DEFAULT_BORDER_PIXELS_PX, { 0 } },
    { "end", NULL, __CALL, { 10 } },
};
static cmdp_token tokens_WORKSPACE_BACK_AND_FORTH[1] = {
    { "word", "value", __CALL, { 11 } },
};
static cmdp_token tokens_ASSIGN_WORKSPACE_NUMBER[1] = {
    { "string", "number", __CALL, { 12 } },
};
static cmdp_token tokens_BAR_WORKSPACE_MIN_WIDTH[1] = {
    { "number", "width", BAR_WORKSPACE_MIN_WIDTH_PX, { 0 } },
};
static cmdp_token tokens_FLOATING_MAXIMUM_SIZE_X[1] = {
    { "'x", NULL, FLOATING_MAXIMUM_SIZE_HEIGHT, { 0 } },
};
static cmdp_token tokens_FLOATING_MINIMUM_SIZE_X[1] = {
    { "'x", NULL, FLOATING_MINIMUM_SIZE_HEIGHT, { 0 } },
};
static cmdp_token tokens_POPUP_DURING_FULLSCREEN[3] = {
    { "'ignore", "value", __CALL, { 13 } },
    { "'leave_fullscreen", "value", __CALL, { 14 } },
    { "'smart", "value", __CALL, { 15 } },
};
static cmdp_token tokens_BAR_COLORS_IGNORE_LINE[1] = {
    { "line", NULL, BAR_COLORS, { 0 } },
};
static cmdp_token tokens_CRITERION_FROM_STR_END[1] = {
    { "'\"", NULL, __CALL, { 16 } },
};
static cmdp_token tokens_BAR_COLORS_BACKGROUND[1] = {
    { "word", "background", BAR_COLORS_TEXT, { 0 } },
};
static cmdp_token tokens_BAR_WORKSPACE_BUTTONS[1] = {
    { "word", "value", __CALL, { 17 } },
};
static cmdp_token tokens_DEFAULT_BORDER_PIXELS[2] = {
    { "end", NULL, __CALL, { 18 } },
    { "number", "width", DEFAULT_BORDER_PIXELS_PX, { 0 } },
};
static cmdp_token tokens_WORKSPACE_OUTPUT_WORD[2] = {
    { "word", "output", __CALL, { 19 } },
    { "end", NULL, INITIAL, { 0 } },
};
static cmdp_token tokens_BAR_SEPARATOR_SYMBOL[1] = {
    { "string", "separator", __CALL, { 20 } },
};
static cmdp_token tokens_FORCE_FOCUS_WRAPPING[1] = {
    { "word", "value", __CALL, { 21 } },
};
static cmdp_token tokens_BAR_BINDSYM_COMMAND[2] = {
    { "'--release", "release", BAR_BINDSYM_COMMAND, { 0 } },
    { "string", "command", __CALL, { 22 } },
};
static cmdp_token tokens_BAR_TRAY_PADDING_PX[2] = {
    { "'px", NULL, BAR_TRAY_PADDING_PX, { 0 } },
    { "end", NULL, __CALL, { 23 } },
};
static cmdp_token tokens_DEFAULT_ORIENTATION[3] = {
    { "'horizontal", "orientation", __CALL, { 24 } },
    { "'vertical", "orientation", __CALL, { 25 } },
    { "'auto", "orientation", __CALL, { 26 } },
};
static cmdp_token tokens_FOCUS_FOLLOWS_MOUSE[1] = {
    { "word", "value", __CALL, { 27 } },
};
static cmdp_token tokens_BAR_PADDING_BOTTOM[3] = {
    { "'px", NULL, BAR_PADDING_BOTTOM, { 0 } },
    { "number", "left", BAR_PADDING_LEFT, { 0 } },
    { "end", NULL, __CALL, { 28 } },
};
static cmdp_token tokens_BAR_STATUS_COMMAND[1] = {
    { "string", "command", __CALL, { 29 } },
};
static cmdp_token tokens_BAR_WHEEL_DOWN_CMD[1] = {
    { "string", "command", __CALL, { 30 } },
};
static cmdp_token tokens_COLOR_CHILD_BORDER[2] = {
    { "word", "child_border", __CALL, { 31 } },
    { "end", NULL, __CALL, { 32 } },
};
static cmdp_token tokens_CRITERION_FROM_STR[2] = {
    { "'auto", "kind", CRITERION_FROM_STR_END, { 0 } },
    { "'user", "kind", CRITERION_FROM_STR_END, { 0 } },
};
static cmdp_token tokens_FOR_WINDOW_COMMAND[1] = {
    { "string", "command", __CALL, { 33 } },
};
static cmdp_token tokens_BAR_COLORS_BORDER[1] = {
    { "word", "border", BAR_COLORS_BACKGROUND, { 0 } },
};
static cmdp_token tokens_BAR_COLORS_SINGLE[1] = {
    { "word", "color", __CALL, { 34 } },
};
static cmdp_token tokens_BAR_PADDING_RIGHT[3] = {
    { "'px", NULL, BAR_PADDING_RIGHT, { 0 } },
    { "number", "bottom", BAR_PADDING_BOTTOM, { 0 } },
    { "end", NULL, __CALL, { 35 } },
};
static cmdp_token tokens_FLOATING_MODIFIER[10] = {
    { "'Mod1", "modifiers", FLOATING_MODIFIER, { 0 } },
    { "'Mod2", "modifiers", FLOATING_MODIFIER, { 0 } },
    { "'Mod3", "modifiers", FLOATING_MODIFIER, { 0 } },
    { "'Mod4", "modifiers", FLOATING_MODIFIER, { 0 } },
    { "'Mod5", "modifiers", FLOATING_MODIFIER, { 0 } },
    { "'Shift", "modifiers", FLOATING_MODIFIER, { 0 } },
    { "'Control", "modifiers", FLOATING_MODIFIER, { 0 } },
    { "'Ctrl", "modifiers", FLOATING_MODIFIER, { 0 } },
    { "'+", NULL, FLOATING_MODIFIER, { 0 } },
    { "end", NULL, __CALL, { 36 } },
};
static cmdp_token tokens_HIDE_EDGE_BORDERS[12] = {
    { "'none", "hide_borders", __CALL, { 37 } },
    { "'vertical", "hide_borders", __CALL, { 38 } },
    { "'horizontal", "hide_borders", __CALL, { 39 } },
    { "'both", "hide_borders", __CALL, { 40 } },
    { "'smart_no_gaps", "hide_borders", __CALL, { 41 } },
    { "'smart", "hide_borders", __CALL, { 42 } },
    { "'1", "hide_borders", __CALL, { 43 } },
    { "'yes", "hide_borders", __CALL, { 44 } },
    { "'true", "hide_borders", __CALL, { 45 } },
    { "'on", "hide_borders", __CALL, { 46 } },
    { "'enable", "hide_borders", __CALL, { 47 } },
    { "'active", "hide_borders", __CALL, { 48 } },
};
static cmdp_token tokens_WORKSPACE_COMMAND[2] = {
    { "'output", NULL, WORKSPACE_OUTPUT_WORD, { 0 } },
    { "'gaps", NULL, GAPS, { 0 } },
};
static cmdp_token tokens_ASSIGN_WORKSPACE[5] = {
    { "'→", NULL, ASSIGN_WORKSPACE, { 0 } },
    { "'output", NULL, ASSIGN_OUTPUT, { 0 } },
    { "'workspace", NULL, ASSIGN_WORKSPACE, { 0 } },
    { "'number", NULL, ASSIGN_WORKSPACE_NUMBER, { 0 } },
    { "string", "workspace", __CALL, { 49 } },
};
static cmdp_token tokens_BAR_COLORS_BRACE[2] = {
    { "end", NULL, BAR_COLORS_BRACE, { 0 } },
    { "'{", NULL, BAR_COLORS, { 0 } },
};
static cmdp_token tokens_BAR_HIDDEN_STATE[2] = {
    { "'hide", "hidden_state", __CALL, { 50 } },
    { "'show", "hidden_state", __CALL, { 51 } },
};
static cmdp_token tokens_BAR_PADDING_LEFT[2] = {
    { "'px", NULL, BAR_PADDING_LEFT, { 0 } },
    { "end", NULL, __CALL, { 52 } },
};
static cmdp_token tokens_BAR_TRAY_PADDING[1] = {
    { "number", "padding_px", BAR_TRAY_PADDING_PX, { 0 } },
};
static cmdp_token tokens_BAR_WHEEL_UP_CMD[1] = {
    { "string", "command", __CALL, { 53 } },
};
static cmdp_token tokens_COLOR_BACKGROUND[1] = {
    { "word", "background", COLOR_TEXT, { 0 } },
};
static cmdp_token tokens_IPC_KILL_TIMEOUT[1] = {
    { "number", "timeout", __CALL, { 54 } },
};
static cmdp_token tokens_MODE_BINDCOMMAND[5] = {
    { "'--release", "release", MODE_BINDCOMMAND, { 0 } },
    { "'--border", "border", MODE_BINDCOMMAND, { 0 } },
    { "'--whole-window", "whole_window", MODE_BINDCOMMAND, { 0 } },
    { "'--exclude-titlebar", "exclude_titlebar", MODE_BINDCOMMAND, { 0 } },
    { "string", "command", __CALL, { 55 } },
};
static cmdp_token tokens_MODE_IGNORE_LINE[1] = {
    { "line", NULL, MODE, { 0 } },
};
static cmdp_token tokens_TILING_DRAG_MODE[3] = {
    { "'modifier", "value", TILING_DRAG_MODE, { 0 } },
    { "'titlebar", "value", TILING_DRAG_MODE, { 0 } },
    { "end", NULL, __CALL, { 56 } },
};
static cmdp_token tokens_WORKSPACE_LAYOUT[4] = {
    { "'default", "layout", __CALL, { 57 } },
    { "'stacking", "layout", __CALL, { 58 } },
    { "'stacked", "layout", __CALL, { 59 } },
    { "'tabbed", "layout", __CALL, { 60 } },
};
static cmdp_token tokens_BAR_BAR_COMMAND[1] = {
    { "string", "command", __CALL, { 61 } },
};
static cmdp_token tokens_BAR_COLORS_TEXT[2] = {
    { "end", NULL, __CALL, { 62 } },
    { "word", "text", __CALL, { 63 } },
};
static cmdp_token tokens_BAR_IGNORE_LINE[1] = {
    { "line", NULL, BAR, { 0 } },
};
static cmdp_token tokens_BAR_PADDING_TOP[3] = {
    { "'px", NULL, BAR_PADDING_TOP, { 0 } },
    { "number", "right_or_right_and_left", BAR_PADDING_RIGHT, { 0 } },
    { "end", NULL, __CALL, { 64 } },
};
static cmdp_token tokens_BAR_SOCKET_PATH[1] = {
    { "string", "path", __CALL, { 65 } },
};
static cmdp_token tokens_BAR_TRAY_OUTPUT[1] = {
    { "word", "output", __CALL, { 66 } },
};
static cmdp_token tokens_COLOR_INDICATOR[2] = {
    { "word", "indicator", COLOR_CHILD_BORDER, { 0 } },
    { "end", NULL, __CALL, { 67 } },
};
static cmdp_token tokens_DISABLE_RANDR15[1] = {
    { "word", "value", __CALL, { 68 } },
};
static cmdp_token tokens_GAPS_WITH_SCOPE[1] = {
    { "number", "value", GAPS_END, { 0 } },
};
static cmdp_token tokens_CRITERION_FROM[1] = {
    { "'=", NULL, CRITERION_FROM_STR_START, { 0 } },
};
static cmdp_token tokens_DEFAULT_BORDER[4] = {
    { "'normal", "border", DEFAULT_BORDER_PIXELS, { 0 } },
    { "'pixel", "border", DEFAULT_BORDER_PIXELS, { 0 } },
    { "'1pixel", "border", __CALL, { 69 } },
    { "'none", "border", __CALL, { 70 } },
};
static cmdp_token tokens_FOCUS_WRAPPING[14] = {
    { "'1", "value", __CALL, { 71 } },
    { "'yes", "value", __CALL, { 72 } },
    { "'true", "value", __CALL, { 73 } },
    { "'on", "value", __CALL, { 74 } },
    { "'enable", "value", __CALL, { 75 } },
    { "'active", "value", __CALL, { 76 } },
    { "'0", "value", __CALL, { 77 } },
    { "'no", "value", __CALL, { 78 } },
    { "'false", "value", __CALL, { 79 } },
    { "'off", "value", __CALL, { 80 } },
    { "'disable", "value", __CALL, { 81 } },
    { "'inactive", "value", __CALL, { 82 } },
    { "'force", "value", __CALL, { 83 } },
    { "'workspace", "value", __CALL, { 84 } },
};
static cmdp_token tokens_FORCE_XINERAMA[1] = {
    { "word", "value", __CALL, { 85 } },
};
static cmdp_token tokens_ASSIGN_OUTPUT[1] = {
    { "string", "output", __CALL, { 86 } },
};
static cmdp_token tokens_CRITERION_STR[1] = {
    { "word", "cvalue", __CALL, { 87 } },
};
static cmdp_token tokens_MOUSE_WARPING[2] = {
    { "'none", "value", __CALL, { 88 } },
    { "'output", "value", __CALL, { 89 } },
};
static cmdp_token tokens_RESTART_STATE[1] = {
    { "string", "path", __CALL, { 90 } },
};
static cmdp_token tokens_SMART_BORDERS[7] = {
    { "'1", "enabled", __CALL, { 91 } },
    { "'yes", "enabled", __CALL, { 92 } },
    { "'true", "enabled", __CALL, { 93 } },
    { "'on", "enabled", __CALL, { 94 } },
    { "'enable", "enabled", __CALL, { 95 } },
    { "'active", "enabled", __CALL, { 96 } },
    { "'no_gaps", "enabled", __CALL, { 97 } },
};
static cmdp_token tokens_BAR_MODIFIER[12] = {
    { "'off", NULL, __CALL, { 98 } },
    { "'none", NULL, __CALL, { 99 } },
    { "'Mod1", "modifiers", BAR_MODIFIER, { 0 } },
    { "'Mod2", "modifiers", BAR_MODIFIER, { 0 } },
    { "'Mod3", "modifiers", BAR_MODIFIER, { 0 } },
    { "'Mod4", "modifiers", BAR_MODIFIER, { 0 } },
    { "'Mod5", "modifiers", BAR_MODIFIER, { 0 } },
    { "'Shift", "modifiers", BAR_MODIFIER, { 0 } },
    { "'Control", "modifiers", BAR_MODIFIER, { 0 } },
    { "'Ctrl", "modifiers", BAR_MODIFIER, { 0 } },
    { "'+", NULL, BAR_MODIFIER, { 0 } },
    { "end", NULL, __CALL, { 100 } },
};
static cmdp_token tokens_BAR_POSITION[2] = {
    { "'top", "position", __CALL, { 101 } },
    { "'bottom", "position", __CALL, { 102 } },
};
static cmdp_token tokens_COLOR_BORDER[1] = {
    { "word", "border", COLOR_BACKGROUND, { 0 } },
};
static cmdp_token tokens_COLOR_SINGLE[1] = {
    { "word", "color", __CALL, { 103 } },
};
static cmdp_token tokens_FAKE_OUTPUTS[1] = {
    { "string", "outputs", __CALL, { 104 } },
};
static cmdp_token tokens_MODE_BINDING[20] = {
    { "'--release", "release", MODE_BINDING, { 0 } },
    { "'--border", "border", MODE_BINDING, { 0 } },
    { "'--whole-window", "whole_window", MODE_BINDING, { 0 } },
    { "'--exclude-titlebar", "exclude_titlebar", MODE_BINDING, { 0 } },
    { "'Mod1", "modifiers", MODE_BINDING, { 0 } },
    { "'Mod2", "modifiers", MODE_BINDING, { 0 } },
    { "'Mod3", "modifiers", MODE_BINDING, { 0 } },
    { "'Mod4", "modifiers", MODE_BINDING, { 0 } },
    { "'Mod5", "modifiers", MODE_BINDING, { 0 } },
    { "'Shift", "modifiers", MODE_BINDING, { 0 } },
    { "'Control", "modifiers", MODE_BINDING, { 0 } },
    { "'Ctrl", "modifiers", MODE_BINDING, { 0 } },
    { "'Mode_switch", "modifiers", MODE_BINDING, { 0 } },
    { "'Group1", "modifiers", MODE_BINDING, { 0 } },
    { "'Group2", "modifiers", MODE_BINDING, { 0 } },
    { "'Group3", "modifiers", MODE_BINDING, { 0 } },
    { "'Group4", "modifiers", MODE_BINDING, { 0 } },
    { "'$mod", "modifiers", MODE_BINDING, { 0 } },
    { "'+", NULL, MODE_BINDING, { 0 } },
    { "word", "key", MODE_BINDCOMMAND, { 0 } },
};
static cmdp_token tokens_NO_FOCUS_END[1] = {
    { "end", NULL, __CALL, { 105 } },
};
static cmdp_token tokens_BAR_BINDSYM[2] = {
    { "'--release", "release", BAR_BINDSYM, { 0 } },
    { "word", "button", BAR_BINDSYM_COMMAND, { 0 } },
};
static cmdp_token tokens_BAR_PADDING[1] = {
    { "number", "top_or_all", BAR_PADDING_TOP, { 0 } },
};
static cmdp_token tokens_BAR_VERBOSE[1] = {
    { "word", "value", __CALL, { 106 } },
};
static cmdp_token tokens_BINDCOMMAND[5] = {
    { "'--release", "release", BINDCOMMAND, { 0 } },
    { "'--border", "border", BINDCOMMAND, { 0 } },
    { "'--whole-window", "whole_window", BINDCOMMAND, { 0 } },
    { "'--exclude-titlebar", "exclude_titlebar", BINDCOMMAND, { 0 } },
    { "string", "command", __CALL, { 107 } },
};
static cmdp_token tokens_IGNORE_LINE[1] = {
    { "line", NULL, INITIAL, { 0 } },
};
static cmdp_token tokens_TILING_DRAG[8] = {
    { "'0", "off", __CALL, { 108 } },
    { "'no", "off", __CALL, { 109 } },
    { "'false", "off", __CALL, { 110 } },
    { "'off", "off", __CALL, { 111 } },
    { "'disable", "off", __CALL, { 112 } },
    { "'inactive", "off", __CALL, { 113 } },
    { "'modifier", "value", TILING_DRAG_MODE, { 0 } },
    { "'titlebar", "value", TILING_DRAG_MODE, { 0 } },
};
static cmdp_token tokens_TITLE_ALIGN[3] = {
    { "'left", "alignment", __CALL, { 114 } },
    { "'center", "alignment", __CALL, { 115 } },
    { "'right", "alignment", __CALL, { 116 } },
};
static cmdp_token tokens_BAR_COLORS[15] = {
    { "end", NULL, BAR_COLORS, { 0 } },
    { "'#", NULL, BAR_COLORS_IGNORE_LINE, { 0 } },
    { "'set", NULL, BAR_COLORS_IGNORE_LINE, { 0 } },
    { "'background", "colorclass", BAR_COLORS_SINGLE, { 0 } },
    { "'statusline", "colorclass", BAR_COLORS_SINGLE, { 0 } },
    { "'separator", "colorclass", BAR_COLORS_SINGLE, { 0 } },
    { "'focused_background", "colorclass", BAR_COLORS_SINGLE, { 0 } },
    { "'focused_statusline", "colorclass", BAR_COLORS_SINGLE, { 0 } },
    { "'focused_separator", "colorclass", BAR_COLORS_SINGLE, { 0 } },
    { "'focused_workspace", "colorclass", BAR_COLORS_BORDER, { 0 } },
    { "'active_workspace", "colorclass", BAR_COLORS_BORDER, { 0 } },
    { "'inactive_workspace", "colorclass", BAR_COLORS_BORDER, { 0 } },
    { "'urgent_workspace", "colorclass", BAR_COLORS_BORDER, { 0 } },
    { "'binding_mode", "colorclass", BAR_COLORS_BORDER, { 0 } },
    { "'}", NULL, BAR, { 0 } },
};
static cmdp_token tokens_BAR_HEIGHT[1] = {
    { "number", "value", __CALL, { 117 } },
};
static cmdp_token tokens_BAR_OUTPUT[1] = {
    { "word", "output", __CALL, { 118 } },
};
static cmdp_token tokens_COLOR_TEXT[1] = {
    { "word", "text", COLOR_INDICATOR, { 0 } },
};
static cmdp_token tokens_FOR_WINDOW[1] = {
    { "'[", NULL, __CALL, { 119 } },
};
static cmdp_token tokens_IPC_SOCKET[1] = {
    { "string", "path", __CALL, { 120 } },
};
static cmdp_token tokens_SHOW_MARKS[1] = {
    { "word", "value", __CALL, { 121 } },
};
static cmdp_token tokens_SMART_GAPS[13] = {
    { "'1", "enabled", __CALL, { 122 } },
    { "'yes", "enabled", __CALL, { 123 } },
    { "'true", "enabled", __CALL, { 124 } },
    { "'on", "enabled", __CALL, { 125 } },
    { "'enable", "enabled", __CALL, { 126 } },
    { "'active", "enabled", __CALL, { 127 } },
    { "'0", "enabled", __CALL, { 128 } },
    { "'no", "enabled", __CALL, { 129 } },
    { "'false", "enabled", __CALL, { 130 } },
    { "'off", "enabled", __CALL, { 131 } },
    { "'disable", "enabled", __CALL, { 132 } },
    { "'inactive", "enabled", __CALL, { 133 } },
    { "'inverse_outer", "enabled", __CALL, { 134 } },
};
static cmdp_token tokens_CRITERION[1] = {
    { "'=", NULL, CRITERION_STR, { 0 } },
};
static cmdp_token tokens_MODEBRACE[2] = {
    { "end", NULL, MODEBRACE, { 0 } },
    { "'{", NULL, MODE, { 0 } },
};
static cmdp_token tokens_WORKSPACE[1] = {
    { "word", "workspace", WORKSPACE_COMMAND, { 0 } },
};
static cmdp_token tokens_BARBRACE[2] = {
    { "end", NULL, BARBRACE, { 0 } },
    { "'{", NULL, __CALL, { 135 } },
};
static cmdp_token tokens_BAR_FONT[1] = {
    { "string", "font", __CALL, { 136 } },
};
static cmdp_token tokens_BAR_MODE[3] = {
    { "'dock", "mode", __CALL, { 137 } },
    { "'hide", "mode", __CALL, { 138 } },
    { "'invisible", "mode", __CALL, { 139 } },
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
    { "'tiling", "ctype", __CALL, { 140 } },
    { "'floating", "ctype", __CALL, { 141 } },
    { "'all", "ctype", __CALL, { 142 } },
    { "']", NULL, __CALL, { 143 } },
};
static cmdp_token tokens_GAPS_END[2] = {
    { "'px", NULL, GAPS_END, { 0 } },
    { "end", NULL, __CALL, { 144 } },
};
static cmdp_token tokens_MODENAME[2] = {
    { "'--pango_markup", "pango_markup", MODENAME, { 0 } },
    { "word", "modename", __CALL, { 145 } },
};
static cmdp_token tokens_NO_FOCUS[1] = {
    { "'[", NULL, __CALL, { 146 } },
};
static cmdp_token tokens_BINDING[20] = {
    { "'--release", "release", BINDING, { 0 } },
    { "'--border", "border", BINDING, { 0 } },
    { "'--whole-window", "whole_window", BINDING, { 0 } },
    { "'--exclude-titlebar", "exclude_titlebar", BINDING, { 0 } },
    { "'Mod1", "modifiers", BINDING, { 0 } },
    { "'Mod2", "modifiers", BINDING, { 0 } },
    { "'Mod3", "modifiers", BINDING, { 0 } },
    { "'Mod4", "modifiers", BINDING, { 0 } },
    { "'Mod5", "modifiers", BINDING, { 0 } },
    { "'Shift", "modifiers", BINDING, { 0 } },
    { "'Control", "modifiers", BINDING, { 0 } },
    { "'Ctrl", "modifiers", BINDING, { 0 } },
    { "'Mode_switch", "modifiers", BINDING, { 0 } },
    { "'Group1", "modifiers", BINDING, { 0 } },
    { "'Group2", "modifiers", BINDING, { 0 } },
    { "'Group3", "modifiers", BINDING, { 0 } },
    { "'Group4", "modifiers", BINDING, { 0 } },
    { "'$mod", "modifiers", BINDING, { 0 } },
    { "'+", NULL, BINDING, { 0 } },
    { "word", "key", BINDCOMMAND, { 0 } },
};
static cmdp_token tokens_INCLUDE[1] = {
    { "string", "pattern", __CALL, { 147 } },
};
static cmdp_token tokens_INITIAL[60] = {
    { "end", NULL, INITIAL, { 0 } },
    { "error", NULL, INITIAL, { 0 } },
    { "'#", NULL, IGNORE_LINE, { 0 } },
    { "'set ", NULL, IGNORE_LINE, { 0 } },
    { "'set	", NULL, IGNORE_LINE, { 0 } },
    { "'set_from_resource", NULL, IGNORE_LINE, { 0 } },
    { "'include", NULL, INCLUDE, { 0 } },
    { "'bindsym", "bindtype", BINDING, { 0 } },
    { "'bindcode", "bindtype", BINDING, { 0 } },
    { "'bind", "bindtype", BINDING, { 0 } },
    { "'bar", NULL, BARBRACE, { 0 } },
    { "'font", NULL, FONT, { 0 } },
    { "'mode", NULL, MODENAME, { 0 } },
    { "'gaps", NULL, GAPS, { 0 } },
    { "'smart_borders", NULL, SMART_BORDERS, { 0 } },
    { "'smart_gaps", NULL, SMART_GAPS, { 0 } },
    { "'floating_minimum_size", NULL, FLOATING_MINIMUM_SIZE_WIDTH, { 0 } },
    { "'floating_maximum_size", NULL, FLOATING_MAXIMUM_SIZE_WIDTH, { 0 } },
    { "'floating_modifier", NULL, FLOATING_MODIFIER, { 0 } },
    { "'default_orientation", NULL, DEFAULT_ORIENTATION, { 0 } },
    { "'workspace_layout", NULL, WORKSPACE_LAYOUT, { 0 } },
    { "'default_border", "windowtype", DEFAULT_BORDER, { 0 } },
    { "'new_window", "windowtype", DEFAULT_BORDER, { 0 } },
    { "'default_floating_border", "windowtype", DEFAULT_BORDER, { 0 } },
    { "'new_float", "windowtype", DEFAULT_BORDER, { 0 } },
    { "'hide_edge_borders", NULL, HIDE_EDGE_BORDERS, { 0 } },
    { "'for_window", NULL, FOR_WINDOW, { 0 } },
    { "'assign", NULL, ASSIGN, { 0 } },
    { "'no_focus", NULL, NO_FOCUS, { 0 } },
    { "'focus_follows_mouse", NULL, FOCUS_FOLLOWS_MOUSE, { 0 } },
    { "'mouse_warping", NULL, MOUSE_WARPING, { 0 } },
    { "'focus_wrapping", NULL, FOCUS_WRAPPING, { 0 } },
    { "'force_focus_wrapping", NULL, FORCE_FOCUS_WRAPPING, { 0 } },
    { "'force_xinerama", NULL, FORCE_XINERAMA, { 0 } },
    { "'force-xinerama", NULL, FORCE_XINERAMA, { 0 } },
    { "'disable_randr15", NULL, DISABLE_RANDR15, { 0 } },
    { "'disable-randr15", NULL, DISABLE_RANDR15, { 0 } },
    { "'workspace_auto_back_and_forth", NULL, WORKSPACE_BACK_AND_FORTH, { 0 } },
    { "'fake_outputs", NULL, FAKE_OUTPUTS, { 0 } },
    { "'fake-outputs", NULL, FAKE_OUTPUTS, { 0 } },
    { "'force_display_urgency_hint", NULL, FORCE_DISPLAY_URGENCY_HINT, { 0 } },
    { "'focus_on_window_activation", NULL, FOCUS_ON_WINDOW_ACTIVATION, { 0 } },
    { "'title_align", NULL, TITLE_ALIGN, { 0 } },
    { "'show_marks", NULL, SHOW_MARKS, { 0 } },
    { "'workspace", NULL, WORKSPACE, { 0 } },
    { "'ipc_socket", NULL, IPC_SOCKET, { 0 } },
    { "'ipc-socket", NULL, IPC_SOCKET, { 0 } },
    { "'ipc_kill_timeout", NULL, IPC_KILL_TIMEOUT, { 0 } },
    { "'restart_state", NULL, RESTART_STATE, { 0 } },
    { "'popup_during_fullscreen", NULL, POPUP_DURING_FULLSCREEN, { 0 } },
    { "'tiling_drag", NULL, TILING_DRAG, { 0 } },
    { "'exec_always", "exectype", EXEC, { 0 } },
    { "'exec", "exectype", EXEC, { 0 } },
    { "'client.background", "colorclass", COLOR_SINGLE, { 0 } },
    { "'client.focused_inactive", "colorclass", COLOR_BORDER, { 0 } },
    { "'client.focused_tab_title", "colorclass", COLOR_BORDER, { 0 } },
    { "'client.focused", "colorclass", COLOR_BORDER, { 0 } },
    { "'client.unfocused", "colorclass", COLOR_BORDER, { 0 } },
    { "'client.urgent", "colorclass", COLOR_BORDER, { 0 } },
    { "'client.placeholder", "colorclass", COLOR_BORDER, { 0 } },
};
static cmdp_token tokens_ASSIGN[1] = {
    { "'[", NULL, __CALL, { 148 } },
};
static cmdp_token tokens_BAR_ID[1] = {
    { "word", "bar_id", __CALL, { 149 } },
};
static cmdp_token tokens_EXEC[2] = {
    { "'--no-startup-id", "no_startup_id", EXEC, { 0 } },
    { "string", "command", __CALL, { 150 } },
};
static cmdp_token tokens_FONT[1] = {
    { "string", "font", __CALL, { 151 } },
};
static cmdp_token tokens_GAPS[8] = {
    { "'inner", "scope", GAPS_WITH_SCOPE, { 0 } },
    { "'outer", "scope", GAPS_WITH_SCOPE, { 0 } },
    { "'horizontal", "scope", GAPS_WITH_SCOPE, { 0 } },
    { "'vertical", "scope", GAPS_WITH_SCOPE, { 0 } },
    { "'top", "scope", GAPS_WITH_SCOPE, { 0 } },
    { "'right", "scope", GAPS_WITH_SCOPE, { 0 } },
    { "'bottom", "scope", GAPS_WITH_SCOPE, { 0 } },
    { "'left", "scope", GAPS_WITH_SCOPE, { 0 } },
};
static cmdp_token tokens_MODE[8] = {
    { "end", NULL, MODE, { 0 } },
    { "error", NULL, MODE, { 0 } },
    { "'#", NULL, MODE_IGNORE_LINE, { 0 } },
    { "'set", NULL, MODE_IGNORE_LINE, { 0 } },
    { "'bindsym", "bindtype", MODE_BINDING, { 0 } },
    { "'bindcode", "bindtype", MODE_BINDING, { 0 } },
    { "'bind", "bindtype", MODE_BINDING, { 0 } },
    { "'}", NULL, INITIAL, { 0 } },
};
static cmdp_token tokens_BAR[30] = {
    { "end", NULL, BAR, { 0 } },
    { "error", NULL, BAR, { 0 } },
    { "'#", NULL, BAR_IGNORE_LINE, { 0 } },
    { "'set", NULL, BAR_IGNORE_LINE, { 0 } },
    { "'i3bar_command", NULL, BAR_BAR_COMMAND, { 0 } },
    { "'status_command", NULL, BAR_STATUS_COMMAND, { 0 } },
    { "'socket_path", NULL, BAR_SOCKET_PATH, { 0 } },
    { "'mode", NULL, BAR_MODE, { 0 } },
    { "'hidden_state", NULL, BAR_HIDDEN_STATE, { 0 } },
    { "'id", NULL, BAR_ID, { 0 } },
    { "'modifier", NULL, BAR_MODIFIER, { 0 } },
    { "'wheel_up_cmd", NULL, BAR_WHEEL_UP_CMD, { 0 } },
    { "'wheel_down_cmd", NULL, BAR_WHEEL_DOWN_CMD, { 0 } },
    { "'bindsym", NULL, BAR_BINDSYM, { 0 } },
    { "'position", NULL, BAR_POSITION, { 0 } },
    { "'output", NULL, BAR_OUTPUT, { 0 } },
    { "'tray_output", NULL, BAR_TRAY_OUTPUT, { 0 } },
    { "'tray_padding", NULL, BAR_TRAY_PADDING, { 0 } },
    { "'font", NULL, BAR_FONT, { 0 } },
    { "'separator_symbol", NULL, BAR_SEPARATOR_SYMBOL, { 0 } },
    { "'binding_mode_indicator", NULL, BAR_BINDING_MODE_INDICATOR, { 0 } },
    { "'workspace_buttons", NULL, BAR_WORKSPACE_BUTTONS, { 0 } },
    { "'workspace_min_width", NULL, BAR_WORKSPACE_MIN_WIDTH, { 0 } },
    { "'strip_workspace_numbers", NULL, BAR_STRIP_WORKSPACE_NUMBERS, { 0 } },
    { "'strip_workspace_name", NULL, BAR_STRIP_WORKSPACE_NAME, { 0 } },
    { "'verbose", NULL, BAR_VERBOSE, { 0 } },
    { "'height", NULL, BAR_HEIGHT, { 0 } },
    { "'padding", NULL, BAR_PADDING, { 0 } },
    { "'colors", NULL, BAR_COLORS_BRACE, { 0 } },
    { "'}", NULL, __CALL, { 152 } },
};
static cmdp_token_ptr tokens[115] = {
    { tokens_FORCE_DISPLAY_URGENCY_HINT_MS, 2 },
    { tokens_FLOATING_MAXIMUM_SIZE_HEIGHT, 1 },
    { tokens_FLOATING_MINIMUM_SIZE_HEIGHT, 1 },
    { tokens_BAR_STRIP_WORKSPACE_NUMBERS, 1 },
    { tokens_FLOATING_MAXIMUM_SIZE_WIDTH, 1 },
    { tokens_FLOATING_MINIMUM_SIZE_WIDTH, 1 },
    { tokens_BAR_BINDING_MODE_INDICATOR, 1 },
    { tokens_BAR_WORKSPACE_MIN_WIDTH_PX, 2 },
    { tokens_FOCUS_ON_WINDOW_ACTIVATION, 1 },
    { tokens_FORCE_DISPLAY_URGENCY_HINT, 1 },
    { tokens_BAR_STRIP_WORKSPACE_NAME, 1 },
    { tokens_CRITERION_FROM_STR_START, 3 },
    { tokens_DEFAULT_BORDER_PIXELS_PX, 2 },
    { tokens_WORKSPACE_BACK_AND_FORTH, 1 },
    { tokens_ASSIGN_WORKSPACE_NUMBER, 1 },
    { tokens_BAR_WORKSPACE_MIN_WIDTH, 1 },
    { tokens_FLOATING_MAXIMUM_SIZE_X, 1 },
    { tokens_FLOATING_MINIMUM_SIZE_X, 1 },
    { tokens_POPUP_DURING_FULLSCREEN, 3 },
    { tokens_BAR_COLORS_IGNORE_LINE, 1 },
    { tokens_CRITERION_FROM_STR_END, 1 },
    { tokens_BAR_COLORS_BACKGROUND, 1 },
    { tokens_BAR_WORKSPACE_BUTTONS, 1 },
    { tokens_DEFAULT_BORDER_PIXELS, 2 },
    { tokens_WORKSPACE_OUTPUT_WORD, 2 },
    { tokens_BAR_SEPARATOR_SYMBOL, 1 },
    { tokens_FORCE_FOCUS_WRAPPING, 1 },
    { tokens_BAR_BINDSYM_COMMAND, 2 },
    { tokens_BAR_TRAY_PADDING_PX, 2 },
    { tokens_DEFAULT_ORIENTATION, 3 },
    { tokens_FOCUS_FOLLOWS_MOUSE, 1 },
    { tokens_BAR_PADDING_BOTTOM, 3 },
    { tokens_BAR_STATUS_COMMAND, 1 },
    { tokens_BAR_WHEEL_DOWN_CMD, 1 },
    { tokens_COLOR_CHILD_BORDER, 2 },
    { tokens_CRITERION_FROM_STR, 2 },
    { tokens_FOR_WINDOW_COMMAND, 1 },
    { tokens_BAR_COLORS_BORDER, 1 },
    { tokens_BAR_COLORS_SINGLE, 1 },
    { tokens_BAR_PADDING_RIGHT, 3 },
    { tokens_FLOATING_MODIFIER, 10 },
    { tokens_HIDE_EDGE_BORDERS, 12 },
    { tokens_WORKSPACE_COMMAND, 2 },
    { tokens_ASSIGN_WORKSPACE, 5 },
    { tokens_BAR_COLORS_BRACE, 2 },
    { tokens_BAR_HIDDEN_STATE, 2 },
    { tokens_BAR_PADDING_LEFT, 2 },
    { tokens_BAR_TRAY_PADDING, 1 },
    { tokens_BAR_WHEEL_UP_CMD, 1 },
    { tokens_COLOR_BACKGROUND, 1 },
    { tokens_IPC_KILL_TIMEOUT, 1 },
    { tokens_MODE_BINDCOMMAND, 5 },
    { tokens_MODE_IGNORE_LINE, 1 },
    { tokens_TILING_DRAG_MODE, 3 },
    { tokens_WORKSPACE_LAYOUT, 4 },
    { tokens_BAR_BAR_COMMAND, 1 },
    { tokens_BAR_COLORS_TEXT, 2 },
    { tokens_BAR_IGNORE_LINE, 1 },
    { tokens_BAR_PADDING_TOP, 3 },
    { tokens_BAR_SOCKET_PATH, 1 },
    { tokens_BAR_TRAY_OUTPUT, 1 },
    { tokens_COLOR_INDICATOR, 2 },
    { tokens_DISABLE_RANDR15, 1 },
    { tokens_GAPS_WITH_SCOPE, 1 },
    { tokens_CRITERION_FROM, 1 },
    { tokens_DEFAULT_BORDER, 4 },
    { tokens_FOCUS_WRAPPING, 14 },
    { tokens_FORCE_XINERAMA, 1 },
    { tokens_ASSIGN_OUTPUT, 1 },
    { tokens_CRITERION_STR, 1 },
    { tokens_MOUSE_WARPING, 2 },
    { tokens_RESTART_STATE, 1 },
    { tokens_SMART_BORDERS, 7 },
    { tokens_BAR_MODIFIER, 12 },
    { tokens_BAR_POSITION, 2 },
    { tokens_COLOR_BORDER, 1 },
    { tokens_COLOR_SINGLE, 1 },
    { tokens_FAKE_OUTPUTS, 1 },
    { tokens_MODE_BINDING, 20 },
    { tokens_NO_FOCUS_END, 1 },
    { tokens_BAR_BINDSYM, 2 },
    { tokens_BAR_PADDING, 1 },
    { tokens_BAR_VERBOSE, 1 },
    { tokens_BINDCOMMAND, 5 },
    { tokens_IGNORE_LINE, 1 },
    { tokens_TILING_DRAG, 8 },
    { tokens_TITLE_ALIGN, 3 },
    { tokens_BAR_COLORS, 15 },
    { tokens_BAR_HEIGHT, 1 },
    { tokens_BAR_OUTPUT, 1 },
    { tokens_COLOR_TEXT, 1 },
    { tokens_FOR_WINDOW, 1 },
    { tokens_IPC_SOCKET, 1 },
    { tokens_SHOW_MARKS, 1 },
    { tokens_SMART_GAPS, 13 },
    { tokens_CRITERION, 1 },
    { tokens_MODEBRACE, 2 },
    { tokens_WORKSPACE, 1 },
    { tokens_BARBRACE, 2 },
    { tokens_BAR_FONT, 1 },
    { tokens_BAR_MODE, 3 },
    { tokens_CRITERIA, 17 },
    { tokens_GAPS_END, 2 },
    { tokens_MODENAME, 2 },
    { tokens_NO_FOCUS, 1 },
    { tokens_BINDING, 20 },
    { tokens_INCLUDE, 1 },
    { tokens_INITIAL, 60 },
    { tokens_ASSIGN, 1 },
    { tokens_BAR_ID, 1 },
    { tokens_EXEC, 2 },
    { tokens_FONT, 1 },
    { tokens_GAPS, 8 },
    { tokens_MODE, 8 },
    { tokens_BAR, 30 },
};
