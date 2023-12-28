#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
 {
    //Criação de processo
 
    pid_t pid = fork(); 
    
    if (pid == 0){
        printf("Hello World\n"); 
        exit(0);
        
    } 
    else if (pid > 0){
        printf("Hello World\n"); 
        waitpid(pid, NULL, 0);
        exit(0);
    }
    else{
        printf("fork() falhou!\n");
        exit(1);
    }

    return 0;
}