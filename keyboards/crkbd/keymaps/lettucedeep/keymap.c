/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "layers.c"
#include "oled.c"
#include "chordal_hold.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
      KC_TAB,         KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                                      KC_Y,     KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
      LCTL_T(KC_ESC), LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G,                                                      KC_H,     RGUI_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
      KC_LSFT,        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                                                      KC_N,     KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,
                                                                MO(_MEDIA),   MO(_NAV), LT(_NUMBER, KC_SPC),       LT(_SYMBOL, KC_BSPC), MO(_NAV), MO(_RGB)

  ),  

  [_NUMBER] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX, XXXXXXX,     KC_DEL, XXXXXXX, XXXXXXX
  ),  

  [_SYMBOL] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_TILD, KC_GRV,  KC_UNDS, KC_MINS, XXXXXXX,                      XXXXXXX, KC_PLUS,  KC_EQL, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LT,   KC_LBRC, KC_LCBR, KC_LPRN, XXXXXXX,                      XXXXXXX, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT,   XXXXXXX,
                                          XXXXXXX, XXXXXXX, KC_ENT,     XXXXXXX, XXXXXXX, XXXXXXX
  ),  


  [_NAV] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, KC_NUM,  KC_CAPS, KC_SCRL, XXXXXXX,                      XXXXXXX, KC_END,  KC_HOME, XXXXXXX, KC_PSCR, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_LEFT, KC_UP,   KC_RGHT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_BTN4, KC_DOWN, KC_BTN5, XXXXXXX,                      XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  ),
    [_MEDIA] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_RGB] = LAYOUT_split_3x6_3(
      RGB_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,
      RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                                           XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
      return OLED_ROTATION_0;
    }
    return rotation;
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
	render_billboard(PSTR("foostan\n"), PSTR("Corne Keyboard\n"), PSTR("QMK Firmware\n"));
    }
    return false;
}

#endif // OLED_ENABLE
