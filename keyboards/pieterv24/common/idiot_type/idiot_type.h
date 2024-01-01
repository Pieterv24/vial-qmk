// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    CK_STYP = QK_KB_0
};

void set_idiot_type_mode(bool status);

bool process_record_idiot_type(uint16_t keycode, keyrecord_t *record);
