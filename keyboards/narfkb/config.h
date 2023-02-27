#pragma once

#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 8
#define MATRIX_COLS 12

#define SPLIT_USB_DETECT
#define USE_SERIAL
#define SOFT_SERIAL_PIN GP0

#define MATRIX_ROW_PINS { GP1, GP2, GP3, GP4 }
#define MATRIX_COL_PINS { GP29, GP28, GP27, GP26, GP15, GP14 }

#define MATRIX_ROW_PINS_RIGHT { GP1, GP2, GP3, GP4 }
#define MATRIX_COL_PINS_RIGHT { GP29, GP28, GP27, GP26, GP15, GP14 }

#define ENCODERS_PAD_A { GP5 }
#define ENCODERS_PAD_B { GP6 }

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
