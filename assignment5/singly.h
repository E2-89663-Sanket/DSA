#ifndef SINGLYCLL_TAIL_H
#define SINGLYCLL_TAIL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *tail;
} list_t;

void init_list(list_t *list);
int isEmpty(list_t *list);
node_t *create_node(int value);
void display(list_t *list);
void add_first(list_t *list, int value);
void add_last(list_t *list, int value);
void delete_first(list_t *list);
void delete_last(list_t *list);
void delete_all(list_t *list);

#endif
