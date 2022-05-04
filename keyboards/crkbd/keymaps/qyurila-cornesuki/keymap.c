#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_korean.h>
#include "oled.c"
#include "layers.h"
#include "keycodes.h"
#include "g/keymap_combo.h"


// Keys
#define CM_V    KC_B
#define CM_Y    KC_O

#define L_SW_ES LT(_SWAP,   KC_ESC)
#define L_SW_QT LT(_SWAP,   KC_QUOT)
#define L_E_SPC LT(_EXTEND, KC_SPC)
#define L_S_BSP LT(_SYMBOL, KC_BSPC)
#define L_M_TAB LT(_MEDIA,  KC_TAB)
#define L_F_DEL LT(_FUNC,   KC_DEL)

#define L_GM_TG TG(_GAMING)
#define L_AR_TG TG(_ARROW)
#define L_MS_TG TG(_MOUSE)
#define L_NP_TG TG(_NUMPAD)
#define L_LK_TG TG(_LOCK)

#define TD_LANG TD(TDA_RCTL_WNSP)
#define TD_SLPW TD(TDA_SLEP_PWR)
#define TD_RSET TD(TDA_XX_RESET)
#define TD_UNLK TD(TDA_SLEP_PWR)

enum {
    // Tap Dance Actions
    TDA_RCTL_WNSP,
    TDA_SLEP_PWR,
    TDA_XX_RESET,
    TDA_XX_UNLOCK,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TDA_RCTL_WNSP] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, LGUI(KC_SPC)),
    [TDA_SLEP_PWR]  = ACTION_TAP_DANCE_DOUBLE(KC_SLEP, KC_PWR),
    [TDA_XX_RESET]  = ACTION_TAP_DANCE_DOUBLE(XXXXXXX, RESET),
    [TDA_XX_UNLOCK] = ACTION_TAP_DANCE_DOUBLE(XXXXXXX, L_LK_TG),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    L_GM_TG,
    L_SW_ES, C_GUI_A, C_ALT_S, C_SFT_D, C_CTL_F, KC_G,      KC_H,    C_CTL_J, C_SFT_K, C_ALT_L, C_GUISC, L_SW_QT,
    TD_LANG, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD_LANG,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               L_M_TAB, L_E_SPC, OS_LSFT,   KC_ENT,  L_S_BSP, L_F_DEL
  ),
  // Use layer instead of Swap Hands in order to make LT and auto-repeat enable
  [_SWAP] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,      KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    XXXXXXX,
    _______, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,      KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    _______,
    XXXXXXX, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,      KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    XXXXXXX,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_DEL,  KC_BSPC, KC_ENT,    OS_LSFT, KC_SPC,  KC_TAB
  ),

  [_GAMING] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    L_GM_TG,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, L_AR_TG,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_TAB,  KC_SPC,  KC_LSFT,   KC_ENT,  KC_BSPC, KC_LGUI
  ),
  [_ARROW] = LAYOUT_split_3x6_3(
    _______, KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,      _______, _______, KC_UP,   _______, _______, XXXXXXX,
    _______, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,      _______, _______, _______, _______, _______, _______,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               _______, _______, _______,   KC_C,    KC_Z,    KC_X
  ),


  [_SYMBOL] = LAYOUT_split_3x6_3(
    XXXXXXX, S(KC_4), S(KC_3), S(KC_2), S(KC_5), KC_LBRC,   KC_RBRC, S(KC_6), S(KC_7), KC_MINS, KC_EQL,  XXXXXXX,
    KC_GRV,  C_GUI_4, C_ALT_3, C_SFT_2, C_CTL_1, KC_LPRN,   KC_RPRN, C_CTL_0, C_SFT_7, C_ALT_8, C_GUI_9, KC_BSLS,
    XXXXXXX, KC_ASTR, XXXXXXX, KC_PSLS, KC_5,    KC_LCBR,   KC_RCBR, KC_6,    KC_COMM, KC_DOT,  KC_SLSH, L_NP_TG,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_TAB,  KC_SPC,  OS_LSFT,   XXXXXXX, _______, XXXXXXX
  ),
  [_NUMPAD] = LAYOUT_split_3x6_3(
    KC_MUTE, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, XXXXXXX,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_CALC,
    KC_VOLU, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,   KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
    KC_VOLD, XXXXXXX, KC_PDOT, KC_PCMM, KC_PEQL, XXXXXXX,   KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, L_NP_TG,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_ESC,  L_E_SPC, XXXXXXX,   KC_PENT, KC_P0,   KC_PDOT
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
    TD_SLPW, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD_RSET,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, PB_1,    PB_2,    PB_3,    PB_4,    XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG, XXXXXXX,   XXXXXXX, KC_LNG1, KC_LNG2, XXXXXXX, XXXXXXX, XXXXXXX,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               L_LK_TG, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, _______
  ),
  [_LOCK] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               TD_UNLK, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, TD_UNLK
  ),


  [_EXTEND] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN5,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_NUM,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_BTN4,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS, KC_SCRL,
    L_MS_TG, C(CM_Y), C(KC_X), C(KC_C), C(CM_V), C(KC_Z),   XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, KC_APP,  KC_PAUS,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               XXXXXXX, _______, XXXXXXX,   KC_ENT,  KC_BSPC, KC_DEL
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
    KC_WHOM, XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN5,   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_ACL2, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_BTN4,   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, XXXXXXX,
    L_MS_TG, C(CM_Y), C(KC_X), C(KC_C), C(CM_V), C(KC_Z),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, XXXXXXX,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_TAB,  KC_SPC,  KC_BTN1,   KC_ENT,  KC_BSPC, KC_DEL
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
    KC_MUTE, KC_F12,  KC_F11,  KC_F10,  KC_F9,   XXXXXXX,   KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, XXXXXXX,
    KC_VOLU, KC_F4,   KC_F3,   KC_F2,   KC_F1,   XXXXXXX,   KC_VOLU, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,
    KC_VOLD, KC_F8,   KC_F7,   KC_F6,   KC_F5,   XXXXXXX,   KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               _______, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  )
};


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_S_BSP:
        case L_M_TAB:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // OLED
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    switch (keycode) {
        default:
            return true;
    }
}
