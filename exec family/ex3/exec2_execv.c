#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    char *args[] = {"ls" , "-l" , "ls" , NULL};
    execv("./necho"  , args);
}
/*
char *args[] = {"ls", "-l", "ls", NULL};
//               ↑      ↑     ↑     ↑
//            argv[0] argv[1] argv[2]  fin
```

| Index | Valeur |
|---|---|
| `args[0]` | `"ls"` |
| `args[1]` | `"-l"` |
| `args[2]` | `"ls"` |
| `args[3]` | `NULL` |

---

### Ce qui se passe
```
execv("./necho", args)
      │
      ▼
necho reçoit le tableau args
      │
      ▼
affiche chaque argv
*/
