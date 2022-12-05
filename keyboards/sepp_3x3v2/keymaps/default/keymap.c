#include QMK_KEYBOARD_H

enum custom_keycodes {
    SHRUG = SAFE_RANGE
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SHRUG:
        if (record->event.pressed) {
            send_unicode_string("¯\\_(ツ)_/¯");
        }
        break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_J, KC_PGUP, KC_L,
        KC_LEFT, KC_Q, KC_RIGHT,
        TO(1), KC_PGDOWN, KC_ESC
    ),
    [1] = LAYOUT(
        KC_COMMA, KC_UP, KC_DOT,
        SHRUG, KC_I, KC_W,
        TO(0), KC_DOWN, KC_S
    )
};

