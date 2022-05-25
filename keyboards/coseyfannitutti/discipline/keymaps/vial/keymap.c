/* Copyright 2019 COSEYFANNITUTTI
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

enum custom_keycodes {
    KC_STYP = USER00             // Stupid type toggle
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_65_ansi_blocker(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_HOME,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_PGUP,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,   KC_PGDN,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_END,
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                 KC_RALT, MO(1),             KC_LEFT, KC_DOWN,  KC_RIGHT),

  [1] = LAYOUT_65_ansi_blocker(
     /* esc      1        2        3        4       5       6       7       8       9         0        -         =     bkspc       `~  */
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,   KC_TRNS,
     /*  tab      Q       W        E        R        T      Y        U      I        O        P        [         ]        \      delete*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_STYP,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
     /*  caps     A       S        D        F        G      H        J      K        L        ;        '                enter     pg up*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,           KC_MPLY,  KC_TRNS,
     /* shift             Z         X        C       V       B       N      M        ,        .        /        shift     up      pg dn*/
      KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_VOLU,  KC_TRNS,
     /* ctrl     win      alt                              space                    alt      fn                 left     down     right*/
      KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                KC_TRNS, KC_TRNS,            KC_MPRV, KC_VOLD,  KC_MNXT),

  [2] = LAYOUT_65_ansi_blocker(
     /* esc      1        2        3        4       5       6       7       8       9         0        -         =     bkspc       `~  */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
     /*  tab      Q       W        E        R        T      Y        U      I        O        P        [         ]        \      delete*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
     /*  caps     A       S        D        F        G      H        J      K        L        ;        '                enter     pg up*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,
     /* shift             Z         X        C       V       B       N      M        ,        .        /        shift     up      pg dn*/
      KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
     /* ctrl     win      alt                              space                    alt      fn                 left     down     right*/
      KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,  KC_TRNS),

  [3] = LAYOUT_65_ansi_blocker(
     /* esc      1        2        3        4       5       6       7       8       9         0        -         =     bkspc       `~  */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
     /*  tab      Q       W        E        R        T      Y        U      I        O        P        [         ]        \      delete*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
     /*  caps     A       S        D        F        G      H        J      K        L        ;        '                enter     pg up*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,
     /* shift             Z         X        C       V       B       N      M        ,        .        /        shift     up      pg dn*/
      KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
     /* ctrl     win      alt                              space                    alt      fn                 left     down     right*/
      KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,  KC_TRNS)
};

static bool idiot_type = false;
static bool idiot_type_shift = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_STYP:
            if (!record->event.pressed) {
                if (idiot_type) {
                    idiot_type_shift = false;
                }
                idiot_type = !idiot_type;
            }
            return false;
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
            return true;
        case KC_SPC:
            idiot_type_shift = false;
            return true;

        case KC_BSPC:
            idiot_type_shift = false;
            return true;

        default:
            return true;   // Process all other keycodes normally
    }
}
