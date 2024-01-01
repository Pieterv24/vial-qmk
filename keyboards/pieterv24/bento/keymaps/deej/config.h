// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

#define VIAL_KEYBOARD_UID {0x4F, 0x93, 0xF2, 0x9E, 0x8E, 0xC3, 0x28, 0x6F}

#define VIAL_UNLOCK_COMBO_ROWS { 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0 }

#ifdef VIAL_ENABLE
    #define VIAL_ENCODER_DEFAULT { \
        USER00, USER01, \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
    }
#endif
