// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "deej.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_0,   KC_1,   KC_2,   KC_3,   KC_4,
        KC_0,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
        KC_0,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
        KC_0,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5
    ),
    [_FN] = LAYOUT(
        _______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_deej(keycode, record);
}

#ifndef VIAL_ENABLE
    void encoder_update_user(uint8_t index, bool clockwise) {
        encoder_update_deej(index, clockwise);
    }
#endif
