//
// Created by dingjing on 23-7-12.
//

#ifndef GRACEFUL_WM_GET_MOD_MASK_H
#define GRACEFUL_WM_GET_MOD_MASK_H
#include <stdint.h>
#include <xcb/xcb.h>
#include <xcb/xcb_keysyms.h>


/**
 * All-in-one function which returns the modifier mask (XCB_MOD_MASK_*) for the
 * given keysymbol, for example for XCB_NUM_LOCK (usually configured to mod2).
 *
 * This function initiates one round-trip. Use get_mod_mask_for() directly if
 * you already have the modifier mapping and key symbols.
 *
 */
uint32_t aio_get_mod_mask_for(uint32_t keysym, xcb_key_symbols_t *symbols);

/**
 * Returns the modifier mask (XCB_MOD_MASK_*) for the given keysymbol, for
 * example for XCB_NUM_LOCK (usually configured to mod2).
 *
 * This function does not initiate any round-trips.
 *
 */
uint32_t get_mod_mask_for(uint32_t keysym, xcb_key_symbols_t *symbols, xcb_get_modifier_mapping_reply_t *modmap_reply);


#endif //GRACEFUL_WM_GET_MOD_MASK_H
