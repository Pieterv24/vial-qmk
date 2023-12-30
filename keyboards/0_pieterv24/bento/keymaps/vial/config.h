// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define VIAL_KEYBOARD_UID {0xE9, 0x61, 0x85, 0x7C, 0xF5, 0x6D, 0xE3, 0x9D}

#define VIAL_UNLOCK_COMBO_ROWS { 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0 }

#ifdef VIAL_ENABLE
    #define VIAL_ENCODER_DEFAULT { \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
    }
#endif
