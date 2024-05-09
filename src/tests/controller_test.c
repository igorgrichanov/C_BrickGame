#include "tetris_suites.h"

START_TEST(userInput_start_test_1) {
  current_state_machine(init_state_machine_tetris());
  userInput(START, false);
  ck_assert_int_eq(1, *current_state_machine(NULL) == SPAWN_STATE);
  destroy_state_machine();
}
END_TEST

START_TEST(userInput_start_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = GAME_OVER_STATE;
  userInput(START, false);
  ck_assert_int_eq(1, *current_state_machine(NULL) == START_STATE);
  destroy_state_machine();
}
END_TEST

START_TEST(userInput_start_test_3) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = SPAWN_STATE;
  userInput(START, false);
  ck_assert_int_eq(1, *current_state_machine(NULL) == SPAWN_STATE);
  destroy_state_machine();
}
END_TEST

START_TEST(userInput_pause_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;
  userInput(PAUSE, false);
  ck_assert_int_eq(1, *current_state_machine(NULL) == PAUSE_STATE);
  destroy_state_machine();
}
END_TEST

START_TEST(userInput_pause_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = PAUSE_STATE;
  userInput(PAUSE, false);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);
  destroy_state_machine();
}
END_TEST

START_TEST(userInput_pause_test_3) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = PAUSE_STATE;
  userInput(DOWN, false);
  ck_assert_int_eq(1, *current_state_machine(NULL) == PAUSE_STATE);
  destroy_state_machine();
}
END_TEST

