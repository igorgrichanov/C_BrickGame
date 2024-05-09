#ifndef CONTROLLER_TETRIS_H
#define CONTROLLER_TETRIS_H

/**
 * @file
 * @brief контроллер, реализующий логику перехода между состояниями конечного
 * автомата
 */

#include <locale.h>
#include <stdbool.h>
#include <time.h>

#include "../model/backend.h"
#include "../model/fsm.h"

/// @brief действия пользователя
typedef enum {
  START,
  PAUSE,
  TERMINATE,
  LEFT,
  RIGHT,
  UP,
  DOWN,
  ACTION,
  NO_ACTION
} UserAction_t;

/// @brief обработка действия пользователя
/// @param action пользовательское действие
/// @param hold зажатие клавиши
void userInput(UserAction_t action, bool hold);

/// @brief подготовка поля к такту: обновление счета, следующей фигуры и др.
void controller_tetris_spawn();

/// @brief обработка состояния MOVING_STATE
void controller_tetris_moving();

/// @brief перемещение фигуры вниз на один ряд
void controller_tetris_shifting();

/// @brief обработка состояния ATTACHING_STATE
void controller_tetris_attaching();

#endif