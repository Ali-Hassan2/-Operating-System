#include<stdio.h>
#include<unistd.h>

int main(){

    pid_t pid = fork(); // pid_t is a data type (like int, float) used in C for process IDs.

    if(pid == 0){
        printf("I am the child process with PID: %d\n",getpid());
    }
    else if(pid > 0){
        printf("I am the parent process with PID: %d\n",getpid());
    }
    else{
        printf("Fork failed");
    }
    return 0;
}