#pragma once

#define MASTER_RIGHT
#define OLED_FONT_H "./glcd-mod.c" // "keyboards/crkbd/lib/glcdfont.c"

// Tap Hold
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_FORCE_HOLD

// Auto Shift
#define AUTO_SHIFT_TIMEOUT 125
#define RETRO_SHIFT 300

// Combos
#define COMBO_VARIABLE_LEN
#define EXTRA_SHORT_COMBOS
#define COMBO_TERM 20
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_SHOULD_TRIGGER

// etc.
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 8

// Squeezing
#define LAYER_STATE_16BIT
