#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define A_LT LGUI_T(DE_A)
#define S_LT LALT_T(DE_S)
#define D_LT LCTL_T(DE_D)
#define F_LT LSFT_T(DE_F)
#define J_LT LSFT_T(DE_J)
#define K_LT LCTL_T(DE_K)
#define L_LT LALT_T(DE_L)
#define MINS_LT LGUI_T(DE_MINS)
#define Y_LT ALGR_T(DE_Y)
#define DOT_LT ALGR_T(DE_DOT)

#define INS_MODE LSA(KC_INS)
#define IJ_RUN C(S(KC_F11))

enum layers { BASE, SYM, NUM, FUN, NAV, OTHER };
enum custom_keycodes { SELWORD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,          DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,     KC_BSPC,
        KC_TAB,  A_LT,    S_LT,    D_LT,    F_LT,    DE_G,          DE_H,    J_LT,    K_LT,    L_LT,    MINS_LT,  DE_PLUS,
        DE_LABK, Y_LT,    DE_X,    DE_C,    DE_V,    DE_B,          DE_N,    DE_M,    DE_COMM, DOT_LT,  DE_HASH,  KC_ENT,
                                   MO(NUM), MO(FUN), KC_BSPC,       KC_SPC,  MO(NAV), MO(SYM)
    ),
    [SYM] = LAYOUT_split_3x6_3(
        _______, DE_BSLS, DE_LPRN, DE_RPRN, DE_UDIA, DE_SS,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, DE_QUES, DE_LCBR, DE_RCBR, DE_ADIA, DE_ODIA,       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  XXXXXXX,
        XXXXXXX, XXXXXXX, DE_LBRC, DE_RBRC, DE_CIRC, DE_GRV,        XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX,  _______,
                                   _______, _______, _______,       _______, _______, _______
    ),
    [NUM] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     XXXXXXX,
        XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       DE_PLUS, DE_MINS, DE_ASTR, DE_SLSH, DE_DOT,   _______,
                                   _______, _______, _______,       KC_DEL,  _______, _______
    ),
    [FUN] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   XXXXXXX,
        XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,  _______,
                                   _______, _______, _______,       KC_DEL,  _______, _______
    ),
    [NAV] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  XXXXXXX,
        KC_CAPS, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, SELWORD,       XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX,  _______,
                                   _______, _______, _______,       _______, _______, _______
    ),
    [OTHER] = LAYOUT_split_3x6_3(
        KC_VOLU, KC_CALC, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,       KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,  TO(NAV),
        KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,  XXXXXXX,
        KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, INS_MODE,IJ_RUN,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                   _______, _______, _______,       _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, FUN, NAV, OTHER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case SELWORD:
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
                break;
        }
    }
    return true;
}
