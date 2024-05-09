#include "view.h"

void tetris_cli_event_loop() {
  StateMachine_tetris *state = current_state_machine(NULL);
  bool break_flag = false;
  nodelay(stdscr, TRUE);
  while (!break_flag) {
    switch (*state) {
      case START_STATE:
        cli_start_state();
        break;
      case SPAWN_STATE:
        controller_tetris_spawn();
        break;
      case MOVING_STATE:
        print_current_screen(updateCurrentState());
        cli_moving_state();
        controller_tetris_moving();
        break;
      case PAUSE_STATE:
        cli_pause_state();
        break;
      case SHIFTING_STATE:
        controller_tetris_shifting();
        break;
      case ATTACHING_STATE:
        controller_tetris_attaching();
        break;
      case GAME_OVER_STATE:
        cli_game_over_state();
        break;
      case EXIT_STATE:
        break_flag = true;
        break;
    }
  }
}

void cli_start_state() {
  clean_game();
  draw_welcome_screen(updateCurrentState());
  while (*current_state_machine(NULL) == START_STATE) {
    userInput(get_signal(getch()), false);
  }
  clean_welcome_screen();
  print_options();
}

void cli_moving_state() {
  StateMachine_tetris *state = current_state_machine(NULL);

  struct timespec *start = (struct timespec *)malloc(sizeof(struct timespec));
  struct timespec *now = (struct timespec *)malloc(sizeof(struct timespec));
  struct timespec *limit = (struct timespec *)malloc(sizeof(struct timespec));

  clock_gettime(CLOCK_REALTIME, start);
  clock_gettime(CLOCK_REALTIME, now);
  get_tick_limit(start, limit);
  while (check_tick_limit(now, limit) && *state == MOVING_STATE) {
    userInput(get_signal(getch()), false);
    if (now->tv_nsec % 50000000 == 0) update_moving_field(updateCurrentState());
    clock_gettime(CLOCK_REALTIME, now);
  }
  free(start);
  free(now);
  free(limit);
}

void cli_pause_state() {
  print_pause_screen();
  while (*current_state_machine(NULL) == PAUSE_STATE) {
    userInput(get_signal(getch()), false);
  }
}

void cli_game_over_state() {
  print_game_over_screen();
  clear_game_info_tetris();
  while (*current_state_machine(NULL) == GAME_OVER_STATE) {
    userInput(get_signal(getch()), false);
  }
}

UserAction_t get_signal(int user_input) {
  UserAction_t input = NO_ACTION;
  switch (user_input) {
    case '\n':
      input = START;
      break;
    case 'p':
      input = PAUSE;
      break;
    case 'q':
      input = TERMINATE;
      break;
    case KEY_LEFT:
      input = LEFT;
      break;
    case KEY_RIGHT:
      input = RIGHT;
      break;
    case KEY_UP:
      input = UP;
      break;
    case KEY_DOWN:
      input = DOWN;
      break;
    case ' ':
      input = ACTION;
      break;
    default:
      break;
  }
  return input;
}