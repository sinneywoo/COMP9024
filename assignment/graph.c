#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "graph.h"
#define VERY_HIGH_VALUE 999999


typedef struct VNode{
    int Vindex;
    int weight;
    struct VNode *Vnext;
} VNode, * Edge;

typedef struct Graph_Repr {
    int nV;
    int nE;
    string *v;
    Edge *e;
    double *pRank;
    double *oRank;
    int *numEdge;
    int *pred;
    bool *vSet;
} Graph_Repr;

graph graph_create (void) {
    graph g = malloc(sizeof(Graph_Repr));
    g->nV = 0;
    g->nE = 0;
    return g;
}

void graph_destroy (graph G) {
    free(G->e);
}

void graph_add_vertex (graph G, string vertex) {
    if (G->nV == 0) {
//        G->v = malloc(strlen(vertex) + 1);
//        G->v[0] = malloc(sizeof(string *));
        G->v = malloc(sizeof(string));
        G->v[0] = malloc(strlen(vertex) + 1);
        G->e = malloc(sizeof(VNode *));
        G->e[0] = malloc(sizeof(VNode));
        G->e[0]->Vnext = NULL;
        strcpy(G->v[0], vertex);
//        G->v[G->nV] = vertex;
        G->nV++;
    } else {
        if (graph_has_vertex(G, vertex) != true) {
//            G->v = realloc(G->v, (strlen(vertex) + 1) * (G->nV + 1));
//            G->v[G->nV] = malloc(sizeof(string *));
            G->v = realloc(G->v, sizeof(string) * (G->nV + 1));
            G->v[G->nV] = malloc(strlen(vertex) + 1);
            G->e = realloc(G->e, sizeof(VNode *) * (G->nV + 1));
            G->e[G->nV] = malloc(sizeof(VNode));
            G->e[G->nV]->Vnext = NULL;
            strcpy(G->v[G->nV], vertex);
//            G->v[G->nV] = vertex;
            G->nV++;
        }
    }
}

bool graph_has_vertex (graph G, string vertex) {
    bool flag = false;
    for (int j = 0; j < G->nV; ++j) {
        if (strcmp(G->v[j], vertex) == 0) {
            flag = true;
        }
    }
    return flag;
}

size_t graph_vertices_count (graph G) {
    return G->nV;
}

void graph_add_edge (graph G, string vertex1, string vertex2, size_t weight) {
    if (graph_has_edge(G, vertex1, vertex2) == true) {
        return;
    }
    int index1 = 0;
    int index2 = 0;
    for (int j = 0; j < G->nV; ++j)  { //get the edge index
        if (strcmp(G->v[j], vertex1) == 0) {
            index1 = j;
        }
        if (strcmp(G->v[j], vertex2) == 0) {
            index2 = j;
        }
    }

    VNode *edge = malloc(sizeof(VNode));
    edge->Vindex = index2;
    edge->weight = weight;
    edge->Vnext = NULL;
    VNode *p;
    VNode *p1;
    p = G->e[index1];
    p1 = G->e[index1]->Vnext;
    while (p1 != NULL) { //add the edge to the tail of list
        p = p1;
        p1 = p1->Vnext;
    }
    edge->Vnext = p->Vnext;
    p->Vnext = edge;
    G->nE++;
}

bool graph_has_edge (graph G, string vertex1, string vertex2) {
    bool flag = false;
    if (G->nE > 0) {
        for (int i = 0; i < G->nV; ++i) {
            VNode *p = G->e[i]->Vnext;
            if (strcmp(G->v[i], vertex1) == 0) {
                while (p != NULL) {
                    if (strcmp(G->v[p->Vindex], vertex2) == 0) {
                        flag = true;
                        break;
                    }
                    p = p->Vnext;
                }
            }
        }
    }
    return flag;
}

void graph_set_edge (graph G, string vertex1, string vertex2, size_t weight) {
    if (graph_has_edge(G, vertex1, vertex2) == false) {
        return;
    }
    for (int i = 0; i < G->nV; ++i) {
        VNode *p = G->e[i]->Vnext;
        while (p != NULL) {
            if (strcmp(G->v[p->Vindex], vertex2) == 0) {
                p->weight = weight;
            }
            p = p->Vnext;
        }
    }
}

size_t graph_get_edge (graph G, string vertex1, string vertex2) {
    if (graph_has_edge(G, vertex1, vertex2) == true) {
        for (int i = 0; i < G->nV; ++i) {
            VNode *p = G->e[i]->Vnext;
            while (p != NULL) {
                if (strcmp(G->v[p->Vindex], vertex2) == 0) {
                    return p->weight;
                }
                p = p->Vnext;
            }
        }
    }
    return 0;
}

