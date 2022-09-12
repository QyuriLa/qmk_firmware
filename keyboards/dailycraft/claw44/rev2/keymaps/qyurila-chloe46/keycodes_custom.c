void double_if_shifted(uint16_t target, keyrecord_t *record) {
    if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT){
            del_mods(MOD_MASK_SHIFT);
            tap_code16(target);
            register_code16(target);
            add_mods(MOD_BIT(KC_LSFT));  // Fine because this keymap doesn't utilize RSFT
        } else {
            register_code16(target);
        }
    } else {
        unregister_code16(target);
    }
}

bool process_custom_keycodes(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Left hands
        case CM_EQL:  double_if_shifted(KC_EQL,  record); return true;
        case CM_MINS: double_if_shifted(KC_MINS, record); return true;
        case CM_PLUS: double_if_shifted(KC_PLUS, record); return true;
        case CM_PERC: double_if_shifted(KC_PERC, record); return true;
        case CM_AMPR: double_if_shifted(KC_AMPR, record); return true;
        case CM_ASTR: double_if_shifted(KC_ASTR, record); return true;
        // Right hands
        case CM_COLN: double_if_shifted(KC_COLN, record); return true;
        case CM_UNDS: double_if_shifted(KC_UNDS, record); return true;
        case CM_HASH: double_if_shifted(KC_HASH, record); return true;
        case CM_BSLS: double_if_shifted(KC_BSLS, record); return true;
        case CM_PIPE: double_if_shifted(KC_PIPE, record); return true;
        case CM_DLR:  double_if_shifted(KC_DLR,  record); return true;
        default:
            return true;
    }
}
