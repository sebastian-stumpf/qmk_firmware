#include QMK_KEYBOARD_H
#include "keymap_german.h"


enum layers { BASE, SYM, NUM, FUN, NAV, OTHER };
enum custom_keycodes {
    GIT_PULL = SAFE_RANGE,
    GIT_PUSH,
    GIT_STATUS,
    GIT_DIFF,
    GIT_COMMIT,
    GIT_CHECKOUT
};

const uint16_t PROGMEM tab_bspc_combo[]  = {KC_TAB, KC_BSPC,  COMBO_END};
const uint16_t PROGMEM spc_enter_combo[] = {KC_SPC, KC_ENTER, COMBO_END};
const uint16_t PROGMEM o_p_combo[]       = {DE_O,   DE_P,     COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(tab_bspc_combo, KC_DEL),
    COMBO(spc_enter_combo, KC_ESC),
    COMBO(o_p_combo, DE_PLUS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
            DE_Q,         DE_W,          DE_E,           DE_R,            DE_T,             DE_Z,           DE_U,         DE_I,         DE_O,           DE_P,
            LGUI_T(DE_A), LALT_T(DE_S),  LCTL_T(DE_D),   LSFT_T(DE_F),    DE_G,             DE_H,           LSFT_T(DE_J), LCTL_T(DE_K), LALT_T(DE_L),   LGUI_T(DE_HASH),
            DE_Y,         ALGR_T(DE_X),  DE_C,           DE_V,            DE_B,             DE_N,           DE_M,         DE_COMM,      ALGR_T(DE_DOT), DE_MINS,
                                                         LT(NUM,KC_TAB),  LT(FUN,KC_BSPC),  LT(NAV,KC_SPC), LT(SYM, KC_ENTER)
    ),
    [SYM] = LAYOUT(
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         DE_GRV,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
            DE_ADIA,      DE_ODIA,       DE_UDIA,        DE_SS,           DE_CIRC,          XXXXXXX,        KC_LSFT,      KC_LCTL,      KC_LALT,        KC_LGUI,
            DE_LABK,      XXXXXXX,       XXXXXXX,        XXXXXXX,         DE_PLUS,          XXXXXXX,        XXXXXXX,      XXXXXXX,      KC_ALGR,        XXXXXXX,
                                                         XXXXXXX,         XXXXXXX,          XXXXXXX,        XXXXXXX
    ),
    [NUM] = LAYOUT(
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          KC_1,           KC_2,         KC_3,         KC_4,           KC_5,
            KC_LGUI,      KC_LALT,       KC_LCTL,        KC_LSFT,         XXXXXXX,          KC_6,           KC_7,         KC_8,         KC_9,           KC_0,
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          KC_PLUS,        KC_MINS,      KC_ASTR,      DE_SLSH,        KC_DOT,
                                                         XXXXXXX,         XXXXXXX,          XXXXXXX,        XXXXXXX
    ),
    [FUN] = LAYOUT(
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          KC_F1,          KC_F2,        KC_F3,        KC_F4,          KC_F5,
            KC_LGUI,      KC_LALT,       KC_LCTL,        KC_LSFT,         XXXXXXX,          KC_F6,          KC_F7,        KC_F8,        KC_F9,          KC_F10,
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          KC_F11,         KC_F12,       XXXXXXX,      XXXXXXX,        XXXXXXX,
                                                         XXXXXXX,         XXXXXXX,          XXXXXXX,        XXXXXXX
    ),
    [NAV] = LAYOUT(
            XXXXXXX,      KC_PGUP,       KC_HOME,        KC_UP,           KC_END,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
            XXXXXXX,      KC_PGDN,       KC_LEFT,        KC_DOWN,         KC_RIGHT,         XXXXXXX,        KC_LSFT,      KC_LCTL,      KC_LALT,        KC_LGUI,
            KC_CAPS,      XXXXXXX,       XXXXXXX,        KC_INS,          XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,      KC_ALGR,        XXXXXXX,
                                                         XXXXXXX,         XXXXXXX,          XXXXXXX,        XXXXXXX
    ),
    [OTHER] = LAYOUT(
            KC_MPRV,      KC_MPLY,       KC_MNXT,        KC_VOLD,         KC_VOLU,          LSA(KC_INS),    XXXXXXX,      GIT_CHECKOUT, GIT_PULL,       GIT_PUSH,
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         KC_CALC,          C(S(KC_F11)),   GIT_STATUS,   GIT_DIFF,     GIT_COMMIT,     XXXXXXX,
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
                                                         XXXXXXX,         XXXXXXX,          XXXXXXX,        XXXXXXX
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, FUN, NAV, OTHER);
}

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
            SEND_STRING("git commit -m ''");
            SEND_STRING(SS_TAP(X_LEFT));
            break;
        case GIT_CHECKOUT:
            SEND_STRING("git checkout ");
            break;
    }
  }
  return true;
}
