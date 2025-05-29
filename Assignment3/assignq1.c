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
    printf("enter size of stack: ");
    scanf("%d", &st->SIZE);
    st->arr=(int *)malloc(sizeof(int )*st->SIZE);
    st->top = st-> SIZE;

}

int isempty_stack(stack_t *st)
{
    return st->top==st->SIZE;
}

int isfull_stack(stack_t *st)
{
    return st->top == 0;

}

void push_stack(stack_t *st, int value)
{
    if(isfull_stack(st))
    printf("stack is full \n");
    else 
    st->arr[--st->top]=value;
}

int pop_stack(stack_t *st)
{
    int num = -1 ;
    if(isempty_stack(st))
    printf("stack is empty\n");
    else
    num = st-> arr[st->top++];
    return num;
}

int peek_stack(stack_t *st)
{
    int num = -1;
    if(isempty_stack(st))
    printf("stack is empty\n");
    else
    num =st->arr[st->top];
return num;
}

int main()
{
    int choise,value;
    stack_t st;
    init_stack(&st);
    do
    {
        printf("1. push\n2. pop \n3. peek\n0. exit: \n");
        printf("enter you choise :");
        scanf("%d", &choise);

        switch (choise)
        {
            case 1:
            printf("Enter value to push on stack : ");
            scanf("%d",&value);
            push_stack(&st,value);
            break;
        case 2:
        printf("pop value : %d \n",pop_stack(&st));
        break;
        case 3:
        printf("peek value : %d \n",peek_stack(&st));
        break;
        default:
        printf("Invalid choise !!!!!\n");
        break;
        }
    } while (choise!=0);
    
free(st.arr);


return 0;
}
        