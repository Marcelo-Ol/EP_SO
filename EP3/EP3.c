#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define numThreads 3

int contador = 0;
pthread_mutex_t mutex;

void *funcao_thread(void *thread_id) {
    int tid = *((int *)thread_id);

    for (int i = 0; i < 5; ++i) { // 5 é o número de vezes que cada thread executurá a seção critica antes de encerrar
        // Entrar na seção crítica
        pthread_mutex_lock(&mutex);

        contador++;
        printf("Thread %d: Contador = %d\n", tid, contador);

        // Sai da seção crítica
        pthread_mutex_unlock(&mutex);

        usleep(100000); // Espera por 100.000 microssegundos (0.1 segundos)
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[numThreads];
    int thread_ids[numThreads];

    // Inicializa o mutex
    pthread_mutex_init(&mutex, NULL);

    // Cria threads
    for (int i = 0; i < numThreads; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, funcao_thread, (void *)&thread_ids[i]);
    }

    // Aguarda a conclusão das threads
    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroi o mutex
    pthread_mutex_destroy(&mutex);

    // Esperar que o usuário pressione uma tecla antes de encerrar
    printf("Pressione qualquer tecla para sair...\n");
    getchar(); // Aguarda uma entrada do usuário
    
    return 0;
}
