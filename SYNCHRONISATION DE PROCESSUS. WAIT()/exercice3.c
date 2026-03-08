/*
Exercice 3 — Affichage concurrent

Partie A — nombre.c

Le père crée deux fils
Fils 1 affiche : 1 → 50
Fils 2 affiche : 51 → 100
Un nombre par ligne


Partie B — nombre_sleep.c

Reprends la partie A
Ajoute sleep(1) dans chaque boucle
Observe comment les nombres des deux fils se mélangent


Partie C — nombre_wait.c

Assure que fils1 finit complètement avant que fils2 commence
Utilise wait() pour synchroniser
Pas d'attente active
  */
//Partie A — nombre.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        for (int i = 1; i <= 50; i++)
            printf("%d\n", i);
        return 0;
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        for (int i = 51; i <= 100; i++)
            printf("%d\n", i);
        return 0;
    }
    wait(NULL);
    wait(NULL);
    return 0;
}
//Partie B — nombre_sleep.c
/*
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        for (int i = 1; i <= 50; i++)
        {
            printf("%d\n", i);
            sleep(1);  // ← ajout
        }
        return 0;
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        for (int i = 51; i <= 100; i++)
        {
            printf("%d\n", i);
            sleep(1);  // ← ajout
        }
        return 0;
    }
    wait(NULL);
    wait(NULL);
    return 0;
}
*/
//Partie C — nombre_wait.c
/*
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        for (int i = 1; i <= 50; i++)
            printf("%d\n", i);
        return 0;
    }

    waitpid(pid1, NULL, 0);  // attend que fils1 finisse

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        for (int i = 51; i <= 100; i++)
            printf("%d\n", i);
        return 0;
    }
    wait(NULL);
    return 0;
}
*/

