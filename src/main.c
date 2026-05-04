#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "io.h"
#include "pagerank.h"
#include "backspace.h"

int main(void) {
    Graph *g = read_graph_from_file("data/test.txt");

    if (g == NULL) {
        printf("Erreur : impossible de lire le graphe.\n");
        return 1;
    }

    double alpha = 0.85;
    double epsilon = 1e-6;
    int max_iter = 10000;

    printf("Graphe original :\n");
    print_graph(g);

    double *rank_google = pagerank_google(g, alpha, epsilon, max_iter);

    if (rank_google == NULL) {
        printf("Erreur : calcul PageRank Google impossible.\n");
        free_graph(g);
        return 1;
    }

    printf("\nScores PageRank Google :\n");
    for (int i = 0; i < g->n; i++) {
        printf("Sommet %d : %.8f\n", i, rank_google[i]);
    }

    Graph *bg = transform_backspace(g);

    if (bg == NULL) {
        printf("Erreur : transformation backspace impossible.\n");
        free(rank_google);
        free_graph(g);
        return 1;
    }

    printf("\nGraphe backspace transforme :\n");
    print_graph(bg);

    double *rank_backspace = pagerank_google(bg, alpha, epsilon, max_iter);

    if (rank_backspace == NULL) {
        printf("Erreur : calcul PageRank Backspace impossible.\n");
        free_graph(bg);
        free(rank_google);
        free_graph(g);
        return 1;
    }

    double *aggregated = calloc(g->n, sizeof(double));

    if (aggregated == NULL) {
        printf("Erreur : allocation aggregation impossible.\n");
        free(rank_backspace);
        free_graph(bg);
        free(rank_google);
        free_graph(g);
        return 1;
    }

    for (int i = 0; i < bg->n; i++) {
        int original = bg->origin[i];

        if (original >= 0 && original < g->n) {
            aggregated[original] += rank_backspace[i];
        }
    }

    printf("\nScores PageRank Backspace agreges :\n");
    for (int i = 0; i < g->n; i++) {
        printf("Sommet %d : %.8f\n", i, aggregated[i]);
    }

    free(aggregated);
    free(rank_backspace);
    free_graph(bg);
    free(rank_google);
    free_graph(g);

    return 0;
}