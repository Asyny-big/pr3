#include "load.h"
#include "lib.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h> // Для работы с динамическими библиотеками в Windows
#else
#include <dlfcn.h> // Для работы с динамическими библиотеками в Linux
#endif

void LoadRun(const char * const s) {
    #ifdef _WIN32
    HMODULE lib;
    #else
    void *lib;
    #endif

    void (*fun1)(void);
    void (*fun2)(void);
    void (*fun3)(void);
    void (*fun4)(void);

    #ifdef _WIN32
    lib = LoadLibrary(s); // Загрузка библиотеки в память для Windows
    if (!lib) {
        printf("cannot open library '%s'\n", s);
        return;
    }

    fun1 = (void (*)(void))GetProcAddress(lib, "fill"); // Получение указателя на функцию из библиотеки для Windows
    if (fun1 == NULL) {
        printf("cannot load function '%s'\n", "fill");
    } else {
        fun1();
    }

    fun2 = (void (*)(void))GetProcAddress(lib, "print"); // Получение указателя на функцию из библиотеки для Windows
    if (fun2 == NULL) {
        printf("cannot load function '%s'\n", "print");
    } else {
        fun2();
    }

    fun3 = (void (*)(void))GetProcAddress(lib, "process"); // Получение указателя на функцию из библиотеки для Windows
    if (fun3 == NULL) {
        printf("cannot load function '%s'\n", "process");
    } else {
        fun3();
    }

    fun4 = (void (*)(void))GetProcAddress(lib, "print"); // Получение указателя на функцию из библиотеки для Windows
    if (fun4 == NULL) {
        printf("cannot load function '%s'\n", "print");
    } else {
        fun4();
    }

    FreeLibrary(lib); // Выгрузка библиотеки для Windows
    #else
    lib = dlopen(s, RTLD_LAZY); // Загрузка библиотеки в память для Linux
    if (!lib) {
        printf("cannot open library '%s': %s\n", s, dlerror());
        return;
    }

    fun1 = (void (*)(void))dlsym(lib, "fill"); // Получение указателя на функцию из библиотеки для Linux
    if (fun1 == NULL) {
        printf("cannot load function '%s': %s\n", "fill", dlerror());
    } else {
        fun1();
    }

    fun2 = (void (*)(void))dlsym(lib, "print"); // Получение указателя на функцию из библиотеки для Linux
    if (fun2 == NULL) {
        printf("cannot load function '%s': %s\n", "print", dlerror());
    } else {
        fun2();
    }

    fun3 = (void (*)(void))dlsym(lib, "process"); // Получение указателя на функцию из библиотеки для Linux
    if (fun3 == NULL) {
        printf("cannot load function '%s': %s\n", "process", dlerror());
    } else {
        fun3();
    }

    fun4 = (void (*)(void))dlsym(lib, "print"); // Получение указателя на функцию из библиотеки для Linux
    if (fun4 == NULL) {
        printf("cannot load function '%s': %s\n", "print", dlerror());
    } else {
        fun4();
    }

    dlclose(lib); // Выгрузка библиотеки для Linux
    #endif
}