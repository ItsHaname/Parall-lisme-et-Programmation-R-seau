# 🧠 Gestion des Processus

---

## 📋 Table des matières

- [1. Qu'est-ce qu'un processus ?](#1-quest-ce-quun-processus-)
- [2. Le PCB — Process Control Block](#2-le-pcb--process-control-block)
- [3. Les états d'un processus](#3-les-états-dun-processus)
- [4. La création de processus : fork()](#4-la-création-de-processus--fork)
- [5. Fonctions utiles](#5-fonctions-utiles)
- [6. La mémoire après fork()](#6-la-mémoire-après-fork)

---

## 1. Qu'est-ce qu'un processus ?

Un **processus** = un programme en cours d'exécution. Il possède :

- Un **compteur ordinal** (l'adresse de la prochaine instruction)
- Des **registres** (données temporaires du CPU)
- Une **pile d'exécution** (pour les appels de fonctions)
- Un **espace mémoire** divisé en 4 segments :

| Segment | Rôle |
|---|---|
| Code | Les instructions du programme |
| Données | Les variables globales |
| Données supp. | Variables supplémentaires (heap) |
| Pile | Appels de fonctions, variables locales |

---

## 2. Le PCB — Process Control Block

Chaque processus est représenté dans le système par un **PCB**, une structure qui contient :

- **PID** : identifiant unique du processus
- **PPID** : PID du processus père
- **État** : en exécution, prêt, en attente...
- Compteur ordinal, registres sauvegardés
- Mémoire allouée, temps CPU utilisé

> Quand le CPU passe d'un processus **A** à un processus **B**, il **sauvegarde le PCB de A** et **charge le PCB de B** — c'est le **changement de contexte**.

---

## 3. Les états d'un processus

Un processus peut être dans **7 états** :

```
nouveau ──admis──► prêt ◄──interruption── en exécution ──sortie──► terminé
                    │          ▲                │
                suspendre   dispatch      attente E/S
                    │                          ▼
              prêt-suspendu            en attente
                                           │
                                       suspendre
                                           ▼
                                   en attente-suspendu
```

Les **3 états principaux** sont : `prêt`, `en exécution`, et `en attente`.

---

## 4. La création de processus : `fork()`

C'est la **seule façon** de créer un processus sous Unix/Linux.

```c
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void);
```

`fork()` **duplique** le processus qui l'appelle. Après le fork, il y a deux processus identiques qui continuent leur exécution à partir du même point.

La différence : la **valeur de retour** de `fork()` :

| Valeur retournée | Qui la reçoit ? |
|---|---|
| `0` | Le processus **fils** |
| `> 0` (le PID du fils) | Le processus **père** |
| `< 0` | Erreur, la création a échoué |

**Exemple de structure typique :**

```c
pid_t pid = fork();

if (pid == 0) {
    // Code exécuté par le FILS

} else if (pid > 0) {
    // Code exécuté par le PÈRE

} else {
    // Erreur
}
```

---

## 5. Fonctions utiles

| Fonction | Rôle |
|---|---|
| `getpid()` | Retourne le PID du processus courant |
| `getppid()` | Retourne le PID du père |
| `getuid()` | Retourne l'UID (identifiant utilisateur) |
| `getgid()` | Retourne le GID (identifiant groupe) |
| `sleep(n)` | Met le processus en pause pendant n secondes |
| `exit(0)` | Termine le processus |

---

## 6. La mémoire après `fork()`

> ⚠️ Après un `fork()`, le fils reçoit une **copie indépendante** de la mémoire du père. Si le fils modifie une variable, le père **ne voit pas** ce changement — et vice versa.

```c
int a = 10;
pid_t pid = fork();

if (pid == 0) {
    a += 40;                        // copie du fils → a = 50
    printf("Fils : a = %d\n", a);
} else {
    a += 30;                        // copie du père → a = 40
    printf("Père : a = %d\n", a);
}
// Chacun a SA propre copie de 'a' !
```

---

