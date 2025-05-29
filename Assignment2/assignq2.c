
#include<stdio.h>
#include <stdlib.h>
typedef struct queue{

   int *arr;
   int rear;
   int front;
   int SIZE;

}queue_t;
void init_queue(queue_t *q)
{

printf("enter the size of queue : ");
scanf("%d",&q->SIZE);

q->arr = (int*)malloc(4*q->SIZE);
q->rear=q->front=0;


}
void push_queue(queue_t *q,int value)
{
   if(q->rear==q->SIZE)
   {
    printf("Queue is full \n");
    return;
   }
   
   q->arr[q->rear]=value;
   q->rear++;


}

int pop_queue(queue_t *q)
{
    int num = -1;
   if(q->rear==q->front)
   {
    printf("Queue is empty\n");
     return num;
   }
   num=q->arr[q->front];
   q->front++;

    if(q->front == q->rear)
    q->front = q->rear = 0;
    

return num;


}
int peek_queue(queue_t *q)
{ 
    int num=-1;
 if(q->rear==q->front)
 {

printf("Queue is empty\n");
     return num;

}
num=q->arr[q->front];
return num;
}


int main()
{
queue_t q;
int value,choice;
init_queue(&q);
do{
        printf("1. Push\n2. Pop\n3. Peek\n");
        printf("enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter value to be pushed : ");
            scanf("%d", &value);
            push_queue(&q, value);
            break;

        case 2:
            printf("poped data : %d\n", pop_queue(&q));
            break;

        case 3:
            printf("peeked data : %d\n", peek_queue(&q));
            break;
        }
    }while(choice != 0);



  return 0;
}