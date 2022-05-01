#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_korean.h>
#include "oled.c"
#include "keycodes.h"
#include "g/keymap_combo.h"

// Layers
#define _BASE 0
#define _GAMING 1

#define _EXTEND 4
#define _MOUSE 5
#define _MEDIA 6
#define _SYMBOL 8
#define _NUMPAD 9

#define CM_V KC_B
#define CM_Y KC_O

#define L_E_SPC LT(_EXTEND, KC_SPC)
#define L_S_BSP LT(_SYMBOL, KC_BSPC)
#define L_M_ESC LT(_MEDIA,  KC_ESC)
#define L_MS_TG TG(_MOUSE)
#define L_NP_TG TG(_NUMPAD)


enum custom_keycodes {
    // Tap Dance
    TD_HGHJ,
    TD_PWR,
    TD_SLEP,
    TD_RSET,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_HGHJ] = ACTION_TAP_DANCE_DOUBLE(KR_HAEN, KR_HANJ),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_TAB,  C_GUI_A, C_ALT_S, C_SFT_D, C_CTL_F, KC_G,      KC_H,    C_CTL_J, C_SFT_K, C_ALT_L, C_GUISC, KC_QUOT,
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_LSFT,
  //--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               L_M_ESC, L_E_SPC, OS_LSFT,   KC_ENT,  L_S_BSP, KC_DEL
  ),

  [_GAMING] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LSFT, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LCTL, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
  //-------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_TAB,  KC_SPC,  KC_LALT,   KC_SPC,  MO(2),   KC_RALT
  ),


  [_EXTEND] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN5,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_CAPS, KC_NUM,
    L_MS_TG, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_BTN4,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_APP,  KC_SCRL,
    XXXXXXX, C(CM_Y), C(KC_X), C(KC_C), C(CM_V), C(KC_Z),   XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS,
  //-------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               XXXXXXX, _______, XXXXXXX,   KC_ENT,  KC_BSPC, KC_DEL
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
    KC_WHOM, XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN5,   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_ACL2, XXXXXXX,
    L_MS_TG, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_BTN4,   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, XXXXXXX,
    XXXXXXX, C(CM_Y), C(KC_X), C(KC_C), C(CM_V), C(KC_Z),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, XXXXXXX,
  //-------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_ESC,  KC_SPC,  KC_BTN1,   KC_ENT,  KC_BSPC, KC_DEL
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
    TD_SLEP, KC_F12,  KC_F11,  KC_F10,  KC_F9,   XXXXXXX,   KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, TD_RSET,
    KC_VOLU, KC_F4,   KC_F3,   KC_F2,   KC_F1,   XXXXXXX,   KC_VOLU, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,
    KC_VOLD, KC_F8,   KC_F7,   KC_F6,   KC_F5,   XXXXXXX,   KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //-------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               _______, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),


  [_SYMBOL] = LAYOUT_split_3x6_3(
    DB_TOGG, KC_TILD, KC_GRV,  KC_UNDS, KC_MINS, KC_LBRC,   KC_RBRC, KC_EQL,  KC_PLUS, KC_BSLS, KC_PIPE, XXXXXXX,
    XXXXXXX, C_GUI_4, C_ALT_3, C_SFT_2, C_CTL_1, KC_LPRN,   KC_RPRN, C_CTL_0, C_SFT_7, C_ALT_8, C_GUI_9, L_NP_TG,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_5,    KC_LCBR,   KC_RCBR, KC_6,    KC_PMNS, KC_PDOT, KC_PSLS, XXXXXXX,
  //-------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               XXXXXXX, KC_SPC,  OS_LSFT,   XXXXXXX, _______, XXXXXXX
  ),

  [_NUMPAD] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_PEQL,   KC_PAST, KC_P7,   KC_P8,   KC_P9,   KC_PCMM, KC_CALC,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_PPLS, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, L_NP_TG,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_PCMM, KC_PDOT, XXXXXXX,   KC_PMNS, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, XXXXXXX,
  //-------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
                               KC_ESC,  KC_SPC,  XXXXXXX,   KC_PENT, KC_P0,   KC_PDOT
  )

};


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_E_SPC:
        case L_M_ESC:
        case L_S_BSP:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
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
