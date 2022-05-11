#pragma once

#define MASTER_RIGHT

#define OLED_FONT_H "./glcd-mod.c" // "keyboards/crkbd/lib/glcdfont.c"


// Tap Hold
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

// Auto Shift
// #define AUTO_SHIFT_TIMEOUT 150
// #define NO_AUTO_SHIFT_SPECIAL
// #define NO_AUTO_SHIFT_ALPHA
// #define RETRO_SHIFT 500

// Combos
#define COMBO_VARIABLE_LEN
#define EXTRA_SHORT_COMBOS
#define COMBO_TERM 20
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_SHOULD_TRIGGER

// etc.
#define MK_COMBINED

// Squeezing
