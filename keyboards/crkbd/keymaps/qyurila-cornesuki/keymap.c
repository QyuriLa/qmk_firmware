#include QMK_KEYBOARD_H
#include "oled.c"
#include "layers.h"
#include "keycodes.h"
#include "g/keymap_combo.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    SH_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, SH_BSPC,
    KC_GRV,  M_GUI_A, M_ALT_R, M_SFT_S, M_CTL_T, KC_G,      KC_M,    M_CTL_N, M_SFT_E, M_ALT_I, M_GUI_O, KC_QUOT,
    KC_NUHS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                               L_F_DEL, L_E_ESC, L_N_TAB,   L_E_ENT, L_N_SPC, KC_BSPC
  ),

  [_UTIL] = LAYOUT_split_3x6_3(
    SH_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, SH_BSPC,
    CTL_GRV, M_GUI_A, M_ALT_R, M_SFT_S, M_CTL_T, KC_G,      KC_M,    M_CTL_N, M_SFT_E, M_ALT_I, M_GUI_O, KC_QUOT,
    KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, L_TG_AR,
                               L_F_DEL, L_E_SPC, L_N_ENT,   L_E_ENT, L_N_SPC, KC_BSPC
  ),
  [_GAME] = LAYOUT_split_3x6_3(
    SH_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN, SH_BSPC,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, L_TG_AR,
                               KC_LALT, KC_SPC,  KC_TAB,    L_E_ENT, L_N_SPC, L_F_DEL
  ),
  [_ARROW] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,      _______, _______, KC_UP,   _______, _______, KC_BSPC,
    _______, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,      _______, _______, _______, _______, _______, L_TG_AR,
                               _______, _______, _______,   _______, _______, _______
  ),

  [_NUMBER] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_DOT,  KC_0,    KC_9,    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, M_GUI_4, M_ALT_3, M_SFT_2, M_CTL_1, XXXXXXX,   XXXXXXX, M_CTL_0, M_SFT_7, M_ALT_8, M_GUI_9, L_TG_NP,
    XXXXXXX, KC_8,    KC_7,    KC_6,    KC_5,    XXXXXXX,   XXXXXXX, KC_6,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                               KC_BSPC, KC_SPC,  KC_ENT,    KC_ENT,  KC_SPC,  KC_BSPC
  ),
  [_NUMPAD] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_PDOT, KC_PCMM, KC_PEQL, XXXXXXX,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_CALC,
    XXXXXXX, KC_LGUI, OSM_ALT, OSM_SFT, OSM_CTL, XXXXXXX,   KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, L_TG_NP,
    XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, XXXXXXX,   KC_SPC,  KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX,
                               L_F_DEL, L_E_ESC, KC_TAB,    KC_PENT, KC_P0,   KC_BSPC
  ),

  [_EXTEND] = LAYOUT_split_3x6_3(                           // HANJ
    XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,   KC_RCTL, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NUM,
    L_TG_MS, KC_LGUI, OSM_ALT, OSM_SFT, OSM_CTL, KC_BTN1,   KC_APP,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_SCRL,
    XXXXXXX, C(KC_Y), C(KC_X), C(KC_C), C(KC_Z), C(KC_V),   KC_PSCR, CAPSWRD, KC_CAPS, KC_INS,  KC_DEL,  KC_PAUS,
                               XXXXXXX, XXXXXXX, XXXXXXX,   KC_ENT,  KC_SPC,  KC_BSPC
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
    KC_WHOM, KC_WH_U, KC_BTN4, KC_BTN1, KC_BTN5, XXXXXXX,   XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
    L_TG_MS, KC_WH_D, KC_LALT, KC_LSFT, KC_LCTL, KC_BTN1,   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
    KC_LGUI, C(KC_Y), C(KC_X), C(KC_C), C(KC_Z), C(KC_V),   C(KC_V), C(KC_Z), C(KC_C), C(KC_X), C(KC_Y), XXXXXXX,
                               KC_BTN3, KC_BTN1, KC_BTN2,   KC_BTN2, KC_BTN1, KC_BTN3
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
    KC_SLEP, KC_F12,  KC_F11,  KC_F10,  KC_F9,   XXXXXXX,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_PWR,
    L_TG_MS, KC_F4,   KC_F3,   KC_F2,   KC_F1,   XXXXXXX,   XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, L_TG_NP,
    L_TG_LK, KC_F8,   KC_F7,   KC_F6,   KC_F5,   XXXXXXX,   XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, DEBUG,
                               KC_RALT, PB_1,    PB_2,      PB_3,    PB_4,    KC_RALT
  ),
  [_LOCK] = LAYOUT_split_3x6_3(
    L_TG_LK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, L_TG_LK,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),
};


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_F_DEL:
        case L_N_TAB:
        case L_E_ENT:
        case L_N_SPC:
        case L_E_SPC:
        case L_N_ENT:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_E_ESC:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


#ifdef AUTO_SHIFT_TIMEOUT
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_GAME)) {
        return false;
    }
#    ifdef RETRO_SHIFT
    if (IS_RETRO(keycode) && IS_LAYER_OFF(_NUMBER)) {
        return true;
    }
#    endif
    switch(keycode) {
        case KC_SCLN:
        case KC_DOT:
        case KC_COMM:
        case KC_BSLS:
        case KC_NUHS:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_SCLN: register_code16((!shifted) ? KC_SCLN : KC_HASH); break;
        case KC_DOT : register_code16((!shifted) ? KC_DOT  : KC_EXLM); break;
        case KC_COMM: register_code16((!shifted) ? KC_COMM : KC_AT  ); break;
        case KC_BSLS: register_code16((!shifted) ? KC_PIPE : KC_BSLS); break;
        case KC_NUHS: register_code16((!shifted) ? KC_AMPR : KC_PERC); break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
#    ifdef RETRO_SHIFT
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
#    else
            register_code16(keycode);
#    endif
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_SCLN: unregister_code16((!shifted) ? KC_SCLN : KC_HASH); break;
        case KC_DOT : unregister_code16((!shifted) ? KC_DOT  : KC_EXLM); break;
        case KC_COMM: unregister_code16((!shifted) ? KC_COMM : KC_AT  ); break;
        case KC_BSLS: unregister_code16((!shifted) ? KC_PIPE : KC_BSLS); break;
        case KC_NUHS: unregister_code16((!shifted) ? KC_AMPR : KC_PERC); break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16(keycode & 0xFF);
    }
}
#endif

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}
#endif

#ifdef COMBO_SHOULD_TRIGGER
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // _BASE, _NUMBER, _NUMPAD
    if (IS_LAYER_OFF(_GAME) || combo_index == BS_GAME) {
        return true;
    }
    return false;
}
#endif


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



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // OLED
    if (record->event.pressed) {
        set_keylog(keycode);
    }

  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, (%u, %u), pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    return true;
}
