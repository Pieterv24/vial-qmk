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
#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 2

#define VIAL_KEYBOARD_UID {0xAC, 0x44, 0x9B, 0x4C, 0x46, 0xED, 0xE5, 0xAA}

#define VIAL_UNLOCK_COMBO_ROWS { 1, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }

#define VIAL_ENCODER_DEFAULT { \
    /* Layer 1 */   KC_A,   KC_B,       KC_C,   KC_D,       KC_E,   KC_F,       KC_G,   KC_H,       KC_I,   KC_J, \
    /* Layer 2 */   KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS \
}
