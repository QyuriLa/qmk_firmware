#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_korean.h>
#include "oled.c"
#include "layers.h"
#include "keycodes.h"
#include "g/keymap_combo.h"


// Keys
#define L_TG_UT TG(_UTIL)
#define L_TG_GM TG(_GAMING)
#define L_TG_AR TG(_ARROW)
#define L_TG_NP TG(_NUMPAD)
#define L_TG_MS TG(_MOUSE)
#define L_TG_LK TG(_LOCK)

#define L_F_DEL LT(_FUNC,   KC_DEL)
#define L_E_TAB LT(_EXTEND, KC_TAB)
#define L_E_SPC LT(_EXTEND, KC_SPC)
#define L_N_ENT LT(_NUMBER, KC_ENT)
#define L_F_ESC LT(_FUNC,   KC_ESC)

#define SFT_TAB LSFT_T(KC_TAB)

#define TD_KOHJ TD(TDA_KOEN_HANJ)
#define TD_SLPW TD(TDA_SLEP_PWR)
#define TD_UNLK TD(TDA_LTG_XX_LOCK)

enum {
    // Tap Dance Actions
    TDA_KOEN_HANJ,
    TDA_SLEP_PWR,
    TDA_LTG_XX_LOCK,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TDA_KOEN_HANJ] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_RCTL),
    [TDA_SLEP_PWR]  = ACTION_TAP_DANCE_DOUBLE(KC_SLEP, KC_PWR),
    [TDA_LTG_XX_LOCK] = ACTION_TAP_DANCE_LAYER_TOGGLE(XXXXXXX, _LOCK),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    L_TG_UT, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, L_TG_GM,
    KC_GRV,  M_GUI_A, M_ALT_R, M_SFT_S, M_CTL_T, KC_G,      KC_M,    M_CTL_N, M_SFT_E, M_ALT_I, M_GUI_O, KC_QUOT,
    TD_KOHJ, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                               L_F_DEL, KC_BSPC, L_E_TAB,   L_N_ENT, KC_SPC,  L_F_ESC
  ),
  /*
  [_QWERTY] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN, XXXXXXX,
    KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_QUOT,
    TD_KOHJ, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                               L_F_DEL, L_E_BSP, SFT_TAB,   KC_ENT,  L_N_SPC, L_F_ESC
  ),
  */

  [_UTIL] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    OS_LCTL, M_GUI_A, M_ALT_R, M_SFT_S, M_CTL_T, KC_G,      KC_M,    M_CTL_N, M_SFT_E, M_ALT_I, M_GUI_O, KC_QUOT,
    OS_LALT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, L_TG_AR,
                               L_F_DEL, KC_SPC,  OS_LSFT,   L_N_ENT, KC_SPC, L_F_ESC
  ),
  [_GAMING] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_QUOT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, L_TG_AR,
                               KC_TAB,  KC_SPC,  KC_LSFT,   KC_ENT,  KC_SPC,  L_F_ESC
  ),
  [_ARROW] = LAYOUT_split_3x6_3(
    _______, KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,      _______, _______, KC_UP,   _______, _______, L_TG_AR,
    _______, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,      _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,   KC_C,    KC_Z,    KC_X
  ),


  [_NUMBER] = LAYOUT_split_3x6_3(
    XXXXXXX, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, XXXXXXX,
    XXXXXXX, M_GUI_4, M_ALT_3, M_SFT_2, M_CTL_1, _______,   _______, M_CTL_0, M_SFT_7, M_ALT_8, M_GUI_9, L_TG_NP,
    XXXXXXX, _______, _______, _______, KC_5,    _______,   _______, KC_6,    _______, _______, _______, XXXXXXX,
                               KC_DEL,  KC_BSPC, KC_TAB,    _______, XXXXXXX, XXXXXXX
  ),
  [_NUMPAD] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_PDOT, KC_PCMM, KC_PEQL, XXXXXXX,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_CALC,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,   KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, L_TG_NP,
    XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, XXXXXXX,   KC_SPC,  KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX,
                               KC_DEL,  KC_SPC,  L_E_TAB,   KC_PENT, KC_P0,   KC_BSPC
  ),

  [_EXTEND] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_MUTE, KC_VOLD, KC_MPLY, KC_VOLU, XXXXXXX,   KC_APP,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NUM,
    L_TG_MS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,   KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_SCRL,
    XXXXXXX, C(KC_Y), C(KC_X), C(KC_C), C(KC_Z), C(KC_V),   KC_PSCR, KC_BSPC, KC_CAPS, KC_INS,  KC_DEL,  KC_PAUS,
                               XXXXXXX, XXXXXXX, _______,   KC_ENT,  KC_SPC,  KC_ESC
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
    KC_WHOM, KC_WH_U, KC_BTN4, KC_BTN1, KC_BTN5, XXXXXXX,   XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
    L_TG_MS, KC_WH_D, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI,   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
    XXXXXXX, C(KC_Y), C(KC_X), C(KC_C), C(KC_V), C(KC_V),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_BTN3, KC_BTN1, KC_BTN2,   KC_ACL0, KC_ACL1, KC_ACL2
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
    TD_SLPW, KC_F12,  KC_F11,  KC_F10,  KC_F9,   XXXXXXX,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, DB_TOGG,
    L_TG_LK, KC_F4,   KC_F3,   KC_F2,   KC_F1,   XXXXXXX,   XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, QK_BOOT,
    XXXXXXX, KC_F8,   KC_F7,   KC_F6,   KC_F5,   XXXXXXX,   XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, RESET,
                               _______, PB_1,    PB_2,      PB_3,    PB_4,    _______
  ),
  [_LOCK] = LAYOUT_split_3x6_3(
    TD_UNLK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD_UNLK,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),
};


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_F_DEL:
        case L_E_TAB:
        case L_N_ENT:
        case L_F_ESC:
        case SFT_TAB:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

/*
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_E_BSP:
        case L_E_SPC:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
*/

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    if (IS_RETRO(keycode)) {
        return true;
    }
    switch(keycode) {
        case KC_DOT:
        case KC_COMM:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_DOT:  register_code16((!shifted) ? KC_DOT  : KC_EXLM); break;
        case KC_COMM: register_code16((!shifted) ? KC_COMM : KC_TILD); break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_DOT:  unregister_code16((!shifted) ? KC_DOT  : KC_EXLM); break;
        case KC_COMM: unregister_code16((!shifted) ? KC_COMM : KC_TILD); break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16(keycode & 0xFF);
    }
}


bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case tr_LPRN:
        case ni_RPRN:
        case sr_MINS:
        case ei_UNDS:
        case ts_PLUS:
        case ne_ASTR:
        case ar_ESC:
        case oi_BSPC:
            return true;
        default:
            return false;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // _BASE, _NUMBER, _NUMPAD
    if (layer_state|0b00110001) {
        return true;
    }
    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // OLED
    if (record->event.pressed) {
        set_keylog(keycode);
    }

    switch (keycode) {
        default:
            return true;
    }
}
