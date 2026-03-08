/*
Exercice 2 — Attendre un fils spécifique avec waitpid()
Écris un programme où :

Le père crée deux fils
Chaque fils fait une tâche différente
Le père se termine seulement après la fin du deuxième fils

Contraintes :

Le père doit contrôler quel fils il attend avec waitpid()
Éviter les conditions de course
*/
/*
C'est quoi waitpid() ?
cwaitpid(pid2, &status, 0);
//       ↑        ↑     ↑
//    quel fils  statut  options
```

| | `wait()` | `waitpid()` |
|---|---|---|
| Attend | **n'importe quel** fils | **un fils précis** |
| Contrôle | ❌ aucun | ✅ on choisit lequel |
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status;

    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        printf("fils1 : je travaille...\n");
        sleep(2);
        printf("fils1 : j'ai fini\n");
        return 10;
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        printf("fils2 : je travaille...\n");
        sleep(4);
        printf("fils2 : j'ai fini\n");
        return 42;
    }

    printf("pere  : j'attends fils2...\n");
    waitpid(pid2, &status, 0);
    printf("pere  : fils2 termine avec code = %d\n", WEXITSTATUS(status));

    return 0;
}
