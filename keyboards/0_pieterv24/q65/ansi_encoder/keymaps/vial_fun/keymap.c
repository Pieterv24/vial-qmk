// Copyright 2023 Pieter Verweij (@Pieterv24)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keychron_common.h"

// clang-format off
enum layers{
    BASE,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_73(
        KC_MUTE,     QK_GESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_HOME,
        MC_0,        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
        MC_1,        KC_CAPS,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PGDN,
        MC_2,        KC_LSFT,            KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_END,
        MC_3,        KC_LCTL,  KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RGUI,  MO(_FN1), KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_73(
        _______,    _______, KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL ,          _______,
        _______,    _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,    _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,            KC_MPLY,          _______,
        _______,    _______,            _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, KC_VOLU, _______,
        _______,    _______, _______,   _______,                              _______,                            _______,  _______,  _______,  KC_MPRV, KC_VOLD, KC_MNXT),

    [_FN2] = LAYOUT_ansi_73(
        _______,    _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,    _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,    _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,    _______,            _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______, _______,
        _______,    _______, _______,   _______,                              _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN3] = LAYOUT_ansi_73(
        _______,    _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,    _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,    _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,    _______,            _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______, _______,
        _______,    _______, _______,   _______,                              _______,                            _______,  _______,  _______,  _______, _______, _______)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1] = { ENCODER_CCW_CW(_______, _______)},
    [_FN2] = { ENCODER_CCW_CW(_______, _______)},
    [_FN3] = { ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE

static bool idiot_type = false;
static bool idiot_type_shift = false;

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        idiot_type = active;
        if (idiot_type) {
            idiot_type_shift = false;
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
            if (idiot_type && record->event.pressed && !(get_mods() & MOD_MASK_CSAG) && !(get_oneshot_mods() & MOD_MASK_CSAG) ) {
                if (idiot_type_shift) {
                    tap_code16(S(keycode));
                    idiot_type_shift = !idiot_type_shift;
                    return false;
                } else {
                    idiot_type_shift = !idiot_type_shift;
                }
            }
            return true; // Continue processing keypress
        case KC_SPC:
            idiot_type_shift = false;
            return true; // Continue processing keypress

        case KC_BSPC:
            idiot_type_shift = false;
            return true; // Continue processing keypress
    }

    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}
