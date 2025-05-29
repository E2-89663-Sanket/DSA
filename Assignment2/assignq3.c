#include<stdio.h>
#include <stdlib.h>
typedef struct queue{
   int *arr;
   int rear;
   int front;
   int SIZE;
   int count;

}queue_t;

void init_queue(queue_t *q)
{
printf("enter the size of queue : ");
scanf("%d",&q->SIZE);
q->arr = (int*)malloc(4*q->SIZE);
q->rear=q->front=-1;
q->count=0;
}

void check_queue(queue_t *q)
{
    printf("No of element in queue : %d\n",q->count);
}

int queue_empty(queue_t *q)
{
return q->count==0;
}

int queue_full(queue_t *q)
{
    return (q->count==q->SIZE);
}

void push_queue(queue_t *q,int value)
{      
   if(queue_full(q))
   {
    printf("Queue is full \n");
    return;
   }
   q->count++;
   q->rear=(q->rear+1)%q->SIZE;
   q->arr[q->rear]=value;   
    check_queue(q);
}

int pop_queue(queue_t *q)
{
    int num = -1;
   if(queue_empty(q))
   {
    printf("Queue is empty\n");
     return num;
   }
   q->count--;
   num=q->arr[(q->front + 1) % q->SIZE];
   
   q->front=(q->front+1)%q->SIZE;
   

    if(q->front == q->rear){
        q->front = q->rear = -1;
        
    }
    check_queue(q);

       
    

    return num;
}

int peek_queue(queue_t *q)
{ 
    int num=-1;
 if(queue_empty(q))
 {

    printf("Queue is empty\n");
     return num;

}
num=q->arr[(q->front + 1) % q->SIZE];
return num;
}


int main()
{
queue_t q;
int value,choice;
init_queue(&q);
do{
        printf("1. Push\n2. Pop\n3. Peek\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to be pushed : ");
            scanf("%d", &value);
            push_queue(&q, value);
            break;

        case 2:
            printf("Poped data : %d\n", pop_queue(&q));
            break;

        case 3:
            printf("Peeked data : %d\n", peek_queue(&q));
            break;
        }
    }while(choice != 0);
  return 0;
}