#pragma once

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

#ifdef VIAL_ENABLE
    #define VIAL_ENCODER_DEFAULT { \
        USER00, USER01, \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
    }
#endif