size_t graph_edges_count (graph G, string vertex) {
    size_t num = 0;
    for (int i = 0; i < G->nV; ++i) {
        VNode *p = G->e[i]->Vnext;
        if (strcmp(G->v[i],  vertex) == 0) {
            while (p != NULL) {
                num++;
                p = p->Vnext;
            }
        }
    }
    return num;
}

size_t graph_edges_ignore_count (graph G, string vertex, list ignore) { //count the num of edges which are not in ignore
    size_t num = 0;
    for (int i = 0; i < G->nV; ++i) {
        VNode *p = G->e[i]->Vnext;
        if (strcmp(G->v[i],  vertex) == 0) {
            while (p != NULL) {
                if (list_contains(ignore, G->v[p->Vindex]) == false) {
                    num++;
                }
                p = p->Vnext;
            }
        }
    }
    return num;
}

void graph_show (graph G, FILE *file, list ignore) {
    if(!file) {
        for (int i = 0; i < G->nV; ++i) {
            if (list_contains(ignore, G->v[i]) == false) {
                fprintf(stdout,"%s\n", G->v[i]);
            }
        }
        for (int i = 0; i < G->nV; ++i) {
            if (list_contains(ignore, G->v[i]) == false) {
                VNode *p = G->e[i]->Vnext;
                while (p != NULL) {
                    if (list_contains(ignore, G->v[p->Vindex]) == false) {
                        fprintf(stdout,"%s %s %d\n", G->v[i], G->v[p->Vindex], p->weight);
                    }
                    p = p->Vnext;
                }
            }
        }
    } else {
        for (int i = 0; i < G->nV; ++i) {
            if (list_contains(ignore, G->v[i]) == false) {
                fprintf(file,"%s\n", G->v[i]);
            }
        }
        for (int i = 0; i < G->nV; ++i) {
            if (list_contains(ignore, G->v[i]) == false) {
                VNode *p = G->e[i]->Vnext;
                while (p != NULL) {
                    if (list_contains(ignore, G->v[p->Vindex]) == false) {
                        fprintf(stdout,"%s %s %d\n", G->v[i], G->v[p->Vindex], p->weight);
                    }
                    p = p->Vnext;
                }
            }
        }
    }
}

void graph_pagerank(graph G, double damping, double delta, list ignore) {
    int num = G->nV;
    G->oRank = calloc(num, sizeof(double ));
    G->pRank = calloc(num, sizeof(double ));
    for (int i = 0; i < G->nV; ++i) {
        if (list_contains(ignore, G->v[i]) == true) {
            num--;
        }
    }
    for (int i = 0; i < G->nV; ++i) {
        G->oRank[i] = 0;
        G->pRank[i] = 1.0 / num;
    }
    for (int j = 0; j < num; ++j) {
        while (fabs(G->pRank[j] - G->oRank[j]) > delta && list_contains(ignore, G->v[j]) == false) {
            for (int i = 0; i < G->nV; ++i) {
                if (list_contains(ignore, G->v[i]) == false) {
                    G->oRank[i] = G->pRank[i];
                }
            }
            double sink_rank = 0;
            for (int i = 0; i < G->nV; ++i) {
                if (list_contains(ignore, G->v[i]) == false) {
                    if (graph_edges_ignore_count(G, G->v[i], ignore) == 0) {
                        sink_rank = sink_rank + (damping * (G->oRank[i] / num));
                    }
                }
            }
            for (int i = 0; i < G->nV; ++i) {
                if (list_contains(ignore, G->v[i]) == false) {
                    G->pRank[i] = sink_rank + ((1 - damping) / num);
                    for (int k = 0; k < G->nV; ++k) {
                        if (list_contains(ignore, G->v[k]) == false) {
                            if (graph_has_edge(G, G->v[k], G->v[i]) == true) {
                                G->pRank[i] = G->pRank[i] + ((damping * G->oRank[k]) / graph_edges_ignore_count(G, G->v[k], ignore));
                            }
                        }
                    }
                }
            }
        }
    }
}

