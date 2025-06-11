#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    pid_t pid = fork();
    int x = 10;
    if(pid == 0){  // This means a child process
        x+=5;
        printf("Child x = %d\n",x);
    } 
    else{
        x-=2;
        printf("Parent x = %d\n",x);
    }

    return 0;
}