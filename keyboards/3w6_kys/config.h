#pragma once

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_SPEED 921600
#define USB_VBUS_PIN GP19
#define EE_HANDS
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_EFFECT_BREATHING + 2
    #define RGBLIGHT_DEFAULT_HUE 152
    #define RGBLIGHT_DEFAULT_SAT 232
    #define RGBLIGHT_DEFAULT_VAR 255
    #define RGBLIGHT_DEFAULT_SPD 2
#endif


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define TAPPING_TERM 190

#define DEBOUNCE 10
