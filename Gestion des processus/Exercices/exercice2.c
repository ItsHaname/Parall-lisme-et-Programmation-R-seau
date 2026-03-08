/*
Exercice 2 — Valeur de retour de fork()
Écris un programme C où :

Tu crées un fils avec fork()
Le fils affiche : "fils : fork() = 0"
Le père affiche : "pere : fork() = 1234" ← le vrai PID du fils
  */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
        printf("fils : fork() = %d\n", pid);
    else if (pid > 0)
        printf("pere : fork() = %d\n", pid);
    else
        printf("erreur fork\n");
    return 0;
}


/*** Résultat

fils : fork() = 0
pere : fork() = 1234
  ***/
