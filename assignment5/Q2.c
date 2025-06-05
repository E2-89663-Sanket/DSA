#include<stdio.h>
#include<stdlib.h>

//node
typedef struct node{
    int data;
    struct node *next;
}node_t;
//list
typedef struct list{
    node_t *head;
}list_t;
//initialise list
void list_init(list_t *list){
    list->head = NULL;
}
//check list empty
int isEmpty(list_t *list){
    return list->head == NULL;
}
//create new node
node_t *create_node(int value){
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
//add first
void add_first(list_t *list, int value){
    node_t *newnode = create_node(value);

    newnode->next = list->head;

    list->head = newnode;
}
//display list
void display_list(list_t *list){
    node_t *trav = list->head;

    if (list->head == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while(trav != NULL){
        printf("%-4d",trav->data);
        trav = trav->next;
    }
    printf("\n");
}
//peek list at head
void peek_list(list_t *list){
    if (list->head == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Peeked Data: %d\n", list->head->data);
}

//delete first
void delete_first(list_t *list){
    if(list->head == NULL)
        return;
    else{
        node_t *temp = list->head;
        list->head = list->head->next;
        printf("popped data: %d\n",temp->data);
        free(temp);
    }
    
}

//delete list
void delete_list(list_t *list){
    node_t *trav = list->head;

    while(trav != NULL){
        node_t *temp = trav;
        trav = trav->next;
        free(temp);
    }
    list->head = NULL;
}


int main(void){

    list_t l1;
    list_init(&l1);

int choice,value;

do{
        printf("1. Push\n2. Pop\n3. Peek\n4. Display Stack\n0. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to be pushed : ");
            scanf("%d", &value);
            add_first(&l1, value);
            break;

        case 2:
            delete_first(&l1);
            break;

        case 3:
            peek_list(&l1);
            break;
        case 4:
            display_list(&l1);
            break;
        case 0:
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }while(choice != 0);

    delete_list(&l1);

    return 0;
}