START_TEST(userInput_terminate_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = START_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  userInput(TERMINATE, false);
  ck_assert_int_eq(1, *current_state_machine(NULL) == EXIT_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_terminate_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = ATTACHING_STATE;
  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);
  userInput(TERMINATE, false);
  ck_assert_int_eq(1, *current_state_machine(NULL) == GAME_OVER_STATE);
  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_left_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(LEFT, false);
  ck_assert_int_eq(info->moving->y, 4);
  ck_assert_int_eq(info->moving->x, 0);
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

  userInput(LEFT, false);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 0);
  ck_assert_int_eq(1, *current_state_machine(NULL) == SHIFTING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_right_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(RIGHT, false);
  ck_assert_int_eq(info->moving->y, 6);
  ck_assert_int_eq(info->moving->x, 0);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_right_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  shift_right(info);
  shift_right(info);
  shift_right(info);
  shift_right(info);

  ck_assert_int_eq(info->moving->y, 7);
  ck_assert_int_eq(info->moving->x, 0);

  userInput(RIGHT, false);
  ck_assert_int_eq(info->moving->y, 7);
  ck_assert_int_eq(info->moving->x, 0);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_down_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(DOWN, false);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 21);
  ck_assert_int_eq(1, *current_state_machine(NULL) == ATTACHING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_down_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  drop_down(info);

  userInput(DOWN, false);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 21);
  ck_assert_int_eq(1, *current_state_machine(NULL) == ATTACHING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_action_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);

  userInput(ACTION, false);
  attach(info);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 0);
  ck_assert_int_eq(info->field[0][7], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[1][7], info->moving->figure[1][2]);
  ck_assert_int_eq(info->field[1][8], info->moving->figure[1][1]);
  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(userInput_action_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

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
  ck_assert_int_eq(info->moving->y, 9);
  ck_assert_int_eq(info->moving->x, 0);

  userInput(ACTION, false);
  ck_assert_int_eq(info->moving->y, 9);
  ck_assert_int_eq(info->moving->x, 0);
  attach(info);
  ck_assert_int_eq(info->field[0][10], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][10], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][9], info->moving->figure[1][2]);
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

  userInput(UP, false);
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 0);
  attach(info);
  ck_assert_int_eq(info->field[1][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[1][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[0][5], info->moving->figure[0][1]);

  ck_assert_int_eq(1, *current_state_machine(NULL) == SHIFTING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(spawn_test) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = SPAWN_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 3);
  drop_new_tetramino();
  get_next_test(info, 5);

  controller_tetris_spawn();
  state = current_state_machine(NULL);

  ck_assert_int_eq(*state == MOVING_STATE, 1);
  ck_assert_int_eq(info->moving->idx, 5);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(moving_test) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 3);
  drop_new_tetramino();
  get_next_test(info, 5);

  controller_tetris_moving();
  state = current_state_machine(NULL);

  ck_assert_int_eq(*state == SHIFTING_STATE, 1);
  ck_assert_int_eq(info->moving->idx, 3);
  ck_assert_int_eq(info->next_idx, 5);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(shifting_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = SHIFTING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 3);
  drop_new_tetramino();
  get_next_test(info, 3);

  controller_tetris_shifting();
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 1);

  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(shifting_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = SHIFTING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 3);
  drop_new_tetramino();
  get_next_test(info, 3);
  drop_down(info);

  controller_tetris_shifting();
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 21);

  ck_assert_int_eq(1, *current_state_machine(NULL) == ATTACHING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(shifting_test_3) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = MOVING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 3);
  drop_new_tetramino();
  get_next_test(info, 3);

  controller_tetris_shifting();
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 0);

  ck_assert_int_eq(1, *current_state_machine(NULL) == MOVING_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(attaching_test_1) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = ATTACHING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  drop_down(info);

  controller_tetris_attaching();
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 21);
  ck_assert_int_eq(info->field[22][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[22][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[21][5], info->moving->figure[0][1]);

  ck_assert_int_eq(1, *current_state_machine(NULL) == SPAWN_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

START_TEST(attaching_test_2) {
  StateMachine_tetris *state =
      current_state_machine(init_state_machine_tetris());
  *state = ATTACHING_STATE;

  GameInfo_t *info = init_game_info_tetris((char *)"igor");
  info = current_game_info(info);

  drop_new_tetramino();
  get_next_test(info, 1);
  drop_new_tetramino();
  get_next_test(info, 1);
  shift_down(info);
  shift_down(info);

  controller_tetris_attaching();
  ck_assert_int_eq(info->moving->y, 5);
  ck_assert_int_eq(info->moving->x, 2);
  ck_assert_int_eq(info->field[3][5], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[3][6], info->moving->figure[1][1]);
  ck_assert_int_eq(info->field[2][5], info->moving->figure[0][1]);

  ck_assert_int_eq(1, *current_state_machine(NULL) == GAME_OVER_STATE);

  destroy_state_machine();
  destroy_game_info();
}
END_TEST

Suite *tetris_controller_test_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("tetris_controller_test_suite");
  tc = tcase_create("tetris_controller_test_case");

  tcase_add_test(tc, userInput_start_test_1);
  tcase_add_test(tc, userInput_start_test_2);
  tcase_add_test(tc, userInput_start_test_3);
  tcase_add_test(tc, userInput_pause_test_1);
  tcase_add_test(tc, userInput_pause_test_2);
  tcase_add_test(tc, userInput_pause_test_3);
  tcase_add_test(tc, userInput_terminate_test_1);
  tcase_add_test(tc, userInput_terminate_test_2);
  tcase_add_test(tc, userInput_left_test_1);
  tcase_add_test(tc, userInput_left_test_2);
  tcase_add_test(tc, userInput_right_test_1);
  tcase_add_test(tc, userInput_right_test_2);
  tcase_add_test(tc, userInput_down_test_1);
  tcase_add_test(tc, userInput_down_test_2);
  tcase_add_test(tc, userInput_action_test_1);
  tcase_add_test(tc, userInput_action_test_2);
  tcase_add_test(tc, userInput_up_test_1);
  tcase_add_test(tc, spawn_test);
  tcase_add_test(tc, moving_test);
  tcase_add_test(tc, shifting_test_1);
  tcase_add_test(tc, shifting_test_2);
  tcase_add_test(tc, shifting_test_3);
  tcase_add_test(tc, attaching_test_1);
  tcase_add_test(tc, attaching_test_2);

  suite_add_tcase(s, tc);

  return s;
}