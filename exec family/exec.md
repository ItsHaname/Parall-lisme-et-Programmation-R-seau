# 🖥️ La Famille des Appels exec

> Cours Programmation Système — Pr. M.A. El Kiram | Université Cadi Ayyad

---

## 📋 Table des matières

- [1. C'est quoi exec ?](#1-cest-quoi-exec-)
- [2. Les 4 fonctions](#2-les-4-fonctions)
- [3. execl()](#3-execl)
- [4. execv()](#4-execv)
- [5. execlp() et execvp()](#5-execlp-et-execvp)
- [6. Règle importante](#6-règle-importante)
- [7. fork() + exec()](#7-fork--exec)
- [8. argc / argv](#8-argc--argv)

---

## 1. C'est quoi exec ?

`exec` **remplace** le code du processus courant par un nouveau programme.
Après un `exec()` réussi, le processus ne revient **jamais** à l'ancien code.
```
avant exec()        après exec()
─────────────       ─────────────
mon programme  →    nouveau programme
même PID            même PID
```

> ⚠️ C'est pourquoi on utilise toujours `fork()` + `exec()` ensemble — le père crée un fils, et le fils change son code avec `exec()`.

---

## 2. Les 4 fonctions
```
exec family
 ├── execl()   → liste  + chemin complet
 ├── execv()   → tableau + chemin complet
 ├── execlp()  → liste  + PATH automatique
 └── execvp()  → tableau + PATH automatique
```

| Fonction | Arguments | Cherche dans PATH ? |
|---|---|---|
| `execl()` | liste | ❌ chemin complet obligatoire |
| `execv()` | tableau | ❌ chemin complet obligatoire |
| `execlp()` | liste | ✅ oui |
| `execvp()` | tableau | ✅ oui |

> 💡 **l** = liste, **v** = vecteur/tableau, **p** = PATH

---

## 3. execl()
```c
#include <unistd.h>

execl(chemin, arg0, arg1, ..., NULL);
//     ↑        ↑     ↑          ↑
//  chemin   nom    args     toujours NULL à la fin
```

**Exemple :**
```c
execl("/bin/ls", "ls", "-l", NULL);
```

---

## 4. execv()

Les arguments sont dans un **tableau** au lieu d'une liste.
```c
char *args[] = {"ls", "-l", NULL};
execv("/bin/ls", args);
```

---

## 5. execlp() et execvp()

Pas besoin du chemin complet — le système cherche dans `PATH` automatiquement.
```c
execlp("ls", "ls", "-l", NULL);  // cherche ls dans PATH

char *args[] = {"ls", "-l", NULL};
execvp("ls", args);               // cherche ls dans PATH
```

---

## 6. Règle importante
```c
printf("avant exec\n");
execl("/bin/ls", "ls", "-l", NULL);
printf("après exec\n");  // ← ne s'affiche JAMAIS
```

> ⚠️ Si `exec()` réussit, tout le code après est **écrasé** et ne s'exécute jamais.
> Si `exec()` échoue, le code continue normalement.

---

## 7. fork() + exec()
```
père
 │
fork()
 ├──────────── fils
 │              │
 │           exec()  ← remplace le code du fils
 │              │
 │         nouveau programme
 │
wait()  ← père attend
```
```c
pid_t pid = fork();

if (pid == 0)
{
    execl("/bin/ls", "ls", "-l", NULL);
    perror("exec failed");  // seulement si exec échoue
    exit(1);
}
else
{
    wait(NULL);
    printf("fils termine\n");
}
```

---

## 8. argc / argv
```c
int main(int argc, char *argv[])
//         ↑              ↑
//   nombre d'args     tableau des args
```
```bash
./necho hello world
# argc    = 3
# argv[0] = "./necho"
# argv[1] = "hello"
# argv[2] = "world"
```

---

## Résumé

| Concept | À retenir |
|---|---|
| `exec()` | remplace le code du processus |
| Après exec réussi | le code suivant ne s'affiche jamais |
| `fork()` + `exec()` | toujours ensemble |
| `l` vs `v` | liste vs tableau d'arguments |
| `p` | cherche dans PATH automatiquement |
| `NULL` | toujours à la fin des arguments |

---

*Cours Programmation Système — Pr. M.A. El Kiram | Université Cadi Ayyad*
