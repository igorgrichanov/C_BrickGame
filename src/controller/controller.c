#include "controller.h"

void userInput(UserAction_t action, bool hold) {
  if (hold) return;
  GameInfo_t *info = current_game_info(NULL);
  StateMachine_tetris *state = current_state_machine(NULL);
  switch (action) {
    case START: {
      if (*state == START_STATE) {
        *state = SPAWN_STATE;
      } else if (*state == GAME_OVER_STATE) {
        *state = START_STATE;
      }
      break;
    }
    case PAUSE: {
      if (*state == MOVING_STATE) {
        *state = PAUSE_STATE;
      } else if (*state == PAUSE_STATE) {
        *state = MOVING_STATE;
      }
      break;
    }
    case TERMINATE: {
      if (*state == START_STATE || *state == GAME_OVER_STATE) {
        *state = EXIT_STATE;
      } else {
        *state = GAME_OVER_STATE;
      }
      break;
    }
    case LEFT: {
      if (*state == MOVING_STATE) {
        shift_left(info);
      }
      break;
    }
    case RIGHT: {
      if (*state == MOVING_STATE) {
        shift_right(info);
      }
      break;
    }
    case DOWN: {
      if (*state == MOVING_STATE) {
        drop_down(info);
        *state = ATTACHING_STATE;
      }
      break;
    }
    case ACTION: {
      if (*state == MOVING_STATE) rotate_tetramino();
      break;
    }
    default:
      break;
  }
}

void controller_tetris_spawn() {
  StateMachine_tetris *state = current_state_machine(NULL);
  if (*state != SPAWN_STATE) return;
  drop_new_tetramino();
  get_next_tetramino(current_game_info(NULL));
  *state = MOVING_STATE;
}

void controller_tetris_moving() {
  StateMachine_tetris *state = current_state_machine(NULL);
  if (*state == MOVING_STATE) *state = SHIFTING_STATE;
}

void controller_tetris_shifting() {
  StateMachine_tetris *state = current_state_machine(NULL);
  if (*state != SHIFTING_STATE) return;
  GameInfo_t *info = current_game_info(NULL);
  int shifted = shift_down(info);
  if (shifted) {
    *state = MOVING_STATE;
  } else {
    *state = ATTACHING_STATE;
  }
}

void controller_tetris_attaching() {
  StateMachine_tetris *state = current_state_machine(NULL);
  if (*state != ATTACHING_STATE) return;
  GameInfo_t *info = current_game_info(NULL);
  attach(info);
  if (check_ceiling(info)) {
    update_user_record(current_game_info(NULL)->user_name,
                       current_game_info(NULL)->score);
    *state = GAME_OVER_STATE;
  } else {
    check_bottom_filling();
    *state = SPAWN_STATE;
  }
}