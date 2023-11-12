#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layers { BASE, SYM, NUM, FUN };

#define SPC_FUN LT(SYM, KC_SPC)
#define INS_MOD LSA(KC_INS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,         DE_Z,    DE_U,     DE_I,    DE_O,    DE_P,     KC_BSPC,
        KC_TAB,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,         DE_H,    DE_J,     DE_K,    DE_L,    DE_HASH,  KC_DEL,
        KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,         DE_N,    DE_M,     DE_COMM, DE_DOT,  DE_MINS,  KC_ENTER,
        KC_LCTL, KC_LALT, KC_LGUI, MO(NUM), MO(FUN),       SPC_FUN,         MO(SYM),  KC_LEFT, KC_UP,   KC_DOWN,  KC_RIGHT
    ),
    [SYM] = LAYOUT(
        _______, DE_AT,   DE_LPRN, DE_RPRN, DE_UDIA, DE_SS,        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, DE_BSLS, DE_LCBR, DE_RCBR, DE_ADIA, DE_ODIA,      XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, DE_EURO, DE_LBRC, DE_RBRC, DE_CIRC, DE_GRV,       XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, _______, _______, _______, _______,       _______,         _______,  _______, _______,  _______, _______
    ),
    [NUM] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, C(KC_PGUP), C(KC_PGDN), XXXXXXX,           DE_TILD, DE_7,     DE_8,    DE_9,    XXXXXXX,  _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,           DE_PIPE, DE_4,     DE_5,    DE_6,    DE_LABK,  _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,           DE_QUES, DE_1,     DE_2,    DE_3,    DE_PLUS,  _______,
        _______, _______, _______, _______,    _______,          _______,               _______, DE_0,     _______, _______, _______
    ),
    [FUN] = LAYOUT(
        _______, CW_TOGG, KC_PGUP, KC_HOME, KC_UP,   KC_END,       KC_VOLU, KC_F7,    KC_F8,   KC_F9,   KC_F12,  _______,
        _______, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,     KC_VOLD, KC_F4,    KC_F5,   KC_F6,   KC_F11,  _______,
        _______, KC_INS,  INS_MOD, KC_MPRV, KC_MPLY, KC_MNXT,      KC_MUTE, KC_F1,    KC_F2,   KC_F6,   KC_F10,  _______,
        _______, _______, _______, _______, _______,       _______,         _______,  _______, _______, _______, _______
    )
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
        case DE_MINS:
        case DE_UDIA:
        case DE_ADIA:
        case DE_ODIA:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;
    }
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Test "), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
