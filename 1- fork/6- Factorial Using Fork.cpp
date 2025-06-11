#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int num = 5;
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed.\n");
    } else if (pid == 0) {
        int result = factorial(num);
        printf("🧠 Child Process (PID: %d): Factorial of %d = %d\n", getpid(), num, result);
    } else {
        wait(NULL);
        printf("Parent Process (PID: %d): Child finished execution.\n", getpid());
    }

    return 0;
}
