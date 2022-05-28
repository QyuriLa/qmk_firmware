#pragma once

#define MASTER_RIGHT
#define OLED_FONT_H "./glcd-mod.c" // "keyboards/crkbd/lib/glcdfont.c"

// Tap Hold
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_FORCE_HOLD

// Auto Shift
#define AUTO_SHIFT_TIMEOUT 150
#define RETRO_SHIFT 300
#define NO_AUTO_SHIFT_NUMERIC

// Combos
#define COMBO_VARIABLE_LEN
#define EXTRA_SHORT_COMBOS
#define COMBO_TERM 15
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_SHOULD_TRIGGER

// etc.
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 8
#define CAPS_WORD_IDLE_TIMEOUT 10000

// Squeezing
#define LAYER_STATE_16BIT
