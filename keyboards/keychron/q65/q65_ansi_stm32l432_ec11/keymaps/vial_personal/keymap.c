/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
    BASE,
    _FN,
    _FN2,
    _FN3
};

enum custom_keycodes {
    KC_MISSION_CONTROL = USER00,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_FN] =     { ENCODER_CCW_CW(_______, _______)  },
    [_FN2] =    { ENCODER_CCW_CW(_______, _______)  },
    [_FN3] =    { ENCODER_CCW_CW(_______, _______)  }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_73(
        KC_MUTE,     QK_GESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_HOME,
        MACRO00,     KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
        MACRO01,     KC_CAPS,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PGDN,
        MACRO02,     KC_LSFT,            KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_END,
        MACRO03,     KC_LCTL,  KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RGUI,  MO(_FN),  KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN] = LAYOUT_ansi_73(
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
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
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
        default:
            return true;  // Process all other keycodes normally
    }
}
