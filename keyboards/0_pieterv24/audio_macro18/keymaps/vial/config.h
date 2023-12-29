// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 2

#define VIAL_KEYBOARD_UID {0xAC, 0x44, 0x9B, 0x4C, 0x46, 0xED, 0xE5, 0xAA}

#define VIAL_UNLOCK_COMBO_ROWS { 1, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }

#define VIAL_ENCODER_DEFAULT { \
    /* Layer 1 */   KC_A,   KC_B,       KC_C,   KC_D,       KC_E,   KC_F,       KC_G,   KC_H,       KC_I,   KC_J, \
    /* Layer 2 */   KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS \
}
