#include<stdio.h>
#include<unistd.h>

int main(){
    fork();
    printf("Hello from parent child %d\n",getpid());
    return 0;
}
// so this will print Hello message twice because one from parent process and another from the child process