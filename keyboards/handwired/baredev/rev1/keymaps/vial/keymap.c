/* Copyright 2021 Fernando "ManoShu" Rodrigues
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

#include "keymap_brazilian_abnt2.h"

enum { 
    LAYER_BASE, 
    LAYER_FUNCTIONS,
    BLANK_LAYER1,
    BLANK_LAYER2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
              KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,              KC_F9,    KC_F10,  KC_F11,   KC_F12,
        /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┤ */
             BR_QUOT,   BR_1,     BR_2,     BR_3,      BR_4,    BR_5,     BR_6,      BR_7,    BR_8,     BR_9,     BR_0,    BR_MINS,  BR_EQL,        KC_BSPC,
        /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┤ */
                KC_TAB,      BR_Q,     BR_W,     BR_E,     BR_R,     BR_T,     BR_Y,     BR_U,     BR_I,     BR_O,     BR_P,    BR_ACUT,  BR_LBRC,      KC_ENT,
        /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬           ┤ */
                  KC_CAPS,      BR_A,     BR_S,      BR_D,    BR_F,     BR_G,     BR_H,     BR_J,     BR_K,     BR_L,    BR_CCED,  BR_TILD,  BR_RBRC,
        /* ├───────────┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─┬─────────┤ */
              KC_LSFT,   BR_BSLS,   BR_Z,     BR_X,     BR_C,     BR_V,     BR_B,     BR_N,     BR_M,    BR_COMM,  BR_DOT,   BR_SCLN,      BR_SLSH,       KC_UP,
        /* ├───────────┼─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┤ */
              KC_LCTL,   KC_LGUI,     KC_LALT,                    LT(LAYER_FUNCTIONS, KC_SPC),                   KC_APP,    KC_DEL,  KC_LEFT,  KC_DOWN,  KC_RGHT
        /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
    ),
    [LAYER_FUNCTIONS] = LAYOUT(
        /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
              RESET,             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  KC_PSCR,  KC_SLCK,  KC_PAUS, 
        /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┤ */
             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,
        /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┤ */
               _______,     KC_MPLY,  KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,
        /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬           ┤ */
                 _______,      KC_MPRV,  KC_MNXT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    
        /* ├───────────┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─┬─────────┤ */
              _______,   _______,  KC_VOLU,  KC_VOLD,  KC_CALC,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,      KC_PGUP, 
        /* ├───────────┼─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┤ */
              _______,    _______,    _______,                                _______,                           _______,   KC_INS,  KC_HOME,  KC_PGDN,  KC_END
        /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
    ),
    [BLANK_LAYER1] = LAYOUT(
        /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
             _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______, 
        /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┤ */
             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,
        /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┤ */
               _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,
        /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬           ┤ */
                 _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    
        /* ├───────────┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─┬─────────┤ */
              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,      _______, 
        /* ├───────────┼─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┤ */
              _______,    _______,    _______,                                _______,                           _______,  _______,  _______,  _______,  _______
        /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */    
    ),
    [BLANK_LAYER2] = LAYOUT(
        /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
             _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______, 
        /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┤ */
             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,
        /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┤ */
               _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,
        /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬           ┤ */
                 _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    
        /* ├───────────┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─┬─────────┤ */
              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,      _______, 
        /* ├───────────┼─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┤ */
              _______,    _______,    _______,                                _______,                           _______,  _______,  _______,  _______,  _______
        /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */    
    )
};