#include <stdio.h>

int linear_search(int arr[],int key,int size)
{
int ret=0;
    for (int i = 0; i <size; i++)
    {
        if(key>=arr[i])
        ret++;
    }
    return ret;
}
int main()
{
int arr[] ={10, 20, 15, 3, 4, 4, 1};
int key;
printf("enter key to find rank = ");
scanf("%d",&key);

int index=linear_search(arr,key,7);
if(index!=0)
printf(" rank of %d is = %d \n",key,index);
else
printf("key not found !!!!!\n");
    return 0;
}