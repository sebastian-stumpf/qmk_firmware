#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE,   KC_MPRV,      KC_MPLY,        KC_MNXT,
        KC_F3,     S(KC_LEFT),   KC_CALC,        S(KC_RIGHT),
        S(KC_F3),  C(KC_LEFT),   LT(1, LCA(KC_L)), C(KC_RIGHT)
    ),
    [1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(LCTL(KC_PLUS));
        } else {
            tap_code16(LCTL(KC_MINUS));
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(ALT_T(KC_RIGHT));
        } else {
            tap_code16(ALT_T(KC_LEFT));
        }
    }
    return false;
}
