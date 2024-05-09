#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

/**
 * @file
 * @brief функции по работе с двумерными массивами
 */

#include <stdlib.h>

#include "defines.h"

/// @brief получение исходной позиции одного из семи тетрамино в порядке их
/// расположения на картинке в src/SRS-pieces.png
/// @param i номер тетрамино на картинке по порядку
/// @return матрица в динамической памяти, соответствующая рисунку
int **get_tetramino(int i);

/// @brief создание матрицы rows x columns
/// @param rows количество рядов
/// @param columns количество столбцов
/// @return указатель на память, выделенную под матрицу
int **create_matrix(int rows, int columns);

/// @brief копирование матрицы src в существующую dest одинакового размера
/// @param dest целевая матрица
/// @param src матрица-источник
/// @param rows количество рядов в матрицах
/// @param columns количество столбцов в матрицах
void copy_matrix(int **dest, int **src, int rows, int columns);

/// @brief очищение матрицы
/// @param matrix матрица для очистки
/// @param rows количество рядов
/// @param columns количество столбцов
void clear_matrix(int **matrix, int rows, int columns);

/// @brief сравнение двух матриц одинакового размера на равенство
/// @param A первая матрица
/// @param B вторая матрица
/// @param rows количество рядов в матрицах
/// @param columns количество столбцов в матрицах
/// @return 1 - матрицы равны, 0 – матрицы не равны
int eq_matrix(int **A, int **B, int rows, int columns);

/// @brief очистка памяти, выделенной под матрицу
/// @param A матрица для удаления
void remove_matrix(int **A);

/// @brief поворот матрицы на 90 градусов по часовой стрелке
/// @param matrix матрица для поворота
/// @param rows количество рядов
/// @param columns количество столбцов
void rotate_matrix_90_clockwise(int **matrix, int rows, int columns);

#endif