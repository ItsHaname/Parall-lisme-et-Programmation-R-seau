/*
Exercice 4 — Carré d'une matrice avec des processus
Écris un programme qui :

Prend en entrée une matrice 2×2
Le père crée 4 fils
Chaque fils calcule un seul élément du carré de la matrice
Chaque fils retourne son résultat au père via exit()
Le père collecte les 4 valeurs avec wait() et affiche la matrice finale


Rappel — Carré d'une matrice 2×2
| a  b |²     | a²+bc   ab+bd |
| c  d |   =  | ca+dc   cb+d² |

Contraintes

Chaque fils calcule exactement un élément
Utilise waitpid() pour récupérer les résultats
Pas de mémoire partagée
exit() ne peut retourner que des valeurs entre 0 et 255
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int a = 1, b = 2, c = 3, d = 4;
    int matrix[2][2];
    pid_t pid[4];

    printf("Matrice initiale :\n");
    printf("%d %d\n", a, b);
    printf("%d %d\n", c, d);

    // fils 0 → matrix[0][0]
    pid[0] = fork();
    if (pid[0] == 0)
        exit(a*a + b*c);

    // fils 1 → matrix[0][1]
    pid[1] = fork();
    if (pid[1] == 0)
        exit(a*b + b*d);

    // fils 2 → matrix[1][0]
    pid[2] = fork();
    if (pid[2] == 0)
        exit(c*a + d*c);

    // fils 3 → matrix[1][1]
    pid[3] = fork();
    if (pid[3] == 0)
        exit(c*b + d*d);

    // père collecte les résultats
    int status;
    waitpid(pid[0], &status, 0);
    matrix[0][0] = WEXITSTATUS(status);

    waitpid(pid[1], &status, 0);
    matrix[0][1] = WEXITSTATUS(status);

    waitpid(pid[2], &status, 0);
    matrix[1][0] = WEXITSTATUS(status);

    waitpid(pid[3], &status, 0);
    matrix[1][1] = WEXITSTATUS(status);

    printf("Matrice au carre :\n");
    printf("%d %d\n", matrix[0][0], matrix[0][1]);
    printf("%d %d\n", matrix[1][0], matrix[1][1]);

    return 0;
}
