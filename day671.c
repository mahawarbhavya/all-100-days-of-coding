#include <stdio.h>
#include <stdlib.h>

/**
 * Merge Two Sorted Arrays - O(m+n) Two Pointer Technique
 * 
 * LOGIC ENHANCERS:
 * 1. TWO POINTERS: i for arr1, j for arr2
 * 2. COMPARE & PICK: Smaller element goes to merged array
 * 3. REMAINING ELEMENTS: Copy rest of non-empty array
 * 4. O(m+n) time, O(m+n) space - optimal
 * 5. Handles edge cases: empty arrays, different sizes
 * 
 * Time: O(m+n) | Space: O(m+n)
 */
void mergeSortedArrays(int* arr1, int m, int* arr2, int n, int* merged) {
    int i = 0, j = 0, k = 0;
    
    // Compare elements from both arrays
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    // Copy remaining elements from arr1
    while (i < m) {
        merged[k++] = arr1[i++];
    }
    
    // Copy remaining elements from arr2
    while (j < n) {
        merged[k++] = arr2[j++];
    }
}

/**
 * In-place merge (modifies arr1) - O(m+n) time, O(1) extra space
 */
void mergeSortedArraysInPlace(int* arr1, int m, int* arr2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    
    // Merge from right to left
    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }
    
    // Copy remaining from arr2
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

/**
 * Print array with formatting
 */
void printArray(int* arr, int n, const char* label) {
    printf("%s[", label);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

/**
 * Verify sorted and contains all elements
 */
int verifyMerged(int* arr1, int m, int* arr2, int n, int* merged) {
    int total = m + n;
    
    // Check sorted
    for (int i = 1; i < total; i++) {
        if (merged[i - 1] > merged[i]) {
            return 0;
        }
    }
    
    // Check all elements from arr1 present
    int count1 = 0;
    for (int i = 0; i < total; i++) {
        if (count1 < m && merged[i] == arr1[count1]) {
            count1++;
        }
    }
    
    // Check all elements from arr2 present
    int count2 = 0;
    for (int i = 0; i < total; i++) {
        if (count2 < n && merged[i] == arr2[count2]) {
            count2++;
        }
    }
    
    return (count1 == m && count2 == n);
}

/**
 * Interactive input for arrays
 */
int* readArray(int* size) {
    printf("Enter array size: ");
    if (scanf("%d", size) != 1 || *size <= 0) {
        printf("Invalid size!\n");
        return NULL;
    }
    
    int* arr = (int*)malloc(*size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    printf("Enter %d sorted integers: ", *size);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input!\n");
            free(arr);
            return NULL;
        }
    }
    return arr;
}

/**
 * Comprehensive test harness
 */
int main() {
    printf("=== MERGE TWO SORTED ARRAYS ===\n");
    printf("O(m+n) Two Pointer Algorithm\n");
    printf("Maintains sorted order\n\n");
    
    // Test cases
    struct TestCase {
        int arr1[10];
        int m;
        int arr2[10];
        int n;
    };
    
    struct TestCase test_cases[] = {
        {{1, 3, 5}, 3, {2, 4, 6}, 3},                    // [1,2,3,4,5,6]
        {{1}, 1, {2, 3, 4}, 3},                          // [1,2,3,4]
        {{1, 2, 3}, 3, {}, 0},                           // [1,2,3]
        {{}, 0, {1, 2, 3}, 3},                           // [1,2,3]
        {{1, 2, 4, 6}, 4, {3, 5, 7}, 3},                // [1,2,3,4,5,6,7]
        {{1, 1, 1}, 3, {1, 1, 1}, 3},                   // [1,1,1,1,1,1]
        {{1, 3, 5, 7}, 4, {2, 4, 6}, 3},                // [1,2,3,4,5,6,7]
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-20s | %-25s | %-10s\n", 
           "arr1", "arr2", "Merged", "Verified");
    printf("%-20s-+-%-20s-+-%-25s-+-%-10s\n", 
           "--------------------", "--------------------", "-------------------------", "----------");
    
    for (int test = 0; test < num_tests; test++) {
        int total = test_cases[test].m + test_cases[test].n;
        int* merged = (int*)malloc(total * sizeof(int));
        
        mergeSortedArrays(test_cases[test].arr1, test_cases[test].m,
                         test_cases[test].arr2, test_cases[test].n,
                         merged);
        
        int valid = verifyMerged(test_cases[test].arr1, test_cases[test].m,
                                test_cases[test].arr2, test_cases[test].n,
                                merged);
        
        printArray(test_cases[test].arr1, test_cases[test].m, "arr1:  ");
        printf(" + ");
        printArray(test_cases[test].arr2, test_cases[test].n, "arr2:  ");
        printf(" = ");
        printArray(merged, total, "merged: ");
        printf("    %s\n", valid ? "✓ PASS" : "✗ FAIL");
        
        free(merged);
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int m, n;
    
    printf("Enter size of first array: ");
    scanf("%d", &m);
    int* arr1 = readArray(&m);
    
    if (arr1 == NULL) return 1;
    
    printf("Enter size of second array: ");
    scanf("%d", &n);
    int* arr2 = readArray(&n);
    
    if (arr2 == NULL) {
        free(arr1);
        return 1;
    }
    
    int total = m + n;
    int* merged = (int*)malloc(total * sizeof(int));
    
    printArray(arr1, m, "arr1: ");
    printf(" + ");
    printArray(arr2, n, "arr2: ");
    printf("\n");
    
    mergeSortedArrays(arr1, m, arr2, n, merged);
    
    printf("Merged: ");
    printArray(merged, total, "");
    printf("\n");
    
    int valid = verifyMerged(arr1, m, arr2, n, merged);
    printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
    
    // Bonus: Demonstrate in-place merge (requires arr1 has enough space)
    if (m >= 0 && n >= 0) {
        printf("\n=== IN-PLACE MERGE DEMO ===\n");
        printf("(Modifies arr1 - needs m+n space in arr1)\n");
        int* arr1_copy = (int*)malloc((m + n) * sizeof(int));
        for (int i = 0; i < m; i++) arr1_copy[i] = arr1[i];
        
        printf("Before: ");
        printArray(arr1_copy, m + n, "");  // Show first m elements
        printf("\n");
        
        mergeSortedArraysInPlace(arr1_copy, m, arr2, n);
        printf("After:  ");
        printArray(arr1_copy, m + n, "");
        printf("\n");
        
        free(arr1_copy);
    }
    
    free(arr1);
    free(arr2);
    free(merged);
    return 0;
}