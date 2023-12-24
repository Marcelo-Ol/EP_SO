#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    pid_t pid;
    pid = fork(); //Tenta criar novo processo
    if (pid == 0)
        printf("Hello World\n"); //Processo filho
        exit(0); // Finaliza processo filho
    else if (pid > 0)
        printf("Hello World\n"); //Processo pai  
        waitpid(pid, NULL, 0); // Aguarda término do processo filho
        exit(0); // Finaliza o processo pai
    else
        printf("Processo filho não criado...\n"); 
    exit();
}