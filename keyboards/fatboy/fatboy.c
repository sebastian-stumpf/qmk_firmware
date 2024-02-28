#include "quantum.h"
#include "fatboy.h"

/*
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        if (led_state.caps_lock) {
            rgblight_setrgb_at(80, 80, 80, 1);
        }
        if (led_state.num_lock) {
            rgblight_setrgb_at(80, 80, 80, 2);
        }
        if (led_state.num_lock) {
            rgblight_setrgb_at(80, 80, 80, 3);
        }
    }
    return res;
}
*/

void housekeeping_task_user(void) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        rgblight_sethsv_at(0, 0, 70, 0);
    }
    else {
        rgblight_sethsv_at(0, 0, 0, 0);
    }

    if (led_state.num_lock) {
        rgblight_sethsv_at(0, 0, 70, 1);
    }
    else {
        rgblight_sethsv_at(0, 0, 0, 1);
    }

    if (led_state.scroll_lock) {
        rgblight_sethsv_at(0, 0, 70, 2);
    }
    else {
        rgblight_sethsv_at(0, 0, 0, 2);
    }
}
