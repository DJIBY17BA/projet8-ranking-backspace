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

    double alphas[] = {0.50, 0.70, 0.85, 0.90, 0.99};
    int nb_alphas = 5;
    double epsilon = 1e-6;
    int max_iter = 10000;

    Graph *bg = transform_backspace(g);

    if (bg == NULL) {
        printf("Erreur : transformation backspace impossible.\n");
        free_graph(g);
        return 1;
    }

    for (int a = 0; a < nb_alphas; a++) {
        double alpha = alphas[a];

        printf("\n==============================\n");
        printf("alpha = %.2f\n", alpha);
        printf("==============================\n");

        double *rank_google = pagerank_google(g, alpha, epsilon, max_iter);
        double *rank_backspace = pagerank_google(bg, alpha, epsilon, max_iter);

        if (rank_google == NULL || rank_backspace == NULL) {
            printf("Erreur : calcul PageRank impossible.\n");
            free(rank_google);
            free(rank_backspace);
            free_graph(bg);
            free_graph(g);
            return 1;
        }

        double *aggregated = calloc(g->n, sizeof(double));

        if (aggregated == NULL) {
            printf("Erreur : allocation aggregation impossible.\n");
            free(rank_google);
            free(rank_backspace);
            free_graph(bg);
            free_graph(g);
            return 1;
        }

        for (int i = 0; i < bg->n; i++) {
            int original = bg->origin[i];

            if (original >= 0 && original < g->n) {
                aggregated[original] += rank_backspace[i];
            }
        }

        printf("Google :\n");
        for (int i = 0; i < g->n; i++) {
            printf("Sommet %d : %.8f\n", i, rank_google[i]);
        }

        printf("Backspace agrege :\n");
        for (int i = 0; i < g->n; i++) {
            printf("Sommet %d : %.8f\n", i, aggregated[i]);
        }

        free(aggregated);
        free(rank_google);
        free(rank_backspace);
    }

    free_graph(bg);
    free_graph(g);

    return 0;
}