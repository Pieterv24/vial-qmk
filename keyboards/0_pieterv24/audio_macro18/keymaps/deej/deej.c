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
#include "deej.h"

#include QMK_KEYBOARD_H
#include "raw_hid.h"

enum deej_sliders {
    MASTER,
    MUSIC,
    GAME,
    VC,
    MIC
};

/**
 * Send data packet with slider number and slider value to deej
 */
void send_deejData(bool down, uint16_t slider) {
    uint8_t data[RAW_EPSIZE];
    data[0] = 0xFD;
    data[1] = slider;
    data[2] = down ? 0x00 : 0x01;
    raw_hid_send(data, sizeof(data));
}

// Process custom keycodes
bool process_record_deej(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case DEEJ_MASTER_VD:
                deej_vold(MASTER);
                break;
            case DEEJ_MASTER_VU:
                deej_volu(MASTER);
                break;
            case DEEJ_MUSIC_VD:
                deej_vold(MUSIC);
                break;
            case DEEJ_MUSIC_VU:
                deej_volu(MUSIC);
                break;
            case DEEJ_GAME_VD:
                deej_vold(GAME);
                break;
            case DEEJ_GAME_VU:
                deej_volu(GAME);
                break;
            case DEEJ_VC_VD:
                deej_vold(VC);
                break;
            case DEEJ_VC_VU:
                deej_volu(VC);
                break;
            case DEEJ_MIC_VD:
                deej_vold(MIC);
                break;
            case DEEJ_MIC_VU:
                deej_volu(MIC);
                break;
            default:
                return true;
        }
    }
    return true;
}

// Send volume up to deej
void deej_volu(uint16_t slider) {
    send_deejData(false, slider);
}

// Send volume down to deej
void deej_vold(uint16_t slider) {
    send_deejData(true, slider);
}

// If vial is not enabled, define encoder behavior
#ifndef VIAL_ENABLE
    void encoder_update_deej(uint8_t index, bool clockwise) {
        if (index == 0) {
            if (clockwise) {
                deej_volu(MASTER);
            } else {
                deej_vold(MASTER);
            }
        } else if (index == 0) {
            if (clockwise) {
                deej_volu(MUSIC);
            } else {
                deej_vold(MUSIC);
            }
        } else if (index == 0) {
            if (clockwise) {
                deej_volu(GAME);
            } else {
                deej_vold(GAME);
            }
        } else if (index == 0) {
            if (clockwise) {
                deej_volu(VC);
            } else {
                deej_vold(VC);
            }
        } else if (index == 0) {
            if (clockwise) {
                deej_volu(MIC);
            } else {
                deej_vold(MIC);
            }
        }
    }
#endif
