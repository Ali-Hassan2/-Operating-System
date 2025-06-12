#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    // Orphan Process creation

    pid_t pid = fork();

    if(pid < 0 ){
        perror("fork failed");
        exit(1);
    }
    else if (pid > 0){
        printf("Parent process ID: %d\n",getpid());
        exit(0);
    }
    else {
        printf("Child Process ID is: %d, Parent Process ID: %d\n",getpid(),getppid());
        sleep(10);
        printf("After sleep new Child ID: %d and New Parent ID: %d\n",getpid(),getppid());
    }


    return 0;
}