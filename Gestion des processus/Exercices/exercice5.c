/*
Exercice 5 — Afficher le PPID
Étends le programme précédent pour afficher :

Le PID avec getpid()
Le PPID avec getppid()
Analyser la relation entre le PID du père et le PPID du fils
*/
#include <sys/types.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
        printf("fils : PID=%d PPID=%d\n", getpid(), getppid());
    else if (pid > 0)
        printf("pere : PID=%d PPID=%d\n", getpid(), getppid());
    else
        printf("erreur fork\n");
    return 0;
}
