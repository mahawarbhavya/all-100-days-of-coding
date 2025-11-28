//Q67: Insert an element in an array at a given position.

/*
Sample Test Cases:
Input 1:
4
10 20 30 40
2 15
Output 1:
10 20 15 30 40

*/
#include <stdio.h>

// Function to insert element at specific position (0-based index)
// Returns new size, or -1 if insertion fails
int insertAtPosition(int arr[], int size, int capacity, int element, int pos) {
    // Validate position
    if (pos < 0 || pos > size) {
        printf("Invalid position! Must be between 0 and %d\n", size);
        return -1;
    }
    
    // Check if array is full
    if (size >= capacity) {
        printf("Error: Array is full! Cannot insert %d\n", element);
        return -1;
    }
    
    // Shift elements to the right from position 'pos'
    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    
    // Insert the new element
    arr[pos] = element;
    
    return size + 1;  // New size after insertion
}

int main() {
    int capacity = 20;
    int arr[20] = {10, 20, 30, 40, 50};  // Only 5 elements used initially
    int size = 5;
    int element, pos;
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter element to insert: ");
    scanf("%d", &element);
    
    printf("Enter position (0 to %d): ", size);
    scanf("%d", &pos);
    
    int newSize = insertAtPosition(arr, size, capacity, element, pos);
    
    if (newSize != -1) {
        printf("Insertion successful!\n");
        printf("Updated array: ");
        for (int i = 0; i < newSize; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}