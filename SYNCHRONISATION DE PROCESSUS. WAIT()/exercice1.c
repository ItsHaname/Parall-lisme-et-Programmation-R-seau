/*
Exercice 1 — Synchronisation père/fils avec wait()
Tu as un programme où :

Le père crée un fils
Le fils fait une action visible
Le père se termine avant le fils
Le prompt du shell réapparaît avant que le fils ait fini

Modifie le programme pour que :

Le père attend correctement la fin du fils avec wait()
Affiche et interprète :

La valeur de retour de wait()
Le statut de terminaison du fils


Remplace toute attente active par une synchronisation bloquante
*/
/*
C'est quoi wait() ?
cint status;
pid_t pid = wait(&status);
```

| | Signification |
|---|---|
| `wait()` | bloque le père jusqu'à la fin du fils |
| `WIFEXITED(status)` | vérifie si le fils s'est terminé normalement |
| `WEXITSTATUS(status)` | récupère la valeur retournée par le fils |

---
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status;
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("fils  : je travaille...\n");
        sleep(2);
        printf("fils  : j'ai fini\n");
        return 42;
    }
    else
    {
        printf("pere  : j'attends le fils...\n");
        pid_t ret = wait(&status);
        printf("pere  : fils termine avec code = %d\n", WEXITSTATUS(status));
        printf("pere  : c'est bien mon fils ? %s\n", (ret == pid) ? "OUI" : "NON");
    }
    return 0;
}
