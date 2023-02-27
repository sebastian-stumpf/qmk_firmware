#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_A,       KC_B,    KC_C,    KC_D,    KC_E,    KC_F,                         KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
      KC_M,       KC_N,    KC_O,    KC_P,    KC_Q,    KC_R,                         KC_S,    KC_T,    KC_U,    KC_V,    KC_X,    KC_Y,
      KC_Z,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_6,       KC_7,      KC_8,    KC_9,    KC_0,    KC_DOT,  KC_SLSH, KC_MINS,
      S(KC_A),    S(KC_B), S(KC_C), S(KC_D), S(KC_E), S(KC_F),                      S(KC_G), S(KC_H), S(KC_I), S(KC_J), S(KC_K), S(KC_L)
  )
};
