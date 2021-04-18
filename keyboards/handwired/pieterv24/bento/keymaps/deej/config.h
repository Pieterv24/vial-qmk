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

#pragma once

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

#ifdef VIAL_ENABLE
    #define VIAL_KEYBOARD_UID {0x45, 0x23, 0x99, 0x87, 0xCC, 0x99, 0x8F, 0x1D}

    #define VIAL_ENCODER_DEFAULT { \
        USER00, USER01, \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
    }
#endif
