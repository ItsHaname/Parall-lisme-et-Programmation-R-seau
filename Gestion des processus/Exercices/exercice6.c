/*
xercice 6 — Observer avec sleep()
Fais deux versions :
Version 1 :

Le fils dort 10 secondes
Le père dort 20 secondes

Version 2 :

Le fils dort 20 secondes
Le père dort 10 secondes

Dans chaque version, observe :

L'ordre de terminaison père/fils
L'apparition d'un processus zombie
Explique ce que tu observes


C'est quoi un zombie ?

Quand le fils se termine avant le père, il devient un zombie — il est mort mais reste dans la table des processus jusqu'à ce que le père lise son état avec wait().
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("fils  : PID=%d\n", getpid());
        sleep(10);   // fils termine en premier
    }
    else if (pid > 0)
    {
        printf("pere  : PID=%d\n", getpid());
        sleep(20);   // père termine en deuxième
    }
    else
        printf("erreur fork\n");
    return 0;
}
/*
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("fils  : PID=%d\n", getpid());
        sleep(20);   // fils termine en deuxième
    }
    else if (pid > 0)
    {
        printf("pere  : PID=%d\n", getpid());
        sleep(10);   // père termine en premier
    }
    else
        printf("erreur fork\n");
    return 0;
}
*/
/*Ce que tu vas observer
V1 fils dort 10s   ---> fils devient zombie en attendant le père
V2 père dort 10s  ---->fils devient orphelin, adopté par init
*/
































































