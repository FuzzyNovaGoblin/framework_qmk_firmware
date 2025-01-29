// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "factory.h"

enum my_keycodes {
  LAY_DEF = SAFE_RANGE+1,
  LAYLEDC,
  RGBBTOG,
  MAX_RGB
};

static int old_brightness = 255;


    /*
     * ┌───────┬───────┬───────┬───────┐
     * |       |       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |       |       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |       |       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |       |       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |       |       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |       |       |       |       |
     * └───────┴───────┴───────┴───────┴
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




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /*
     * ┌───────┬───────┬───────┬───────┐
     * |lay led|       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |vol+   |Home   |pgup   |bri+   |
     * ├───────┼───────┼───────┼───────┤
     * |vol-   |Endp    |pgdw   |bri-   |
     * ├───────┼───────┼───────┼───────┤
     * |left   |mid    |righ   |prsc   |
     * ├───────┼───────┼───────┼───────┤
     * |left   |m up   |righ   |whu    |
     * ├───────┼───────┼───────┼───────┤
     * |mlef   |mdwn   |mrig   |whd    |
     * └───────┴───────┴───────┴───────┴
     *
     */
    [_DEF] = LAYOUT(
        LAYLEDC, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_VOLU, KC_HOME, KC_PGUP, KC_BRIU,
        KC_VOLD, KC_END , KC_PGDN, KC_BRID,
        KC_BTN1, KC_BTN3, KC_BTN2, KC_PSCR,
        KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,
        KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
        ),

    /*
     * ┌───────┬───────┬───────┬───────┐
     * |lay def|       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |tog lig|       |       |bri  up|
     * ├───────┼───────┼───────┼───────┤
     * |MAX bri|       |       |bridown|
     * ├───────┼───────┼───────┼───────┤
     * |       |       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |       |       |       |       |
     * ├───────┼───────┼───────┼───────┤
     * |       |       |       |       |
     * └───────┴───────┴───────┴───────┴
     *
     */


    [_LIGHT_CONF] = LAYOUT(
        LAY_DEF, XXXXXXX, XXXXXXX, XXXXXXX,
        RGBBTOG, XXXXXXX, XXXXXXX, RGB_VAI,
        MAX_RGB, XXXXXXX, XXXXXXX, RGB_VAD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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

    case RGB_VAI:
    case RGB_VAD:
        old_brightness = rgb_matrix_get_val();
        return true;

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
        if(rgb_matrix_get_val() > 0){
            old_brightness = rgb_matrix_get_val();
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
