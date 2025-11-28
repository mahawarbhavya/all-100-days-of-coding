//Q69: Find the second largest element in an array.

/*
Sample Test Cases:
Input 1:
5
10 20 30 40 50
Output 1:
40

*/
#include <stdio.h>
#include <limits.h>

// Function to find second largest element
// Returns the second largest, or INT_MIN if not exists
int findSecondLargest(int arr[], int size) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    // Handle case where array has less than 2 elements
    if (size < 2) {
        printf("Array must have at least 2 elements!\n");
        return INT_MIN;
    }
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;   // Old largest becomes second
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];    // Update second largest
        }
    }
    
    // If no valid second largest found (e.g., all elements same)
    if (secondLargest == INT_MIN) {
        printf("No second largest element exists (all elements are same)\n");
    }
    
    return secondLargest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 35, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int second = findSecondLargest(arr, size);
    
    if (second != INT_MIN) {
        printf("Second largest element = %d\n", second);
    }
    
    return 0;
}