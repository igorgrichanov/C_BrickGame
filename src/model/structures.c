#include "structures.h"

GameInfo_t *current_game_info(GameInfo_t *game_info) {
  static GameInfo_t *info = NULL;
  if (game_info == NULL) return info;
  info = game_info;
  return info;
}

GameInfo_t updateCurrentState() {
  GameInfo_t *game_info = current_game_info(NULL);
  return *game_info;
}