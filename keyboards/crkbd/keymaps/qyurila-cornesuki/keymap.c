#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_korean.h>
#include "oled.c"
#include "layers.h"
#include "keycodes.h"
#include "g/keymap_combo.h"


// Keys
#define L_TG_GM TG(_GAMING)
#define L_TG_AR TG(_ARROW)
#define L_TG_MS TG(_MOUSE)
#define L_TG_NP TG(_NUMPAD)
#define L_TG_LK TG(_LOCK)
#define L_TG_AJ TG(_LOCK)

#define SW_ESC  LT(_SWAP,   KC_ESC)
#define SW_QUOT LT(_SWAP,   KC_QUOT)
#define L_F_TAB LT(_FUNC,   KC_TAB)
#define L_E_ENT LT(_EXTEND, KC_ENT)
#define L_S_SPC LT(_SYMBOL, KC_SPC)
#define L_F_BSP LT(_FUNC,   KC_BSPC)

#define SFT_TAB LSFT_T(KC_TAB)

#define TD_LANG TD(TDA_RCTL_WNSP)
#define TD_LLNG TD(TDA_LNG1_LNG2)
#define TD_SLPW TD(TDA_SLEP_PWR)
#define TD_UNLK TD(TDA_LTG_XX_LOCK)

enum {
    // Tap Dance Actions
    TDA_RCTL_WNSP,
    TDA_LNG1_LNG2,
    TDA_SLEP_PWR,
    TDA_LTG_XX_LOCK,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TDA_RCTL_WNSP] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, LGUI(KC_SPC)),
    [TDA_LNG1_LNG2] = ACTION_TAP_DANCE_DOUBLE(KC_LNG1, KC_LNG2),
    [TDA_SLEP_PWR]  = ACTION_TAP_DANCE_DOUBLE(KC_SLEP, KC_PWR),
    [TDA_LTG_XX_LOCK] = ACTION_TAP_DANCE_LAYER_TOGGLE(XXXXXXX, _LOCK),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_LGUI, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, L_TG_GM,
    SW_ESC,  M_GUI_A, M_ALT_R, M_SFT_S, M_CTL_T, KC_G,      KC_M,    M_CTL_N, M_SFT_E, M_ALT_I, M_GUI_O, SW_QUOT,
    TD_LLNG, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, TD_LANG,
  //--- ----+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               L_F_TAB, L_E_ENT, OS_LSFT,   L_S_SPC, L_F_BSP, KC_DEL
  ),
  // Use layer instead of Swap Hands in order to make LT and auto-repeat enable
  [_SWAP] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_SCLN, KC_Y,    KC_U,    KC_L,    KC_J,      KC_B,    KC_P,    KC_F,    KC_W,    KC_Q,    XXXXXXX,
    _______, KC_O,    KC_I,    KC_E,    KC_N,    KC_M,      KC_G,    KC_T,    KC_S,    KC_R,    KC_A,    _______,
    XXXXXXX, KC_SLSH, KC_DOT,  KC_COMM, KC_H,    KC_K,      KC_V,    KC_D,    KC_C,    KC_X,    KC_Z,    XXXXXXX,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_DEL,  KC_BSPC, KC_SPC,    KC_ENT,  OS_LSFT, KC_TAB
  ),

  [_GAMING] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    L_TG_GM,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, L_TG_AR,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_TAB,  KC_SPC,  KC_LSFT,   KC_ENT,  KC_SPC,  KC_BSPC
  ),
  [_ARROW] = LAYOUT_split_3x6_3(
    _______, KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,      _______, _______, KC_UP,   _______, _______, L_TG_AR,
    _______, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,      _______, _______, _______, _______, _______, _______,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               _______, _______, _______,   KC_Z,    KC_X,    KC_C
  ),


  [_SYMBOL] = LAYOUT_split_3x6_3(
    XXXXXXX, S(KC_4), S(KC_3), S(KC_2), S(KC_5), KC_LBRC,   KC_RBRC, S(KC_6), S(KC_7), KC_MINS, KC_EQL,  XXXXXXX,
    KC_GRV,  M_GUI_4, M_ALT_3, M_SFT_2, M_CTL_1, KC_LPRN,   KC_RPRN, M_CTL_0, M_SFT_7, M_ALT_8, M_GUI_9, KC_BSLS,
    XXXXXXX, KC_ASTR, XXXXXXX, XXXXXXX, KC_5,    KC_LCBR,   KC_RCBR, KC_6,    KC_COMM, KC_DOT,  KC_SLSH, L_TG_NP,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_ESC,  OS_LSFT, KC_ENT,    _______, XXXXXXX, XXXXXXX
  ),
  [_NUMPAD] = LAYOUT_split_3x6_3(
    KC_MUTE, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, XXXXXXX,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_CALC,
    KC_VOLU, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,   KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
    KC_VOLD, XXXXXXX, KC_PDOT, KC_PCMM, KC_PEQL, XXXXXXX,   KC_SPC,  KC_P1,   KC_P2,   KC_P3,   KC_PDOT, L_TG_NP,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_TAB,  KC_SPC,  L_E_ENT,   KC_PENT, KC_P0,   KC_BSPC
  ),

  [_EXTEND] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN5,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_NUM,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_BTN1,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS, KC_SCRL,
    L_TG_MS, C(KC_Y), C(KC_X), C(KC_C), C(KC_Z), C(KC_V),   KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_APP,  KC_PAUS,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               XXXXXXX, _______, XXXXXXX,   KC_SPC,  KC_BSPC, KC_DEL
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
    KC_WHOM, XXXXXXX, KC_BTN4, KC_BTN1, KC_BTN5, KC_WH_U,   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_WH_D,   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
    L_TG_MS, C(KC_Y), C(KC_X), C(KC_C), C(KC_V), C(KC_V),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_BTN3, KC_BTN1, KC_BTN2,   KC_ACL0, KC_ACL1, KC_ACL2
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
    KC_VOLU, KC_F12,  KC_F11,  KC_F10,  KC_F9,   XXXXXXX,   KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, TD_SLPW,
    KC_VOLD, KC_F4,   KC_F3,   KC_F2,   KC_F1,   XXXXXXX,   KC_VOLD, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, DB_TOGG,
    KC_MUTE, KC_F8,   KC_F7,   KC_F6,   KC_F5,   XXXXXXX,   KC_MUTE, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, RESET,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               _______, XXXXXXX, XXXXXXX,   XXXXXXX, _______, L_TG_LK
  ),
  [_LOCK] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               TD_UNLK, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, TD_UNLK
  ),
};


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SW_ESC :
        case SW_QUOT:
        case L_F_TAB:
        case L_E_ENT:
        case L_S_SPC:
        case L_F_BSP:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_TAB:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case rt_LPRN:
        case in_RPRN:
        case rs_MINS:
        case ie_UNDS:
        case st_PLUS:
        case en_ASTR:
        case ar_GRV:
        case oi_QUOT:
        case ars_TILD:
        case oie_DQT:
            return true;
        default:
            return false;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // _BASE, _SYMBOL, _NUMPAD
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
