// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H

#define RAW_EPSIZE 32

/**
 * Define the custom keycodes
 * If you're going to define your own additional custom keycodes,
 * Please use 'NEW_SAFE_RANGE' instead of 'QK_KB_0' or 'SAFE_RANGE'
 */
enum deej_keycodes {
    // Use custom keycodes if via is enabled
#ifdef VIA_ENABLE
    DEEJ_VD = QK_KB_0,
#else
    DEEJ_VD = SAFE_RANGE,
#endif
    DEEJ_VU,
    DEEJ_MASTER,
    DEEJ_SPOTIFY,
    DEEJ_GAME,
    DEEJ_MIC,
    NEW_SAFE_RANGE
};

void send_deejData(bool down);
bool process_record_deej(uint16_t keycode, keyrecord_t *record);
void deej_volu(void);
void deej_vold(void);

#ifndef VIAL_ENABLE
void encoder_update_deej(uint8_t index, bool clockwise);
#endif
