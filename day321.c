//Q63: Merge two arrays.

/*
Sample Test Cases:
Input 1:
3
1 2 3
2
4 5
Output 1:
1 2 3 4 5

*/
#include <stdio.h>

// Function to merge two 1D arrays into a result array
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    // Copy all elements from arr1
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    
    // Copy all elements from arr2
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {10, 20, 30, 40};
    int size1 = 4;
    
    int arr2[] = {50, 60, 70, 80, 90};
    int size2 = 5;
    
    // Result array must be large enough
    int result[size1 + size2];
    
    mergeArrays(arr1, size1, arr2, size2, result);
    
    printf("Array 1: ");
    for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for (int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    
    printf("\nMerged Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}