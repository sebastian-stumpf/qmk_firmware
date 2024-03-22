#include QMK_KEYBOARD_H

#include "keymap_german.h"


enum layers { BASE, SYM, NUM, FUN, NAV };

#define A_LT LGUI_T(DE_A)
#define S_LT LALT_T(DE_S)
#define D_LT LCTL_T(DE_D)
#define F_LT LSFT_T(DE_F)
#define J_LT LSFT_T(DE_J)
#define K_LT LCTL_T(DE_K)
#define L_LT LALT_T(DE_L)
#define HASH_LT LGUI_T(DE_HASH)


#define DEL_NUM LT(NUM, KC_DEL)
#define BSPC_FUN LT(FUN, KC_BSPC)
#define SPC_NAV LT(NAV, KC_SPC)
#define TAB_SYM LT(SYM, KC_TAB)


#define OS_GUI OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_SFT OSM(MOD_LSFT)

#define INS_MODE LSA(KC_INS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_2(
        DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,         DE_Z,    DE_U,     DE_I,    DE_O,    DE_P,
        A_LT,    S_LT,    D_LT,    F_LT,    DE_G,         DE_H,    J_LT,     K_LT,    L_LT,    HASH_LT,
        DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,         DE_N,    DE_M,     DE_COMM, DE_DOT,  DE_MINS,
                                   DEL_NUM, BSPC_FUN,     SPC_NAV, TAB_SYM
    ),
    [SYM] =  LAYOUT_split_3x5_2(
        DE_AT,   DE_LPRN, DE_RPRN, DE_UDIA, DE_SS,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        DE_BSLS, DE_LCBR, DE_RCBR, DE_ADIA, DE_ODIA,      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        DE_EURO, DE_LBRC, DE_RBRC, DE_CIRC, DE_GRV,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                    _______, _______,      _______, _______
    ),
    [NUM] =  LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX,    C(KC_PGUP), C(KC_PGDN), XXXXXXX,      DE_TILD, DE_7,    DE_8,    DE_9,    TO(BASE),
        KC_LGUI, KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,      DE_PIPE, DE_4,    DE_5,    DE_6,    DE_LABK,
        XXXXXXX, C(S(DE_X)), C(S(DE_C)), C(S(DE_V)), XXXXXXX,      DE_QUES, DE_1,    DE_2,    DE_3,    DE_PLUS,
                                         _______, _______,         _______,  DE_0
    ),
    [FUN] =  LAYOUT_split_3x5_2(
        KC_ESC,  OS_ALT,  OS_CTL,  OS_SFT,  XXXXXXX,      TG(NUM),    KC_F7,   KC_F8,   KC_F9,  KC_F12,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,      XXXXXXX,    KC_F4,   KC_F5,   KC_F6,  KC_F11,
        XXXXXXX, C(DE_X), C(DE_C), C(DE_V), XXXXXXX,      XXXXXXX,    KC_F1,   KC_F2,   KC_F3,  KC_F10,
                                   _______, _______,      _______, _______
    ),
    [NAV] =  LAYOUT_split_3x5_2(
        CW_TOGG, KC_PGUP, KC_HOME, KC_UP,   KC_END,       KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_ENT,
        KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,     KC_MUTE, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_INS,  INS_MODE,XXXXXXX, XXXXXXX, XXXXXXX,      KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______,      _______, _______
    )
};

const uint16_t PROGMEM escape_combo[] = {DE_Q, DE_W, COMBO_END};
const uint16_t PROGMEM enter_combo[] =  {DE_P, DE_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(escape_combo, KC_ESC),
    COMBO(enter_combo, KC_ENT),
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
