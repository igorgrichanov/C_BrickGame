#ifndef VIEW_TETRIS_H
#define VIEW_TETRIS_H

/**
 * @file
 * @brief модуль View, обеспечивающий отрисовку консольного интерфейса,
 * взаимодействие с пользователем и отправку запросов контроллеру на изменение
 * модели
 */

#include <ncurses.h>
#include <unistd.h>

#include "../../model/fsm.h"
#include "frontend.h"

/// @brief трансляция ввода пользователя в тип UserAction_t
/// @param user_input ввод пользователя с клавиатуры
/// @return ввод пользователя. NO_ACTION возвращается в случае отсутствия ввода
UserAction_t get_signal(int user_input);

/// @brief конечный автомат игры и обработка действий пользователя
void tetris_cli_event_loop();

#endif