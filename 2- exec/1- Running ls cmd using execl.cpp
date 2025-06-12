#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    pid_t pid = fork();
    if(pid == 0){
        // running the ls command using execl
        // ending will always with NULL
        execl("/bin/ls","ls","-l",NULL);
        // In case if execl failed
        perror("execl failed");
        sleep(1);
    }
    else if(pid > 0){
        wait(NULL);
        printf("The child completed its task.\n");
    }
    else{
        perror("Fork Failed");
    }

    return 0;
}