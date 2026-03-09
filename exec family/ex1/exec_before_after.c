#include <stdio.h>
#include <unistd.h>


int main()
{
    printf("Before exec\n");
    execl("/bin/ls", "ls", "-l", NULL);
    printf("After exec\n");
}
/*
### Ce qui se passe étape par étape
```
ton programme
      │
      ▼
"Before exec"  ← s'affiche
      │
      ▼
execl()  ← ton programme est ÉCRASÉ par ls
      │
      ▼
ls -l  ← s'exécute à la place
      │
      ▼
"After exec"  ← n'existe plus en mémoire 
*/
