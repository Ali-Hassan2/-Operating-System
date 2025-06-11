#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


bool isPrime(int& number){

    if(number < 2){
        return false;
    }

    for(int i = 2; i * i <= number; i++){
        if(number % i == 0){
            return false;
        }
    }

    return true;
}


int main(){
    
    
    int number;
    printf("Enter the number:");
    scanf("%d",&number);
    pid_t pid = fork();
    if(pid == 0){
        bool result = isPrime(number);
        if(result) exit(1);
        else{
            exit(0);
        }
    }
    else if(pid > 0){
        int status;
        wait(&status);

        if(WIFEXITED(status)){
            int exitcode = WEXITSTATUS(status);
            if(exitcode == 1){
                printf("The Parent %d number is Prime number\n",number);
            }
            else printf("The Parent %d is not a Prime number.\n",number);
        }
    }
    else{
        perror("fork failed");
    }

    return 0;
}