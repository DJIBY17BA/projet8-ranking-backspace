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

    if (g->src == NULL || g->dst == NULL || g->out_degree == NULL || g->in_degree == NULL) {
        free(g->src);
        free(g->dst);
        free(g->out_degree);
        free(g->in_degree);
        free(g);
        return NULL;
    }

    return g;
}

void free_graph(Graph *g) {
    if (g == NULL) return;

    free(g->src);
    free(g->dst);
    free(g->out_degree);
    free(g->in_degree);
    free(g);
}