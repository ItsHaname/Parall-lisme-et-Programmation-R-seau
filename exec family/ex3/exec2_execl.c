#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    execl("./necho" , "ls" , "-l" , "slak" , NULL);
}
/*  execl("./necho", "ls", "-l", "slak", NULL);
//      ↑          ↑     ↑     ↑      ↑
//   chemin      argv[0] argv[1] argv[2]  fin
*/
/*
Ce que fait necho
necho est un programme qui affiche tous ses arguments :
c// necho.c
int main(int argc, char *argv[])
{
    for (int j = 0; j < argc; j++)
        printf("argv[%d] = %s\n", j, argv[j]);
}
*/
