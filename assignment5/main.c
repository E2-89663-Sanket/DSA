#include <stdio.h>
#include "singly.h"

int main() {
    list_t myList;
    init_list(&myList);

    printf("Adding elements at the beginning:\n");
    add_first(&myList, 30);
    add_first(&myList, 20);
    add_first(&myList, 10);
    display(&myList);  

    printf("\nAdding elements at the end:\n");
    add_last(&myList, 40);
    add_last(&myList, 50);
    display(&myList); 

    printf("\nDeleting first element:\n");
    delete_first(&myList);
    display(&myList); 

    printf("\nDeleting last element:\n");
    delete_last(&myList);
    display(&myList);  

    printf("\nDeleting all elements:\n");
    delete_all(&myList);
    display(&myList);  

    return 0;
}
