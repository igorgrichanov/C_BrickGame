#include "tetris_suites.h"

START_TEST(shift_down_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[3][6] = 1;
  shift_down(info);
  shift_down(info);
  shift_down(info);
  attach(info);
  ck_assert_int_eq(info->moving->x, 1);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[2][4], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_down_test_2) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[4][6] = 1;
  shift_down(info);
  shift_down(info);
  shift_down(info);
  attach(info);
  ck_assert_int_eq(info->moving->x, 2);
  ck_assert_int_eq(info->field[2][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[3][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[3][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[3][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[3][4], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_down_test_3) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[3][7] = 1;
  shift_down(info);
  shift_down(info);
  shift_down(info);
  attach(info);
  ck_assert_int_eq(info->moving->x, 1);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[2][4], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_down_test_4) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[3][8] = 1;
  shift_down(info);
  shift_down(info);
  shift_down(info);
  attach(info);
  ck_assert_int_eq(info->moving->x, 3);
  ck_assert_int_eq(info->field[3][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[4][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[4][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[4][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[2][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[2][4], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_right_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[0][8] = 1;
  shift_right(info);
  shift_right(info);
  shift_right(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 7);
  ck_assert_int_eq(info->field[0][7], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][7], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][8], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][9], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[1][6], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_right_test_2) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[1][8] = 1;
  shift_right(info);
  shift_right(info);
  shift_right(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->field[0][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[1][9], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_right_test_3) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[2][8] = 1;
  shift_right(info);
  shift_right(info);
  shift_right(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 8);
  ck_assert_int_eq(info->field[0][8], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][8], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][9], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][10], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][7], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_right_test_4) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[2][8] = 1;
  shift_right(info);
  shift_right(info);
  shift_right(info);
  shift_right(info);
  shift_right(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 8);
  ck_assert_int_eq(info->field[0][8], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][8], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][9], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][10], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][7], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_right_test_5) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  rotate_tetramino();
  rotate_tetramino();
  rotate_tetramino();
  shift_right(info);
  shift_right(info);
  shift_right(info);
  shift_right(info);
  shift_right(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 9);
  ck_assert_int_eq(info->field[0][10], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][10], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][10], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[3][10], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][9], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_left_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[0][3] = 1;
  shift_left(info);
  shift_left(info);
  shift_left(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 4);
  ck_assert_int_eq(info->field[0][4], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][4], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][6], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][5], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_left_test_2) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[1][2] = 1;
  shift_left(info);
  shift_left(info);
  shift_left(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 3);
  ck_assert_int_eq(info->field[0][3], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][3], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][4], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[1][6], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_left_test_3) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[2][2] = 1;
  shift_left(info);
  shift_left(info);
  shift_left(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 2);
  ck_assert_int_eq(info->field[0][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][3], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][4], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[1][5], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_left_test_4) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[2][2] = 1;
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, 1);
  ck_assert_int_eq(info->field[0][1], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][1], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][3], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][2], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(shift_left_test_5) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  rotate_tetramino();
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  attach(info);
  ck_assert_int_eq(info->moving->y, -1);
  ck_assert_int_eq(info->field[0][1], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[1][1], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[2][1], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[3][1], info->moving->figure[1][2]);
  ck_assert_int_ne(info->field[1][2], info->moving->figure[1][2]);

  destroy_game_info();
}
END_TEST

START_TEST(drop_down_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 6);
  drop_new_tetramino();
  get_next_test(info, 6);
  drop_down(info);

  attach(info);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 21);
  ck_assert_int_eq(info->field[21][6], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][5], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][6], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][7], info->moving->figure[1][2]);
  ck_assert_int_ne(info->field[20][5], info->moving->figure[1][2]);

  destroy_game_info();
}
END_TEST

START_TEST(drop_down_test_2) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 6);
  drop_new_tetramino();
  get_next_test(info, 6);
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 6);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  drop_down(info);

  attach(info);
  ck_assert_int_eq(info->moving->y, 2);
  ck_assert_int_eq(info->moving->x, 21);
  ck_assert_int_eq(info->field[21][6], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][5], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][6], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][7], info->moving->figure[1][2]);
  ck_assert_int_ne(info->field[20][5], info->moving->figure[1][2]);

  ck_assert_int_eq(info->field[21][3], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][2], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][3], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[22][4], info->moving->figure[1][2]);
  ck_assert_int_ne(info->field[21][1], info->moving->figure[1][2]);

  destroy_game_info();
}
END_TEST

