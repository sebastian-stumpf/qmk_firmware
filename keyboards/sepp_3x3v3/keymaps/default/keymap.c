#include QMK_KEYBOARD_H
#include "sendstring_german.h"

enum custom_keycodes {
    GIT_PULL = SAFE_RANGE,
    GIT_PUSH,
    GIT_STATUS,
    GIT_DIFF,
    GIT_COMMIT,
    GIT_CHECKOUT,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LT(1,KC_MEDIA_PREV_TRACK), KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
        GIT_PUSH,                  GIT_STATUS,          GIT_DIFF,
        GIT_PULL,                  GIT_CHECKOUT,        GIT_COMMIT
    ),
    [1] = LAYOUT(
        XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
        case GIT_PULL:
            SEND_STRING("git pull -p\n");
            break;
        case GIT_PUSH:
            SEND_STRING("git push\n");
            break;
        case GIT_STATUS:
            SEND_STRING("git status\n");
            break;
        case GIT_DIFF:
            SEND_STRING("git diff\n");
            break;
        case GIT_COMMIT:
            SEND_STRING("git commit -m ''"SS_TAP(X_LEFT));
            break;
        case GIT_CHECKOUT:
            SEND_STRING("git checkout ");
            break;
    }
  }
  return true;
}



bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code_delay(KC_VOLU, 10);
    } else {
        tap_code_delay(KC_VOLD, 10);
    }
    return false;
}
