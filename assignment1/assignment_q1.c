#include <stdio.h>


int binary(int arr[], int size, int key) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])  // In descending: go right
            left = mid + 1;
        else                      // key > arr[mid] — go left
            right = mid - 1;
    }
    return -1;
}


int binary_recursive(int arr[], int left, int right, int key) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (key == arr[mid])
        return mid;
    else if (key < arr[mid])  // go right in descending
        return binary_recursive(arr, mid + 1, right, key);
    else                      // go left
        return binary_recursive(arr, left, mid - 1, key);
}

int main() {
    int key;
    
    int arr[] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
    printf("Enter the key: ");
    scanf("%d", &key);
    
    int index = binary_recursive(arr, 0, 8, key);     
    if (index != -1)
        printf("Key is found at index %d\n", index);
    else
        printf("Key is not found\n");
    
    return 0;
}
