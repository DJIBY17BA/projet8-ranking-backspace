#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pagerank.h"

double *pagerank_google(const Graph *g, double alpha, double epsilon, int max_iter) {
    int n = g->n;
    int m = g->m;

    double *x = malloc(n * sizeof(double));
    double *y = malloc(n * sizeof(double));

    if (x == NULL || y == NULL) {
        free(x);
        free(y);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        x[i] = 1.0 / n;
    }

    for (int iter = 0; iter < max_iter; iter++) {
        for (int i = 0; i < n; i++) {
            y[i] = (1.0 - alpha) / n;
        }

        double dangling_mass = 0.0;

        for (int i = 0; i < n; i++) {
            if (g->out_degree[i] == 0) {
                dangling_mass += x[i];
            }
        }

        for (int i = 0; i < n; i++) {
            y[i] += alpha * dangling_mass / n;
        }

        for (int k = 0; k < m; k++) {
            int u = g->src[k];
            int v = g->dst[k];

            if (g->out_degree[u] > 0) {
                y[v] += alpha * x[u] / g->out_degree[u];
            }
        }

        double diff = 0.0;

        for (int i = 0; i < n; i++) {
            diff += fabs(y[i] - x[i]);
        }

        for (int i = 0; i < n; i++) {
            x[i] = y[i];
        }

        if (diff < epsilon) {
            break;
        }
    }

    free(y);
    return x;
}