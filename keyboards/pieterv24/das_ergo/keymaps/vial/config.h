// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define VIAL_KEYBOARD_UID {0x86, 0xC8, 0x1F, 0x60, 0x60, 0xEF, 0x15, 0x09}

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
