#ifndef PAGERANK_H
#define PAGERANK_H

#include "graph.h"
#include "list.h"

void graph_pagerank(graph G, double damping, double delta, list ignore);
void graph_viewrank(graph G, FILE *file, list ignore);

#endif // PAGERANK_H
