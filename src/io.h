#ifndef IO_H
#define IO_H

#include "graph.h"

Graph *read_graph_from_file(const char *filename);
Graph *read_graph_mtx(const char *filename);

#endif