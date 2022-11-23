#include QMK_KEYBOARD_H

#include "keymap_german.h"

enum layer_number {
  _QWERTZ = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
    GIT_PULL = SAFE_RANGE,
    GIT_PUSH,
    GIT_STATUS,
    GIT_DIFF,
    GIT_COMMIT,
    GIT_CHECKOUT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTZ
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ß   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |  Ü   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|   +   |    |   #   |------+------+------+------+------+------|
 * |LCTRL |   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 */

 [_QWERTZ] = LAYOUT(
  KC_ESC,   DE_1,   DE_2,    DE_3,    DE_4,    DE_5,                     DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,
  KC_TAB,   DE_Q,   DE_W,    DE_E,    DE_R,    DE_T,                     DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA,
  KC_LSFT,  DE_A,   DE_S,    DE_D,    DE_F,    DE_G,                     DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA,
  KC_LCTRL, DE_Y,   DE_X,    DE_C,    DE_V,    DE_B, DE_PLUS,  DE_HASH,  DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  ^   |   (  |   )  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|  `   |   [  |   ]  |      |      |      |
 * |------+------+------+------+------+------|   <   |    |    >  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   {  |   }  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |  Del | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   DE_CIRC, DE_LPRN, DE_RPRN, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   DE_GRV,  DE_LBRC, DE_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_LABK, DE_RABK, XXXXXXX, DE_LCBR, DE_RCBR, XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______, _______, _______,  _______, KC_DEL, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Mprev |MplayP|Mnext |Calc  | VolD | VolU |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Up  |      |      | Home |                    |  End |      |      | MSU  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left | Down |Right |      |      |-------.    ,-------|      |      | MSL  | MSD  | MSR  |      |
 * |------+------+------+------+------+------| PGUP  |    | PGDN  |------+------+------+------+------+------|
 * |      |      |      |      |      |Insert|-------|    |-------| MS1  | MS2  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_MPRV, KC_MPLY, KC_MNXT, KC_CALC,  KC_VOLD, KC_VOLU,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  XXXXXXX, KC_HOME,                    KC_END,  XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_INS,   KC_PGUP, KC_PGDN, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______,  _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | Run  |      |                    |      |      | RowM |      | Pull | Push |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |Status| Diff |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |Commit|Checko|      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    C(S(KC_F11)), XXXXXXX,                   XXXXXXX, XXXXXXX, LSA(KC_INS), XXXXXXX, GIT_PULL, GIT_PUSH,
  XXXXXXX, XXXXXXX, GIT_STATUS, GIT_DIFF,   XXXXXXX,      XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,    GIT_COMMIT, GIT_CHECKOUT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX,
                                       _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
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
    // set_timelog();
  }
  return true;
}
