// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "factory.h"

enum my_keycodes {
  LAY_DEF = SAFE_RANGE+1,
  LAYLEDC,
  RGBBTOG
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
     * |bri  up|       |       |tog lig|
     * ├───────┼───────┼───────┼───────┤
     * |bridown|       |       |       |
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
        RGB_VAI, XXXXXXX, XXXXXXX, RGBBTOG,
        RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        ),


    /*
     *         ┌───────┬───────┬───────┬───────┐
     *  4 keys │ RGB   │ RGB + │ RGB + │ RGB + │
     *         │Toggle │ Speed │ Hue   │ Sat   │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │Numlock│ RGB - │ RGB - │ RGB - │
     *         │       │ Speed │ Hue   │ Sat   │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Home  │   ↑   │ Page  │RGB Nxt│
     *         │       │       │ Up    │Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │  ←    │       │   →   │RGB Prv│
     *         │       │       │       │Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ End   │  ↓    │ Page  │ BL    │
     *         │       │       │ Down  │ Step  │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Insert│ Insert│ Delete│ BL    │
     *         │       │       │       │ Step  │
     *         └───────┴───────┴───────┴───────┘
     * 24 total
     */
    // [_FN] = LAYOUT(RGB_TOG, RGB_SPI, RGB_HUI, RGB_SAI, _______, RGB_SPD, RGB_HUD, RGB_SAD, _______, _______, _______, RGB_MOD, _______, _______, _______, RGB_RMOD, _______, _______, _______, BL_STEP, _______, _______, _______, BL_STEP),
    /* Alphabet
     *         ┌────┬────┬────┬────┐
     *  4 keys │ A  │ B  │ C  │ D  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ E  │ F  │ G  │ H  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ I  │ J  │ K  │ L  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ M  │ N  │ O  │ P  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ Q  │ R  │ S  │ T  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ U  │ V  │ W  │ X  │
     *         └────┴────┴────┴────┘
     * 24 total
     */
    // [_FACTORY] = LAYOUT(KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T, KC_U, KC_V, KC_W, KC_X),
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
