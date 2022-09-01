#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#include "list.h"
//
//int main(void) {
//    list mylist;
//    mylist = list_create();
//    list_push(mylist, "https://www.bilibili.com/");
//    list_push(mylist, "asd");
//    list_push(mylist, "sdf");
//    printf("%d\n", list_length(mylist));
//    showList(mylist);
//    printf("%s\n", list_pop(mylist));
//    printf("%d\n", list_length(mylist));
//    printf("%s\n", list_pop(mylist));
//    printf("%d\n", list_length(mylist));
//    printf("%s\n", list_pop(mylist));
//    printf("%d\n", list_length(mylist));
//
//
//    list_destroy(mylist);
//    mylist = list_create();
//    list_enqueue(mylist, "dfg");
//    list_enqueue(mylist, "ggs");
//    list_enqueue(mylist, "hjk");
//    printf("%d\n", list_length(mylist));
//    showList(mylist);
//    printf("%s\n", list_dequeue(mylist));
//    printf("%d\n", list_length(mylist));
//    printf("%s\n", list_dequeue(mylist));
//    printf("%d\n", list_length(mylist));
//    printf("%s\n", list_dequeue(mylist));
//    printf("%d\n", list_length(mylist));
//    printf("%s\n", list_dequeue(mylist));
//    printf("%d\n", list_length(mylist));
//
//    list_destroy(mylist);
//    mylist = list_create();
//    list_add(mylist, "hhh");
//    list_add(mylist, "jjj");
//    list_add(mylist, "kkk");
//    list_add(mylist, "hhh");
//    list_remove(mylist, "jjj");
//    list_remove(mylist, "kkk");
//    showList(mylist);
//    printf("%d\n", list_is_empty(mylist));
//    printf("%d\n", list_length(mylist));
//    printf("%d", list_contains(mylist, "hhh"));
//}