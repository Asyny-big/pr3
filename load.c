#include "load.h"
#include "lib.h"
#include <stdio.h>
#include <windows.h>

void LoadRun(const char * const s) {
    void * lib;
    void (*fun1)(void);
    void (*fun2)(void);
    void (*fun3)(void);
    void (*fun4)(void);

    lib = LoadLibrary(s); // Загрузка библиотеки в память
    if (!lib) {
        printf("cannot open library '%s'\n", s);
        return;
    }

    fun1 = (void (*)(void))GetProcAddress((HINSTANCE)lib, "fill"); // Получение указателя на функцию из библиотеки
    if (fun1 == NULL) {
        printf("cannot load function '%s'\n", "fill");
    } else {
        fun1();
    }

    fun2 = (void (*)(void))GetProcAddress((HINSTANCE)lib, "print"); // Получение указателя на функцию из библиотеки
    if (fun2 == NULL) {
        printf("cannot load function '%s'\n", "print");
    } else {
        fun2();
    }

    fun3 = (void (*)(void))GetProcAddress((HINSTANCE)lib, "process"); // Получение указателя на функцию из библиотеки
    if (fun3 == NULL) {
        printf("cannot load function '%s'\n", "process");
    } else {
        fun3();
    }

    fun4 = (void (*)(void))GetProcAddress((HINSTANCE)lib, "print"); // Получение указателя на функцию из библиотеки
    if (fun4 == NULL) {
        printf("cannot load function '%s'\n", "print");
    } else {
        fun4();
    }

    FreeLibrary((HINSTANCE)lib); // Выгрузка библиотеки
}