//Q66: Insert an element in a sorted array at the appropriate position.

/*
Sample Test Cases:
Input 1:
5
1 2 4 5 6
3
Output 1:
1 2 3 4 5 6

*/
#include <stdio.h>

// Function to insert element in sorted array (returns new size)
int insertSorted(int arr[], int size, int capacity, int element) {
    // Check if array has space
    if (size >= capacity) {
        printf("Error: Array is full! Cannot insert %d\n", element);
        return size;  // No insertion
    }

    int i;
    // Find the correct position to insert
    for (i = size - 1; i >= 0 && arr[i] > element; i--) {
        arr[i + 1] = arr[i];  // Shift larger elements right
    }

    arr[i + 1] = element;  // Insert the element
    return size + 1;       // Return new size
}

int main() {
    // 1D array with some space left at the end for insertion
    int capacity = 20;
    int arr[20] = {10, 20, 30, 40, 60, 70, 80};  // Sorted
    int size = 7;  // Current number of elements
    int element;

    printf("Original sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter element to insert: ");
    scanf("%d", &element);

    // Perform insertion
    int newSize = insertSorted(arr, size, capacity, element);

    if (newSize > size) {
        printf("Element %d inserted successfully!\n", element);
    }

    printf("Updated sorted array: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}