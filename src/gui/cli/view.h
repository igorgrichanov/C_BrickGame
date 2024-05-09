#ifndef VIEW_TETRIS_H
#define VIEW_TETRIS_H

/**
 * @file
 * @brief модуль View, обеспечивающий отрисовку консольного интерфейса,
 * взаимодействие с пользователем и отправку запросов контроллеру на изменение
 * модели
 */

#include <ncurses.h>

#include "../../controller/controller.h"
#include "frontend.h"

/// @brief конечный автомат игры и обработка действий пользователя
void tetris_cli_event_loop();

/// @brief обработка состояния START_STATE
void cli_start_state();

/// @brief обработка состояния MOVING_STATE
void cli_moving_state();

/// @brief обработка состояния PAUSE_STATE
void cli_pause_state();

/// @brief обработка состояния GAME_OVER_STATE
void cli_game_over_state();

/// @brief трансляция ввода пользователя в тип UserAction_t
/// @param user_input ввод пользователя с клавиатуры
/// @return ввод пользователя. NO_ACTION возвращается в случае отсутствия ввода
UserAction_t get_signal(int user_input);

#endif