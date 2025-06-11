#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){

    pid_t pid = fork();
    if(pid == 0){
        printf("Child process is working");
        exit(5);
    }
    else{
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("The process terminated with status %d\n",WEXITSTATUS(status));
        }
    }


    return 0;
}