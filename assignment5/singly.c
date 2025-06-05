#include"singly.h"

void init_list(list_t *list) {
    list->tail = NULL;
}

int isEmpty(list_t *list) {
    return list->tail == NULL;
}

node_t *create_node(int value) {
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void display(list_t *list) {
    if (isEmpty(list)) return;

    node_t *trav = list->tail->next;  
    printf("List: ");
    do {
        printf("%-4d", trav->data);
        trav = trav->next;
    } while (trav != list->tail->next);
    printf("\n");
}

void add_first(list_t *list, int value) {
    node_t *nn = create_node(value);

    if (isEmpty(list)) {
        nn->next = nn;
        list->tail = nn;
    } else {
        nn->next = list->tail->next;
        list->tail->next = nn;
    }
}

void add_last(list_t *list, int value) {
    node_t *nn = create_node(value);

    if (isEmpty(list)) {
        nn->next = nn;
        list->tail = nn;
    } else {
        nn->next = list->tail->next;
        list->tail->next = nn;
        list->tail = nn;
    }
}

void delete_first(list_t *list) {
    if (isEmpty(list)) return;

    node_t *head = list->tail->next;

    if (head == list->tail) {
        free(head);
        list->tail = NULL;
    } else {
        list->tail->next = head->next;
        free(head);
    }
}

void delete_last(list_t *list) {
    if (isEmpty(list)) return;

    node_t *head = list->tail->next;

    if (head == list->tail) {
        free(list->tail);
        list->tail = NULL;
    } else {
        node_t *trav = head;
        while (trav->next != list->tail)
            trav = trav->next;

        trav->next = list->tail->next;
        free(list->tail);
        list->tail = trav;
    }
}

void delete_all(list_t *list) {
    if (isEmpty(list)) return;

    node_t *head = list->tail->next;
    node_t *trav = head;

    do {
        node_t *temp = trav;
        trav = trav->next;
        free(temp);
    } while (trav != head);

    list->tail = NULL;
}
