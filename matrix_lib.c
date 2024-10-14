#include "matrix_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MATRIX_ROWS 9
#define MATRIX_COLS 8

static int matrix[MATRIX_ROWS][MATRIX_COLS];

void fill(void) {
    printf("Заполнение матрицы случайными числами...\n");
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            matrix[i][j] = rand() % 101 - 50;
        }
    }
    printf("Матрица заполнена.\n");
}

void print(void) {
    printf("Вывод матрицы:\n");
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void process(void) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        int maxIndex = 0;
        for (int j = 1; j < MATRIX_COLS; j++) {
            if (abs(matrix[i][j]) > abs(matrix[i][maxIndex])) {
                maxIndex = j;
            }
        }
        printf("Максимальное по модулю значение в строке %d: %d на позиции %d\n", i, matrix[i][maxIndex], maxIndex);
        matrix[i][maxIndex] = -matrix[i][maxIndex];
        printf("Значение на позиции %d в строке %d заменено на %d\n", maxIndex, i, matrix[i][maxIndex]);
    }
}