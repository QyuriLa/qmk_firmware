#pragma once

// Layer-Tap
#define L_E_ENT LT(_EXTEND, KC_ENT)
#define L_N_TAB LT(_NUMBER, KC_TAB)
#define L_P_ESC LT(_NUMPAD, KC_ESC)

#define L_S_GRV LT(_SWAP,   KC_GRV)
#define L_S_QUT LT(_SWAP,   KC_QUOT)
#define L_M_RAL LT(_MODEXT, KC_RALT)

#define LMO_EXT TG(_EXTEND)
#define LMO_NUM MO(_NUMBER)
#define LMO_MOD MO(_MODEXT)
#define LMO_CFG MO(_CONFIG)

// Layer Toggle
#define LTO_BS  TO(_BASE)
#define LTO_GM  TO(_GAME)
#define LTO_ARW TO(_ARROW)
#define LTG_EXT TG(_EXTEND)
#define LTG_NPD TG(_NUMPAD)
#define LTG_LCK TG(_LOCK)

// Home Row Mod-Tap
#define M_GUI_A LGUI_T(KC_A)
#define M_ALT_R LALT_T(KC_R)
#define M_SFT_S LSFT_T(KC_S)
#define M_CTL_T LCTL_T(KC_T)
#define M_CTL_N LCTL_T(KC_N)
#define M_SFT_E LSFT_T(KC_E)
#define M_ALT_I LALT_T(KC_I)
#define M_GUI_O LGUI_T(KC_O)

// Double & Triple Mod-Tap
#define DBL_D   LT(_DOUBLE, KC_D)
#define DBL_H   LT(_DOUBLE, KC_H)
#define TRP_C   LT(_TRIPLE, KC_C)
#define TRP_CMM LT(_TRIPLE, KC_COMM)

// ModExt Layer
#define G_GRV   G(KC_GRV)
#define S_COMM  S(KC_COMM)
#define A_DOT   A(KC_DOT)
#define G_SLSH  G(KC_SLSH)
#define G_SCLN  G(KC_SCLN)
#define G_QUOT  G(KC_QUOT)

// Config Layer
#define LDF_QTY DF(_QWERTY)
#define LDF_CMK DF(_BASE)


// Custom Keycodes
enum my_keycodes {
    // Left hand combos
    CM_EQL = SAFE_RANGE,
    CM_MINS,
    CM_PLUS,
    CM_PERC,
    CM_AMPR,
    CM_ASTR,
    // Right hand combos
    CM_COLN,
    CM_UNDS,
    CM_HASH,
    CM_BSLS,
    CM_PIPE,
    CM_DLR,
};
