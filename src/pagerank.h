#ifndef PAGERANK_H
#define PAGERANK_H

#include "graph.h"

double *pagerank_google(const Graph *g, double alpha, double epsilon, int max_iter);

#endif