// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 2

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

#define VIAL_KEYBOARD_UID {0xE1, 0x3D, 0x06, 0x1F, 0x95, 0x41, 0x0E, 0x3A}

#define VIAL_UNLOCK_COMBO_ROWS { 1, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }

#define VIAL_ENCODER_DEFAULT { \
    /* Layer 1 */   USER00, USER01,     USER02, USER03,     USER04, USER05,     USER06, USER07,     USER08, USER09, \
    /* Layer 2 */   KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS \
}
