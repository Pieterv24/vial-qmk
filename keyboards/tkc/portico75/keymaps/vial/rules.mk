VIA_ENABLE = yes
VIAL_ENABLE = yes
LTO_ENABLE = yes

COMMAND_ENABLE = no

RGB_MATRIX_ENABLE = yes        # Use RGB matrix
RGB_MATRIX_DRIVER = IS31FL3741
CIE1931_CURVE = yes
VIALRGB_ENABLE = yes

QMK_SETTINGS = no
TAP_DANCE_ENABLE = no
COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no

VIAL_ENCODERS_ENABLE = yes


# project specific files
# SRC += keyboards/wilba_tech/wt_main.c \
#        keyboards/wilba_tech/wt_rgb_backlight.c \
#        quantum/color.c \
#        drivers/led/issi/is31fl3741.c

# QUANTUM_LIB_SRC += i2c_master.c
