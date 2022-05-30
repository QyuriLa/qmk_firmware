#pragma once

// Layer-Tap
#define L_F_DEL LT(_FUNC,   KC_DEL)
#define L_E_ESC LT(_EXTEND, KC_ESC)
#define L_N_TAB LT(_NUMBER,  KC_TAB)
#define L_E_ENT LT(_EXTEND, KC_ENT)
#define L_N_SPC LT(_NUMBER, KC_SPC)

#define L_E_SPC LT(_EXTEND, KC_SPC)
#define L_N_ENT LT(_NUMBER, KC_ENT)

// Layer Toggle
#define L_TG_UT TG(_UTIL)
#define L_TG_GM TG(_GAME)
#define L_TG_AR TG(_ARROW)
#define L_TG_NO TG(_NUMBER)
#define L_TG_NP TG(_NUMPAD)
#define L_TG_MS TG(_MOUSE)
#define L_TG_LK TG(_LOCK)

// Mod-Tap
// Home Row
#define M_GUI_A   LGUI_T(KC_A)
#define M_ALT_R   LALT_T(KC_R)
#define M_SFT_S   LSFT_T(KC_S)
#define M_CTL_T   LCTL_T(KC_T)
#define M_CTL_N   LCTL_T(KC_N)
#define M_SFT_E   LSFT_T(KC_E)
#define M_ALT_I   LALT_T(KC_I)
#define M_GUI_O   LGUI_T(KC_O)

#define M_GUI_4   LGUI_T(KC_4)
#define M_ALT_3   LALT_T(KC_3)
#define M_SFT_2   LSFT_T(KC_2)
#define M_CTL_1   LCTL_T(KC_1)
#define M_CTL_0   LCTL_T(KC_0)
#define M_SFT_7   LSFT_T(KC_7)
#define M_ALT_8   LALT_T(KC_8)
#define M_GUI_9   LGUI_T(KC_9)

// etc.
#define CTL_GRV LCTL_T(KC_GRV)

// Swap Hands
#define SH_ESC  SH_T(KC_ESC)
#define SH_BSPC SH_T(KC_BSPC)

// One-Shot Mod
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