void graph_viewrank(graph G, FILE *file, list ignore) {
    int index[G->nV];
    int temp;
    double temp1;
    for (int i = 0; i < G->nV; ++i) {
        index[i] = i;
    }
    for (int i = 0; i < G->nV; ++i) {
        for (int j = 0; j < G->nV - i - 1; ++j) {
            if (G->pRank[j] < G->pRank[j + 1]) {
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;

                temp1 = G->pRank[j];
                G->pRank[j] = G->pRank[j + 1];
                G->pRank[j + 1] = temp1;
            }
        }
    }
    if (!file) {
        for (int i = 0; i < G->nV; ++i) {
            if (list_contains(ignore, G->v[index[i]]) == false) {
                fprintf(stdout,"%s (%.3lf)\n", G->v[index[i]], G->pRank[i]);
            }
        }
    } else {
        for (int i = 0; i < G->nV; ++i) {
            if (list_contains(ignore, G->v[index[i]]) == false) {
                fprintf(file,"%s (%.3lf)\n", G->v[index[i]], G->pRank[i]);
            }
        }
    }
}

void graph_shortest_path(graph G, string source, list ignore) {
    G->numEdge = calloc(G->nV, sizeof(int));
    G->pred = calloc(G->nV, sizeof(int));
    G->vSet = calloc(G->nV, sizeof(bool));
    bool hasbeMin[G->nV];
    for (int i = 0; i < G->nV; ++i) {
        if (list_contains(ignore, G->v[i]) == true) {
            G->vSet[i] = false;
            hasbeMin[i] = false;
        } else {
            G->vSet[i] = true;
            hasbeMin[i] = true;
        }
        if (strcmp(G->v[i], source) == 0) {
            G->numEdge[i] = 0;
            G->pred[i] = -1;
        } else {
            G->numEdge[i] = VERY_HIGH_VALUE;
            G->pred[i] = -1;
        }
    }

    for (int i = 0; i < G->nV; ++i) {
        int min = VERY_HIGH_VALUE;
        int index = 0;
        for (int j = 0; j < G->nV; ++j) {
           if (hasbeMin[j] == true && G->numEdge[j] < min) {
               min = G->numEdge[j];
               index = j;
           }
        }

        for (int j = 0; j < G->nV; ++j) {
            int path1[G->nV], path2[G->nV];
            if (G->numEdge[j] == min && j != index && hasbeMin[j] == true) { //compare two path and output by the input order
                int cyindex = index;
                int cj = j;
                int p1 = 1;
                int p2 = 1;
                path1[0] = cyindex;
                path2[0] = cj;
                while (G->pred[cyindex] != -1) {
                    cyindex = G->pred[cyindex];
                    path1[p1] = cyindex;
                    p1++;
                }

                while (G->pred[cj] != -1) {
                    cj = G->pred[cj];
                    path2[p2] = cj;
                    p2++;
                }

                if (cj == cyindex) {
                    p1--;
                    p2--;
                    while (path1[p1] == path2[p2] && p1 >= 0 && p2 >= 0) {
                        p1--;
                        p2--;
                    }
                    if (path1[p1] > path2[p2]) {
                        min = G->numEdge[path2[0]];
                        index = path2[0];
                    } else {
                        min = G->numEdge[path1[0]];
                        index = path1[0];
                    }
                } else if (cj < cyindex) {
                    min = G->numEdge[j];
                    index = j;
                }
            }
        }
        hasbeMin[index] = false;


        for (int j = 0; j < G->nV; ++j) {
            if (list_contains(ignore, G->v[j]) == false) {
                if (graph_has_edge(G, G->v[index], G->v[j]) == true) {
                    if (G->numEdge[index] + 1 < G->numEdge[j]) {
                        G->numEdge[j] = G->numEdge[index] + 1;
                        G->pred[j] = index;
                    }
                }
            }
        }
        G->vSet[i] = false;
    }
}

void graph_view_path(graph G, string destination, list ignore) { //use list function to view the path
    list p = list_create();
    int index = -1;
    list_push(p, destination);
    for (int i = 0; i < G->nV; ++i) {
        if (strcmp(G->v[i], destination) == 0) {
            index = i;
        }
    }
    while (G->pred[index] != -1) {
        int pre = G->pred[index];
        list_push(p, G->v[pre]);
        index = pre;
    }
    int length = list_length(p);
    if (length > 1) {
        for (int i = 0; i < length; ++i) {
            printf("%s\n", list_pop(p));
        }
    }
}

//just a test function
void show(graph G) {
    printf("V:\n");
    for (int i = 0; i < G->nV; ++i) {
        printf("%s\n", G->v[i]);
    }
    printf("E:\n");
    for (int i = 0; i < G->nV; ++i) {
        VNode *p = G->e[i]->Vnext;
        while (p != NULL) {
            printf("%s %s %d\n", G->v[i], G->v[p->Vindex], p->weight);
            p = p->Vnext;
        }
    }
}



