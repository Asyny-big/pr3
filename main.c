#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "load.h"

#define ARRAY_SIZE 35
#define MATRIX_ROWS 9
#define MATRIX_COLS 8

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(NULL));
    int choice;
    int array[ARRAY_SIZE];
    int matrix[MATRIX_ROWS][MATRIX_COLS];

    printf("Выберите опцию:\n");
    printf("1. Работа с массивом\n");
    printf("2. Работа с матрицей\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            LoadRun("array_lib.so");
            break;
        case 2:
            LoadRun("matrix_lib.so");
            break;
        default:
            printf("Неверный выбор!\n");
            break;
    }

    return 0;
}