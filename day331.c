//Q65: Search in a sorted array using binary search.

/*
Sample Test Cases:
Input 1:
5
1 3 5 7 9
7
Output 1:
Found at index 3

Input 2:
5
1 3 5 7 9
6
Output 2:
-1

*/
#include <stdio.h>

// Iterative Binary Search - returns index if found, -1 if not found
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoids integer overflow
        
        if (arr[mid] == target) {
            return mid;       // Found! Return index
        }
        else if (arr[mid] < target) {
            low = mid + 1;    // Search right half
        }
        else {
            high = mid - 1;   // Search left half
        }
    }
    
    return -1;  // Not found
}

int main() {
    // Must be sorted in ascending order
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int size = 11;
    int target;
    
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter element to search: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    return 0;
}