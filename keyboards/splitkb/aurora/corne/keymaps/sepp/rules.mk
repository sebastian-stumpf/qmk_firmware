BOOTLOADER = caterina
MCU = atmega32u4

ENCODER_ENABLE = no
BACKLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
RGBLIGHT_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
BOOTMAGIC_ENABLE = no
LTO_ENABLE = yes
WPM_ENABLE = yes
CAPS_WORD_ENABLE = yes
SWAP_HANDS_ENABLE = yes

OLED_ENABLE = yes

ifeq ($(OLED_ENABLE),yes)
	SRC += ./oled.c
endif
