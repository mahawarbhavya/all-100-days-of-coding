//Q68: Delete an element from an array.

/*
Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
1 2 4 5

*/
#include <stdio.h>

// Delete first occurrence of 'element' from array
// Returns new size, or original size if not found
int deleteByValue(int arr[], int size, int element) {
    int pos = -1;
    
    // Find the position of the element
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            pos = i;
            break;
        }
    }
    
    // If not found
    if (pos == -1) {
        printf("Element %d not found in array!\n", element);
        return size;
    }
    
    // Shift elements to the left
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    printf("Element %d deleted successfully!\n", element);
    return size - 1;  // New size
}

int main() {
    int arr[20] = {10, 20, 30, 40, 50, 30, 60};
    int size = 7;
    int element;
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter element to delete: ");
    scanf("%d", &element);
    
    size = deleteByValue(arr, size, element);
    
    printf("Updated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}