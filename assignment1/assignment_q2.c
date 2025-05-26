#include<stdio.h>

#define SIZE 9

int linear_search_last(int key, int arr[SIZE]);

int main()
{
    int arr[SIZE] = {11, 55, 33, 44, 66, 88, 77, 22, 99};
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = linear_search_last(key, arr);
    if (index == -1)
        printf("Key not found!\n");
    else
        printf("Key found at last occurrence index = %d\n", index);
    
    
    return 0;
}

int linear_search_last(int key, int arr[SIZE])
{
    int last_index = -1;
     // Reset comparisons counter before search

    for (int index = 0; index < SIZE; index++)
    {
        
        if (key == arr[index])
        {
            last_index = index;  
        }
    }
    return last_index;
}
