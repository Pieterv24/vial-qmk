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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _F1,
    _F2,
    _F3
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_F13,     KC_F14,     KC_F15,
        KC_F16,     KC_F17,     KC_F18,
        MO(_F1),    MO(_F2),    MO(_F3)
    ),
    [_F1] = LAYOUT(
        KC_F19, KC_F20, KC_F21,
        KC_F22, KC_F23, KC_F24,
        _______,_______,_______
    ),
    [_F2] = LAYOUT(
        _______,_______,_______,
        _______,_______,_______,
        _______,_______,_______
    ),
    [_F3] = LAYOUT(
        _______,_______,_______,
        _______,_______,_______,
        _______,_______,_______
    )
};
