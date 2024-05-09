#ifndef DEFINES_TETRIS_H
#define DEFINES_TETRIS_H

/**
 * @file
 * @brief определение констант, используемых в игре "Тетрис"
 */

#define USER_NAME_SIZE 255
#define USER_RECORD_LINE_LENGTH 25

#define FIELD_ROWS 20
#define FIELD_COLUMNS 10
#define TETRAMINO_BUFFER 3
#define WALL_SIZE 2

/// индекс верхнего ряда в массиве field
#define TOP_FIELD TETRAMINO_BUFFER

/// индекс нижнего ряда в массиве field
#define BOTTOM_FIELD TOP_FIELD + FIELD_ROWS - 1

/// отступ от границы окна терминала
#define BOARD 3

/// координаты рамки с игрой
#define TOP_T BOARD - 1
#define BOTTOM_T TOP_T + FIELD_ROWS + 1
#define LEFT_T BOARD
#define RIGHT_T LEFT_T + FIELD_COLUMNS + 1

/// координаты рамки с дополнительной информацией
#define TOP_A TOP_T
#define BOTTOM_A BOTTOM_T
#define LEFT_A RIGHT_T + 4
#define RIGHT_A LEFT_A + 10

/// координаты надписи SCORE
#define Y_SCORE TOP_A + 1
#define X_SCORE LEFT_A + 3

/// координаты рамки для SCORE
#define TOP_SCORE Y_SCORE + 1
#define BOTTOM_SCORE TOP_SCORE + 2
#define LEFT_SCORE LEFT_A + 2
#define RIGHT_SCORE RIGHT_A - 2

#define MAX_SCORE_LENGTH 5

/// координаты надписи BEST
#define Y_BEST BOTTOM_SCORE + 1
#define X_BEST LEFT_A + 3

/// координаты рамки для BEST
#define TOP_BEST Y_BEST + 1
#define BOTTOM_BEST TOP_BEST + 2
#define LEFT_BEST LEFT_SCORE
#define RIGHT_BEST RIGHT_SCORE

/// координаты надписи LEVEL
#define Y_LEVEL BOTTOM_BEST + 1
#define X_LEVEL LEFT_A + 3

/// координаты рамки для LEVEL
#define TOP_LEVEL Y_LEVEL + 1
#define BOTTOM_LEVEL TOP_LEVEL + 2
#define LEFT_LEVEL LEFT_BEST
#define RIGHT_LEVEL RIGHT_BEST

/// координаты надписи NEXT
#define Y_NEXT BOTTOM_LEVEL + 3
#define X_NEXT LEFT_A + 3

/// координаты рамки для NEXT
#define TOP_NEXT Y_NEXT + 1
#define BOTTOM_NEXT TOP_NEXT + 4
#define LEFT_NEXT LEFT_LEVEL
#define RIGHT_NEXT RIGHT_LEVEL

/// координаты welcome-текста
#define Y_WELCOME_TEXT BOTTOM_T + 2
#define X_WELCOME_TEXT LEFT_T

/// координаты надписи OPTIONS
#define Y_OPTIONS TOP_A + 7
#define X_OPTIONS RIGHT_A + 11

/// координаты рамки для OPTIONS
#define TOP_OPTIONS Y_OPTIONS + 1
#define BOTTOM_OPTIONS TOP_OPTIONS + 5
#define LEFT_OPTIONS RIGHT_A + 4
#define RIGHT_OPTIONS LEFT_OPTIONS + 21

#define SUCCESS 0
#define ERROR 1

#endif