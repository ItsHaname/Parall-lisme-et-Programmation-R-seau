#include <unistd.h>

int main()
{
    execl("/bin/ls", "ls", "-l", NULL);
}
/*
execl("/bin/ls", "ls", "-l", NULL);
//      ↑          ↑     ↑     ↑
//   chemin      nom   arg   fin
```

---

### Ce qui se passe
```
ton programme
      │
      ▼
execl()  ← remplace ton programme par ls
      │
      ▼
ls -l  ← s'exécute
  */
