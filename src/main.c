#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "io.h"
#include "pagerank.h"

int main(void) {
    Graph *g = read_graph_from_file("data/test.txt");

    if (g == NULL) {
        printf("Erreur : impossible de lire le graphe.\n");
        return 1;
    }

    printf("Degres du graphe :\n");
    for (int i = 0; i < g->n; i++) {
        printf("Sommet %d : out = %d, in = %d\n",
               i, g->out_degree[i], g->in_degree[i]);
    }

    double alpha = 0.85;
    double epsilon = 1e-6;
    int max_iter = 10000;

    double *rank = pagerank_google(g, alpha, epsilon, max_iter);

    if (rank == NULL) {
        printf("Erreur : calcul PageRank impossible.\n");
        free_graph(g);
        return 1;
    }

    printf("\nScores PageRank Google :\n");
    for (int i = 0; i < g->n; i++) {
        printf("Sommet %d : %.8f\n", i, rank[i]);
    }

    free(rank);
    free_graph(g);

    return 0;
}