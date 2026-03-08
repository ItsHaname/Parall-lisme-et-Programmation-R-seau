/*
Exercice 4 — Afficher les identifiants de processus
Modifie le programme précédent pour afficher :

Son propre PID avec getpid()
Sans synchronisation entre père et fils
Observer l'ordre d'affichage
  */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        sleep(10);
        // while(1);
        printf("I am the child PID = %d\n", pid );
        printf("PID = %d\n", getpid());
    }
    else
    {
        printf("I am the parent PID(child id) = %d\n" , pid);
        printf("PID = %d\n" , getpid());
    }
}

