#ifndef T_STRING
#define T_STRING

typedef char *string;

#endif // T_STRING

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "list.h"

typedef struct Graph_Repr *graph;

// meta interface
/**
 * graph_create
 * allocate the required memory for a new graph
 * return a pointer to the new graph
 * return NULL on error
 */
graph graph_create (void);
/**
 * graph_destroy
 * free all memory associated with a given graph
 */
void graph_destroy (graph G);
/**
 * graph_show
 * print the contents of the graph to the given file
 * If the given file is NULL, print to stdout
 * The graph should be printed in the following format:
 *      vertex1
 *      vertex2
 *      vertex3
 *      ...
 *      vertexN
 *      vertex1 vertex2 weight
 *      vertex2 vertex4 weight
 *      vertexN vertex4 weight
 * Where the name name of each vertex is first printed
 * Then the directed edges between each vertex along with the edge weight is printed
 *
 * An ignore list is also passed, indicating that certain URLs are required
 * to be excluded from the output. The each element in the list will
 * be a url string.
 */
void graph_show (graph G, FILE *file, list ignore);

// vertex interface
/**
 * graph_add_vertex
 * Add a new vertex with a particular value to the graph
 * if a vertex with the same value already exists do not add a new vertex
 */
void graph_add_vertex (graph G, string vertex);
/**
 * graph_has_vertex
 * return True if a vertex with a particular value exists in the graph, False otherwise
 * return False on error
 */
bool graph_has_vertex (graph G, string vertex);

/**
 * graph_vertices_count
 * return the number of vertices in the graph
 * return 0 on error
 */
size_t graph_vertices_count (graph G);

// edge interface
/**
 * graph_add_edge
 * Add a new edge between two vertices with a weight to the graph
 * if a edge between two vertices already exists do not add a new edge
 */
void graph_add_edge (graph G, string vertex1, string vertex2, size_t weight);
/**
 * graph_has_edge
 * return True if a edge between two vertices exists in the graph, False otherwise
 * return False on error
 */
bool graph_has_edge (graph G, string vertex1, string vertex2);

/**
 * graph_set_edge
 * Update the weight of a edge between two vertices, if the edge doesn't exist do nothing
 */
void graph_set_edge (graph G, string vertex1, string vertex2, size_t weight);
/**
 * graph_get_edge
 * return the weight of the edge between two vertices
 * return 0 on error
 */
size_t graph_get_edge (graph G, string vertex1, string vertex2);
/**
 * graph_edges_count
 * return the number of outgoing edges from a particular vertex in the graph
 * return 0 on error
 */
size_t graph_edges_count (graph G, string vertex);

void show(graph G);
#endif //GRAPH_H
