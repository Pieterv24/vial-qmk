/* Copyright 2021 Pieterv24
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "deej.h"

enum additionalCodes {
    KC_HELLO = NEW_SAFE_RANGE,
    KC_THERE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        DEEJ_MASTER, DEEJ_MIC, MO(1),
        DEEJ_SPOTIFY, DEEJ_GAME, KC_MPLY
    ),
    [1] = LAYOUT(
        KC_HELLO, _______, _______,
        KC_THERE, _______, _______
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // return process_record_deej(keycode, record);
    switch (keycode) {
        case KC_HELLO:
            if (record->event.pressed) {
                SEND_STRING("Hello");
            }
            return true;
        case KC_THERE:
            if (record->event.pressed) {
                SEND_STRING("There!");
            }
            return true;
        default:
            return process_record_deej(keycode, record);
    }
    return true;
}

#ifndef VIAL_ENABLE
    void encoder_update_user(uint8_t index, bool clockwise) {
        encoder_update_deej(index, clockwise);
    }
#endif
