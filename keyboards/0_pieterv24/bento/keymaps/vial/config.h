// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define VIAL_KEYBOARD_UID {0xA0, 0xF8, 0x6E, 0xF7, 0xC7, 0x48, 0xFB, 0x33}

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
