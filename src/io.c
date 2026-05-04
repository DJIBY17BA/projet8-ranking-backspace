#include <stdio.h>
#include <stdlib.h>
#include "io.h"

Graph *read_graph_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier\n");
        return NULL;
    }

    int n, m;
    if (fscanf(file, "%d %d", &n, &m) != 2) {
        printf("Erreur : lecture n m\n");
        fclose(file);
        return NULL;
    }

    Graph *g = create_graph(n, m);
    if (g == NULL) {
        fclose(file);
        return NULL;
    }

    for (int k = 0; k < m; k++) {
        int u, v;
        if (fscanf(file, "%d %d", &u, &v) != 2) {
            printf("Erreur : lecture arc\n");
            free_graph(g);
            fclose(file);
            return NULL;
        }

        g->src[k] = u;
        g->dst[k] = v;
    }

    fclose(file);

    compute_degrees(g);

    return g;
}