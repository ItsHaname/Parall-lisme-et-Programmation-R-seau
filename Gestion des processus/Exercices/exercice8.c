/*
Exercice 8 — Duplication de mémoire
Écris un programme où :

Une variable a = 10 est initialisée avant fork()
Le père ajoute 30
Le fils ajoute 40
Observe : les changements sont-ils partagés ? Pourquoi ?

Ensuite étends le programme :

Affiche le UID avec getuid() et le GID avec getgid()
Crée une variable x = 2 avant le fork()
Le fils fait : x = x + 3
Le père fait : x = x * 5
Explique le comportement de la mémoire
*/
#include <unistd.h>
#include <stdio.h>

int main()
{
    int x = 2;
    pid_t pid = fork();

    if (pid == 0)
    {
        x = x + 3;
        printf("fils  : UID=%d GID=%d x=%d\n", getuid(), getgid(), x);
    }
    else
    {
        x = x * 5;
        printf("pere  : UID=%d GID=%d x=%d\n", getuid(), getgid(), x);
    }
    return 0;
}
/*
### Résultat
```
pere  : UID=1000 GID=1000 x=10
fils  : UID=1000 GID=1000 x=5
  */
/*
UID et GID sont identiques — le fils hérite des mêmes droits que le père. Mais x est différent — chacun a sa propre copie. 
  */

/*
avant fork()
x = 2
    │
  fork()
   ┌──┴──┐
  père  fils
  x=2   x=2   ← copie indépendante
   │     │
  x*5   x+3
   │     │
  x=10  x=5   ← chacun modifie SA copie
*/




























