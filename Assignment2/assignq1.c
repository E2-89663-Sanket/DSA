#include<stdio.h>

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)

{

int temp = arr[i];
int j;
for (j=i-1; j>=0; j--)
{
    if(arr[j]< temp)
    {
        arr[j+i]= arr[j];
    }
    else
    break;
    }
    arr[j+1]=temp;
}

}
void show_arr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%4d", arr[i]);

    }
    printf("\n");

}

int main()
{
    int arr[]= {11,22,33,44,55,66,77,88,99};
    printf("before_sort : ");
    show_arr(arr, 9);
    insertion_sort(arr, 9);
    printf("after_sort : ");
    show_arr(arr, 9);
    return 0;
}
