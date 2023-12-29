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

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

#define VIAL_KEYBOARD_UID {0xAC, 0x44, 0x9B, 0x4C, 0x46, 0xED, 0xE5, 0xAA}

#define VIAL_UNLOCK_COMBO_ROWS { 1, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }

#define VIAL_ENCODER_DEFAULT { \
    /* Layer 1 */   USER00, USER01,     USER02, USER03,     USER04, USER05,     USER06, USER07,     USER08, USER09, \
    /* Layer 2 */   KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS \
}
