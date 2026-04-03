// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later



// keycodes:
// https://docs.qmk.fm/keycodes_basic
// https://docs.qmk.fm/feature_advanced_keycodes

#include QMK_KEYBOARD_H
#include "factory.h"

enum my_keycodes {
  LAY_DEF = SAFE_RANGE+1,
  LAYLEDC,
  LAY_GW2,
  LAY_NUM,
  RGBBTOG,
  MAX_RGB,
  RGB_VU1,
  RGB_VD1,
};

static int old_brightness = 255;


    /*
     * ┌───────┬───────┬───────┬───────┐
     * │       │       │       │       │
     * ├───────┼───────┼───────┼───────┤
     * │       │       │       │       │
     * ├───────┼───────┼───────┼───────┤
     * │       │       │       │       │
     * ├───────┼───────┼───────┼───────┤
     * │       │       │       │       │
     * ├───────┼───────┼───────┼───────┤
     * │       │       │       │       │
     * ├───────┼───────┼───────┼───────┤
     * │       │       │       │       │
     * └───────┴───────┴───────┴───────┘
     *
     */

    /*
    [_EMPTY] = LAYOUT(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
        ),
    */

   /*
    ====================
    ========TODO========
    ====================
    - [ ] add binary brightness indicator to brightness control layer
    - [ ] make mouse layer
      - [ ] toggle mouse click buttons
      - [ ] mouse speed control buttons
      - [ ]
    - [ ] make emoji layer
      - could have a second/sub layer that stays up and the main one just goes back to _DEF after I click something
    - [ ] move the layer settings and RGB matrix controls to function so I don't have to worry about all the different options in the buttons switch case
    */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



    /*
     * ┌───────┬─────────┬──────────┬───────┐
     * │lay led│lay mouse│lay gw2   │       │
     * ├───────┼─────────┼──────────┼───────┤
     * │vol+   │Home     │pgup      │bri+   │
     * ├───────┼─────────┼──────────┼───────┤
     * │vol-   │Endp     │pgdw      │bri-   │
     * ├───────┼─────────┼──────────┼───────┤
     * │left   │mid      │righ      │prsc   │
     * ├───────┼─────────┼──────────┼───────┤
     * │left   │m up     │righ      │whu    │
     * ├───────┼─────────┼──────────┼───────┤
     * │mlef   │mdwn     │mrig      │whd    │
     * └───────┴─────────┴──────────┴───────┘
     *
     */
    [_DEF] = LAYOUT(
        LAYLEDC, LAY_NUM, LAY_GW2, XXXXXXX,
        KC_VOLU, KC_HOME, KC_PGUP, KC_BRIU,
        KC_VOLD, KC_END , KC_PGDN, KC_BRID,
        KC_BTN1, KC_BTN3, KC_BTN2, KC_PSCR,
        KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,
        KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
        ),

    /*
     * ┌───────┬───────┬───────┬───────┐
     * │lay def│       │       │       │
     * ├───────┼───────┼───────┼───────┤
     * │tog lig│       │1bri up│bri  up│
     * ├───────┼───────┼───────┼───────┤
     * │MAX bri│       │1bri dw│bridown│
     * ├───────┼───────┼───────┼───────┤
     * │       │       │       │       │
     * ├───────┼───────┼───────┼───────┤
     * │       │       │       │       │
     * ├───────┼───────┼───────┼───────┤
     * │       │       │       │       │
     * └───────┴───────┴───────┴───────┘
     *
     */


    [_LIGHT_CONF] = LAYOUT(
        LAY_DEF, XXXXXXX, XXXXXXX, XXXXXXX,
        RGBBTOG, XXXXXXX, RGB_VU1, RGB_VAI,
        MAX_RGB, XXXXXXX, RGB_VD1, RGB_VAD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        ),


        /*
     * ┌────────┬────────┬────────┬────────┐
     * │        │lay def │        │        │
     * ├────────┼────────┼────────┼────────┤
     * │num lock│   /    │   *    │   -    │
     * ├────────┼────────┼────────┼────────┤
     * │   7    │   8    │   9    │   +    │
     * ├────────┼────────┼────────┼────────┤
     * │   4    │   5    │   6    │   +    │
     * ├────────┼────────┼────────┼────────┤
     * │   1    │   2    │   3    │ enter  │
     * ├────────┼────────┼────────┼────────┤
     * │   0    │   0    │   .    │ enter  │
     * └────────┴────────┴────────┴────────┘
     *
     */


    [_NUM_PAD] = LAYOUT(
        _______,  LAY_DEF,  _______,  _______,
         KC_NUM,  KC_PSLS,  KC_PAST,  KC_PAST,
          KC_P7,  KC_P8,    KC_P9,    KC_PPLS,
          KC_P4,  KC_P5,    KC_P6,    KC_PPLS,
          KC_P1,  KC_P2,    KC_P3,    KC_PENT,
          KC_P0,  KC_P0,    KC_PDOT,  KC_PENT
        ),




    /*
     * ┌───────┬───────┬───────┬───────┐
     * │   `   │  esc  │lay def│  F1   │
     * ├───────┼───────┼───────┼───────┤
     * │   1   │   2   │   3   │   4   │
     * ├───────┼───────┼───────┼───────┤
     * │   q   │   w   │   e   │   5   │
     * ├───────┼───────┼───────┼───────┤
     * │   a   │   s   │   d   │   f   │
     * ├───────┼───────┼───────┼───────┤
     * │   6   │   7   │   8   │   9   │
     * ├───────┼───────┼───────┼───────┤
     * │   0   │   x   │   c   │ space │
     * └───────┴───────┴───────┴───────┘
     *
     */


    [_GW2] = LAYOUT(
        KC_GRV, KC_ESC,  LAY_DEF, KC_F1,
        KC_1,   KC_2,    KC_3,    KC_4,
        KC_5,   KC_Q,    KC_W,    KC_E,
        KC_F,   KC_A,    KC_S,    KC_D,
        KC_6,   KC_7,    KC_8,    KC_9,
        KC_0,   KC_X,    KC_V,    KC_SPC
        ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAY_DEF:
      if (record->event.pressed) {
            layer_move(_DEF);
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_def_layout_effect);

      }
      return false;

    case LAYLEDC:
      if (record->event.pressed) {
            layer_move(_LIGHT_CONF);
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_light_conf_layout_effect);

      }
      return false;

    case LAY_GW2:
      if (record->event.pressed) {
            layer_move(_GW2);
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_gw2_layout_effect);

        }
        return false;
    case LAY_NUM:
        if (record->event.pressed) {
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_num_pad_layout_effect);
            layer_move(_NUM_PAD);
      }
      return false;

    case RGB_VAI:
    case RGB_VAD:
        if (record->event.pressed)
            old_brightness = rgb_matrix_get_val();
        return true;

    case RGB_VU1:
        if (record->event.pressed){
            if (rgb_matrix_get_val() < 255){
                old_brightness = rgb_matrix_get_val();
                rgb_matrix_sethsv(rgb_matrix_get_hue(),rgb_matrix_get_sat(), old_brightness+1);
            }
        }
        return false;
    case RGB_VD1:
        if (record->event.pressed){
            if (rgb_matrix_get_val() > 0){
                old_brightness = rgb_matrix_get_val();
                rgb_matrix_sethsv(rgb_matrix_get_hue(),rgb_matrix_get_sat(), old_brightness-1);
            }
        }
        return false;

    case MAX_RGB:
        if (record->event.pressed) {
            if(rgb_matrix_get_val() != 255){
                old_brightness = rgb_matrix_get_val();
                rgb_matrix_sethsv(rgb_matrix_get_hue(),rgb_matrix_get_sat(), 255);
            }else{
                rgb_matrix_sethsv(rgb_matrix_get_hue(),rgb_matrix_get_sat(), old_brightness);
            }
        }
        return false;

    case RGBBTOG:
      if (record->event.pressed) {
        if(rgb_matrix_get_val() > 2){
            old_brightness = rgb_matrix_get_val();
            rgb_matrix_sethsv(rgb_matrix_get_hue(),rgb_matrix_get_sat(), 2);
        }else if(rgb_matrix_get_val() == 2){
            rgb_matrix_sethsv(rgb_matrix_get_hue(),rgb_matrix_get_sat(), 0);
        }else{
            rgb_matrix_sethsv(rgb_matrix_get_hue(),rgb_matrix_get_sat(), old_brightness);
        }
      }
      return false;

    default:
      return true; // Process all other keycodes normally
  }
}

// void set_brightness_level_indicator(){
//     uint8_t brightness = rgb_matrix_get_val();

// }
