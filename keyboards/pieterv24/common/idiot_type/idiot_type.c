// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "idiot_type.h"

static bool idiotTypeState = false;
static bool isCapital = false;

void set_idiot_type_mode(bool status) {
    idiotTypeState = status;
}

// Add this method after all your record processes
bool process_record_idiot_type(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_STYP:
            if (record->event.pressed) {
                if (idiotTypeState) {
                    isCapital = false;
                }

                idiotTypeState = !idiotTypeState;
            }
            return false;

        case KC_A ... KC_Z:
            if (idiotTypeState && record->event.pressed) {
                if (isCapital) {
                    tap_code16(S(keycode));
                    isCapital = !isCapital;
                    return false;
                } else {
                    isCapital = !isCapital;
                }
            }
            return true;

        case KC_SPC:
            if (idiotTypeState) {
                isCapital = false;
            }

        case KC_BSPC:
            if (idiotTypeState) {
                isCapital = false;
            }
    }

    return true;
}
