#include "backend.h"

void drop_new_tetramino() {
  GameInfo_t *info = current_game_info(NULL);
  remove_matrix(info->moving->figure);
  info->moving->figure = info->next;
  info->moving->idx = info->next_idx;
  info->moving->x = 0;
  info->moving->y = 5;
  info->moving->rows = get_tetramino_size(info->moving->idx);
  info->moving->columns = get_tetramino_size(info->moving->idx);
}

void get_next_tetramino(GameInfo_t *info) {
  rand();
  int idx = rand() % 7 + 1;
  info->next = get_tetramino(idx);
  info->next_idx = idx;
}

int get_tetramino_size(int idx) {
  int result = 3;
  if (idx == 1)
    result = 4;
  else if (idx == 4)
    result = 2;
  return result;
}

void check_bottom_filling() {
  GameInfo_t *info = current_game_info(NULL);
  int filled_rows = count_filled_rows(info);
  add_points(filled_rows);
  for (int i = 0; i < filled_rows; i++) {
    move_field_down(info);
  }
  change_level();
}

void add_points(int filled_rows) {
  GameInfo_t *info = current_game_info(NULL);
  while (filled_rows) {
    if (filled_rows % 4 == 1) {
      info->score += 100;
      filled_rows--;
    } else if (filled_rows % 4 == 2) {
      info->score += 300;
      filled_rows -= 2;
    } else if (filled_rows % 4 == 3) {
      info->score += 700;
      filled_rows -= 3;
    } else if (filled_rows % 4 == 0) {
      info->score += 1500;
      filled_rows -= 4;
    }
  }
  if (info->score > info->high_score) info->high_score = info->score;
}

void change_level() {
  GameInfo_t *info = current_game_info(NULL);
  info->level = info->score / 600 + 1;
  if (info->level > 10) info->level = 10;
  info->delay = 860 - 60 * info->level;
}

moving_t *init_moving_tetris(int idx) {
  moving_t *moving = (moving_t *)malloc(sizeof(moving_t));
  moving->idx = idx;
  moving->rows = get_tetramino_size(moving->idx);
  moving->columns = get_tetramino_size(moving->idx);
  moving->figure = get_tetramino(idx);
  moving->x = 0;
  moving->y = 5;
  return moving;
}

GameInfo_t *init_game_info_tetris(char *user_name) {
  GameInfo_t *info = (GameInfo_t *)malloc(sizeof(GameInfo_t));
  info->field = init_field();
  info->moving = init_moving_tetris(1);
  info->next = NULL;
  get_next_tetramino(info);
  info->score = 0;
  info->user_name = user_name;
  info->high_score = load_user_record(user_name);
  info->level = 1;
  info->delay = 800;
  return info;
}

void clear_game_info_tetris() {
  GameInfo_t *info = current_game_info(NULL);
  remove_matrix(info->field);
  info->field = init_field();
  destroy_moving(info->moving);
  info->moving = init_moving_tetris(1);
  if (info->next) remove_matrix(info->next);
  get_next_tetramino(info);
  info->score = 0;
  info->high_score = load_user_record(info->user_name);
  info->level = 1;
  info->delay = 800;
}

void destroy_moving(moving_t *moving_info) {
  remove_matrix(moving_info->figure);
  free(moving_info);
}

void destroy_game_info() {
  GameInfo_t *info = current_game_info(NULL);
  if (info) {
    if (info->field) remove_matrix(info->field);
    if (info->next) remove_matrix(info->next);
    destroy_moving(info->moving);
    free(info);
  }
}

void rotate_tetramino() {
  GameInfo_t *info = current_game_info(NULL);
  int rows = info->moving->rows, columns = info->moving->columns;
  int **figure_copy = create_matrix(rows, columns);
  copy_matrix(figure_copy, info->moving->figure, rows, columns);

  rotate_matrix_90_clockwise(info->moving->figure, rows, columns);
  if (check_collide(info)) {
    remove_matrix(info->moving->figure);
    info->moving->figure = figure_copy;
  } else {
    remove_matrix(figure_copy);
  }
}

void get_tick_limit(struct timespec *start, struct timespec *limit) {
  GameInfo_t *info = current_game_info(NULL);
  long tick_ns = info->delay * 1000 * 1000;
  long start_nsec_left = 999999999 - start->tv_nsec;
  if (start_nsec_left < tick_ns) {
    limit->tv_sec = start->tv_sec + 1;
    limit->tv_nsec = tick_ns - start_nsec_left;
  } else {
    limit->tv_sec = start->tv_sec;
    limit->tv_nsec = start->tv_nsec + tick_ns;
  }
}

int check_tick_limit(struct timespec *now, struct timespec *limit) {
  int result = 0;
  if (now->tv_sec < limit->tv_sec)
    result = 1;
  else if (now->tv_sec == limit->tv_sec && now->tv_nsec < limit->tv_nsec)
    result = 1;
  return result;
}

int load_user_record(char *user_name) {
  int result = -1;
  char line_from_file[USER_RECORD_LINE_LENGTH] = {0}, *read = NULL;
  FILE *fp = fopen("build/user_record.txt", "r+");
  if (fp != NULL) {
    int flag = 0;
    while ((read = fgets(line_from_file, USER_RECORD_LINE_LENGTH, fp)) !=
               NULL &&
           !flag) {
      if (!strncmp(user_name, line_from_file, strlen(user_name))) {
        flag = 1;
        char *result_str = strtok(line_from_file, " ");
        result_str = strtok(NULL, " ");
        result = (int)atof(result_str);
      }
    }
    if (result == -1) {
      fprintf(fp, "%s %d\n", user_name, 0);
      result = 0;
    }
  }
  fclose(fp);
  return result;
}

void update_user_record(char *user_name, int new_record) {
  int prev_record = load_user_record(user_name);
  if (new_record > prev_record) {
    FILE *fp = fopen("build/user_record.txt", "r");
    FILE *fp_copy = fopen("tmp.txt", "w");
    char line_from_file[USER_RECORD_LINE_LENGTH] = {0}, *read = NULL;
    if (fp != NULL) {
      while ((read = fgets(line_from_file, USER_RECORD_LINE_LENGTH, fp)) !=
             NULL) {
        if (!strncmp(user_name, line_from_file, strlen(user_name))) {
          fprintf(fp_copy, "%s %d\n", user_name, new_record);
        } else {
          fprintf(fp_copy, "%s", line_from_file);
        }
      }
    }
    fclose(fp);
    fclose(fp_copy);
    remove("build/user_record.txt");
    rename("tmp.txt", "build/user_record.txt");
  }
}