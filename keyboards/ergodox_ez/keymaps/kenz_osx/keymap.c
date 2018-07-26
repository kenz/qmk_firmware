// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define NUMB 1 // number layer
#define MOVE 2 // move keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------------.           ,--------------------------------------------------.
 * |  `~   |   1  |   2  |   3  |   4  |   5  |  6   |           |   6  |   7  |   8  |   9  |   0  |   -  |   =    |
 * |-------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab   |   Q  |   W  |   E  |   R  |   T  |  かな |           |  [   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |-------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |-------+------+------+------+------+------|  英  |           |   ]  |------+------+------+------+------+--------|
 * | LShift|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `-------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Ctrl |  ALT |  L2  | L1   | LGui |                                       | RGui | Left | Down | Up   | Right  |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | F2   | VoUp |       | Left |Right|
 *                                 ,------|------|------|       |------+-----+-----.
 *                                 |      |      | VoDwn|       |  Up  |     |     |
 *                                 | Back | Esc  |------|       |------|Enter|Space|
 *                                 | Space|      | Mute |       | Down |     |     |
 *                                 `--------------------'       `------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,     KC_1,         KC_2,    KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,     KC_Q,         KC_W,    KC_E,   KC_R,   KC_T,   KC_LANG1,
        KC_LCTRL,   KC_A,         KC_S,    KC_D,   KC_F,   KC_G,
        KC_LSFT,    KC_Z,         KC_X,    KC_C,   KC_V,   KC_B,   KC_LANG2,
        KC_LCTRL,   KC_LALT,      MO(MOVE),MO(NUMB),KC_LGUI,
                                                       KC_F2,  KC_VOLU,
                                                               KC_VOLD,
                                               KC_BSPC,KC_ESC, KC_MUTE,
        // right hand
             KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,
             KC_LBRC,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,
             KC_RBRC,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,
                             KC_RGUI,KC_LEFT,KC_DOWN,KC_UP,   KC_RIGHT,
             KC_LEFT,        KC_RIGHT,
             KC_UP,
             KC_DOWN ,KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6 |   F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |   [  |   ]  |   =  |   F12  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |   `    |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       |MsLeft|MsRight|
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |      |       | MsUp |       |      |
 *                                 |      |      |------|       |------| Lclk  | Rclk |
 *                                 |      |      |      |       |MsDown|       |      |
 *                                 `--------------------'       `---------------------'
 */

// NUMBER
[NUMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_TRNS,
       KC_TRNS,KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_TRNS,
       KC_TRNS,KC_1,   KC_2,    KC_3,    KC_4,    KC_5,
       KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
                KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_LBRC, KC_RBRC, KC_EQL,  KC_F12,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,
       KC_MS_L, KC_MS_R,
       KC_MS_U,
       KC_MS_D, KC_BTN1, KC_BTN2
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,---------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |       |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+-------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      | BTN1 | BTN2  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+-------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------| LEFT | DOWN |  UP   | RIGHT|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+-------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev  | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+-------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       | VolUp | VolDn | Mute |      |      |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOVE LAYOER
[MOVE] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NUMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case NUMB:
      ergodox_right_led_1_off();
      ergodox_right_led_2_off();
      ergodox_right_led_3_on();
      break;
    case MOVE:
      ergodox_right_led_1_off();
      ergodox_right_led_2_on();
      ergodox_right_led_3_off();
      break;
    default:
      ergodox_right_led_1_on();
      ergodox_right_led_2_off();
      ergodox_right_led_3_off();
      break;
  }

};
