#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){


    pid_t pid = fork();

    if(pid == 0){
        // making a argument list to pass in the execpv
        // ending with NULL
        char* args[] = {"ping","-c","3","google.com",NULL};
        execvp("ping",args);
        perror("EXECVP FAILED");
        sleep(2);
    }
    else if(pid > 0){
        wait(NULL);
        printf("CHILD COMPLETED ITS TASK.");
    }
    else{
        perror("Fork Failed");
    }

    return 0;
}