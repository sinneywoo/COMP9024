#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct List_Repr {
    string data;
    struct List_Repr *next;
} List_Repr;

list list_create (void) {
    List_Repr *p = malloc(sizeof(List_Repr));
    p->next = NULL;
    return p;
}

void list_destroy (list l) {
    List_Repr *temp;
    while (l != NULL) {
        temp = l->next;
        free(l);
        l = temp;
    }
}

bool list_is_empty (list l) {
    bool flag;
    List_Repr *p = l->next;
    if (p == NULL) {
        flag = true;
    } else {
        flag = false;
    }
    return flag;
}

size_t list_length (list l) {
    List_Repr *p = l->next;
    size_t count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

List_Repr *makeNode(string v) {
    List_Repr *new = malloc(sizeof(List_Repr));
    assert(new != NULL);
    new->data = malloc(strlen(v) + 1);
    strcpy(new->data, v);
    new->next = NULL;    // initialise link to next node
    return new;          // return pointer to new node
}

void list_push (list l, string s) { //add a item to the tail of list
    List_Repr *new = makeNode(s);
    while (l->next != NULL) {
        l = l->next;
    }
    l->next = new;
}

string list_pop (list l) { //remove a item from the tail of list
    List_Repr *pfront, *p;
    if (list_length(l) != 0) {
        pfront = l;
        p = l->next;
        while (p->next != NULL) {
            pfront = p;
            p = p->next;
        }
        string t = malloc(strlen(p->data) + 1);
        strcpy(t, p->data);
        pfront->next = NULL;
        free(p);
        return t;
    }
    return NULL;
}

void list_enqueue (list l, string s) { //add a item to the head of list
    List_Repr *new = makeNode(s);
    new->next = l->next;
    l->next = new;
}

string list_dequeue (list l) { //remove a item from the tail of list
    List_Repr *pfront, *p;
    if (list_length(l) != 0) {
        pfront = l;
        p = l->next;
        while (p->next != NULL) {
            pfront = p;
            p = p->next;
        }
        string t = malloc(strlen(p->data) + 1);
        strcpy(t, p->data);
        pfront->next = NULL;
        free(p);
        return t;
    }
    return NULL;
}

void list_add (list l, string s) { //add a item to the tail of list
    if (list_contains(l, s) == false) {
        List_Repr *new = makeNode(s);
        while (l->next != NULL) {
            l = l->next;
        }
        l->next = new;
    }
}

void list_remove (list l, string s) { //search a item in the list and remove it
    List_Repr *pfront, *p;
    pfront = l;
    p = l->next;
    while (p != NULL) {
        if (strcmp(p->data, s) == 0) {
            pfront->next = p->next;
            free(p);
            break;
        }
        pfront = p;
        p = p->next;
    }
}

bool list_contains (list l, string s) {
    bool flag = false;
    List_Repr *p = l->next;
    while (p != NULL) {
        if (strcmp(p->data, s) == 0) {
            flag = true;
        }
        p = p->next;
    }
    return flag;
}

//just a test function
void showList(list l) {
    l = l->next;
    while (l != NULL) {
        printf("%s\n", l->data);
        l = l->next;
    }
}

