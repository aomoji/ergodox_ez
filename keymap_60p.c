#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(
    // left
    KC_ESC,           KC_1,         KC_2,       KC_3,       KC_4,       KC_5,       KC_GRAVE,
    KC_TAB,           KC_Q,         KC_W,       KC_E,       KC_R,       KC_T,       KC_MINUS,
    KC_LCTRL,         KC_A,         KC_S,       KC_D,       KC_F,       KC_G,
    KC_LSHIFT,        KC_Z,         KC_X,       KC_C,       KC_V,       KC_B,       KC_LBRACKET,
    LCTL(LGUI(KC_Q)), KC_NO,        KC_LALT,    KC_LGUI,    KC_LSHIFT,
    LGUI(LSFT(KC_4)),       LGUI(LSFT(LCTL(KC_4))), // スクリーンショット
    LGUI(LSFT(KC_5)), //スクリーンショット
    LT(1, KC_SPACE),         KC_LPRN,    KC_NO,
    // rightƒ
    KC_BSLASH,        KC_6,         KC_7,       KC_8,        KC_9,      KC_0,       KC_NO,
    KC_EQUAL,         KC_Y,         KC_U,       KC_I,        KC_O,      KC_P,       KC_BSPACE,
                      KC_H,         KC_J,       KC_K,        KC_L,      KC_SCOLON,  KC_ENTER,
    KC_RBRACKET,      KC_N,         KC_M,       KC_COMMA,    KC_DOT,    KC_SLASH,   SFT_T(KC_QUOTE),
                                    KC_LSHIFT,  KC_RGUI,     KC_RALT,   KC_NO,      KC_NO,
    KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
    KC_AUDIO_MUTE,
    KC_MPLY,            KC_RPRN,     LT(1, KC_SPACE)
    ),

  [1] = LAYOUT_ergodox(
    // left
    KC_ESC,           KC_F1,          KC_F2,          KC_F3,           KC_F4,          KC_F5,         KC_F14,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_HOME, LCTL(RSFT(KC_TAB)),LCTL(KC_TAB), KC_PGUP,       KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_END, KC_TRANSPARENT,  LGUI(KC_RBRC), KC_PGDOWN,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LSFT(KC_C)),LGUI(LSFT(KC_V)), LGUI(KC_LBRC),KC_TRANSPARENT,
    RESET,            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
    // right
    KC_F15,   KC_F6,          KC_F7,          KC_F8,           KC_F9,          KC_F10,        KC_F11,
    KC_TRANSPARENT,   KC_TRANSPARENT, LALT(KC_LEFT),  LALT(KC_RIGHT),  RGUI(KC_SPACE), KC_TRANSPARENT,KC_TRANSPARENT,
                      KC_LEFT,        KC_DOWN,        KC_UP,           KC_RIGHT,       KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
                                      KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT
    ),

    [2] = LAYOUT_ergodox(
    // For numbers
    // left
    RESET,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_EXLM,        KC_AT,          KC_HASH,         KC_DLR,         KC_PERC,KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_1,           KC_2,           KC_3,            KC_4,           KC_5,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT,     KC_TRANSPARENT,
    // right
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_CIRC,        KC_AMPR,        KC_ASTR,         KC_LPRN,        KC_RPRN,       KC_TRANSPARENT,
                      KC_6,           KC_7,           KC_8,            KC_9,           KC_0,          KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
                                      KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
