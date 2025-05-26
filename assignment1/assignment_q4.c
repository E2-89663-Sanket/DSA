#include <stdio.h>

#define SIZE 9


int linear_occurrence(int key, int n, int arr[SIZE]);

int main()
{
    int arr[SIZE] = {1,5,6,2,3,4,9,7,8};
    int key, n;

    printf("Enter the key to search: ");
    scanf("%d", &key);
    printf("Enter the occurrence number (n): ");
    scanf("%d", &n);

    int index = linear_occurrence(key, n, arr);

    if (index == -1)
        printf("The %d occurrence of key %d not found!\n", n, key);
    else
        printf("The %d occurrence of key %d found at index = %d\n", n, key, index);

    
    return 0;
}

int linear_occurrence(int key, int n, int arr[SIZE])
{
    int count = 0;


    for (int index = 0; index < SIZE; index++)
    {
        
        if (arr[index] == key)
        {
            count++;
            if (count == n)
                return index;
        }
    }
    return -1;
}
