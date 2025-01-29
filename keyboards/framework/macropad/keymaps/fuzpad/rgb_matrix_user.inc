RGB_MATRIX_EFFECT(def_layout_effect)
RGB_MATRIX_EFFECT(light_conf_layout_effect)



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

  float percent = rgb_matrix_get_val()/255.0;

  /* Layer indicator */
  rgb_matrix_set_color(led_pos[0][0], percent*0x00, MAX(0x01, percent*0xff), percent*0x00);
  rgb_matrix_set_color(led_pos[0][1], percent*0x00, percent*0x00, percent*0x00);
  rgb_matrix_set_color(led_pos[0][2], percent*0x00, percent*0x00, percent*0x00);
  rgb_matrix_set_color(led_pos[0][3], percent*0x00, percent*0x00, percent*0x00);

  rgb_matrix_set_color(led_pos[3][3], percent*0xcc, percent*0x11, percent*0x11); // print screen

  rgb_matrix_set_color(led_pos[1][0], percent*0x4f, percent*0x89, percent*0xff); // vol up
  rgb_matrix_set_color(led_pos[2][0], percent*0x4f, percent*0x89, percent*0xff); // vol down

  rgb_matrix_set_color(led_pos[1][1], percent*0x00, percent*0xcc, percent*0x00); // home
  rgb_matrix_set_color(led_pos[2][1], percent*0x00, percent*0xcc, percent*0x00); // end
  rgb_matrix_set_color(led_pos[1][2], percent*0x00, percent*0xcc, percent*0x00); // page up
  rgb_matrix_set_color(led_pos[2][2], percent*0x00, percent*0xcc, percent*0x00); // page down

  rgb_matrix_set_color(led_pos[1][3], percent*0xcc, percent*0xcc, percent*0x00); // brightness up
  rgb_matrix_set_color(led_pos[2][3], percent*0xcc, percent*0xcc, percent*0x00); // brightness down

  rgb_matrix_set_color(led_pos[3][0], percent*0xcc, percent*0x00, percent*0xcc); // left click
  rgb_matrix_set_color(led_pos[3][1], percent*0xcc, percent*0x00, percent*0xcc); // middle click
  rgb_matrix_set_color(led_pos[3][2], percent*0xcc, percent*0x00, percent*0xcc); // right click
  rgb_matrix_set_color(led_pos[4][0], percent*0xcc, percent*0x00, percent*0xcc); // left click
  rgb_matrix_set_color(led_pos[4][2], percent*0xcc, percent*0x00, percent*0xcc); // right click

  rgb_matrix_set_color(led_pos[5][0], percent*0xcc, percent*0xcc, percent*0xcc); // mouse left
  rgb_matrix_set_color(led_pos[4][1], percent*0xcc, percent*0xcc, percent*0xcc); // mouse move up
  rgb_matrix_set_color(led_pos[5][1], percent*0xcc, percent*0xcc, percent*0xcc); // mouse move down
  rgb_matrix_set_color(led_pos[5][2], percent*0xcc, percent*0xcc, percent*0xcc); // mouse move right

  rgb_matrix_set_color(led_pos[4][3], percent*0xdd, percent*0x00, percent*0x67); // mouse wheel up
  rgb_matrix_set_color(led_pos[5][3], percent*0xdd, percent*0x00, percent*0x67); // mouse wheel down
  return rgb_matrix_check_finished_leds(led_max);
}
static bool light_conf_layout_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  float percent = rgb_matrix_get_val()/255.0;


  rgb_matrix_set_color_all(0x00, 0x00, 0x00);

  /* Layer indicator */
  rgb_matrix_set_color(led_pos[0][0], MAX(0x01, percent*0xff), percent*0x00, percent*0x00);
  rgb_matrix_set_color(led_pos[0][1], percent*0x00, percent*0x00, percent*0x00);
  rgb_matrix_set_color(led_pos[0][2], percent*0x00, percent*0x00, percent*0x00);
  rgb_matrix_set_color(led_pos[0][3], percent*0x00, percent*0x00, percent*0x00);

  rgb_matrix_set_color(led_pos[1][3], percent*0xcc, percent*0xcc, percent*0x00); // brightness up
  rgb_matrix_set_color(led_pos[2][3], percent*0xcc, percent*0xcc, percent*0x00); // brightness down

  rgb_matrix_set_color(led_pos[1][0], percent*0xff, percent*0x00, percent*0x00); // RGB tog off
  rgb_matrix_set_color(led_pos[2][0], percent*0x00, percent*0xff, percent*0x00); // RGB MAX brightness tog

  return rgb_matrix_check_finished_leds(led_max);
}

#endif
