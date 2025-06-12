#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){

    pid_t pid = fork();
    if(pid == 0){
        char *args[] = {"/bin/echo","Hello from Ali",NULL};
        execv("/bin/echo",args);
        perror("execv failed");
    }
    else if (pid > 0){
        wait(NULL);
        printf("Child has completed his task");
    }
    else{
        perror("Fork failed");
    }


    return 0;
}