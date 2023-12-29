// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "deej.h"

#include QMK_KEYBOARD_H
#include "raw_hid.h"

enum deej_sliders {
    MASTER,
    SPOTIFY,
    GAME,
    MIC
};

// Store deej data
uint16_t currentSlider = MASTER;

/**
 * Send data packet with slider number and slider value to deej
 */
void send_deejData(bool down) {
    uint8_t data[RAW_EPSIZE];
    data[0] = 0xFD;
    data[1] = currentSlider;
    data[2] = down ? 0x00 : 0x01;
    raw_hid_send(data, sizeof(data));
}

// Process custom keycodes
bool process_record_deej(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case DEEJ_VU:
                deej_volu();
                break;
            case DEEJ_VD:
                deej_vold();
                break;
            case DEEJ_MASTER:
                currentSlider = MASTER;
                break;
            case DEEJ_MIC:
                currentSlider = MIC;
                break;
            case DEEJ_SPOTIFY:
                currentSlider = SPOTIFY;
                break;
            case DEEJ_GAME:
                currentSlider = GAME;
                break;
            default:
                return true;
        }
    }
    return true;
}

// Send volume up to deej
void deej_volu(void) {
    send_deejData(false);
}

// Send volume down to deej
void deej_vold(void) {
    send_deejData(true);
}

// If vial is not enabled, define encoder behavior
#ifndef VIAL_ENABLE
    void encoder_update_deej(uint8_t index, bool clockwise) {
        if (index == 0) {
            if (clockwise) {
                deej_volu();
            } else {
                deej_vold();
            }
        }
    }
#endif
