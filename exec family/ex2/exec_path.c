#include <stdio.h>
#include <unistd.h>


int main()
{
    execlp("ls", "ls" , "-l" , "-a", NULL);
}
/*
execl("/bin/ls", "ls", "-l", "-a", NULL);  // chemin complet obligatoire
execlp("ls",     "ls", "-l", "-a", NULL);  // PATH automatique ✅
//      ↑
//  pas besoin de /bin/
```

---

### Les arguments

| Argument | Valeur | Rôle |
|---|---|---|
| 1er | `"ls"` | nom du programme — cherché dans PATH |
| 2ème | `"ls"` | argv[0] |
| 3ème | `"-l"` | affichage détaillé |
| 4ème | `"-a"` | fichiers cachés |
| 5ème | `NULL` | fin de liste |

---

### Comment execlp trouve ls ?
```
execlp("ls", ...)
      │
      ▼
cherche ls dans PATH
/usr/bin → /bin → /usr/local/bin ...
      │
      ▼
trouve /bin/ls  ✅
      │
      ▼
exécute ls -l -aexecl("/bin/ls", "ls", "-l", "-a", NULL);  // chemin complet obligatoire
execlp("ls",     "ls", "-l", "-a", NULL);  // PATH automatique ✅
//      ↑
//  pas besoin de /bin/
```

---

### Les arguments

| Argument | Valeur | Rôle |
|---|---|---|
| 1er | `"ls"` | nom du programme — cherché dans PATH |
| 2ème | `"ls"` | argv[0] |
| 3ème | `"-l"` | affichage détaillé |
| 4ème | `"-a"` | fichiers cachés |
| 5ème | `NULL` | fin de liste |

---

### Comment execlp trouve ls ?
```
execlp("ls", ...)
      │
      ▼
cherche ls dans PATH
/usr/bin → /bin → /usr/local/bin ...
      │
      ▼
trouve /bin/ls  
      │
      ▼
exécute ls -l -a


  */
