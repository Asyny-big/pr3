#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 35

static int array[ARRAY_SIZE];

void fill(void) {
    printf("Заполнение массива случайными числами...\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 101 - 50;
    }
    printf("Массив заполнен.\n");
}

void print(void) {
    printf("Вывод массива:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void process(void) {
    int maxIndex = 0;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (abs(array[i]) > abs(array[maxIndex])) {
            maxIndex = i;
        }
    }
    printf("Максимальное по модулю значение: %d на позиции %d\n", array[maxIndex], maxIndex);
    array[maxIndex] = -array[maxIndex];
    printf("Значение на позиции %d заменено на %d\n", maxIndex, array[maxIndex]);
}