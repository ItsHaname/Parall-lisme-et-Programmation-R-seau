#include <stdio.h>
#include <unistd.h>


int main()
{
    execl("/bin/ls", "ls" , "-l" , "-a", NULL);
}
//execl("/bin/ls", "ls", "-l", "-a", NULL);
//      ↑          ↑     ↑     ↑     ↑
//   chemin      nom   arg1  arg2   fin
