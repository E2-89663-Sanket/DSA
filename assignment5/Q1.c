#include<stdio.h>
#include<stdlib.h>

//struct node
typedef struct node{
    int data;
    struct node *next;
}node_t;
//struct list
typedef struct list{
    node_t *tail;
}list_t;
//init list
void list_init(list_t *list){
    list->tail = NULL;
}
//check list Empty
int isEmpty(list_t *list){
    return list->tail == NULL;
}
//create newnode
node_t *create_node(int value){
    node_t *newnode = (node_t*)malloc(sizeof(node_t));
    newnode->data = value;
    newnode->next=NULL;
    return newnode;
}
//add first
void add_first(list_t *list, int value){
        node_t *newnode = create_node(value);

        if(list->tail == NULL){
            list->tail = newnode;
            list->tail->next=newnode;
        }
        else{
        newnode->next = list->tail->next;
        list->tail->next = newnode;
        }
}
//add last
void add_last(list_t *list, int value){
     node_t *newnode = create_node(value);

        if(list->tail == NULL){
            list->tail = newnode;
            list->tail->next=newnode;
        }
        else{
        newnode->next = list->tail->next;
        list->tail->next = newnode;
         list->tail = newnode;
        }
}
//display List
void display_list(list_t *list){
    printf("list: ");
    if(list->tail == NULL)
        return;
    
    node_t *trav = list->tail->next;
    
    do{
        printf("%-6d",trav->data);
        trav = trav->next;
    }while( trav != list->tail->next);
    printf("\n");
}
//delete first
void delete_first(list_t *list){
    if(list->tail == NULL)
        return;
    else if(list->tail->next == list->tail){
        free(list->tail);
        list->tail = NULL;
    }
    else{
        node_t *temp = list->tail->next;
        list->tail->next = list->tail->next->next;
        free(temp);
    }
}
//delete last
void delete_last(list_t *list){
  if(list->tail == NULL)
    return;
  if(list->tail->next == list->tail){
    printf("abc\n");
        free(list->tail);
        list->tail = NULL;
    }
    else{
        node_t *trav = list->tail;

        while(trav->next != list->tail)
        {
            trav=trav->next;
        }
        node_t *temp = trav->next;
         trav->next = list->tail->next;
        list->tail = trav;
        free(temp);
    }
}
//delete list
void delete_all(list_t *list){

if(list->tail == NULL)
        return;

     node_t *trav = list->tail;
     node_t *temp;
   do{
        temp = trav;
        trav = trav->next;
        free(temp);
   }while(trav != list->tail);
    
     //free(list->tail);
     list->tail = NULL;
}


//Main
int main(void){
 
    list_t l;

    list_init(&l);

   add_first(&l, 400);
   add_first(&l, 500);
   add_first(&l, 600);
   add_first(&l, 700);

   display_list(&l);
    
    add_last(&l, 1100);    
    add_last(&l, 1200);    

    display_list(&l);

    delete_last(&l);
    display_list(&l);
    

    delete_all(&l);

    return 0;
}