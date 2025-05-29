#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int *arr;
    int SIZE;
    int top;

}stack_t;

void init_stack(stack_t *st)
{
    printf("enter size of stack :");
    scanf("%d", &st->SIZE);
    st->arr=(int *)malloc(sizeof(int) *st->SIZE);
    st->top = -1;

}

int isempty_stack(stack_t *st)
{
    return st->top == -1;

}

int isfull_stack(stack_t *st)
{
    return st->top == st-> SIZE-1;

}

void push_stack(stack_t *st, int value)
{
    if(isfull_stack(st))
    printf("stack is full \n");
    else
    st->arr[++st -> top] = value;

}

int pop_stack(stack_t *st)
{
    int num = -1;
    if(isempty_stack(st))
    printf("stack is empty\n");
    else
    num = st ->arr[st->top--];

    return num;
}

int main()
{
    int choise, value;
    stack_t st;
    init_stack(&st);

    printf("enter arr interger to get reverse \n ");
    while(!isfull_stack(&st))
    {
        scanf("%d", &value);
        push_stack(&st, value);
    }
    printf("reverse:");
    
    while(!isempty_stack(&st))
    {
        printf("%4d", pop_stack(&st));
    }
    printf("\n");
    free(st.arr);
    return 0;
}