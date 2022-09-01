#ifndef T_STRING
#define T_STRING

typedef char *string;

#endif // T_STRING

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct List_Repr *list;

// meta interface
/**
 * list_create
 * allocate the required memory for a new list
 * return a pointer to the new list
 * return NULL on error
 */
list list_create (void);
/**
 * list_destroy
 * free all memory associated with a given list
 */
void list_destroy (list);

// misc interface
/**
 * list_is_empty
 * return True if there are no items in the list, False otherwise
 * return False on error
 */
bool list_is_empty (list);
/**
 * list_length
 * return the number of items in the list
 * return 0 on error
 */
size_t list_length (list);

// stack interface
/**
 * list_push
 * add an item to the head of the stack
 */
void list_push (list, string);
/**
 * list_pop
 * remove and return the item at the head of the stack
 * return NULL on error
 */
string list_pop (list);

// queue interface
/**
 * list_enqueue
 * add an item to the head of the queue
 */
void list_enqueue (list, string);
/**
 * list_dequeue
 * remove and return the item at the tail of the queue
 * return NULL on error
 */
string list_dequeue (list);

// set interface
/**
 * list_add
 * add an item into the set, if it is not already in the set
 */
void list_add (list, string);
/**
 * list_remove
 * remove an item from the set
 */
void list_remove (list, string);
/**
 * list_contains
 * return True if a particular item is in the set, False otherwise
 * return False on error
 */
bool list_contains (list, string);

// general interface
// You do not need to implement these functions, but they could be useful internally or for testing...
//void   list_append   (list, string);
//string list_shrink   (list);
//void   list_prepend  (list, string);
//string list_shift    (list);
void showList(list);

#endif // LIST_H
