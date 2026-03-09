#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int ac, char **av)
{
    if (ac > 1)
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            char **arg = malloc(ac * sizeof(char *));
            if (arg == NULL)
            {
                perror("malloc failed");
                exit(EXIT_FAILURE);
            }

            for (int i = 1; i < ac; i++)
                arg[i - 1] = av[i];
            arg[ac - 1] = NULL;

            execvp(arg[0], arg);

            perror("execvp failed");
            free(arg);
            exit(EXIT_FAILURE);
        }
        else 
        {
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status))
                printf("Process ended with exit code %d\n", WEXITSTATUS(status));
            else
                printf("Process did not terminate normally\n");
            }
    }
    else
    {
        printf("Usage: %s <command> [arguments]\n", av[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
