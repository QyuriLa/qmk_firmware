#pragma once

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
        case _QWERTY:
        case _NUMBER:
        case _NUMPAD:
        case _DOUBLE:
        case _TRIPLE:
            autoshift_enable();
            break;
        default:
            autoshift_disable();
            break;
    }
    return state;
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
#ifdef RETRO_SHIFT
    if (IS_RETRO(keycode)) {
        return true;
    }
#endif
    switch(keycode) {
        // Native
        case KC_TAB:
        case KC_SLSH:
        // Custom
        case KC_2:
        case KC_3:
        case TRP_CMM:
        case KC_DOT:
        case KC_SCLN:
            return true;
    }
    return false;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    if (IS_LAYER_ON(_DOUBLE) || IS_LAYER_ON(_TRIPLE)) {
        uint16_t kc_shift = KC_NO;
        switch (keycode) {
            case KC_DOT:  kc_shift = KC_EXLM; break;
            case KC_SLSH: kc_shift = KC_QUES; break;
            case KC_SCLN: kc_shift = KC_CIRC; break;
            case L_S_GRV: kc_shift = KC_TILD; break;
            case L_S_QUT: kc_shift = KC_DQT;  break;
            default:
                break;
        }
        if (kc_shift != KC_NO) {
            if (shifted) {
                keycode = kc_shift;
            }
            if (IS_LAYER_ON(_TRIPLE)) {
                tap_code16(keycode);
            }
            tap_code16(keycode);
            register_code16(keycode);
            return;
        }
    }
    switch (keycode) {
        case KC_2:    register_code16((!shifted) ? KC_2    : KC_COMM); break;
        case KC_3:    register_code16((!shifted) ? KC_3    : KC_DOT ); break;
        case TRP_CMM: register_code16((!shifted) ? KC_COMM : KC_AT  ); break;
        // Fallback if neither double nor triple not held
        case KC_DOT:  register_code16((!shifted) ? KC_DOT  : KC_EXLM); break;
        case KC_SCLN: register_code16((!shifted) ? KC_SCLN : KC_CIRC); break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
#ifdef RETRO_SHIFT
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
#else
            register_code16(keycode);
#endif
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_2:    unregister_code16((!shifted) ? KC_2    : KC_COMM); break;
        case KC_3:    unregister_code16((!shifted) ? KC_3    : KC_DOT ); break;
        case TRP_CMM: unregister_code16((!shifted) ? KC_COMM : KC_AT  ); break;
        case KC_DOT:  unregister_code16((!shifted) ? KC_DOT  : KC_EXLM); break;
        case KC_SCLN: unregister_code16((!shifted) ? KC_SCLN : KC_CIRC); break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16(keycode & 0xFF);
    }
}
