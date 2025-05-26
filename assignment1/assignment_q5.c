#include<stdio.h>

#define SIZE 11

int first_non_repeating(int arr[], int size);

int main()
{
    int arr[SIZE] = { 1,5,4,5,3,-1,2,3,6,2,1 };
    int index = first_non_repeating(arr, SIZE);
    if(index != -1)
        printf("First non-repeating element: %d at index %d\n", arr[index], index);
    else
        printf("No non-repeating element found.\n");
    return 0 ;
}

int first_non_repeating(int arr[], int size)
{
    for(int i = 0; i < size; i++) {
        int repeat = 0;
        for(int j = 0; j < size; j++) {
            if(i != j && arr[i] == arr[j]) {
                repeat = 1;
                break;
            }
        }
        if(!repeat)
            return i;
    }
    return -1;
}