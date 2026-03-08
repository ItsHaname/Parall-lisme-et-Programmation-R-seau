/*
Exercice 1 — Création de base Père/Fils
Écris un programme C où :

-->Un processus père crée un fils avec fork()
-->Le père affiche : "Je suis le père"
-->Le fils affiche : "Je suis le fils"
Explique ce qui détermine l'ordre d'exécution
*/
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t p = fork();

    if (p == 0)
        write(1, "je suis le processus fils\n", 26);
    else if (p > 0)
        write(1, "je suis le processus pere\n", 26);
    else
        write(1, "404\n", 4);
    return 0;
}
                                                                    /****** L'ordre d'execution ********/
/*
---> Le Scheduler (Ordonnanceur)
C'est le composant de l'OS qui décide quel processus tourne sur le CPU et quand. Après un fork(), le père et le fils sont tous les deux prêts, et le scheduler choisit lequel passe en premier.
```
fork()
       ┌──┴──┐
      père  fils
       │     │
    prêt    prêt
       └──┬──┘
          │
       scheduler
          │
     qui passe ?  
```
Ce qui influence l'ordre:
Charge du système --> Si le CPU est occupé, l'ordre change
Priorité des processus  --> Un processus prioritaire passe avant
Politique d'ordonnancement --> FIFO, Round Robin... chaque OS a la sienne
Le hasar            --> dMême conditions = pas forcément même résultat

**Concrètement:
# Exécution 1
je suis le processus pere
je suis le processus fils

# Exécution 2
je suis le processus fils
je suis le processus pere

Les deux sont corrects. L'ordre n'est jamais garanti sans mécanisme de synchronisation comme wait()
*/




















