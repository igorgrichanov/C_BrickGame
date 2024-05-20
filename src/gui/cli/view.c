#include "view.h"

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

void tetris_cli_event_loop() {
  print_overlay();
  print_options();

  while (current_game_info(NULL)->score != -1) {
    userInput(get_signal(getch()));
    print_current_screen(updateCurrentState());
    usleep(UPD_FREQUENCY_MICROSECONDS);
  }
}