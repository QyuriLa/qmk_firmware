#include QMK_KEYBOARD_H
#include <stdio.h>
#include "layers.h"


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

void write_highest_layer(uint8_t line) {
    oled_set_cursor(0, line);

    switch (get_highest_layer(layer_state)) {
        case _BASE:   oled_write_P(PSTR(" Base"), false); break;
        case _UTIL:   oled_write_P(PSTR(" Util"), false); break;
        case _GAMING: oled_write_P(PSTR(" Game"), false); break;
        case _ARROW:  oled_write_P(PSTR("Arrow"), false); break;
        case _NUMBER: oled_write_P(PSTR(" Num "), false); break;
        case _NUMPAD: oled_write_P(PSTR(" NPad"), false); break;
        case _EXTEND: oled_write_P(PSTR(" Ext "), false); break;
        case _MOUSE:  oled_write_P(PSTR("Mouse"), false); break;
        case _FUNC:   oled_write_P(PSTR(" Func"), false); break;
        case _LOCK:   oled_write_P(PSTR(" Lock"), false); break;
        default:      oled_write_P(PSTR("     "), false); break;
    }
}


void render_layer_icon(uint8_t line) {
    static const char PROGMEM layer_icons[][96] = {
        // Base: HiTNEX TRAX
        {0,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,248, 16, 32, 64,127,  2,  4,248,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24, 36, 66,129,255,  8,  8,  8,255,  0,  0, 24, 24,  0,  0,255,  4,  8, 16,255,129, 66, 36, 24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0, 31, 32, 64,254,  2,  4,  8, 31,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
        // NumPad
        {0,  0,  0,  0,  0,  0,  0,223, 81, 81, 81,223,  0,223, 81, 81, 81,223,  0,223, 81, 81, 81,223,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,247, 20, 20, 20,247,  0,247, 20, 20, 20,247,  0,247, 20, 20, 20,247,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,125, 69, 69, 69, 69, 68, 69, 69, 69, 69,125,  0,127, 64, 64, 64,127,  0,  0,  0,  0,  0,  0,  0,  0,},
        // Mouse
        {0,  0,  0,  0,  0,  8,136, 73, 34,  0,248, 16, 34, 73,136,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,  0,  0,  0,  0,  1,  2,  4,  8, 16, 32, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 63, 16,  8,  4,  2,  6, 24, 35, 45, 17,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,},
        // Lock
        {0,  0,  0,  0,  0,  0,  0,  0,248,  4,  2,  1,  1,  1,  1,  1,  1,  1,  1,  2,  4,248,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,254,  2,  2,  3,  2,  2,  2,  2,  2,194,194,  2,  2,  2,  2,  2,  3,  2,  2,254,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,127, 64, 64, 64, 64, 64, 64, 64, 64, 67, 67, 64, 64, 64, 64, 64, 64, 64, 64,127,  0,  0,  0,  0,  0,  0,  0,},
        // Gaming
        {0,  0,  0,  0,  0,  0,  0,128, 64, 64, 64, 64, 70, 73, 73, 73,113, 64, 64, 64, 64, 64, 64, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,  3,  0, 24, 24,126,126, 24, 24,  0,  0,  0,  0, 24, 24,102,102, 24, 24,  0,  3,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 32, 32, 32, 16,  8,  4,  2,  2,  2,  2,  2,  2,  2,  2,  4,  8, 16, 32, 32, 32, 31,  0,  0,  0,  0,  0,},
        // Arrow
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,  1, 61, 65, 61, 65, 61,  1,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,  4,228, 84, 84, 84,228,  4,252,  0,253,  5, 37, 85, 85, 85,149,  5,253,  0,252,  4,244, 20, 20, 20,228,  4,252,  0,  0,  0,  7,  4,  5,  4,  4,  4,  5,  4,  7,  0,  7,  4,  5,  5,  5,  5,  4,  4,  7,  0,  7,  4,  5,  5,  5,  5,  4,  4,  7,  0,  0,},
    };

    oled_set_cursor(0, line);

    uint8_t layer = 0;
    if      (layer_state_is(_ARROW))  { layer = 5; }
    else if (layer_state_is(_GAMING)) { layer = 4; }
    else if (layer_state_is(_UTIL)) { layer = 4; }
    else if (layer_state_is(_LOCK))   { layer = 3; }
    else if (layer_state_is(_MOUSE))  { layer = 2; }
    else if (layer_state_is(_NUMPAD)) { layer = 1; }
    else                              { layer = 0; }
    oled_write_raw_P(layer_icons[layer], sizeof(layer_icons[0]));
}


static char keylog_str[2] = " \n";

static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',   1,   2,   3,   4,   5, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/',   6,   8,   8,   8,   8,   8,   8,   // 3x
      8,   8,   8,   8,   8,   8,   7,  20, 128,  10,  12,  14,  11,  13,  15,  16,  // 4x
     17,  18,  19,  20,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,  // 5x
      9,   9,   9,   9,'\\',  21, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,  // 6x
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,  // 7x
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,  // 8x
    128, 128, 128, 128, 128, 'N', 'N', 'J', 'J', 'J', 'J', 'J', 'J', 128, 128, 128,  // 9x
    'K', 'H', 'K', 'H', 'Z',  26,  27,  26,  29,  29,  29, 128, 128,  30,  31, 128,  // Ax
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
     22,  23,  24,  25,  22,  23,  24,  25, ' ', ' ', ' ', ' ', ' ',  28,  28,  28,  // Ex
     28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28, ' ', ' '        // Fx
};

void set_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) ||
            (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode >= 0xFF) {
        keycode = 0;
    }

    if (keycode < 0xFF) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }
}

void write_keylog(uint8_t line) {
    oled_set_cursor(2, line);
    oled_write(keylog_str, false);
}


void render_mod_ctrl(void) {
    static const char PROGMEM font_ctrl[3] = {0x85, 0x86, 0};
    oled_write_P(font_ctrl, false);
};

void render_mod_alt(void) {
    static const char PROGMEM font_alt[3] = {0x88, 0x89, 0};
    oled_write_P(font_alt, false);
};

void render_mod_shift(void) {
    static const char PROGMEM font_shift[3] = {0xA5, 0xA6, 0};
    oled_write_P(font_shift, false);
};

void render_mod_gui(void) {
    static const char PROGMEM font_gui[3] = {0xA8, 0xA9, 0};
    oled_write_P(font_gui, false);
};


void render_mod_status(uint8_t line1, uint8_t line2) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();

    oled_set_cursor(0, line1);
    (modifiers & MOD_MASK_CTRL) ? render_mod_ctrl() : oled_write_P(PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    (modifiers & MOD_MASK_ALT) ? render_mod_alt() : oled_write_P(PSTR("  "), false);


    oled_set_cursor(0, line2);
    (modifiers & MOD_MASK_SHIFT) ? render_mod_shift() : oled_write_P(PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    (modifiers & MOD_MASK_GUI) ? render_mod_gui() : oled_write_P(PSTR("  "), false);
}


void render_logo(uint8_t line) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0
    };

    oled_set_cursor(0, line);
    oled_write_P(crkbd_logo, false);
    oled_write_P(PSTR("corne"), false);
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo(0);
        write_keylog(6);
        render_mod_status(5, 7);
        render_layer_icon(9);
        write_highest_layer(12);
    }
    return false;
}

/*
qmk compile
cp crkbd_rev1_qyurila-cornesuki.hex /mnt/d/Keyboard

*/