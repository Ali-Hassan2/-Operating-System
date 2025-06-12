#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        char *args[] = {"/usr/bin/env", NULL};
        char *envp[] = {"MY_VAR=HelloWorld", NULL};
        execve("/usr/bin/env", args, envp);
        perror("execve failed");
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("Parent: execve child done.\n");
    }
    else
    {
        perror("fork failed");
    }
    return 0;

    return 0;
}