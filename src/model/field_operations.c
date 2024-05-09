#include "field_operations.h"

int **init_field() {
  /// тетрамино не появляется на поле сразу целиком, поэтому зарезервируем
  /// дополнительный буфер. Еще по две строки выделим для нижней и правой
  /// стенок, так как тетрамино под номером 1 при проверках может выйти за
  /// границы поля. Левая граница имеет длину 1, так как
  /// ошибка выхода за пределы поля при проверке смещений была выявлена на
  /// поздних стадиях проекта – увеличение толщины левой стенки потребует
  /// изменения значетельной части тестов и логики игры
  int rows = FIELD_ROWS + TETRAMINO_BUFFER + WALL_SIZE;
  /// выделим два столбца под границы поля
  int columns = 1 + FIELD_COLUMNS + WALL_SIZE;
  int **field = create_matrix(rows, columns);
  /// установка левой и правой грацицы поля
  for (int i = 0; i < rows; i++) {
    field[i][0] = 1;
    field[i][columns - 2] = 1;
    field[i][columns - 1] = 1;
  }
  /// установка нижней границы поля
  for (int j = 1; j < columns - 1; j++) {
    field[rows - 2][j] = 1;
    field[rows - 1][j] = 1;
  }
  return field;
}

int shift_down(GameInfo_t *info) {
  int result = check_down(info);
  if (result) info->moving->x++;
  return result;
}

int check_down(GameInfo_t *info) {
  int flag = 1;
  int x = info->moving->x, y = info->moving->y;
  int rows = info->moving->rows, columns = info->moving->columns;
  // if (info->moving->idx == 1 && info->moving->figure[1][0]) rows = 2;
  for (int i = 0; i < rows && flag; i++) {
    for (int j = 0; j < columns && flag; j++) {
      if (info->field[x + i + 1][y + j] && info->moving->figure[i][j]) {
        flag = 0;
      }
    }
  }
  return flag;
}

void shift_left(GameInfo_t *info) {
  if (check_left(info)) info->moving->y--;
}

int check_left(GameInfo_t *info) {
  int flag = 1;
  int x = info->moving->x, y = info->moving->y;
  int rows = info->moving->rows, columns = info->moving->columns;
  int j_start = 0;

  /// костыль для проверок третьего положения первого тетрамино
  if (info->moving->idx == 1 && info->moving->figure[0][2]) {
    j_start = 1;
  }
  for (int i = 0; i < rows && flag; i++) {
    for (int j = j_start; j < columns && flag; j++) {
      if (info->field[x + i][y + j - 1] && info->moving->figure[i][j]) {
        flag = 0;
      }
    }
  }
  return flag;
}

void shift_right(GameInfo_t *info) {
  if (check_right(info)) info->moving->y++;
}

int check_right(GameInfo_t *info) {
  int flag = 1;
  int x = info->moving->x, y = info->moving->y;
  int rows = info->moving->rows, columns = info->moving->columns;
  for (int i = 0; i < rows && flag; i++) {
    for (int j = 0; j < columns && flag; j++) {
      if (info->field[x + i][y + j + 1] && info->moving->figure[i][j]) {
        flag = 0;
      }
    }
  }
  return flag;
}

int check_collide(GameInfo_t *info) {
  int flag = 0;
  int x = info->moving->x, y = info->moving->y;
  int rows = info->moving->rows, columns = info->moving->columns;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (info->field[x + i][y + j] && info->moving->figure[i][j]) flag = 1;
    }
  }
  return flag;
}

void drop_down(GameInfo_t *info) {
  while (check_down(info)) {
    shift_down(info);
  }
}

void attach(GameInfo_t *info) {
  int x = info->moving->x, y = info->moving->y;
  int rows = info->moving->rows, columns = info->moving->columns;
  if (rows == 4 && info->moving->figure[1][0]) rows = 2;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (info->moving->figure[i][j])
        info->field[x + i][y + j] = info->moving->figure[i][j];
    }
  }
}

int check_ceiling(GameInfo_t *info) {
  int result = 0;
  for (int j = 1; j < FIELD_COLUMNS + 1 && !result; j++) {
    if (info->field[TOP_FIELD][j]) result = 1;
  }
  return result;
}

int check_row_filling_by_idx(GameInfo_t *info, int idx) {
  int result = 1;
  for (int j = 1; j < FIELD_COLUMNS + 1 && result; j++) {
    if (!info->field[idx][j]) result = 0;
  }
  return result;
}

void move_field_down(GameInfo_t *info) {
  for (int i = BOTTOM_FIELD; i > TOP_FIELD; i--) {
    for (int j = 1; j < FIELD_COLUMNS + 1; j++) {
      info->field[i][j] = info->field[i - 1][j];
    }
  }
}

int count_filled_rows(GameInfo_t *info) {
  int flag = 0, filled_rows = 0;
  for (int i = BOTTOM_FIELD; i > TOP_FIELD && !flag; i--) {
    if (check_row_filling_by_idx(info, i))
      filled_rows++;
    else
      flag = 1;
  }
  return filled_rows;
}