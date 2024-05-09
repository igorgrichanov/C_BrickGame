#include "tetris_suites.h"

void get_next_test(GameInfo_t *info, int i) {
  info->next = get_tetramino(i);
  info->next_idx = i;
}

void fill_bottom_test(GameInfo_t *info) {
  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 4);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  shift_left(info);
  drop_down(info);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 4);
  shift_right(info);
  shift_right(info);
  shift_right(info);
  shift_right(info);
  drop_down(info);
  attach(info);
}

START_TEST(load_existing_record_test) {
  int record_correct = 200;
  char *user_name = (char *)"serge";
  update_user_record(user_name, record_correct);
  int record_from_file = load_user_record(user_name);
  ck_assert_int_eq(record_correct, record_from_file);
}
END_TEST

START_TEST(load_non_existing_record_test) {
  int record_correct = 0;
  char *user_name = (char *)"kirill";
  int record_from_file = load_user_record(user_name);
  ck_assert_int_eq(record_correct, record_from_file);
}
END_TEST

START_TEST(update_record_test) {
  GameInfo_t *info = init_game_info_tetris((char *)"pavel");
  info = current_game_info(info);
  int new_record = info->high_score + 10;
  update_user_record(info->user_name, new_record);
  int record_from_file = load_user_record(info->user_name);
  ck_assert_int_eq(new_record, record_from_file);
}
END_TEST

START_TEST(game_info_test_init) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  int correct_field[FIELD_ROWS + TETRAMINO_BUFFER + 1][FIELD_COLUMNS + 2] = {
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
  for (int i = 0; i < FIELD_ROWS + TETRAMINO_BUFFER + 1; i++) {
    for (int j = 0; j < FIELD_COLUMNS + 2; j++) {
      ck_assert_int_eq(correct_field[i][j], info->field[i][j]);
    }
  }
  destroy_game_info();
}
END_TEST

START_TEST(rotate_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[2][5] = 1;
  rotate_tetramino();

  attach(info);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 0);
  ck_assert_int_eq(info->field[0][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[0][7], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][6], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][5], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[1][5], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(rotate_test_2) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[2][6] = 1;
  rotate_tetramino();

  attach(info);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 0);
  ck_assert_int_eq(info->field[0][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][6], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][7], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(rotate_test_3) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  drop_new_tetramino();
  get_next_test(info, 2);
  drop_new_tetramino();
  get_next_test(info, 2);
  info->field[2][5] = 1;
  rotate_tetramino();
  rotate_tetramino();
  rotate_tetramino();

  attach(info);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 0);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][7], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][7], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[2][6], info->moving->figure[1][1]);
  ck_assert_int_ne(info->field[0][6], info->moving->figure[1][1]);

  destroy_game_info();
}
END_TEST

START_TEST(add_points_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  for (int i = 17; i < 23; i++) {
    for (int j = 1; j < 11; j++) {
      info->field[i][j] = 1;
    }
  }
  info->field[16][1] = 1;
  info->field[16][2] = 1;
  info->field[16][10] = 1;
  info->field[15][3] = 1;

  add_points(count_filled_rows(info));
  ck_assert_int_eq(info->score, 1800);
  int filled_rows = count_filled_rows(info);
  for (int i = 0; i < filled_rows; i++) {
    move_field_down(info);
  }
  ck_assert_int_eq(count_filled_rows(info), 0);
  ck_assert_int_eq(info->field[22][1], 1);
  ck_assert_int_eq(info->field[22][2], 1);
  ck_assert_int_eq(info->field[22][10], 1);
  ck_assert_int_eq(info->field[21][3], 1);

  change_level();
  update_user_record((char *)"igor", info->score);
  ck_assert_int_eq(info->level, 4);

  destroy_game_info();
}
END_TEST

START_TEST(fsm_test_1) {
  StateMachine_tetris *machine = current_state_machine(NULL);
  ck_assert_ptr_null(machine);
  StateMachine_tetris *mem = init_state_machine_tetris();
  machine = current_state_machine(mem);
  ck_assert_ptr_nonnull(machine);
  destroy_state_machine();
}
END_TEST

START_TEST(delay_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  struct timespec *start = (struct timespec *)malloc(sizeof(struct timespec));
  struct timespec *now = (struct timespec *)malloc(sizeof(struct timespec));
  struct timespec *limit = (struct timespec *)malloc(sizeof(struct timespec));
  clock_gettime(CLOCK_REALTIME, start);
  clock_gettime(CLOCK_REALTIME, now);
  get_tick_limit(start, limit);
  while (check_tick_limit(now, limit)) {
    clock_gettime(CLOCK_REALTIME, now);
  }
  free(start);
  free(now);
  free(limit);

  destroy_game_info();
}
END_TEST

START_TEST(check_bottom_filling_test_1) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  fill_bottom_test(info);

  check_bottom_filling();
  ck_assert_int_eq(info->level, 1);
  ck_assert_int_eq(info->score, 100);

  destroy_game_info();
}
END_TEST

START_TEST(check_bottom_filling_test_2) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  fill_bottom_test(info);
  fill_bottom_test(info);
  fill_bottom_test(info);
  fill_bottom_test(info);
  fill_bottom_test(info);
  fill_bottom_test(info);
  fill_bottom_test(info);

  check_bottom_filling();
  ck_assert_int_eq(info->level, 4);
  ck_assert_int_eq(info->score, 2200);

  destroy_game_info();
}
END_TEST

START_TEST(clear_game_info_test) {
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  fill_bottom_test(info);

  clear_game_info_tetris();

  ck_assert_int_eq(updateCurrentState().level, 1);
  ck_assert_int_eq(updateCurrentState().score, 0);
  ck_assert_int_eq(updateCurrentState().field[22][9], 0);
  ck_assert_int_eq(updateCurrentState().moving->idx, 1);

  destroy_game_info();
}
END_TEST

Suite *tetris_backend_test_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("tetris_backend_test_suite");
  tc = tcase_create("tetris_backend_test_case");

  tcase_add_test(tc, load_existing_record_test);
  tcase_add_test(tc, load_non_existing_record_test);
  tcase_add_test(tc, update_record_test);
  tcase_add_test(tc, game_info_test_init);
  tcase_add_test(tc, rotate_test_1);
  tcase_add_test(tc, rotate_test_2);
  tcase_add_test(tc, rotate_test_3);
  tcase_add_test(tc, add_points_test_1);
  tcase_add_test(tc, fsm_test_1);
  tcase_add_test(tc, delay_test_1);
  tcase_add_test(tc, check_bottom_filling_test_1);
  tcase_add_test(tc, check_bottom_filling_test_2);
  tcase_add_test(tc, clear_game_info_test);

  suite_add_tcase(s, tc);

  return s;
}
