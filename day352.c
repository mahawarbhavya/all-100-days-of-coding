//Q70: Rotate an array to the right by k positions.

/*
Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
4 5 1 2 3

*/
#include <stdio.h>

// Function to reverse a portion of array from start to end
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Rotate array to the right by k positions
void rotateRight(int arr[], int size, int k) {
    if (size <= 1 || k == 0) return;
    
    // Handle k > size
    k = k % size;
    if (k == 0) return;
    
    // Step 1: Reverse last k elements
    reverse(arr, size - k, size - 1);
    
    // Step 2: Reverse first (size - k) elements
    reverse(arr, 0, size - k - 1);
    
    // Step 3: Reverse entire array
    reverse(arr, 0, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int k;
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter number of positions to rotate right: ");
    scanf("%d", &k);
    
    rotateRight(arr, size, k);
    
    printf("After right rotation by %d: ", k);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}