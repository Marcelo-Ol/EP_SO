#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Definições de códigos de erro
#define ERROR_THREAD_CREATE 1
#define ERROR_THREAD_JOIN 2

// Função para lidar com erros
static inline void handle_error_en(int en, const char *msg) {
    errno = en;
    perror(msg);
    exit(EXIT_FAILURE);
}

#endif
