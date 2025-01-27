// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "factory.h"

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
     * ┌────┬────┬────┬────┐
     * |    |    |    |    |
     * ├────┼────┼────┼────┤
     * |vol+|Home|pgup|bri+|
     * ├────┼────┼────┼────┤
     * |vol-|End |pgdw|bri-|
     * ├────┼────┼────┼────┤
     * |left|mid |righ|prsc|
     * ├────┼────┼────┼────┤
     * |left|m up|righ|whu |
     * ├────┼────┼────┼────┤
     * |mlef|mdwn|mrig|whd |
     * └────┴────┴────┴────┴
     *
     */
    [_DEF] = LAYOUT(
        _______,           _______,      _______,       _______,
        KC_AUDIO_VOL_UP,   KC_HOME,      KC_PAGE_UP,    KC_BRIU,
        KC_AUDIO_VOL_DOWN, KC_END,       KC_PAGE_DOWN,  KC_BRID,
        KC_MS_BTN1,        KC_MS_BTN3,   KC_MS_BTN2,    KC_PRINT_SCREEN,
        KC_MS_BTN1,        KC_MS_UP,     KC_MS_BTN2,    KC_MS_WH_UP,
        KC_MS_LEFT,        KC_MS_DOWN,   KC_MS_RIGHT,   KC_MS_WH_DOWN
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
