#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    pid_t pid = fork();
    if(pid == 0){
        execlp("gedit","getdit",NULL);
        // opening gedit which is a Text editor in linux and ending with NULL
        perror("execlp failed");
    }
    else if(pid > 0){
        wait(NULL);
        printf("The child completed its task.\n");
    }
    else{
        perror("Fork failed");
    }
    return 0;
}