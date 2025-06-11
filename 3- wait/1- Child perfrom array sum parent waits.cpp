#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int array_sum (int* arr){
    int sum = 0;
    int size = sizeof(arr)/sizeof(int);

    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum;
}


int main(){

    int arr[5] = {1,2,3,4,5};
    pid_t pid = fork();
    if(pid == 0){
        int result = array_sum(arr);
        printf("The result of array sum is: %d\n",result);
    }
    else if(pid > 0){
        // parent waits for the completion of the child process
        wait(NULL);
        printf("The child has done his job");

    }
    else {
        perror("fork failed");
    }


    return 0;
}
