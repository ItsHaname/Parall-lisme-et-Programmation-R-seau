#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();    
    if(pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0)
    {
        printf("child process %d running the exec syscall\n" , getpid());
        char *arg[] = {"ls" , "-l" , "-a" , NULL};
        if(execvp("ls" , arg) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("parent process %d waiting for the child %d\n" , getpid() , pid);
        wait(NULL);
    }
}
