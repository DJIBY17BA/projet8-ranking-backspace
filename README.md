# Projet 8 - Ranking Backspace

Projet de M1 Informatique — Ranking et Recommandation

Auteurs :
- Djiby Ba
- Narimane Mouhcene

## Objectif du projet

Le projet consiste à comparer :

- le modèle classique de Google PageRank ;
- un modèle alternatif appelé Backspace pour les pages sans lien sortant.

Dans le modèle classique de Google, lorsqu’un utilisateur arrive sur une page sans lien sortant, la probabilité est redistribuée uniformément grâce au surfeur aléatoire.

Dans le modèle Backspace, l’utilisateur revient à la page précédente, ce qui modifie la structure du graphe et les scores PageRank.

Le but est d’étudier l’impact de cette modification sur le classement des pages.

---

# Langage utilisé

- C (implémentation principale)
- Python (analyse et visualisation)

---

# Structure du projet

```text
projet8-ranking-backspace/
│
├── src/        # Code source C
├── data/       # Matrices et graphes
├── results/    # Résultats CSV et figures
├── scripts/    # Scripts Python
├── docs/       # Rapport et notes
└── README.md

# Contenu des dossiers

## `src/`

Contient :
- lecture des graphes ;
- calcul du PageRank ;
- transformation Backspace ;
- export des résultats.

### Principaux fichiers

- `graph.c`
- `io.c`
- `pagerank.c`
- `backspace.c`
- `main.c`

---

## `data/`

Contient les graphes utilisés :
- petits graphes de validation ;
- matrice réelle `wb-cs-stanford.mtx`.

---

## `results/`

Contient :
- résultats CSV ;
- figures générées avec Python.

### Exemples

- `results.csv`
- `top10_diff.csv`
- `sommet_0.png`
- `evolution_alpha.png`

---

## `scripts/`

Scripts Python utilisés pour :
- analyser les résultats ;
- générer les graphiques.

---

## `docs/`

Contient :
- le rapport du projet ;
- le PDF final.

---

# Compilation

Compilation sous GCC :

```bash
gcc src/main.c src/graph.c src/io.c src/pagerank.c src/backspace.c -o projet8.exe
```

---

# Exécution

```bash
./projet8.exe
```

ou sous Windows :

```bash
projet8.exe
```
# Générer les figures :

python scripts/plot_results.py

Les figures sont ensuite sauvegardées dans results/figures/.
---

# Paramètres étudiés

Le projet étudie principalement :

```text
alpha = 0.5, 0.7, 0.85, 0.9, 0.99
```

avec :
- PageRank Google ;
- PageRank Backspace.

---

# Méthode utilisée

Le calcul du PageRank est effectué avec :
- l’algorithme des puissances ;
- un seuil de convergence :

```text
epsilon = 1e-6
```

---

# Résultats principaux

Les expériences montrent que :
- le modèle Backspace modifie fortement certains scores ;
- certains sommets deviennent beaucoup plus importants ;
- les différences augmentent lorsque alpha devient grand.

Le modèle Backspace est donc plus sensible à la structure du graphe.

---

# Matrice utilisée

Matrice principale :

```text
wb-cs-stanford.mtx
```

Source :  
https://sparse.tamu.edu/Gleich/wb-cs-stanford

---

# Génération des figures

Exemple :

```bash
python scripts/plot_results.py
```

Ce script génère :
- les courbes ;
- les comparaisons ;
- les figures utilisées dans le rapport.