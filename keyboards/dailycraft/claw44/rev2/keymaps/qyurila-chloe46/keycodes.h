#pragma once

// Layer-Tap
#define L_F_ESC LT(_FUNC,   KC_ESC)
#define L_E_TAB LT(_EXTEND, KC_TAB)
#define L_N_ENT LT(_NUMBER, KC_ENT)

#define L_E_BSP LT(_EXTEND, KC_BSPC)
#define L_F_DEL LT(_FUNC,   KC_DEL)
#define LOS_MOD OSL(_MODEXT)

// Layer Toggle
#define LTO_BS  TO(_BASE)
#define LTO_GM  TO(_GAME)
#define LTG_ARW TG(_ARROW)
#define LTG_NPD TG(_NUMPAD)
#define LTG_MUS TG(_MOUSE)
#define LTG_LCK TG(_LOCK)

// Mod-Tap
// Home Row
#define M_GUI_A LGUI_T(KC_A)
#define M_ALT_R LALT_T(KC_R)
#define M_SFT_S LSFT_T(KC_S)
#define M_CTL_T LCTL_T(KC_T)
#define M_CTL_N LCTL_T(KC_N)
#define M_SFT_E LSFT_T(KC_E)
#define M_ALT_I LALT_T(KC_I)
#define M_GUI_O LGUI_T(KC_O)

#define M_GUI_4 LGUI_T(KC_4)
#define M_ALT_3 LALT_T(KC_3)
#define M_SFT_2 LSFT_T(KC_2)
#define M_CTL_1 LCTL_T(KC_1)
#define M_CTL_0 LCTL_T(KC_0)
#define M_SFT_7 LSFT_T(KC_7)
#define M_ALT_8 LALT_T(KC_8)
#define M_GUI_9 LGUI_T(KC_9)

// Swap Hands
// #define SH_TAB  SH_T(KC_TAB)
// #define SH_RALT SH_T(KC_RALT)

// One-Shot Mod
// #define OSM_SFT OSM(MOD_LSFT)
// #define OSM_ALT OSM(MOD_LALT)
// #define OSM_CTL OSM(MOD_LCTL)

// etc.
// #define CTL_MNS C(KC_MINS)
// #define CTL_EQL C(KC_EQL)

#define G_GRV   G(KC_GRV)
#define S_COMM  S(KC_COMM)
#define A_DOT   A(KC_DOT)
#define G_SLSH  G(KC_SLSH)
#define G_SCLN  G(KC_SCLN)
#define G_QUOT  G(KC_QUOT)
