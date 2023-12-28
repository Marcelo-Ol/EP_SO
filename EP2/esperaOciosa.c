#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

long compartilhada = 0;
int vez = 0; 


void secao_nao_critica(){
   
    return; 
}

void secao_critica(){
    for(int i = 0; i < 100000; i++){
        compartilhada++; 
    }
}

void * processo1(){
    int meu_id = 0; 
    int outro = 1; 
    int i = 0; 
    
    while(i < 1){ //uma iteração
        while(meu_id != vez){}
        secao_critica();
        vez = outro;
        secao_nao_critica();
        i++; 
        
    }
    
    return NULL; 
}

void * processo2(){
    int meu_id = 1; 
    int outro = 0; 
    int i = 0; 
    while(i < 1){ //uma iteração
        while(meu_id != vez){}
        secao_critica();
        vez = outro;
        secao_nao_critica();
        i++; 
        
    }
    return NULL; 
}

int main(){

pthread_t p0;
pthread_t p1; 

pthread_create(&p0, NULL, processo1, NULL);
pthread_create(&p1, NULL, processo2, NULL); 

pthread_join(p0, NULL); 
pthread_join(p1, NULL); 

printf("Variavel compartilhada: %ld", compartilhada);

}