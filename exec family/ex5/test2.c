#include <stdio.h>
#include <stdlib.h>
int main()
{
 int temps ;
    fprintf(stdout, "Nouveau code du fils \n") ;
    fprintf (stdout, "Durée du someil :") ;
    fscanf (stdin,"%d", &temps) ;
    sleep (temps) ;
    fprintf(stdout, "réveil et fin du fils après %d secondes \n", temps) ;
    exit(0) ;
}
