#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layers { BASE, SYM, NUM, FUN, NAV, OTHER };
enum custom_keycodes { SELWORD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        KC_ESC,         DE_Q,         DE_W,         DE_E,         DE_R,         DE_T,        DE_Z,    DE_U,         DE_I,         DE_O,           DE_P,            KC_BSPC,
        KC_TAB,         LGUI_T(DE_A), LALT_T(DE_S), LCTL_T(DE_D), LSFT_T(DE_F), DE_G,        DE_H,    LSFT_T(DE_J), LCTL_T(DE_K), LALT_T(DE_L),   LGUI_T(DE_MINS), DE_PLUS,
        DE_LABK,        ALGR_T(DE_Y), DE_X,         DE_C,         DE_V,         DE_B,        DE_N,    DE_M,         DE_COMM,      ALGR_T(DE_DOT), DE_HASH,         KC_ENT,
                                                    MO(NUM),      MO(FUN),      KC_SPC,      KC_BSPC, MO(NAV),      MO(SYM)
    ),
    [SYM] = LAYOUT_split_3x6_3(
        _______,        XXXXXXX,      XXXXXXX,      XXXXXXX,      DE_UDIA,      DE_SS,       XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         _______,
        _______,        XXXXXXX,      XXXXXXX,      XXXXXXX,      DE_ADIA,      DE_ODIA,     XXXXXXX, LSFT,         LCTL,         LALT,           LGUI,            XXXXXXX,
        XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      DE_GRV,       DE_CIRC,     XXXXXXX, XXXXXXX,      XXXXXXX,      ALGR,           XXXXXXX,         _______,
                                                    XXXXXXX,      XXXXXXX,      _______,     _______, XXXXXXX,      XXXXXXX
    ),
    [NUM] = LAYOUT_split_3x6_3(
        _______,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,     KC_1,    KC_2,         KC_3,         KC_4,           KC_5,         _______,
        _______,        LGUI,         LALT,         LCTL,         LSFT,         XXXXXXX,     KC_6,    KC_7,         KC_8,         KC_9,           KC_0,         XXXXXXX,
        XXXXXXX,        ALGR,         XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,     DE_PLUS, DE_MINS,      DE_ASTR,      DE_SLSH,        DE_DOT,       _______,
                                                    XXXXXXX,      XXXXXXX,      _______,     _______, XXXXXXX,      XXXXXXX
    ),
    [FUN] = LAYOUT_split_3x6_3(
        _______,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,     KC_F1,   KC_F2,        KC_F3,        KC_F4,          KC_F5,      _______,
        _______,        LGUI,         LALT,         LCTL,         LSFT,         XXXXXXX,     KC_F6,   KC_F7,        KC_F8,        KC_F9,          KC_F10,     XXXXXXX,
        XXXXXXX,        ALGR,         XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,     KC_F11,  KC_F12,       XXXXXXX,      XXXXXXX,        XXXXXXX,    _______,
                                                    XXXXXXX,      XXXXXXX,      _______,     KC_DEL,  XXXXXXX,      XXXXXXX
    ),
    [NAV] = LAYOUT_split_3x6_3(
        _______,        XXXXXXX,      KC_PGUP,      KC_HOME,      KC_UP,        KC_END,      XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         _______,
        _______,        XXXXXXX,      KC_PGDN,      KC_LEFT,      KC_DOWN,      KC_RIGHT,    XXXXXXX, LSFT,         LCTL,         LALT,           LGUI,            XXXXXXX,
        KC_CAPS,        KC_INS,       XXXXXXX,      XXXXXXX,      XXXXXXX,      SELWORD,     XXXXXXX, XXXXXXX,      XXXXXXX,      ALGR,           XXXXXXX,         _______,
                                                    XXXXXXX,      XXXXXXX,      _______,     _______, XXXXXXX,      XXXXXXX
    ),
    [OTHER] = LAYOUT_split_3x6_3(
        KC_VOLU,        KC_CALC,      XXXXXXX,      KC_MPRV,      KC_MPLY,      KC_MNXT,     KC_BTN1, KC_MS_U,      KC_BTN2,      XXXXXXX,        XXXXXXX,         TO(NAV),
        KC_VOLD,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,     KC_MS_L, KC_MS_D,      KC_MS_R,      XXXXXXX,        XXXXXXX,         XXXXXXX,
        KC_MUTE,        XXXXXXX,      XXXXXXX,      XXXXXXX,      LSA(KC_INS),  C(S(KC_F11)  XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
                                                    XXXXXXX,      XXXXXXX,      XXXXXXX,     XXXXXXX, XXXXXXX,      XXXXXXX
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
