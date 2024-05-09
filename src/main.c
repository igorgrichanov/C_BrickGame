#include <ncurses.h>

#include "gui/cli/view.h"

/// @brief инициализация библиотеки ncurses
void init_ncurses() {
  /// инициализация библиотеки
  initscr();
  /// выключение буферизации ввода
  cbreak();
  /// не выводить символы, полученные от пользователя
  noecho();
  setlocale(LC_ALL, "");
  /// видимость курсора (0,1,2)
  curs_set(FALSE);
  /// обработка символов с дополнительной клавиатуры (KEY_)
  keypad(stdscr, TRUE);
}

/// @brief инициализация цветов тетрамино (1-7) и цвета текста OPTIONS
void init_color_pairs() {
  if (has_colors()) {
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_RED, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_YELLOW);
  }
}

void play_console_tetris(char *user_name) {
  srand(time(NULL));
  current_game_info(init_game_info_tetris(user_name));
  current_state_machine(init_state_machine_tetris());

  tetris_cli_event_loop();

  destroy_game_info();
  destroy_state_machine();
}

int main() {
  char *user_name = ask_user_name();
  init_ncurses();
  init_color_pairs();

  play_console_tetris(user_name);

  free(user_name);
  endwin();

  return 0;
}
