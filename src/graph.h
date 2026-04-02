#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int n;
    int m;
    int *src;
    int *dst;
    int *out_degree;
    int *in_degree;
} Graph;

Graph *create_graph(int n, int m);
void free_graph(Graph *g);
void compute_degrees(Graph *g);
void print_graph(const Graph *g);

#endif