START_TEST(drop_down_test_3) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 6);
  drop_new_tetramino();
  get_next_test(info, 6);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 6);
  shift_left(info);
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 6);
  shift_right(info);
  shift_right(info);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 7);
  ck_assert_int_eq(info->moving->x, 21);
  for (int i = 1; i < 10; i++) {
    ck_assert_int_eq(info->field[22][i], info->moving->figure[1][1]);
  }
  ck_assert_int_eq(info->field[21][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[21][1], info->moving->figure[1][1]);

  ck_assert_int_eq(info->field[21][8], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[21][4], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(drop_down_test_4) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 2);
  ck_assert_int_eq(info->moving->x, 21);

  drop_new_tetramino();
  get_next_test(info, 2);
  rotate_tetramino();
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 0);
  ck_assert_int_eq(info->moving->x, 20);

  ck_assert_int_eq(info->field[20][1], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[20][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][1], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][1], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][3], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][4], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[20][3], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[20][4], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[21][3], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[21][4], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(drop_down_test_5) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 21);

  drop_new_tetramino();
  get_next_test(info, 2);
  shift_right(info);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 6);
  ck_assert_int_eq(info->moving->x, 20);

  ck_assert_int_eq(info->field[21][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][7], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][7], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][8], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[20][6], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[20][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[22][8], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[21][9], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[20][7], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(drop_down_test_6) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 5);
  drop_new_tetramino();
  get_next_test(info, 1);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 2);
  shift_left(info);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 4);
  ck_assert_int_eq(info->moving->x, 21);

  ck_assert_int_eq(info->field[22][1], 5);
  ck_assert_int_eq(info->field[22][2], 5);
  ck_assert_int_ne(info->field[22][3], 5);
  ck_assert_int_ne(info->field[21][1], 5);
  ck_assert_int_eq(info->field[21][2], 5);
  ck_assert_int_eq(info->field[21][3], 5);
  ck_assert_int_eq(info->field[22][4], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][7], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(drop_down_test_7) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 21);

  ck_assert_int_eq(info->field[22][5], 1);
  ck_assert_int_eq(info->field[22][6], 1);
  ck_assert_int_eq(info->field[22][7], 1);
  ck_assert_int_eq(info->field[22][8], 1);
  ck_assert_int_ne(info->field[21][5], 1);

  destroy_game_info();
}
END_TEST

START_TEST(game_over_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  rotate_tetramino();
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 2);
  rotate_tetramino();
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 2);
  rotate_tetramino();
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 2);
  rotate_tetramino();
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 2);
  rotate_tetramino();
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 2);
  rotate_tetramino();
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 5);

  drop_new_tetramino();
  get_next_test(info, 2);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 3);

  ck_assert_int_eq(info->field[3][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[5][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[5][7], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[6][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[8][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[8][7], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[9][6], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[9][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[10][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[5][5], info->moving->figure[1][1]);

  ck_assert_int_eq(check_ceiling(info), 1);

  destroy_game_info();
}
END_TEST

START_TEST(bottom_filling_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 2);
  ck_assert_int_eq(info->moving->x, 21);

  drop_new_tetramino();
  get_next_test(info, 2);
  rotate_tetramino();
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 2);
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 2);
  shift_right(info);
  shift_right(info);
  shift_right(info);
  drop_down(info);
  attach(info);

  ck_assert_int_eq(info->moving->y, 8);
  ck_assert_int_eq(info->moving->x, 21);

  for (int i = 1; i < 11; i++) {
    ck_assert_int_eq(info->field[22][i], 2);
  }

  ck_assert_int_eq(count_filled_rows(info), 1);
  move_field_down(info);
  ck_assert_int_eq(count_filled_rows(info), 0);
  ck_assert_int_eq(info->field[22][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][1], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][1], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][2], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[22][3], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][8], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[22][9], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(drop_down_figure_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_down(info);
  attach(info);
  ck_assert_int_eq(info->moving->x, 21);
  ck_assert_int_eq(info->field[22][5], 1);
  ck_assert_int_eq(info->field[22][6], 1);
  ck_assert_int_eq(info->field[22][7], 1);
  ck_assert_int_eq(info->field[22][8], 1);
  ck_assert_int_ne(info->field[21][5], 1);

  destroy_game_info();
}
END_TEST

Suite *tetris_field_test_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("tetris_field_test_suite");
  tc = tcase_create("tetris_field_test_case");

  tcase_add_test(tc, shift_down_test_1);
  tcase_add_test(tc, shift_down_test_2);
  tcase_add_test(tc, shift_down_test_3);
  tcase_add_test(tc, shift_down_test_4);

  tcase_add_test(tc, shift_right_test_1);
  tcase_add_test(tc, shift_right_test_2);
  tcase_add_test(tc, shift_right_test_3);
  tcase_add_test(tc, shift_right_test_4);
  tcase_add_test(tc, shift_right_test_5);

  tcase_add_test(tc, shift_left_test_1);
  tcase_add_test(tc, shift_left_test_2);
  tcase_add_test(tc, shift_left_test_3);
  tcase_add_test(tc, shift_left_test_4);
  tcase_add_test(tc, shift_left_test_5);

  tcase_add_test(tc, drop_down_test_1);
  tcase_add_test(tc, drop_down_test_2);
  tcase_add_test(tc, drop_down_test_3);
  tcase_add_test(tc, drop_down_test_4);
  tcase_add_test(tc, drop_down_test_5);
  tcase_add_test(tc, drop_down_test_6);
  tcase_add_test(tc, drop_down_test_7);

  tcase_add_test(tc, game_over_test_1);
  tcase_add_test(tc, bottom_filling_test_1);
  tcase_add_test(tc, drop_down_figure_1);

  suite_add_tcase(s, tc);

  return s;
}