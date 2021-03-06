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

    // KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
    // KC_AUDIO_MUTE,


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /*
     * ,--------------------------------------------------.    ,--------------------------------------------------.
     * |    0   |   1  |   2  |   3  |   4  |   5  |  6   |    |  38  |  39  |  40  |  41  |  42  |  43  |   44   |
     * |--------+------+------+------+------+------+------|    |------+------+------+------+------+------+--------|
     * |    7   |   8  |   9  |  10  |  11  |  12  |  13  |    |  45  |  46  |  47  |  48  |  49  |  50  |   51   |
     * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
     * |   14   |  15  |  16  |  17  |  18  |  19  |------|    |------|  52  |  53  |  54  |  55  |  56  |   57   |
     * |--------+------+------+------+------+------|  26  |    |  58  |------+------+------+------+------+--------|
     * |   20   |  21  |  22  |  23  |  24  |  25  |      |    |      |  59  |  60  |  61  |  62  |  63  |   64   |
     * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
     *   |  27  |  28  |  29  |  30  |  31  |                                |  65  |  66  |  67  |  68  |  69  |
     *   `----------------------------------'                                `----------------------------------'
     *                                       ,-------------.  ,-------------.
     *                                       |  32  |  33  |  |  70  |  71  |
     *                                ,------+------+------|  |------+------+------.
     *                                |      |      |  34  |  |  72  |      |      |
     *                                |  35  |  36  |------|  |------|  74  |  75  |
     *                                |      |      |  37  |  |  73  |      |      |
     *                                `--------------------'  `--------------------'
     */

[0] = LAYOUT_ergodox_pretty(
  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX , XXXXXXX, XXXXXXX       , XXXXXXX , XXXXXXX       , XXXXXXX     , XXXXXXX        ,
   KC_TAB,        KC_Q,    KC_W,    KC_E,           KC_R,    KC_T, KC_LANG2,      KC_LANG1, KC_Y   , KC_U          , KC_I    , KC_O          , KC_P        , KC_BSPACE      ,
 KC_LCTRL,        KC_A,    KC_S,    KC_D,           KC_F,    KC_G,                          KC_H   , KC_J          , KC_K    , KC_L          , KC_SCOLON   , KC_ENTER       ,
KC_LSHIFT,        KC_Z,    KC_X,    KC_C,           KC_V,    KC_B,  XXXXXXX,      XXXXXXX , KC_N   , KC_M          , KC_COMMA, KC_DOT        , KC_SLASH    , SFT_T(KC_QUOTE),
  XXXXXXX, KC_CAPSLOCK, KC_LALT, KC_LGUI,          MO(2),                                            MO(1)         , KC_RGUI , RGUI(KC_SPACE), RSFT(KC_TAB), KC_TAB         ,

                                                          XXXXXXX,  XXXXXXX,      XXXXXXX , XXXXXXX,
                                                                    XXXXXXX,      XXXXXXX ,
                                          LT(3,KC_SPACE), XXXXXXX,  XXXXXXX,      XXXXXXX , XXXXXXX, LT(3,KC_SPACE)
),

[1] = LAYOUT_ergodox_pretty(
         _______,                _______,          _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
LCTL(LGUI(KC_Q)),                XXXXXXX,          XXXXXXX,  KC_GRV, KC_BSLS, KC_LBRC, _______,      _______, KC_RBRC, KC_MINS, KC_EQL , XXXXXXX, XXXXXXX, _______,
         _______,                   KC_1,             KC_2,    KC_3,    KC_4,    KC_5,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
         _______, LGUI(LSFT(LCTL(KC_4))), LGUI(LSFT(KC_4)), XXXXXXX, XXXXXXX, XXXXXXX, _______,      _______, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,
         XXXXXXX,                XXXXXXX,          _______, _______, XXXXXXX,                                          XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,

                                                                              _______, _______,      _______, _______,
                                                                                       _______,      _______,
                                                                     XXXXXXX, _______, _______,      _______, _______, XXXXXXX
),

[2] = LAYOUT_ergodox_pretty(
_______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
 KC_ESC, XXXXXXX, XXXXXXX, KC_TILD, KC_PIPE, KC_LCBR, _______,      _______, KC_RCBR, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, RESET  ,
_______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,      _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX,
XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,                                          XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,

                                             _______, _______,      _______, _______,
                                                      _______,      _______,
                                    KC_MPLY, _______, _______,      _______, _______, KC_MPLY
),

[3] = LAYOUT_ergodox_pretty(
_______,   _______,     _______,          _______,       _______,       _______, _______,      _______, _______ , _______      , _______       , _______       , _______, _______,
_______,   XXXXXXX,     XXXXXXX,          XXXXXXX,       XXXXXXX,      KC_LANG2, _______,      _______, KC_LANG1, LALT(KC_LEFT), LALT(KC_RIGHT), RGUI(KC_SPACE), XXXXXXX, _______,
_______, KC__VOLUP, KC__VOLDOWN,    KC_AUDIO_MUTE, LGUI(KC_RBRC),       XXXXXXX,                        KC_LEFT , KC_DOWN      , KC_UP         , KC_RGHT       , XXXXXXX, _______,
_______,    KC_F14,      KC_F15, LGUI(LSFT(KC_C)),       XXXXXXX, LGUI(KC_LBRC), _______,      _______, XXXXXXX , RSFT(KC_TAB) , KC_TAB        , XXXXXXX       , XXXXXXX, XXXXXXX,
XXXXXXX,   XXXXXXX,     _______,          _______,       XXXXXXX,                                                 XXXXXXX      , _______       , XXXXXXX       , XXXXXXX, XXXXXXX,

                                                                        _______, _______,      _______, _______ ,
                                                                                 _______,      _______,
                                                         XXXXXXX,       _______, _______,      _______, _______ , XXXXXXX
)
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
