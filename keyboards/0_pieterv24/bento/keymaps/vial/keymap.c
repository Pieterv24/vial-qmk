// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        _______, _______, MO(1),
        _______, _______, _______
    ),
    [1] = LAYOUT(
        _______, _______, _______,
        _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______,
        _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______,
        _______, _______, _______
    ),
};

#ifndef VIAL_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        return false;
    }
#endif
