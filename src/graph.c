#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph *create_graph(int n, int m) {
    Graph *g = malloc(sizeof(Graph));
    if (g == NULL) return NULL;

    g->n = n;
    g->m = m;

    g->src = malloc(m * sizeof(int));
    g->dst = malloc(m * sizeof(int));
    g->out_degree = calloc(n, sizeof(int));
    g->in_degree = calloc(n, sizeof(int));
    g->origin = malloc(n * sizeof(int));

    if (g->src == NULL || g->dst == NULL ||
        g->out_degree == NULL || g->in_degree == NULL ||
        g->origin == NULL) {
        free(g->src);
        free(g->dst);
        free(g->out_degree);
        free(g->in_degree);
        free(g->origin);
        free(g);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        g->origin[i] = i;
    }

    return g;
}

void free_graph(Graph *g) {
    if (g == NULL) return;

    free(g->src);
    free(g->dst);
    free(g->out_degree);
    free(g->in_degree);
    free(g->origin);
    free(g);
}

void compute_degrees(Graph *g) {
    if (g == NULL) return;

    for (int i = 0; i < g->n; i++) {
        g->out_degree[i] = 0;
        g->in_degree[i] = 0;
    }

    for (int k = 0; k < g->m; k++) {
        int u = g->src[k];
        int v = g->dst[k];

        if (u >= 0 && u < g->n && v >= 0 && v < g->n) {
            g->out_degree[u]++;
            g->in_degree[v]++;
        }
    }
}

void print_graph(const Graph *g) {
    if (g == NULL) return;

    printf("Graphe : %d sommets, %d arcs\n", g->n, g->m);

    printf("\nArcs :\n");
    for (int k = 0; k < g->m; k++) {
        printf("%d -> %d\n", g->src[k], g->dst[k]);
    }

    printf("\nDegres :\n");
    for (int i = 0; i < g->n; i++) {
        printf("Sommet %d : out = %d, in = %d, origine = %d\n",
               i, g->out_degree[i], g->in_degree[i], g->origin[i]);
    }
}