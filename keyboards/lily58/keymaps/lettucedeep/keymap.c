#include QMK_KEYBOARD_H


#include <stdio.h>
#include "oled.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
        KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,  
        KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,  
        LCTL_T(KC_ESC), LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G, KC_H, RGUI_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,  
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX,                       XXXXXXX, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  
        XXXXXXX, MO(_MEDIA), MO(_NAV), LT(_NUMBER, KC_SPC),                         LT(_SYMBOL, KC_BSPC), MO(_NAV), XXXXXXX, MO(_RGB)
    ),
	[_NAV] = LAYOUT(
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_NO, KC_NO, KC_NUM, KC_CAPS, KC_SCRL, KC_NO, KC_NO, KC_END, KC_HOME, KC_NO, KC_PSCR, KC_F12,
        KC_NO, KC_HOME, KC_LEFT, KC_UP, KC_RGHT, KC_PGUP, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BTN4, KC_BTN5,
        KC_NO, KC_END, KC_BTN4, KC_DOWN, KC_BTN5, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, _______, KC_NO, KC_NO, _______, KC_NO, KC_NO
    ),
	[_SYMBOL] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_TILD, KC_GRV, KC_UNDS, KC_MINS, KC_NO, KC_NO, KC_PLUS, KC_EQL, KC_GRV  , KC_NO, KC_NO,
        TO(_BASE), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
        KC_NO, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_ENT, _______, KC_NO, KC_NO, KC_NO
    ),
	[_NUMBER] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        TO(_BASE), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, _______, KC_DEL, KC_NO, KC_NO, KC_NO
    ),
	[_MEDIA] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO,
        KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,
        KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,
        KC_NO, _______, KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_NO
    ),
	[_RGB] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_RBT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______
    )
};


#ifdef OLED_ENABLE

// Rotate OLED display
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    //return OLED_ROTATION_180;
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    }
    else return rotation;
}


// OLED display rendering
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_billboard(PSTR("kata0510 & ergohaven\n"), PSTR("Lily58 Pro\n"), PSTR("QMK Firmware\n"));
    }
    return false;
}
#endif
