#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    pid_t pid = fork();

    if(pid == 0){
        printf("Child is running. PID %d\n",getpid());
        sleep(2);
        printf("Child done.\n");
    }
    else{
        wait(NULL);
        printf("Parent now start its execution");
    }
}