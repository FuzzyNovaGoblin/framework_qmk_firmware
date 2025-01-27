RGB_MATRIX_EFFECT(def_layout_effect)



#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// static int led_index[24]  = {5, 2, 22, 17,
//                           4, 0, 20, 18,
//                           7, 1, 21, 16,
//                           6, 3, 23, 19,
//                           9, 11, 15, 13,
//                           8, 10, 14, 12};
static int led_pos[6][4]  = {{5,  2, 22, 17},
                          {4,  0, 20, 18},
                          {7,  1, 21, 16},
                          {6,  3, 23, 19},
                          {9, 11, 15, 13},
                          {8, 10, 14, 12}};

// e.g: A simple effect, self-contained within a single method
static bool def_layout_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

//   rgb_matrix_set_color(led_pos[0][0], 0x00, 0x00, 0x00); // print screen

  rgb_matrix_set_color(led_pos[3][3], 0xcc, 0x11, 0x11); // print screen

  rgb_matrix_set_color(led_pos[1][0], 0x4f, 0x89, 0xff); // vol up
  rgb_matrix_set_color(led_pos[2][0], 0x4f, 0x89, 0xff); // vol down

  rgb_matrix_set_color(led_pos[1][1], 0x00, 0xcc, 0x00); // home
  rgb_matrix_set_color(led_pos[2][1], 0x00, 0xcc, 0x00); // end
  rgb_matrix_set_color(led_pos[1][2], 0x00, 0xcc, 0x00); // page up
  rgb_matrix_set_color(led_pos[2][2], 0x00, 0xcc, 0x00); // page down

  rgb_matrix_set_color(led_pos[1][3], 0xcc, 0xcc, 0x00); // brightness up
  rgb_matrix_set_color(led_pos[2][3], 0xcc, 0xcc, 0x00); // brightness down

  rgb_matrix_set_color(led_pos[3][0], 0xcc, 0x00, 0xcc); // left click
  rgb_matrix_set_color(led_pos[3][1], 0xcc, 0x00, 0xcc); // middle click
  rgb_matrix_set_color(led_pos[3][2], 0xcc, 0x00, 0xcc); // right click
  rgb_matrix_set_color(led_pos[4][0], 0xcc, 0x00, 0xcc); // left click
  rgb_matrix_set_color(led_pos[4][2], 0xcc, 0x00, 0xcc); // right click

  rgb_matrix_set_color(led_pos[5][0], 0xcc, 0xcc, 0xcc); // mouse left
  rgb_matrix_set_color(led_pos[4][1], 0xcc, 0xcc, 0xcc); // mouse move up
  rgb_matrix_set_color(led_pos[5][1], 0xcc, 0xcc, 0xcc); // mouse move down
  rgb_matrix_set_color(led_pos[5][2], 0xcc, 0xcc, 0xcc); // mouse move right

  rgb_matrix_set_color(led_pos[4][3], 0xdd, 0x00, 0x67); // mouse wheel up
  rgb_matrix_set_color(led_pos[5][3], 0xdd, 0x00, 0x67); // mouse wheel down
  return rgb_matrix_check_finished_leds(led_max);
}

#endif
