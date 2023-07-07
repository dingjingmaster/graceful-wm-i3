//
// Created by dingjing on 23-7-7.
//

#ifndef GRACEFUL_XF_WM_MATCH_H
#define GRACEFUL_XF_WM_MATCH_H
#include "types.h"

/**
 * Initializes the Match data structure. This function is necessary because the
 * members representing boolean values (like dock) need to be initialized with
 * -1 instead of 0.
 *
 */
void match_init(Match *match);

/**
 * Check if a match is empty. This is necessary while parsing commands to see
 * whether the user specified a match at all.
 *
 */
bool match_is_empty(Match *match);

/**
 * Copies the data of a match from src to dest.
 *
 */
void match_copy(Match *dest, Match *src);

/**
 * Check if a match data structure matches the given window.
 *
 */
bool match_matches_window(Match *match, i3Window *window);

/**
 * Frees the given match. It must not be used afterwards!
 *
 */
void match_free(Match *match);

/**
 * Interprets a ctype=cvalue pair and adds it to the given match specification.
 *
 */
void match_parse_property(Match *match, const char *ctype, const char *cvalue);

#endif //GRACEFUL_XF_WM_MATCH_H
