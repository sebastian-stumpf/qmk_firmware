#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "klor.h"
#include "keymap_german.h"


enum layers { BASE, SYM, NUM, FUN, NAV, MOUSE };


#define A_LT LGUI_T(DE_A)
#define S_LT LALT_T(DE_S)
#define D_LT LCTL_T(DE_D)
#define F_LT LSFT_T(DE_F)
#define J_LT LSFT_T(DE_J)
#define K_LT LCTL_T(DE_K)
#define L_LT LALT_T(DE_L)
#define HASH_LT LGUI_T(DE_HASH)

#define ESC_NUM LT(NUM, KC_ESC)
#define DEL_FUN LT(FUN, KC_DEL)
#define BSPC_NAV LT(NAV, KC_BSPC)
#define TAB_SYM LT(SYM, KC_TAB)

#define OS_GUI OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_SFT OSM(MOD_LSFT)

#define INS_MODE LSA(KC_INS)

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

#ifdef POINTING_DEVICE_ENABLE
bool set_scrolling = false;

void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOUSE);
    set_auto_mouse_enable(true);
}

#define SCROLL_DIVISOR_H 8.0
#define SCROLL_DIVISOR_V 8.0
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v -= (float)mouse_report.y / SCROLL_DIVISOR_V;

        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    return true;
}
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_saegewerk(
        DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,                          DE_Z,     DE_U,     DE_I,     DE_O,     DE_P,
        A_LT,     S_LT,     D_LT,     F_LT,     DE_G,                          DE_H,     J_LT,     K_LT,     L_LT,     HASH_LT,
        DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,    KC_MUTE,     KC_CALC, DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS,
                            ESC_NUM,  DEL_FUN,  KC_ENT,                        KC_SPC,   BSPC_NAV, TAB_SYM
    ),
    [SYM] =  LAYOUT_saegewerk(
        DE_AT,   DE_LPRN, DE_RPRN, DE_UDIA, DE_SS,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        DE_BSLS, DE_LCBR, DE_RCBR, DE_ADIA, DE_ODIA,                        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        DE_EURO, DE_LBRC, DE_RBRC, DE_CIRC, DE_GRV,  _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,                        _______, _______, _______
    ),
    [NUM] =  LAYOUT_saegewerk(
        KC_ESC,  XXXXXXX,    C(KC_PGUP), C(KC_PGDN), XXXXXXX,                                DE_7,    DE_8,    DE_9,    DE_TILD, XXXXXXX,
        KC_LGUI, KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,                                DE_4,    DE_5,    DE_6,    DE_PIPE, DE_LABK,
        XXXXXXX, C(S(DE_X)), C(S(DE_C)), C(S(DE_V)), XXXXXXX, _______,  _______,             DE_1,    DE_2,    DE_3,    DE_QUES, DE_PLUS,
                                   _______, _______, _______,                                _______, _______, DE_0
    ),
    [FUN] =  LAYOUT_saegewerk(
        OS_GUI,  OS_ALT,  OS_CTL,  OS_SFT,  XXXXXXX,                        KC_F7,    KC_F8,   KC_F9,   KC_F12,  TO(BASE),
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        KC_F4,    KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
        XXXXXXX, C(DE_X), C(DE_C), C(DE_V), XXXXXXX, _______, _______,      KC_F1,    KC_F2,   KC_F3,   KC_F10,  TG(NUM),
                          _______, _______, _______,                        _______, _______, _______
    ),
    [NAV] =  LAYOUT_saegewerk(
        CW_TOGG, KC_PGUP, KC_HOME, KC_UP,   KC_END,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,                       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_INS,  INS_MODE,XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,                        _______, _______, _______
    ),
    [MOUSE] =  LAYOUT_saegewerk(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DRAG_SCROLL,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, C(DE_X), C(DE_C), C(DE_V), XXXXXXX, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          KC_BTN2, KC_BTN3, KC_BTN1,                        _______, _______, _______
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }

    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    return true;
}

#endif

#ifdef OLED_ENABLE
void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0};
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false); // ──── MAC
    } else {
        oled_write_P(os_w_1, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false); // ──── MAC
    } else {
        oled_write_P(os_w_2, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_ln_P(sep_v, false);


    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

    oled_write_P(sep_h2, false);
}


bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        render_os_lock_status();
    }
    return false;
}
#endif

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
