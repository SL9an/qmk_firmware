#include QMK_KEYBOARD_H
#include "layers.c"
#include "chordal_hold.c"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* layout example
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_BASE] = LAYOUT_ergodox_pretty(
  XXXXXXX,         XXXXXXX,       XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,       XXXXXXX,         XXXXXXX,
  KC_TAB,          KC_Q,          KC_W,          KC_E,         KC_R,         KC_T,       XXXXXXX,              XXXXXXX,      KC_Y,      KC_U,         KC_I,         KC_O,          KC_P,            KC_BSLS,
  LCTL_T(KC_ESC),  LCTL_T(KC_A),  LALT_T(KC_S),  LSFT_T(KC_D), LGUI_T(KC_F), KC_G,                                           KC_H,      RGUI_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L),  RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,         KC_Z,          KC_X,          KC_C,         KC_V,         KC_B,       XXXXXXX,              XXXXXXX,      KC_N,      KC_M,         KC_COMM,      KC_DOT,        KC_SLSH,         KC_RSFT,
  XXXXXXX,         XXXXXXX,       XXXXXXX,       MO(_MEDIA),   MO(_NAV),                                                                MO(_NAV),     MO(_MEDIA),   XXXXXXX,       XXXXXXX,         XXXXXXX,
                                                                             XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,
                                                                                         KC_VOLU,              KC_BRIU,
                                                           LT(_NUMBER, KC_SPC), KC_ENT,  KC_VOLD,              KC_BRID, KC_DEL, LT(_SYMBOL, KC_BSPC)
),

[_SYMBOL] = LAYOUT_ergodox_pretty(
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          KC_TILD,        KC_GRV,       KC_UNDS,     KC_MINS,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    KC_PLUS,      KC_EQL,       XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          KC_EXLM,        KC_AT,        KC_HASH,     KC_DLR,       KC_PERC,                                        KC_CIRC,    KC_AMPR,      KC_ASTR,      XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          KC_LABK,        KC_LBRC,      KC_LCBR,     KC_LPRN,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    KC_RPRN,      KC_RCBR,      KC_RBRC,        KC_RABK,         XXXXXXX,
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,                                                                  XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
                                                                             XXXXXXX,    KC_ENT,               KC_DEL,       XXXXXXX,
                                                                                         XXXXXXX,              XXXXXXX,
                                                                       XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX
),

[_NUMBER] = LAYOUT_ergodox_pretty(
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          KC_F1,          KC_F2,        KC_F3,       KC_F4,        KC_F5,      XXXXXXX,              XXXXXXX,      KC_F6,      KC_F7,        KC_F8,        KC_F9,          KC_F10,          KC_F11,
  XXXXXXX,          KC_1,           KC_2,         KC_3,        KC_4,         KC_5,                                           KC_6,       KC_7,         KC_8,         KC_9,           KC_0,            KC_F12,
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,                                                                  XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
                                                                             XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,
                                                                                         XXXXXXX,              XXXXXXX,
                                                                       XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX
),

[_NAV] = LAYOUT_ergodox_pretty(
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,      XXXXXXX,
  XXXXXXX,          XXXXXXX,        KC_NUM,       KC_CAPS,     KC_SCRL,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    KC_END,       KC_HOME,      XXXXXXX,        KC_PSCR,      XXXXXXX,
  XXXXXXX,          XXXXXXX,        KC_LEFT,      KC_UP,       KC_RGHT,      XXXXXXX,                                        KC_LEFT,    KC_DOWN,      KC_UP,        KC_RGHT,        XXXXXXX,      XXXXXXX,
  KC_LSFT,          KC_Z,           KC_BTN4,      KC_DOWN,     KC_BTN5,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    KC_PGDN,      KC_PGUP,      XXXXXXX,        XXXXXXX,      XXXXXXX,
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,                                                                  XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,      XXXXXXX,
                                                                             XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,
                                                                                         XXXXXXX,              XXXXXXX,
                                                                       XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX
),

[_MEDIA] = LAYOUT_ergodox_pretty(
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          KC_BRID,        KC_BRIU,      XXXXXXX,     XXXXXXX,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          KC_VOLD,        KC_VOLU,      KC_MUTE,     KC_RGHT,      XXXXXXX,                                        XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          KC_MPRV,        KC_MPLY,      KC_MNXT,     KC_MSTP,      XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
  XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,                                                                  XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,         XXXXXXX,
                                                                             XXXXXXX,    XXXXXXX,              XXXXXXX,      XXXXXXX,
                                                                                         XXXXXXX,              XXXXXXX,
                                                                       XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX
),

};
