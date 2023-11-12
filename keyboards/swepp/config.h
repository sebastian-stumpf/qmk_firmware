#pragma once

#define EE_HANDS

#define USE_SERIAL
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
// #define SERIAL_USART_PIN_SWAP

#define DIRECT_PINS { { GP6, GP5, GP4, GP3, GP2 }, { GP9, GP12, GP13, GP8, GP7 }, { GP22, GP20, GP23, GP21, GP16 }, { NO_PIN, NO_PIN, NO_PIN, GP14, GP15 } }
#define DIRECT_PINS_RIGHT { { GP6, GP5, GP4, GP3, GP2 }, { GP13, GP12, GP9, GP8, GP7 }, { GP22, GP20, GP23, GP21, GP14 }, { GP15, GP16, NO_PIN, NO_PIN, NO_PIN } }

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define TAPPING_TERM 190
// #define IGNORE_MOD_TAP_INTERRUPT
