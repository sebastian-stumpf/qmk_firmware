#include "quantum.h"
#include "klackerkasten.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}
#endif

#ifdef RGBLIGHT_ENABLE
void housekeeping_task_user(void) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        rgblight_sethsv_at(200, 200, 70, 0);
    }
    else {
        rgblight_sethsv_at(0, 0, 0, 0);
    }

    if (led_state.num_lock) {
        rgblight_sethsv_at(200, 200, 70, 1);
    }
    else {
        rgblight_sethsv_at(0, 0, 0, 1);
    }

    if (led_state.scroll_lock) {
        rgblight_sethsv_at(200, 200, 70, 2);
    }
    else {
        rgblight_sethsv_at(0, 0, 0, 2);
    }
}
#endif
