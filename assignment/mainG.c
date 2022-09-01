#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"
#include "dijkstra.h"

int main(void) {
    graph myGrapth;
    myGrapth = graph_create();
    graph_add_vertex(myGrapth, "x");
    graph_add_vertex(myGrapth, "a");
    graph_add_vertex(myGrapth, "b");
    graph_add_vertex(myGrapth, "c");
    graph_add_vertex(myGrapth, "d");
    graph_add_vertex(myGrapth, "e");
    graph_add_vertex(myGrapth, "f");
    graph_add_vertex(myGrapth, "g");
    graph_add_vertex(myGrapth, "h");
    graph_add_vertex(myGrapth, "i");

    graph_add_edge(myGrapth, "x", "a", 12);
    graph_add_edge(myGrapth, "a", "b", 12);
    graph_add_edge(myGrapth, "b", "e", 12);
    graph_add_edge(myGrapth, "e", "f", 12);
    graph_add_edge(myGrapth, "f", "g", 12);
    graph_add_edge(myGrapth, "a", "c", 12);
    graph_add_edge(myGrapth, "c", "d", 12);
    graph_add_edge(myGrapth, "d", "f", 12);
    graph_add_edge(myGrapth, "a", "h", 12);
    graph_add_edge(myGrapth, "h", "i", 12);
    graph_add_edge(myGrapth, "i", "f", 12);
    printf("======\n");
    show(myGrapth);
    list ignore = list_create();
    list_add(ignore, "e");
    list_add(ignore, "d");
    list_add(ignore, "i");
    //list_add(ignore, "e");
    graph_shortest_path(myGrapth, "x", ignore);
    graph_view_path(myGrapth, "g", ignore);
}