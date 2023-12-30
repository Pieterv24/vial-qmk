// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define VIAL_KEYBOARD_UID {0x55, 0x83, 0x0A, 0xB3, 0xA9, 0x18, 0xB7, 0x84}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 11 }

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define VIAL_ENCODER_DEFAULT { \
    KC_VOLD, KC_VOLU,       KC_LEFT, KC_RIGHT, \
    KC_TRNS, KC_TRNS,       KC_UP, KC_DOWN, \
    KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS \
}
