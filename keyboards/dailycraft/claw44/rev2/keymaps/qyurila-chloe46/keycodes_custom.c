#pragma once

void process_double_triple(uint16_t target, bool is_custom) {
    if (IS_LAYER_ON(_TRIPLE)){
        tap_code16(target);
        tap_code16(target);
    } else if (IS_LAYER_ON(_DOUBLE)) {
        tap_code16(target);
    }
    if (is_custom) {
        tap_code16(target);
    }
}

void process_custom_keycodes(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            // Double / Triple Keys
            // NOTE: Auto Shifted keys are handled in autoshift_press_user()
            // Left hand puncs
            case CM_EQL:  process_double_triple(KC_EQL,  true);  break;
            case CM_MINS: process_double_triple(KC_MINS, true);  break;
            case CM_PLUS: process_double_triple(KC_PLUS, true);  break;
            case CM_PERC: process_double_triple(KC_PERC, true);  break;
            case CM_AMPR: process_double_triple(KC_AMPR, true);  break;
            case CM_ASTR: process_double_triple(KC_ASTR, true);  break;
            // Right hand puncs
            case CM_COLN: process_double_triple(KC_COLN, true);  break;
            case CM_UNDS: process_double_triple(KC_UNDS, true);  break;
            case CM_HASH: process_double_triple(KC_HASH, true);  break;
            case CM_BSLS: process_double_triple(KC_BSLS, true);  break;
            case CM_PIPE: process_double_triple(KC_PIPE, true);  break;
            case CM_DLR:  process_double_triple(KC_DLR,  true);  break;
            // etc.
            case KC_BSPC: process_double_triple(KC_BSPC, false); break;
            case KC_DEL:  process_double_triple(KC_DEL,  false); break;
            case L_N_TAB: process_double_triple(KC_TAB,  false); break;
            case L_E_ENT: process_double_triple(KC_ENT,  false); break;
            case KC_SPC:  process_double_triple(KC_SPC,  false); break;
        }
    }
    return;
}
