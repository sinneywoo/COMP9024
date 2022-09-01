#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include "list.h"

void graph_shortest_path(graph, string source, list ignore);
void graph_view_path(graph, string destination, list ignore);

#endif // DIJKSTRA_H
