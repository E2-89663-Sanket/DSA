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




void add_position(list_t *list, int value, int pos)
{
    
    node_t *newnode = create_node(value);
   
    if(list->head == NULL)
       
        list->head = newnode;
  
    else if(pos <= 1){
       newnode->next=list->head;
        list->head=newnode;
    }
   
    else{
        
        node_t *trav = list->head;
                    
        for(int i = 1 ; i < pos - 1 && trav->next != NULL ; i++)
            trav = trav->next;
       
        newnode->next = trav->next;
       
        trav->next = newnode;
    }
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



void add_sort (list_t *list,int value)
{ 
    int i=0; 

node_t *trav=list->head;
   while(trav!=NULL)
   {
      if((trav->data) < value)
      {
        i++;
      }
      trav=trav->next;
    }
  
  if(i==0)
  {
   add_position(list,value,1);
  }
  else
  {
    add_position(list,value,++i);
  }
  


}

int main(void)
{
    list_t l1;

    init_list(&l1);
    int value;
    while(1)
    {
        printf("Enter value to enter : ");
            scanf("%d",&value);
          add_sort(&l1, value);
   
     
    display_list(&l1);
    }
    display_list(&l1);

   
    
    return 0;
}