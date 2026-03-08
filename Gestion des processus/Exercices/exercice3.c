/*
Exercice 3 — Observer la duplication de processus
Reprends l'exercice 2 et :

Ajoute un sleep() dans le père et dans le fils
Utilise la commande ps pour voir les deux processus en même temps
Décris ce que tu observes sur le PID et le PPID
*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        sleep(10);  // ← ajoute ça
        printf("fils : fork() = %d\n", pid);
    }
    else if (pid > 0)
    {
        sleep(10);  // ← ajoute ça
        printf("pere : fork() = %d\n", pid);
    }
    else
        printf("erreur fork\n");
    return 0;
}
