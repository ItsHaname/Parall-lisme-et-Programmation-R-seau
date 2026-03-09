#include <stdio.h>
#include <string.h>


int main(int ac , char **av)
{
    printf("ac = %d\n" , ac);
    for(int i = 1; av[i] ; i++)
    {
        printf("av[%d] = %s\n" ,  i ,  av[i]);
    }
}
/*int main(int ac, char **av)
//         ↑          ↑
//   nombre d'args   tableau des args*/
