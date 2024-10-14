# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -I./src

# Каталоги
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Исходные файлы
SRCS = $(wildcard $(SRCDIR)/*.c)

# Объектные файлы
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Исполняемый файл
TARGET = $(BINDIR)/main

# Библиотеки
LIBS = -L$(BINDIR) -lload -ldl

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS) $(BINDIR)/libload.dll $(BINDIR)/libarray_lib.dll $(BINDIR)/libmatrix_lib.dll
    $(CC) $(CFLAGS) -o $@ $(OBJDIR)/main.o $(LIBS)

# Правило для компиляции исходных файлов в объектные файлы
$(OBJDIR)/%.o: $(SRCDIR)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

# Правило для сборки библиотеки load.dll
$(BINDIR)/libload.dll: $(OBJDIR)/load.o
    $(CC) -shared -o $@ $^

# Правило для сборки библиотеки array_lib.dll
$(BINDIR)/libarray_lib.dll: $(OBJDIR)/array_lib.o
    $(CC) -shared -o $@ $^

# Правило для сборки библиотеки matrix_lib.dll
$(BINDIR)/libmatrix_lib.dll: $(OBJDIR)/matrix_lib.o
    $(CC) -shared -o $@ $^

# Правило для очистки
clean:
    rm -f $(OBJDIR)/*.o $(BINDIR)/*

# Создание необходимых каталогов
$(shell mkdir -p $(OBJDIR) $(BINDIR))