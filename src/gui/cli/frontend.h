#ifndef CONSOLE_FRONTEND_H
#define CONSOLE_FRONTEND_H

/**
 * @file
 * @brief функции вывода информации на экран
 */

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../../model/defines.h"
#include "../../model/structures.h"

/// @brief полное обноление экрана
/// @param game_info информация об игре
void print_current_screen(GameInfo_t game_info);

/// @brief ежетактная печать падающего тетрамино
/// @param game_info информация об игре
void print_moving_tetramino(GameInfo_t game_info);

/// @brief печать поля
/// @param game_info информация об игре
void print_field(GameInfo_t game_info);

/// @brief обновление экрана в MOVING_STATE
/// @param game_info информация об игре
void update_moving_field(GameInfo_t game_info);

/// @brief авторизация пользователя
/// @return имя пользователя
char *ask_user_name();

/// @brief отрисовка макета для тетриса
void print_overlay();

/// @brief очистка игрового поля
void clean_field();

/// @brief очистка макета после предыдущей игры
void clean_game();

/// @brief отрисовка прямоугольника, отображаемого в консоли
/// @param top положение верхней границы
/// @param bottom положение нижней грацицы
/// @param left положение левой границы
/// @param right положение правой границы
void draw_rectangle(int top, int bottom, int left, int right);

/// @brief приветственное окно
/// @param game_info информация об игре
void draw_welcome_screen(GameInfo_t game_info);

/// @brief удаление приветствия при старте игры
void clean_welcome_screen();

/// @brief печать дополнительной информации по игре
/// @param game_info информация об игре
void print_game_info(GameInfo_t game_info);

/// @brief удаление дополнительной информации для обновления
void clean_game_info();

/// @brief печать следующей фигуры
/// @param game_info информация об игре
void print_next_tetramino(GameInfo_t game_info);

/// @brief очистка поля следующей фигуры
void clean_next_tetramino();

/// @brief вывод информации о кнопках паузы и завершения игры
void print_options();

/// @brief печать экрана режима паузы
void print_pause_screen();

/// @brief печать экрана окончания игры
void print_game_over_screen();

/// @brief печать экрана победы
void print_win_screen();

/// @brief печать обычного экрана с игрой после паузы
/// @param game_info информация об игре
void clean_pause_screen(GameInfo_t game_info);
#endif