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
#include QMK_KEYBOARD_H
#include "raw_hid.h"

#define RAW_EPSIZE 32

enum deej_keycodes {
    // Use custom keycodes if via is enabled
#ifdef VIA_ENABLE
    DEEJ_VD = USER00,
#else
    DEEJ_VD = SAFE_RANGE,
#endif
    DEEJ_VU,
    DEEJ_MASTER,
    DEEJ_SPOTIFY,
    DEEJ_GAME,
    DEEJ_MIC
};

enum deej_sliders {
    MASTER,
    SPOTIFY,
    GAME,
    MIC,
    SLIDER_COUNT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        DEEJ_MASTER, DEEJ_MIC, _______,
        DEEJ_SPOTIFY, DEEJ_GAME, _______
    ),
    [1] = LAYOUT(
        _______, _______, _______,
        _______, _______, _______
    ),
};

// Store deej data
uint16_t currentSlider = MASTER;
uint16_t deejVolumes[SLIDER_COUNT];


// Receive current slider status from deej
void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    if (data[0] == 0x03 && data[1] == 0xFF) {
        uint8_t slider = data[2];
        uint16_t volume = data[3] << 8 | data[4];

        deejVolumes[slider] = volume;
    }
}

/**
 * Send data packet with slider number and slider value to deej
 */
void send_deejData(void) {
    uint8_t data[RAW_EPSIZE];
    data[0] = 0xFD;
    data[1] = currentSlider;
    data[2] = (deejVolumes[currentSlider] >> 8) & 0xFF;
    data[3] = deejVolumes[currentSlider] & 0xFF;
    raw_hid_send(data, sizeof(data));
}

// Send volume up to deej
void deej_volu(void) {
    if (deejVolumes[currentSlider] + 5 < 100) {
        deejVolumes[currentSlider] += 5;
    } else {
        deejVolumes[currentSlider] = 100;
    }
    send_deejData();
}

// Send volume down to deej
void deej_vold(void) {
    if (deejVolumes[currentSlider] >= 5) {
        deejVolumes[currentSlider] -= 5;
    } else {
        deejVolumes[currentSlider] = 0;
    }
    send_deejData();
}

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    return true;
}

// If vial is not enabled, define encoder behavior
#ifndef VIAL_ENABLE
    void encoder_update_user(uint8_t index, bool clockwise) {
        if (index == 0) {
            if (clockwise) {
                deej_volu();
            } else {
                deej_vold();
            }
        }
    }
#endif
