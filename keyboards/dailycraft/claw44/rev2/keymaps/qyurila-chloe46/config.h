#pragma once

#define MASTER_LEFT

// Encoder
#define ENCODERS_PAD_A { B5, B6 }
#define ENCODERS_PAD_B { B4, B2 }
#define ENCODER_RESOLUTION 4

// Tap Hold
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

// Auto Shift
#define AUTO_SHIFT_TIMEOUT 140
#define RETRO_SHIFT 260
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_SPECIAL

// Combos
#define COMBO_VARIABLE_LEN
#define EXTRA_SHORT_COMBOS
#define COMBO_TERM 20
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_SHOULD_TRIGGER
#define COMBO_ONLY_FROM_LAYER 0

// etc.
// #define MOUSEKEY_INTERVAL 16
// #define MOUSEKEY_MAX_SPEED 8
#define CAPS_WORD_IDLE_TIMEOUT 5000
#define TAP_CODE_DELAY 10

// Squeezing
// #define LAYER_STATE_8BIT
