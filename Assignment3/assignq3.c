#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node_t;

typedef struct list
{
    struct node *tail;
    struct node *head;
    int len;
}list_t;

void init_linklist(list_t *li)
 {
  li->head=NULL;
 }

void add_first(list_t *li,int value)
{
     node_t *newnode = (node_t *)malloc(sizeof(node_t));
     newnode->data = value;
      newnode->next = li->head;
     
    li->head=newnode;
    
    
}

void reverse(node_t *node) {
    if (node == NULL) 
    return;
    reverse(node->next);
    printf("%d ", node->data);
}

void display_Reverse(list_t *li)
{
   
reverse(li->head);
    
}



int main()
{

    list_t li;
    init_linklist(&li);
     
    add_first(&li, 50);
    add_first(&li, 60);
    add_first(&li, 70);
    add_first(&li, 80);

     printf("list in reverse order:\n");
      display_Reverse(&li);
      printf("\n");
    return 0;
}