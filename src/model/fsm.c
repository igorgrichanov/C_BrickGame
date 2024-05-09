#include "fsm.h"

StateMachine_tetris *init_state_machine_tetris() {
  StateMachine_tetris *state =
      (StateMachine_tetris *)malloc(sizeof(StateMachine_tetris));
  *state = START_STATE;
  return state;
}

StateMachine_tetris *current_state_machine(StateMachine_tetris *machine) {
  static StateMachine_tetris *state = NULL;
  if (machine == NULL) return state;
  state = machine;
  return state;
}

void destroy_state_machine() {
  StateMachine_tetris *machine = current_state_machine(NULL);
  if (machine) free(machine);
}