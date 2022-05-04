#include QMK_KEYBOARD_H
#include <stdio.h>
#include "layers.h"

static const char PROGMEM layer_names[][6] = {
    " Def ", " Swap", " Game", "Arrow",
    " Sym ", " Num ", " Func", " Lock",
    " Ext ", "Mouse", "Media", "     ",
};

static const char PROGMEM layer_icons[][11] = {
    [_BASE] = {
        0x00, 0x85, 0x86, 0x87, 0x00,
        0x00, 0xA5, 0xA6, 0xA7, 0x00, 0x00
    },
    [_NUMPAD] = {
        0x00, 0x88, 0x89, 0x8A, 0x00,
        0x00, 0xA8, 0xA9, 0xAA, 0x00, 0x00
    },
    [_MOUSE] = {
        0x00, 0x8B, 0x8C, 0x8D, 0x00,
        0x00, 0xAB, 0xAC, 0xAD, 0x00, 0x00
    },
    [_LOCK] = {
        0x00, 0x8E, 0x8F, 0x90, 0x00,
        0x00, 0xAE, 0xAF, 0xB0, 0x00, 0x00
    },
    [_GAMING] = {
        0x00, 0xC5, 0xC6, 0xC7, 0x00,
        0x00, 0xE5, 0xE6, 0xE7, 0x00, 0x00
    },
    [_ARROW] = {
        0x00, 0xC8, 0xC9, 0xCA, 0x00,
        0x00, 0xE8, 0xE9, 0xEA, 0x00, 0x00
    },
};


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }
    return OLED_ROTATION_180;
}


void write_highest_layer(uint8_t line) {
    oled_set_cursor(0, line);
    uint8_t layer = get_highest_layer(layer_state);
    if (layer <= sizeof(layer_names) / sizeof(layer_names[0])) {
        oled_write_P(layer_names[layer], false);
    } else {
        oled_write_P(PSTR("undef"), false);
    }
}


void render_layer_icon(uint8_t line) {
    oled_set_cursor(0, line);
    uint32_t icons_len = sizeof(layer_icons) / sizeof(layer_icons[0]);
    for (uint32_t i = icons_len; i >= 0; i--) {
        if (layer_icons[i] && (i & layer_state)) {
            oled_write_P(layer_icons[i], false);
            break;
        }
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(
        keylog_str, sizeof(keylog_str), "%dx%d, k%2d:\n%c",
        record->event.key.row, record->event.key.col, keycode, name
    );
}

void write_keylog(uint8_t line) {
    oled_set_cursor(0, line);
    oled_write(keylog_str, false);
}


void render_logo(uint8_t line) {
    oled_set_cursor(0, line);
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0x00
    };
    oled_write_ln_P(crkbd_logo, false);
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo(0);
        // write_highest_layer(4);
        // render_layer_icon(6);
        // write_keylog(10);
    }
    return false;
}

/*
qmk compile
cp crkbd_rev1_qyurila-cornesuki.hex /mnt/d/Keyboard

*/