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
   | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------| BackSp|    | Delete|------+------+------+------+------+------|
 * |LShift|   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCtrl | LGui |LAlt  | /LOWER  /       \RAISE \  |Space |Enter | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTZ] = LAYOUT(
  KC_ESC,   DE_1,   DE_2,    DE_3,    DE_4,    DE_5,                     DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,
  KC_TAB,   DE_Q,   DE_W,    DE_E,    DE_R,    DE_T,                     DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA,
  KC_CAPS,  DE_A,   DE_S,    DE_D,    DE_F,    DE_G,                     DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA,
  KC_LSFT,  DE_Y,   DE_X,    DE_C,    DE_V,    DE_B, KC_BSPC,  KC_DEL,   DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
                       KC_LCTRL, KC_LGUI, KC_LALT, MO(_LOWER), MO(_RAISE), KC_SPC, KC_ENTER, KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |  MS1 |      |  MS2 |                    |      | PGUP |      |      |      |Insert|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |  MSU |      |                    |      |  Up  |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  MSL |  MSD |  MSR |-------.    ,-------| Left | Down | Right|      |      |      |
 * |------+------+------+------+------+------| Home  |    |  End  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PGDN |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCtrl | LGui |LAlt  | /LOWER  /       \RAISE \  |Space |Enter | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN1, XXXXXXX, KC_MS_BTN2,                XXXXXXX, KC_PGUP, XXXXXXX,  XXXXXXX, XXXXXXX, KC_INS,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_MS_U, XXXXXXX,                   XXXXXXX, KC_UP,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_MS_L,    KC_MS_D, KC_MS_R,                   KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  KC_HOME, KC_END, XXXXXXX, KC_PGDN, XXXXXXX,  XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______,  _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  +   |  (   |   )  |  ^   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  #   |  [   |   ]  |  `   |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   <   |    |    >  |------+------+------+------+------+------|
 * |      |      |  |   |  {   |   }  |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCtrl | LGui |LAlt  | /LOWER  /       \RAISE \  |Space |Enter | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, XXXXXXX, DE_PLUS, DE_LPRN, DE_RPRN, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, DE_HASH, DE_LBRC, DE_RBRC, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, DE_PIPE, DE_LCBR, DE_RCBR, XXXXXXX, DE_LABK, DE_RABK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

/*

XXXXXXX, KC_PGUP, XXXXXXX,
XXXXXXX, KC_UP,   XXXXXXX,
KC_LEFT, KC_DOWN, KC_RIGHT
XXXXXXX, KC_PGDN, KC_INS, 

KC_MS_BTN1, XXXXXXX, KC_MS_BTN1, 
XXXXXXX,    KC_MS_U, XXXXXXX,    
KC_MS_L,    KC_MS_D, KC_MS_R,    
XXXXXXX,    XXXXXXX, XXXXXXX,    

*/
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MPrev |MPlay |MNext | Calc | VolD | VolU |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | Run  |      |                    |      |      | RowM |      | Pull | Push |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |Status| Diff |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |Commit|Checko|      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCtrl | LGui |LAlt  | /LOWER  /       \RAISE \  |Space |Enter | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  KC_MPRV, KC_MPLY, KC_MNXT,    KC_CALC,    KC_VOLD,      KC_VOLU,                   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX,
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

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    oled_set_cursor(0,1);
    uint8_t n = get_current_wpm();
    char    wpm_counter[4];
    wpm_counter[3] = '\0';
    wpm_counter[2] = '0' + n % 10;
    wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
    wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
    oled_write_P(PSTR("WPM: "), false);
    oled_write(wpm_counter, false);
    oled_set_cursor(0,3); {
        oled_write_ln(read_layer_state(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
        case GIT_PULL:
            SEND_STRING("git pull\n");
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
