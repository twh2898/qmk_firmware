/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    NUM_LAYERS,
};

enum my_keycodes {
    MY_MXTG = SAFE_RANGE,
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  Fn  | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, MY_MXTG, KC_LGUI, KC_LALT, TL_LOWR, KC_SPC,          TL_UPPR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      | PgUp | PgDn | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12_1x2uC(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END,  _______,
        _______, _______, _______, _______, _______,          _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    // TODO: WASD and numpad on layer Raise
    // TODO: Shift key on mod row (Raise + Alt, Lower + Left)

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      |      | Up   |      |      |      |      |      |      |      |      | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Left | Down |Right |      |      |      |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Prev | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12_1x2uC(
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MPLY),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
        _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, RGB_RMOD, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______)
};

// clang-format on

#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#ifndef RGB_MATRIX_ENABLED
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    RGB ledcol[NUM_LAYERS] = { {RGB_BLUE}, {RGB_CYAN}, {RGB_GREEN}, {RGB_PURPLE} };
    uint8_t layer = get_highest_layer(layer_state);

  // For special layers: Set the key LEDs, overwriting effects
  if (layer > _QWERTY) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t index = g_led_config.matrix_co[row][col];

        // Valid LED on that position?
        if ((index >= led_min) && (index < led_max) && (index != NO_LED)) {
          // Highlight keys with special functions
          if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
            rgb_matrix_set_color(index, ledcol[layer].g, ledcol[layer].r, ledcol[layer].b);
          }
        }
      }
    }
  }

  // All layers: Underglow and Indicators (with reduced intensity)
  for (uint8_t i = led_min; i < led_max; i++) {
    if (g_led_config.flags[i] == LED_FLAG_UNDERGLOW) {
      rgb_matrix_set_color(i, ledcol[layer].g, ledcol[layer].r, ledcol[layer].b);
    }
    if (g_led_config.flags[i] == LED_FLAG_INDICATOR) {
      rgb_matrix_set_color(i, ledcol[layer].g>>4, ledcol[layer].r>>4, ledcol[layer].b>>4);
    }
  }

  return false;
}

#endif // RGB_MATRIX_ENABLED

#define RBG_VAL 120

bool rainbow = true;
enum layers last_layer = _QWERTY;
extern rgb_config_t rbg_matrix_config;

void bg_layer(enum layers layer) {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    switch (layer) {
        default:
        case _QWERTY:
            rgblight_sethsv(106, 100, RBG_VAL);
            break;
        case _LOWER:
            rgblight_sethsv_noeeprom(64, 200, RBG_VAL);
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(0, 180, RBG_VAL);
            break;
        case _ADJUST:
            rgblight_sethsv_noeeprom(201, 140, RBG_VAL);
            break;
    }
}

void fg_layer(enum layers layer) {
    switch (layer) {
        default:
        case _QWERTY:
            if (rainbow) {
                rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
            }
            else {
                rgb_matrix_mode(RGB_MATRIX_NONE);
                // TODO: set key colors
            }
            break;
        case _LOWER:
            rgb_matrix_mode(RGB_MATRIX_NONE);
            break;
        case _RAISE:
            rgb_matrix_mode(RGB_MATRIX_NONE);
            break;
        case _ADJUST:
            rgb_matrix_mode(RGB_MATRIX_NONE);
            break;
    }
}

void keyboard_post_init_user(void) {
    last_layer = _QWERTY;
    bg_layer(last_layer);
    fg_layer(last_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    last_layer = biton32(state);
    bg_layer(last_layer);
    fg_layer(last_layer);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_MXTG:
      if (record->event.pressed) {
          rainbow = !rainbow;
          fg_layer(last_layer);
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
