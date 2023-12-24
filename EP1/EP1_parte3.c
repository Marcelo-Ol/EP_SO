#include <pthread.h>
#include <stdio.h>
//#include "errors.h"

#define numThread 10

void *runner(void *parametro); //Processo filho

int main(){
    pthread_t tid[numThread]; 
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    for(int i = 0; i < numThread; i++){
        int resultado = pthread_create(&tid[i], &attr, runner, (void *)i);
        if (resultado != 0) {
            handle_error_en(resultado, "Erro ao criar a thread");
        }
    }
    
    for(int i = 0; i < numThread; i++){
        int resultado = pthread_join(tid[i], NULL);
        if (resultado != 0) {
            handle_error_en(resultado, "Erro ao aguardar a thread");
        }
    }
    

    printf("Hello world, Processo pai\n"); //Processo pai

    return 0;
}

void *runner (void *param){
    int thread_id = (int)param;
    printf("Hello world, Processo Filho%d\n", thread_id);
    pthread_exit(0);
}