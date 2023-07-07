#pragma once
static void GENERATED_call(Match *current_match, struct stack *stack, const int call_identifier, struct ConfigResultIR *result) {
    switch (call_identifier) {
         case 0:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_force_display_urgency_hint(current_match, result, get_long(stack, "duration_ms"));
#else
           fprintf(stderr, "cfg_force_display_urgency_hint(%ld)\n", get_long(stack, "duration_ms"));
#endif
             break;
         case 1:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_floating_maximum_size(current_match, result, get_long(stack, "width"), get_long(stack, "height"));
#else
           fprintf(stderr, "cfg_floating_maximum_size(%ld, %ld)\n", get_long(stack, "width"), get_long(stack, "height"));
#endif
             break;
         case 2:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_floating_minimum_size(current_match, result, get_long(stack, "width"), get_long(stack, "height"));
#else
           fprintf(stderr, "cfg_floating_minimum_size(%ld, %ld)\n", get_long(stack, "width"), get_long(stack, "height"));
#endif
             break;
         case 3:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_strip_workspace_numbers(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_bar_strip_workspace_numbers(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 4:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_binding_mode_indicator(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_bar_binding_mode_indicator(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 5:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_workspace_min_width(current_match, result, get_long(stack, "width"));
#else
           fprintf(stderr, "cfg_bar_workspace_min_width(%ld)\n", get_long(stack, "width"));
#endif
             break;
         case 6:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_on_window_activation(current_match, result, get_string(stack, "mode"));
#else
           fprintf(stderr, "cfg_focus_on_window_activation(%s)\n", get_string(stack, "mode"));
#endif
             break;
         case 7:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_strip_workspace_name(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_bar_strip_workspace_name(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 8:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_add(current_match, result, get_string(stack, "ctype"), get_string(stack, "kind"));
#else
           fprintf(stderr, "cfg_criteria_add(%s, %s)\n", get_string(stack, "ctype"), get_string(stack, "kind"));
       cfg_criteria_add(current_match, result, get_string(stack, "ctype"), get_string(stack, "kind"));
#endif
             break;
         case 9:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_add(current_match, result, get_string(stack, "ctype"), get_string(stack, "kind"));
#else
           fprintf(stderr, "cfg_criteria_add(%s, %s)\n", get_string(stack, "ctype"), get_string(stack, "kind"));
       cfg_criteria_add(current_match, result, get_string(stack, "ctype"), get_string(stack, "kind"));
#endif
             break;
         case 10:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_default_border(current_match, result, get_string(stack, "windowtype"), get_string(stack, "border"), get_long(stack, "width"));
#else
           fprintf(stderr, "cfg_default_border(%s, %s, %ld)\n", get_string(stack, "windowtype"), get_string(stack, "border"), get_long(stack, "width"));
#endif
             break;
         case 11:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_workspace_back_and_forth(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_workspace_back_and_forth(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 12:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_assign(current_match, result, get_string(stack, "number"), 1);
#else
           fprintf(stderr, "cfg_assign(%s, %d)\n", get_string(stack, "number"), 1);
#endif
             break;
         case 13:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_popup_during_fullscreen(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_popup_during_fullscreen(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 14:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_popup_during_fullscreen(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_popup_during_fullscreen(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 15:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_popup_during_fullscreen(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_popup_during_fullscreen(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 16:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_add(current_match, result, get_string(stack, "ctype"), get_string(stack, "kind"));
#else
           fprintf(stderr, "cfg_criteria_add(%s, %s)\n", get_string(stack, "ctype"), get_string(stack, "kind"));
       cfg_criteria_add(current_match, result, get_string(stack, "ctype"), get_string(stack, "kind"));
#endif
             break;
         case 17:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_workspace_buttons(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_bar_workspace_buttons(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 18:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_default_border(current_match, result, get_string(stack, "windowtype"), get_string(stack, "border"), 2);
#else
           fprintf(stderr, "cfg_default_border(%s, %s, %d)\n", get_string(stack, "windowtype"), get_string(stack, "border"), 2);
#endif
             break;
         case 19:
             result->next_state = WORKSPACE_OUTPUT_WORD;
#ifndef TEST_PARSER
             cfg_workspace(current_match, result, get_string(stack, "workspace"), get_string(stack, "output"));
#else
           fprintf(stderr, "cfg_workspace(%s, %s)\n", get_string(stack, "workspace"), get_string(stack, "output"));
#endif
             break;
         case 20:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_separator_symbol(current_match, result, get_string(stack, "separator"));
#else
           fprintf(stderr, "cfg_bar_separator_symbol(%s)\n", get_string(stack, "separator"));
#endif
             break;
         case 21:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_force_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_force_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 22:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_bindsym(current_match, result, get_string(stack, "button"), get_string(stack, "release"), get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_bar_bindsym(%s, %s, %s)\n", get_string(stack, "button"), get_string(stack, "release"), get_string(stack, "command"));
#endif
             break;
         case 23:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_tray_padding(current_match, result, get_long(stack, "padding_px"));
#else
           fprintf(stderr, "cfg_bar_tray_padding(%ld)\n", get_long(stack, "padding_px"));
#endif
             break;
         case 24:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_default_orientation(current_match, result, get_string(stack, "orientation"));
#else
           fprintf(stderr, "cfg_default_orientation(%s)\n", get_string(stack, "orientation"));
#endif
             break;
         case 25:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_default_orientation(current_match, result, get_string(stack, "orientation"));
#else
           fprintf(stderr, "cfg_default_orientation(%s)\n", get_string(stack, "orientation"));
#endif
             break;
         case 26:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_default_orientation(current_match, result, get_string(stack, "orientation"));
#else
           fprintf(stderr, "cfg_default_orientation(%s)\n", get_string(stack, "orientation"));
#endif
             break;
         case 27:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_follows_mouse(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_follows_mouse(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 28:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_padding_three(current_match, result, get_long(stack, "top_or_all"), get_long(stack, "right_or_right_and_left"), get_long(stack, "bottom"));
#else
           fprintf(stderr, "cfg_bar_padding_three(%ld, %ld, %ld)\n", get_long(stack, "top_or_all"), get_long(stack, "right_or_right_and_left"), get_long(stack, "bottom"));
#endif
             break;
         case 29:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_status_command(current_match, result, get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_bar_status_command(%s)\n", get_string(stack, "command"));
#endif
             break;
         case 30:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_wheel_down_cmd(current_match, result, get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_bar_wheel_down_cmd(%s)\n", get_string(stack, "command"));
#endif
             break;
         case 31:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_color(current_match, result, get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), get_string(stack, "text"), get_string(stack, "indicator"), get_string(stack, "child_border"));
#else
           fprintf(stderr, "cfg_color(%s, %s, %s, %s, %s, %s)\n", get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), get_string(stack, "text"), get_string(stack, "indicator"), get_string(stack, "child_border"));
#endif
             break;
         case 32:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_color(current_match, result, get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), get_string(stack, "text"), get_string(stack, "indicator"), NULL);
#else
           fprintf(stderr, "cfg_color(%s, %s, %s, %s, %s, NULL)\n", get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), get_string(stack, "text"), get_string(stack, "indicator"));
#endif
             break;
         case 33:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_for_window(current_match, result, get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_for_window(%s)\n", get_string(stack, "command"));
#endif
             break;
         case 34:
             result->next_state = BAR_COLORS;
#ifndef TEST_PARSER
             cfg_bar_color_single(current_match, result, get_string(stack, "colorclass"), get_string(stack, "color"));
#else
           fprintf(stderr, "cfg_bar_color_single(%s, %s)\n", get_string(stack, "colorclass"), get_string(stack, "color"));
#endif
             break;
         case 35:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_padding_two(current_match, result, get_long(stack, "top_or_all"), get_long(stack, "right_or_right_and_left"));
#else
           fprintf(stderr, "cfg_bar_padding_two(%ld, %ld)\n", get_long(stack, "top_or_all"), get_long(stack, "right_or_right_and_left"));
#endif
             break;
         case 36:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_floating_modifier(current_match, result, get_string(stack, "modifiers"));
#else
           fprintf(stderr, "cfg_floating_modifier(%s)\n", get_string(stack, "modifiers"));
#endif
             break;
         case 37:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 38:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 39:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 40:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 41:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 42:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 43:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 44:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 45:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 46:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 47:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 48:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_hide_edge_borders(current_match, result, get_string(stack, "hide_borders"));
#else
           fprintf(stderr, "cfg_hide_edge_borders(%s)\n", get_string(stack, "hide_borders"));
#endif
             break;
         case 49:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_assign(current_match, result, get_string(stack, "workspace"), 0);
#else
           fprintf(stderr, "cfg_assign(%s, %d)\n", get_string(stack, "workspace"), 0);
#endif
             break;
         case 50:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_hidden_state(current_match, result, get_string(stack, "hidden_state"));
#else
           fprintf(stderr, "cfg_bar_hidden_state(%s)\n", get_string(stack, "hidden_state"));
#endif
             break;
         case 51:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_hidden_state(current_match, result, get_string(stack, "hidden_state"));
#else
           fprintf(stderr, "cfg_bar_hidden_state(%s)\n", get_string(stack, "hidden_state"));
#endif
             break;
         case 52:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_padding_four(current_match, result, get_long(stack, "top_or_all"), get_long(stack, "right_or_right_and_left"), get_long(stack, "bottom"), get_long(stack, "left"));
#else
           fprintf(stderr, "cfg_bar_padding_four(%ld, %ld, %ld, %ld)\n", get_long(stack, "top_or_all"), get_long(stack, "right_or_right_and_left"), get_long(stack, "bottom"), get_long(stack, "left"));
#endif
             break;
         case 53:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_wheel_up_cmd(current_match, result, get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_bar_wheel_up_cmd(%s)\n", get_string(stack, "command"));
#endif
             break;
         case 54:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_ipc_kill_timeout(current_match, result, get_long(stack, "timeout"));
#else
           fprintf(stderr, "cfg_ipc_kill_timeout(%ld)\n", get_long(stack, "timeout"));
#endif
             break;
         case 55:
             result->next_state = MODE;
#ifndef TEST_PARSER
             cfg_mode_binding(current_match, result, get_string(stack, "bindtype"), get_string(stack, "modifiers"), get_string(stack, "key"), get_string(stack, "release"), get_string(stack, "border"), get_string(stack, "whole_window"), get_string(stack, "exclude_titlebar"), get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_mode_binding(%s, %s, %s, %s, %s, %s, %s, %s)\n", get_string(stack, "bindtype"), get_string(stack, "modifiers"), get_string(stack, "key"), get_string(stack, "release"), get_string(stack, "border"), get_string(stack, "whole_window"), get_string(stack, "exclude_titlebar"), get_string(stack, "command"));
#endif
             break;
         case 56:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_tiling_drag(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_tiling_drag(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 57:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_workspace_layout(current_match, result, get_string(stack, "layout"));
#else
           fprintf(stderr, "cfg_workspace_layout(%s)\n", get_string(stack, "layout"));
#endif
             break;
         case 58:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_workspace_layout(current_match, result, get_string(stack, "layout"));
#else
           fprintf(stderr, "cfg_workspace_layout(%s)\n", get_string(stack, "layout"));
#endif
             break;
         case 59:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_workspace_layout(current_match, result, get_string(stack, "layout"));
#else
           fprintf(stderr, "cfg_workspace_layout(%s)\n", get_string(stack, "layout"));
#endif
             break;
         case 60:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_workspace_layout(current_match, result, get_string(stack, "layout"));
#else
           fprintf(stderr, "cfg_workspace_layout(%s)\n", get_string(stack, "layout"));
#endif
             break;
         case 61:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_i3bar_command(current_match, result, get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_bar_i3bar_command(%s)\n", get_string(stack, "command"));
#endif
             break;
         case 62:
             result->next_state = BAR_COLORS;
#ifndef TEST_PARSER
             cfg_bar_color(current_match, result, get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), NULL);
#else
           fprintf(stderr, "cfg_bar_color(%s, %s, %s, NULL)\n", get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"));
#endif
             break;
         case 63:
             result->next_state = BAR_COLORS;
#ifndef TEST_PARSER
             cfg_bar_color(current_match, result, get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), get_string(stack, "text"));
#else
           fprintf(stderr, "cfg_bar_color(%s, %s, %s, %s)\n", get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), get_string(stack, "text"));
#endif
             break;
         case 64:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_padding_one(current_match, result, get_long(stack, "top_or_all"));
#else
           fprintf(stderr, "cfg_bar_padding_one(%ld)\n", get_long(stack, "top_or_all"));
#endif
             break;
         case 65:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_socket_path(current_match, result, get_string(stack, "path"));
#else
           fprintf(stderr, "cfg_bar_socket_path(%s)\n", get_string(stack, "path"));
#endif
             break;
         case 66:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_tray_output(current_match, result, get_string(stack, "output"));
#else
           fprintf(stderr, "cfg_bar_tray_output(%s)\n", get_string(stack, "output"));
#endif
             break;
         case 67:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_color(current_match, result, get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), get_string(stack, "text"), NULL, NULL);
#else
           fprintf(stderr, "cfg_color(%s, %s, %s, %s, NULL, NULL)\n", get_string(stack, "colorclass"), get_string(stack, "border"), get_string(stack, "background"), get_string(stack, "text"));
#endif
             break;
         case 68:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_disable_randr15(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_disable_randr15(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 69:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_default_border(current_match, result, get_string(stack, "windowtype"), get_string(stack, "border"), -1);
#else
           fprintf(stderr, "cfg_default_border(%s, %s, %d)\n", get_string(stack, "windowtype"), get_string(stack, "border"), -1);
#endif
             break;
         case 70:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_default_border(current_match, result, get_string(stack, "windowtype"), get_string(stack, "border"), -1);
#else
           fprintf(stderr, "cfg_default_border(%s, %s, %d)\n", get_string(stack, "windowtype"), get_string(stack, "border"), -1);
#endif
             break;
         case 71:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 72:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 73:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 74:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 75:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 76:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 77:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 78:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 79:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 80:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 81:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 82:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 83:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 84:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_focus_wrapping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_focus_wrapping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 85:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_force_xinerama(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_force_xinerama(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 86:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_assign_output(current_match, result, get_string(stack, "output"));
#else
           fprintf(stderr, "cfg_assign_output(%s)\n", get_string(stack, "output"));
#endif
             break;
         case 87:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_add(current_match, result, get_string(stack, "ctype"), get_string(stack, "cvalue"));
#else
           fprintf(stderr, "cfg_criteria_add(%s, %s)\n", get_string(stack, "ctype"), get_string(stack, "cvalue"));
       cfg_criteria_add(current_match, result, get_string(stack, "ctype"), get_string(stack, "cvalue"));
#endif
             break;
         case 88:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_mouse_warping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_mouse_warping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 89:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_mouse_warping(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_mouse_warping(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 90:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_restart_state(current_match, result, get_string(stack, "path"));
#else
           fprintf(stderr, "cfg_restart_state(%s)\n", get_string(stack, "path"));
#endif
             break;
         case 91:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_borders(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_borders(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 92:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_borders(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_borders(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 93:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_borders(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_borders(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 94:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_borders(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_borders(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 95:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_borders(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_borders(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 96:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_borders(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_borders(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 97:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_borders(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_borders(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 98:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_modifier(current_match, result, NULL);
#else
           fprintf(stderr, "cfg_bar_modifier(NULL)\n");
#endif
             break;
         case 99:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_modifier(current_match, result, NULL);
#else
           fprintf(stderr, "cfg_bar_modifier(NULL)\n");
#endif
             break;
         case 100:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_modifier(current_match, result, get_string(stack, "modifiers"));
#else
           fprintf(stderr, "cfg_bar_modifier(%s)\n", get_string(stack, "modifiers"));
#endif
             break;
         case 101:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_position(current_match, result, get_string(stack, "position"));
#else
           fprintf(stderr, "cfg_bar_position(%s)\n", get_string(stack, "position"));
#endif
             break;
         case 102:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_position(current_match, result, get_string(stack, "position"));
#else
           fprintf(stderr, "cfg_bar_position(%s)\n", get_string(stack, "position"));
#endif
             break;
         case 103:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_color_single(current_match, result, get_string(stack, "colorclass"), get_string(stack, "color"));
#else
           fprintf(stderr, "cfg_color_single(%s, %s)\n", get_string(stack, "colorclass"), get_string(stack, "color"));
#endif
             break;
         case 104:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_fake_outputs(current_match, result, get_string(stack, "outputs"));
#else
           fprintf(stderr, "cfg_fake_outputs(%s)\n", get_string(stack, "outputs"));
#endif
             break;
         case 105:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_no_focus(current_match, result);
#else
           fprintf(stderr, "cfg_no_focus()\n");
#endif
             break;
         case 106:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_verbose(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_bar_verbose(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 107:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_binding(current_match, result, get_string(stack, "bindtype"), get_string(stack, "modifiers"), get_string(stack, "key"), get_string(stack, "release"), get_string(stack, "border"), get_string(stack, "whole_window"), get_string(stack, "exclude_titlebar"), get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_binding(%s, %s, %s, %s, %s, %s, %s, %s)\n", get_string(stack, "bindtype"), get_string(stack, "modifiers"), get_string(stack, "key"), get_string(stack, "release"), get_string(stack, "border"), get_string(stack, "whole_window"), get_string(stack, "exclude_titlebar"), get_string(stack, "command"));
#endif
             break;
         case 108:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_tiling_drag(current_match, result, get_string(stack, "off"));
#else
           fprintf(stderr, "cfg_tiling_drag(%s)\n", get_string(stack, "off"));
#endif
             break;
         case 109:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_tiling_drag(current_match, result, get_string(stack, "off"));
#else
           fprintf(stderr, "cfg_tiling_drag(%s)\n", get_string(stack, "off"));
#endif
             break;
         case 110:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_tiling_drag(current_match, result, get_string(stack, "off"));
#else
           fprintf(stderr, "cfg_tiling_drag(%s)\n", get_string(stack, "off"));
#endif
             break;
         case 111:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_tiling_drag(current_match, result, get_string(stack, "off"));
#else
           fprintf(stderr, "cfg_tiling_drag(%s)\n", get_string(stack, "off"));
#endif
             break;
         case 112:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_tiling_drag(current_match, result, get_string(stack, "off"));
#else
           fprintf(stderr, "cfg_tiling_drag(%s)\n", get_string(stack, "off"));
#endif
             break;
         case 113:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_tiling_drag(current_match, result, get_string(stack, "off"));
#else
           fprintf(stderr, "cfg_tiling_drag(%s)\n", get_string(stack, "off"));
#endif
             break;
         case 114:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_title_align(current_match, result, get_string(stack, "alignment"));
#else
           fprintf(stderr, "cfg_title_align(%s)\n", get_string(stack, "alignment"));
#endif
             break;
         case 115:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_title_align(current_match, result, get_string(stack, "alignment"));
#else
           fprintf(stderr, "cfg_title_align(%s)\n", get_string(stack, "alignment"));
#endif
             break;
         case 116:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_title_align(current_match, result, get_string(stack, "alignment"));
#else
           fprintf(stderr, "cfg_title_align(%s)\n", get_string(stack, "alignment"));
#endif
             break;
         case 117:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_height(current_match, result, get_long(stack, "value"));
#else
           fprintf(stderr, "cfg_bar_height(%ld)\n", get_long(stack, "value"));
#endif
             break;
         case 118:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_output(current_match, result, get_string(stack, "output"));
#else
           fprintf(stderr, "cfg_bar_output(%s)\n", get_string(stack, "output"));
#endif
             break;
         case 119:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_init(current_match, result, 36);
#else
           fprintf(stderr, "cfg_criteria_init(%d)\n", 36);
       cfg_criteria_init(current_match, result, 36);
#endif
             break;
         case 120:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_ipc_socket(current_match, result, get_string(stack, "path"));
#else
           fprintf(stderr, "cfg_ipc_socket(%s)\n", get_string(stack, "path"));
#endif
             break;
         case 121:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_show_marks(current_match, result, get_string(stack, "value"));
#else
           fprintf(stderr, "cfg_show_marks(%s)\n", get_string(stack, "value"));
#endif
             break;
         case 122:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 123:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 124:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 125:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 126:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 127:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 128:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 129:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 130:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 131:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 132:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 133:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 134:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_smart_gaps(current_match, result, get_string(stack, "enabled"));
#else
           fprintf(stderr, "cfg_smart_gaps(%s)\n", get_string(stack, "enabled"));
#endif
             break;
         case 135:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_start(current_match, result);
#else
           fprintf(stderr, "cfg_bar_start()\n");
#endif
             break;
         case 136:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_font(current_match, result, get_string(stack, "font"));
#else
           fprintf(stderr, "cfg_bar_font(%s)\n", get_string(stack, "font"));
#endif
             break;
         case 137:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_mode(current_match, result, get_string(stack, "mode"));
#else
           fprintf(stderr, "cfg_bar_mode(%s)\n", get_string(stack, "mode"));
#endif
             break;
         case 138:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_mode(current_match, result, get_string(stack, "mode"));
#else
           fprintf(stderr, "cfg_bar_mode(%s)\n", get_string(stack, "mode"));
#endif
             break;
         case 139:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_mode(current_match, result, get_string(stack, "mode"));
#else
           fprintf(stderr, "cfg_bar_mode(%s)\n", get_string(stack, "mode"));
#endif
             break;
         case 140:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_add(current_match, result, get_string(stack, "ctype"), NULL);
#else
           fprintf(stderr, "cfg_criteria_add(%s, NULL)\n", get_string(stack, "ctype"));
       cfg_criteria_add(current_match, result, get_string(stack, "ctype"), NULL);
#endif
             break;
         case 141:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_add(current_match, result, get_string(stack, "ctype"), NULL);
#else
           fprintf(stderr, "cfg_criteria_add(%s, NULL)\n", get_string(stack, "ctype"));
       cfg_criteria_add(current_match, result, get_string(stack, "ctype"), NULL);
#endif
             break;
         case 142:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_add(current_match, result, get_string(stack, "ctype"), NULL);
#else
           fprintf(stderr, "cfg_criteria_add(%s, NULL)\n", get_string(stack, "ctype"));
       cfg_criteria_add(current_match, result, get_string(stack, "ctype"), NULL);
#endif
             break;
         case 143:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_criteria_pop_state(current_match, result);
#else
           fprintf(stderr, "cfg_criteria_pop_state()\n");
       cfg_criteria_pop_state(current_match, result);
#endif
             break;
         case 144:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_gaps(current_match, result, get_string(stack, "workspace"), get_string(stack, "scope"), get_long(stack, "value"));
#else
           fprintf(stderr, "cfg_gaps(%s, %s, %ld)\n", get_string(stack, "workspace"), get_string(stack, "scope"), get_long(stack, "value"));
#endif
             break;
         case 145:
             result->next_state = MODEBRACE;
#ifndef TEST_PARSER
             cfg_enter_mode(current_match, result, get_string(stack, "pango_markup"), get_string(stack, "modename"));
#else
           fprintf(stderr, "cfg_enter_mode(%s, %s)\n", get_string(stack, "pango_markup"), get_string(stack, "modename"));
#endif
             break;
         case 146:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_init(current_match, result, 79);
#else
           fprintf(stderr, "cfg_criteria_init(%d)\n", 79);
       cfg_criteria_init(current_match, result, 79);
#endif
             break;
         case 147:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_include(current_match, result, get_string(stack, "pattern"));
#else
           fprintf(stderr, "cfg_include(%s)\n", get_string(stack, "pattern"));
#endif
             break;
         case 148:
             result->next_state = CRITERIA;
#ifndef TEST_PARSER
             cfg_criteria_init(current_match, result, 43);
#else
           fprintf(stderr, "cfg_criteria_init(%d)\n", 43);
       cfg_criteria_init(current_match, result, 43);
#endif
             break;
         case 149:
             result->next_state = BAR;
#ifndef TEST_PARSER
             cfg_bar_id(current_match, result, get_string(stack, "bar_id"));
#else
           fprintf(stderr, "cfg_bar_id(%s)\n", get_string(stack, "bar_id"));
#endif
             break;
         case 150:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_exec(current_match, result, get_string(stack, "exectype"), get_string(stack, "no_startup_id"), get_string(stack, "command"));
#else
           fprintf(stderr, "cfg_exec(%s, %s, %s)\n", get_string(stack, "exectype"), get_string(stack, "no_startup_id"), get_string(stack, "command"));
#endif
             break;
         case 151:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_font(current_match, result, get_string(stack, "font"));
#else
           fprintf(stderr, "cfg_font(%s)\n", get_string(stack, "font"));
#endif
             break;
         case 152:
             result->next_state = INITIAL;
#ifndef TEST_PARSER
             cfg_bar_finish(current_match, result);
#else
           fprintf(stderr, "cfg_bar_finish()\n");
#endif
             break;
        default:
            printf("BUG in the parser. state = %d\n", call_identifier);
            assert(false);
    }
}
