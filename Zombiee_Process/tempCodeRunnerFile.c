#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){


    // creation of zombie process

    pid_t pid = fork();
    if(pid < 0){
        perror("Fork failed");
        exit(1);
    }
    else if(pid == 0){
        printf("The Child PID is: %d\n",getpid());
        exit(0);
    }
    else {
        printf("The parent is sleeping.");
        sleep (10);
        printf("The sleeping of Parent done.");

    }


    return 0;
}