#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;    
}node_t;

typedef struct list
{
    node_t *head;
}list_t;

void init_list(list_t *list)
{
    list->head = NULL;
}

int isEmpty(list_t *list)
{
    return list->head == NULL;
}

node_t *create_node(int value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void add_first(list_t *list, int value)
{
   
    node_t *newnode = create_node(value);
    
    newnode->next = list->head;
  
    list->head = newnode;
}






void display_list(list_t *list)
{
    
    node_t *trav = list->head;
    printf("List : ");
    while(trav != NULL){
        
        printf("%-4d", trav->data);
      
        trav = trav->next;
    }
    printf("\n");
}
void delete_data(list_t *list,int data)
{
 node_t *trav = list->head;
 while(trav->next->data!=data && trav->next!= NULL)
 {
      trav=trav->next;

 }
 node_t *temp =trav->next;
 trav->next=trav->next->next;
 free(temp);

}

void delete_list(list_t *list)
{
    
    node_t *trav = list->head;
    while(trav != NULL){
        
        node_t *temp = trav;
        
        trav = trav->next;
        
        free(temp);
    }
    list->head = NULL;
}

int main(void)
{
    list_t l1;

    init_list(&l1);

    add_first(&l1, 40);
    add_first(&l1, 30);
    add_first(&l1, 20);
    add_first(&l1, 10);
    delete_data(&l1,10);
    
    display_list(&l1);

    delete_list(&l1);
    
    return 0;
}