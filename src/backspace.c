#include <stdio.h>
#include <stdlib.h>
#include "backspace.h"

Graph *transform_backspace(const Graph *g) {
    if (g == NULL) return NULL;

    int extra_nodes = 0;
    int new_edges = 0;

    // 1. Compter combien de copies à créer
    for (int i = 0; i < g->n; i++) {
        if (g->out_degree[i] == 0 && g->in_degree[i] > 0) {
            extra_nodes += g->in_degree[i];
        }
    }

    // 2. Compter le nombre d’arcs du nouveau graphe
    for (int k = 0; k < g->m; k++) {
        int v = g->dst[k];

        if (g->out_degree[v] == 0 && g->in_degree[v] > 0) {
            new_edges += 2; // u -> copie et copie -> u
        } else {
            new_edges += 1;
        }
    }

    // 3. Créer le nouveau graphe
    Graph *bg = create_graph(g->n + extra_nodes, new_edges);
    if (bg == NULL) return NULL;

    // 4. Copier les origins des anciens sommets
    for (int i = 0; i < g->n; i++) {
        bg->origin[i] = g->origin[i];
    }

    // 5. Tableau pour gérer les copies
    int *next_copy = malloc(g->n * sizeof(int));
    if (next_copy == NULL) {
        free_graph(bg);
        return NULL;
    }

    int current = g->n;

    for (int i = 0; i < g->n; i++) {
        next_copy[i] = -1;

        if (g->out_degree[i] == 0 && g->in_degree[i] > 0) {
            next_copy[i] = current;

            for (int j = 0; j < g->in_degree[i]; j++) {
                bg->origin[current + j] = g->origin[i];
            }

            current += g->in_degree[i];
        }
    }

    // 6. Utilisation des copies
    int *used_copy = calloc(g->n, sizeof(int));
    if (used_copy == NULL) {
        free(next_copy);
        free_graph(bg);
        return NULL;
    }

    int e = 0;

    // 7. Reconstruction des arcs
    for (int k = 0; k < g->m; k++) {
        int u = g->src[k];
        int v = g->dst[k];

        if (g->out_degree[v] == 0 && g->in_degree[v] > 0) {
            int copy = next_copy[v] + used_copy[v];

            // u -> copie
            bg->src[e] = u;
            bg->dst[e] = copy;
            e++;

            // copie -> u (backspace)
            bg->src[e] = copy;
            bg->dst[e] = u;
            e++;

            used_copy[v]++;
        } else {
            bg->src[e] = u;
            bg->dst[e] = v;
            e++;
        }
    }

    compute_degrees(bg);

    free(next_copy);
    free(used_copy);

    return bg;
}