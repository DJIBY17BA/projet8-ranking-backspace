# Notes de travail

## Sujet
Comparer PageRank Google classique avec le modèle backspace pour les pages sans lien sortant.

## Idée Google
Si une page n'a pas de lien sortant, on redistribue uniformément.

## Idée Backspace
Si une page n'a pas de lien sortant, l'utilisateur revient à la page précédente.

## Paramètre à étudier
alpha
## Graph.h
graph.h définit la structure Graph
cette structure contient le nombre de sommets, le nombre d’arcs, les arcs et les degrés
les tableaux sont représentés par des pointeurs
le fichier annonce aussi les fonctions pour créer, libérer, calculer les degrés et afficher le graphe