#pragma once

#include QMK_KEYBOARD_H

#define RAW_EPSIZE 32

/**
 * Define the custom keycodes
 * If you're going to define your own additional custom keycodes,
 * Please use 'NEW_SAFE_RANGE' instead of 'USER00' or 'SAFE_RANGE'
 */
enum deej_keycodes {
    // Use custom keycodes if via is enabled
#ifdef VIA_ENABLE
    DEEJ_MASTER_VD = USER00,
#else
    DEEJ_MASTER_VD = SAFE_RANGE,
#endif
    DEEJ_MASTER_VU,
    DEEJ_MUSIC_VD,
    DEEJ_MUSIC_VU,
    DEEJ_GAME_VD,
    DEEJ_GAME_VU,
    DEEJ_VC_VD,
    DEEJ_VC_VU,
    DEEJ_MIC_VD,
    DEEJ_MIC_VU,
    NEW_SAFE_RANGE
};

void send_deejData(bool down, uint16_t slider);
bool process_record_deej(uint16_t keycode, keyrecord_t *record);
void deej_volu(uint16_t slider);
void deej_vold(uint16_t slider);

#ifndef VIAL_ENABLE
void encoder_update_deej(uint8_t index, bool clockwise);
#endif
