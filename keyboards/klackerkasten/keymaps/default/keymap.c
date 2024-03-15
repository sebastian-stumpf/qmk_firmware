#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layers { BASE, SYM, NUM, FUN, NAV, ADJUST };

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
    [BASE] = LAYOUT(
        DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,         DE_Z,    DE_U,     DE_I,    DE_O,    DE_P,
        A_LT,    S_LT,    D_LT,    F_LT,    DE_G,         DE_H,    J_LT,     K_LT,    L_LT,    HASH_LT,
        DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,         DE_N,    DE_M,     DE_COMM, DE_DOT,  DE_MINS,
                          KC_ESC,  DEL_NUM, BSPC_FUN,     SPC_NAV, TAB_SYM,  KC_ENT
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

