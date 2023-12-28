#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3
#define COUNT 5

int contador_compartilhado = 0;
pthread_mutex_t mutex;

void *funcao_thread(void *thread_id) {
    int tid = *((int *)thread_id);

    for (int i = 0; i < COUNT; ++i) {
        // Entrar na seção crítica
        pthread_mutex_lock(&mutex);

        // Operações críticas
        contador_compartilhado++;
        printf("Thread %d: Contador = %d\n", tid, contador_compartilhado);

        // Sair da seção crítica
        pthread_mutex_unlock(&mutex);

        // Simular algum trabalho fora da seção crítica
        usleep(100000); // Espera por 100.000 microssegundos (0.1 segundos)
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Inicializar o mutex
    pthread_mutex_init(&mutex, NULL);

    // Criar threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, funcao_thread, (void *)&thread_ids[i]);
    }

    // Aguardar a conclusão das threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destruir o mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
