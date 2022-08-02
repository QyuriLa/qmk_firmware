/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2022 Hyeon Gu <rea9lizer@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "layers.h"
#include "keycodes.h"
#include "g/keymap_combo.h"
#include "auto_shift_config.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX,
    KC_GRV,  M_GUI_A, M_ALT_R, M_SFT_S, M_CTL_T, KC_G,    XXXXXXX, XXXXXXX, KC_M,    M_CTL_N, M_SFT_E, M_ALT_I, M_GUI_O, KC_QUOT,
    KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, LTO_GM,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //--------+--------+--------+--------+--------+--------|--------+--------|--------+--------+--------+--------+--------+--------
                      L_F_SPC, L_E_ESC, L_N_ENT, SH_TAB,                    SH_RALT, KC_SPC,  KC_BSPC, KC_DEL
  ),                                                                     // =HANGUL (KC_LNG1)

  [_GAME] = LAYOUT(
    KC_ESC,  KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LSFT, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,    XXXXXXX, LTO_BS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
    KC_LCTL, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,    XXXXXXX, LTG_ARW, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
  //--------+--------+--------+--------+--------+--------|--------+--------|--------+--------+--------+--------+--------+--------
                      KC_LALT, KC_ENT,  KC_SPC,  KC_TAB,                    KC_RALT, L_N_ENT, L_E_BSP, L_F_DEL
  ),
  [_ARROW] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, KC_UP,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
  //--------+--------+--------+--------+--------+--------|--------+--------|--------+--------+--------+--------+--------+--------
                      _______, _______, _______, _______,                   KC_ENT,  KC_SPC,  KC_BSPC, KC_DEL
  ),


  [_NUMBER] = LAYOUT(
    XXXXXXX, KC_COMM, KC_DOT,  KC_0,    KC_9,    _______,                   _______, _______, _______, _______, _______, XXXXXXX,
    XXXXXXX, M_GUI_4, M_ALT_3, M_SFT_2, M_CTL_1, _______, XXXXXXX, _______, _______, M_CTL_0, M_SFT_7, M_ALT_8, M_GUI_9, XXXXXXX,
    LTG_NPD, KC_8,    KC_7,    KC_6,    KC_5,    _______, XXXXXXX, _______, _______, KC_6,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
  //--------+--------+--------+--------+--------+--------|--------+--------|--------+--------+--------+--------+--------+--------
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, _______, _______, _______
  ),
  [_NUMPAD] = LAYOUT(
    KC_CALC, XXXXXXX, KC_PDOT, KC_PCMM, KC_PEQL, XXXXXXX,                   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_CALC,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX, LTO_BS,  KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
    LTG_NPD, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX,
  //--------+--------+--------+--------+--------+--------|--------+--------|--------+--------+--------+--------+--------+--------
                      L_F_SPC, L_E_ESC, L_N_ENT, SH_TAB,                    KC_PENT, KC_P0,   KC_BSPC, KC_DEL
  ),

  [_EXTEND] = LAYOUT(
    XXXXXXX, KC_AGIN, KC_CUT,  KC_COPY, KC_UNDO, KC_PSTE,                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PERC, KC_NUM,
    KC_MEH,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, C(KC_T), XXXXXXX, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_GRV , KC_SCRL,
    LTG_MUS, C(KC_Y), C(KC_X), C(KC_C), C(KC_Z), C(KC_V), XXXXXXX, _______, KC_PSCR, CAPSWRD, KC_CAPS, KC_INS,  KC_APP,  KC_PAUS,
  //--------+--------+--------+--------+--------+--------|--------+--------|--------+--------+--------+--------+--------+--------
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_RCTL, _______, _______, _______
  ),                                                                     // = HANGA (KC_LNG2)
  [_MOUSE] = LAYOUT(
    KC_WHOM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_WHOM,
    KC_MEH,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_BTN1, XXXXXXX, LTO_BS,  KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
    LTG_MUS, C(KC_Y), C(KC_X), C(KC_C), C(KC_Z), C(KC_V), XXXXXXX, XXXXXXX, C(KC_V), C(KC_Z), C(KC_C), C(KC_X), C(KC_Y), XXXXXXX,
  //--------+--------+--------+--------+--------+--------|--------+--------|--------+--------+--------+--------+--------+--------
                      KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN4,                   KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN3
  ),

  [_FUNC] = LAYOUT(
    RESET,   KC_F12,  KC_F11,  KC_F10,  KC_F9,   _______,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, XXXXXXX,
    XXXXXXX, KC_F4,   KC_F3,   KC_F2,   KC_F1,   _______, XXXXXXX, _______, XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_F8,   KC_F7,   KC_F6,   KC_F5,   _______, XXXXXXX, _______, XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, XXXXXXX,
  //--------+--------+--------+--------+--------+--------|--------+--------|--------+--------+--------+--------+--------+--------
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};


// Encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:  // Left Upper Knob
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;

        case 1:  // Left Lower Knob
            if (clockwise) {
                tap_code(KC_WH_U);
            } else {
                tap_code(KC_WH_D);
            }
            break;

        default:
            break;
    }

    return true;
}


// Tap-Hold Config
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_F_SPC:
        case L_E_ESC:
        case L_E_BSP:
        case L_F_DEL:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_N_ENT:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_N_ENT:
            return true;
        default:
            return false;
    }
}


// Combos
#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}
#endif

#ifdef COMBO_SHOULD_TRIGGER
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
        case _NUMBER:
            return true;

        default:
            return false;
    }
}
#endif


// Caps Word
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_QUOT:
        case KC_SLSH:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
