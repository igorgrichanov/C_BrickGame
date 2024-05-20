#include "tetris_suites.h"

START_TEST(userInput_start_test_1) {
  current_state_machine(init_state_machine_tetris());
  current_game_info(init_game_info_tetris((char *)"Igor"));
  userInput(START);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);
  ck_assert_ptr_eq(updateCurrentState().bottom_text, NULL);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_start_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  current_game_info(init_game_info_tetris((char *)"Igor"));
  *state = GAME_OVER_STATE;
  userInput(START);
  ck_assert_int_eq(1, *current_state_machine(NULL) == START_STATE);
  ck_assert_ptr_ne(updateCurrentState().bottom_text, NULL);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_start_test_3) {
  current_state_machine(init_state_machine_tetris());
  current_game_info(init_game_info_tetris((char *)"Igor"));
  userInput(START);
  userInput(START);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_pause_test_1) {
  current_state_machine(init_state_machine_tetris());
  current_game_info(init_game_info_tetris((char *)"Igor"));

  userInput(START);

  userInput(PAUSE);
  ck_assert_int_eq(1, *current_state_machine(NULL) == PAUSE_STATE);
  ck_assert_int_eq(updateCurrentState().pause == true, 1);
  ck_assert_int_eq('P', updateCurrentState().field[Y_WIN][3]);

  userInput(PAUSE);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);
  ck_assert_int_eq(updateCurrentState().pause == false, 1);
  ck_assert_ptr_eq(updateCurrentState().bottom_text, NULL);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_pause_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  current_game_info(init_game_info_tetris((char *)"Igor"));

  *state = PAUSE_STATE;
  userInput(DOWN);
  ck_assert_int_eq(1, *current_state_machine(NULL) == PAUSE_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_terminate_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = START_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  userInput(TERMINATE);
  ck_assert_int_eq(1, *state == EXIT_STATE);
  ck_assert_int_eq(updateCurrentState().score, -1);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_terminate_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = PAUSE_STATE;
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(TERMINATE);
  ck_assert_int_eq(1, *current_state_machine(NULL) == PAUSE_STATE);
  ck_assert_int_ne(updateCurrentState().score, -1);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_terminate_test_3) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(TERMINATE);
  ck_assert_int_eq(1, *current_state_machine(NULL) == START_STATE);
  ck_assert_int_eq(updateCurrentState().score, 0);
  ck_assert_int_eq(updateCurrentState().game_over == false, 1);
  ck_assert_ptr_ne(updateCurrentState().bottom_text, NULL);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(timer_expired_test_1) {
  current_state_machine(init_state_machine_tetris());
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(START);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  userInput(LEFT);

  moving_timer_has_expired();
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);
  ck_assert_int_eq(info->moving->row, MOVING_INIT_ROW + 1);
  ck_assert_int_eq(info->moving->col, MOVING_INIT_COL - 1);
  ck_assert_ptr_eq(updateCurrentState().bottom_text, NULL);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(timer_expired_test_2) {
  current_state_machine(init_state_machine_tetris());
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(START);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  userInput(LEFT);
  drop_down(info);

  moving_timer_has_expired();
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);
  ck_assert_int_eq(info->moving->row, MOVING_INIT_ROW);
  ck_assert_int_eq(info->moving->col, MOVING_INIT_COL);
  ck_assert_int_eq(info->field[19][MOVING_INIT_COL - 1], 1);
  ck_assert_int_eq(info->field[19][MOVING_INIT_COL + 2], 1);
  ck_assert_int_ne(info->field[19][MOVING_INIT_COL + 3], 1);
  ck_assert_ptr_eq(updateCurrentState().bottom_text, NULL);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(timer_expired_test_3) {
  current_state_machine(init_state_machine_tetris());
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  userInput(START);
  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  moving_timer_has_expired();
  moving_timer_has_expired();
  moving_timer_has_expired();
  ck_assert_int_eq(info->moving->row, MOVING_INIT_ROW + 3);
  attach(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  moving_timer_has_expired();
  moving_timer_has_expired();
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);
  moving_timer_has_expired();

  ck_assert_int_eq(1, *current_state_machine(NULL) == GAME_OVER_STATE);
  ck_assert_int_eq(info->moving->row, -1);
  ck_assert_int_eq(info->moving->col, MOVING_INIT_COL);
  ck_assert_int_eq(info->field[0][MOVING_INIT_COL], 0);
  ck_assert_int_eq(info->field[0][MOVING_INIT_COL + 2], 0);
  ck_assert_int_eq(info->field[19][MOVING_INIT_COL + 3], 0);
  ck_assert_int_eq(1, info->game_over == true);
  ck_assert_ptr_ne(updateCurrentState().bottom_text, NULL);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_left_test_1) {
  current_state_machine(init_state_machine_tetris());

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(START);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(LEFT);
  ck_assert_int_eq(info->moving->row, MOVING_INIT_ROW);
  ck_assert_int_eq(info->moving->col, MOVING_INIT_COL - 1);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_left_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = SHIFTING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(LEFT);
  ck_assert_int_eq(info->moving->row, MOVING_INIT_ROW);
  ck_assert_int_eq(info->moving->col, MOVING_INIT_COL);
  ck_assert_int_eq(1, *current_state_machine(NULL) == SHIFTING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_right_test_1) {
  current_state_machine(init_state_machine_tetris());

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(START);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(RIGHT);
  ck_assert_int_eq(info->moving->row, MOVING_INIT_ROW);
  ck_assert_int_eq(info->moving->col, MOVING_INIT_COL + 1);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_right_test_2) {
  current_state_machine(init_state_machine_tetris());

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(START);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  shift_right(info);
  shift_right(info);
  shift_right(info);
  shift_right(info);

  ck_assert_int_eq(info->moving->row, MOVING_INIT_ROW);
  ck_assert_int_eq(info->moving->col, 6);

  userInput(RIGHT);
  ck_assert_int_eq(info->moving->row, MOVING_INIT_ROW);
  ck_assert_int_eq(info->moving->col, 6);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_down_test_1) {
  current_state_machine(init_state_machine_tetris());

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(START);

  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(DOWN);
  ck_assert_int_eq(info->field[19][MOVING_INIT_COL], 1);
  ck_assert_int_eq(info->field[19][MOVING_INIT_COL + 3], 1);
  ck_assert_int_ne(info->field[19][MOVING_INIT_COL + 4], 1);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_down_test_2) {
  current_state_machine(init_state_machine_tetris());

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(START);

  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  drop_down(info);

  userInput(DOWN);
  ck_assert_int_eq(info->field[19][MOVING_INIT_COL], 1);
  ck_assert_int_eq(info->field[19][MOVING_INIT_COL + 3], 1);
  ck_assert_int_ne(info->field[19][MOVING_INIT_COL + 4], 1);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_action_test_1) {
  current_state_machine(init_state_machine_tetris());

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  userInput(START);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(ACTION);
  shift_down(info);
  shift_down(info);
  shift_down(info);
  attach(info);
  ck_assert_int_eq(info->moving->row, 0);
  ck_assert_int_eq(info->moving->col, MOVING_INIT_COL);
  ck_assert_int_eq(info->field[0][6], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[1][6], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[1][7], info->moving->figure[1][1]);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_action_test_2) {
  current_state_machine(init_state_machine_tetris());

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  userInput(START);

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
  shift_down(info);
  shift_down(info);
  shift_down(info);
  ck_assert_int_eq(info->moving->row, 0);
  ck_assert_int_eq(info->moving->col, 8);

  userInput(ACTION);
  ck_assert_int_eq(info->moving->row, 0);
  ck_assert_int_eq(info->moving->col, 8);
  attach(info);
  ck_assert_int_eq(info->field[0][9], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][9], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][8], info->moving->figure[1][2]);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_up_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = SHIFTING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  shift_down(info);
  shift_down(info);
  shift_down(info);

  userInput(UP);
  ck_assert_int_eq(info->moving->row, 0);
  ck_assert_int_eq(info->moving->col, MOVING_INIT_COL);
  attach(info);
  ck_assert_int_eq(info->field[1][4], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[0][4], info->moving->figure[0][1]);

  ck_assert_int_eq(1, *current_state_machine(NULL) == SHIFTING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

Suite *tetris_controller_test_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("fsm_test_suite");
  tc = tcase_create("fsm_test_case");

  tcase_add_test(tc, userInput_start_test_1);
  tcase_add_test(tc, userInput_start_test_2);
  tcase_add_test(tc, userInput_start_test_3);
  tcase_add_test(tc, userInput_pause_test_1);
  tcase_add_test(tc, userInput_pause_test_2);
  tcase_add_test(tc, userInput_terminate_test_1);
  tcase_add_test(tc, userInput_terminate_test_2);
  tcase_add_test(tc, userInput_terminate_test_3);
  tcase_add_test(tc, timer_expired_test_1);
  tcase_add_test(tc, timer_expired_test_2);
  tcase_add_test(tc, timer_expired_test_3);
  tcase_add_test(tc, userInput_left_test_1);
  tcase_add_test(tc, userInput_left_test_2);
  tcase_add_test(tc, userInput_right_test_1);
  tcase_add_test(tc, userInput_right_test_2);
  tcase_add_test(tc, userInput_down_test_1);
  tcase_add_test(tc, userInput_down_test_2);
  tcase_add_test(tc, userInput_action_test_1);
  tcase_add_test(tc, userInput_action_test_2);
  tcase_add_test(tc, userInput_up_test_1);

  suite_add_tcase(s, tc);

  return s;
}