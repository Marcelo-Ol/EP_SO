#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
//#include "errors.h"


#define numThreads 2

int vez = 0;
int count = 0;

void *P0(void *arg) {
    while (1) {
        while (vez != 0); // Espera ociosa

        // Seção crítica
        printf("Thread P0: Entrando na seção crítica\n");
        count++;
        printf("Thread P0: count = %d\n", count);
        printf("Thread P0: Saindo da seção crítica\n");

        vez = 1;

        // Seção não crítica
        sleep(1);
    }
}

void *P1(void *arg) {
    while (1) {
        while (vez != 1); // Espera ociosa

        // Seção crítica
        printf("Thread P1: Entrando na seção crítica\n");
        count++;
        printf("Thread P1: count = %d\n", count);
        printf("Thread P1: Saindo da seção crítica\n");

        vez = 0;

        // Seção não crítica
        sleep(1);
    }
}

int main() {
    pthread_t threads[numThreads];
    int i, rc;

    rc = pthread_create(&threads[0], NULL, P0, NULL);
    if (rc != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&threads[1], NULL, P1, NULL);
    if (rc != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < numThreads; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
