/*
Exercice 7 — Arbre de processus avec une boucle
Avec une boucle qui appelle fork() plusieurs fois :

Dessine l'arbre de processus
Détermine combien de processus sont créés
Explique le rôle du break
Analyse le comportement de l'ordonnancement
  */
#include <stdio.h>
#include <unistd.h>

int main()
{
    for (int i = 0; i < 3; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            printf("fils  : PID=%d\n", getpid());
            break;  // le fils sort de la boucle
        }
        else
            printf("pere  : PID=%d a cree fils=%d\n", getpid(), pid);
    }
    return 0;
/*Rôle du break
Sans break chaque fils repart dans la boucle et crée d'autres fils — ça explose. Avec break seul le père crée les fils.
 */
