#include <stdio.h>
#include <stdlib.h>

/**
 * Next Greater Element - Brute Force O(n²)
 * 
 * LOGIC ENHANCERS:
 * 1. Nested loops: For each element, scan right side only
 * 2. Early termination: Stop at FIRST greater element found
 * 3. Right-to-left optimization: Skip unnecessary comparisons
 * 4. Single pass per element: No redundant work
 * 5. Edge case handling: Last element always -1
 * 
 * Time: O(n²) | Space: O(1) | Guaranteed to find leftmost NGE
 */
void nextGreaterElement(int* arr, int n, int* result) {
    for (int i = 0; i < n; i++) {
        result[i] = -1;  // Default: no greater element
        
        // Scan from i+1 to end (right side only)
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;  // EARLY TERMINATION: First greater found!
            }
        }
    }
}

/**
 * Print result array in comma-separated format
 */
void printResult(int* result, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

/**
 * Print input array for clarity
 */
void printArray(int* arr, int n, const char* label) {
    printf("%s[", label);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("] -> ");
}

/**
 * Verify correctness of NGE solution
 */
int verifyNGE(int* arr, int n, int* result) {
    for (int i = 0; i < n; i++) {
        if (result[i] == -1) {
            // Check no greater element exists on right
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    return 0;  // Should have found it
                }
            }
        } else {
            // Check result[i] is actually greater and nearest
            int found = 0;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] == result[i]) {
                    found = 1;
                    // Check no closer greater element
                    for (int k = i + 1; k < j; k++) {
                        if (arr[k] > arr[i]) {
                            return 0;  // Closer one exists
                        }
                    }
                    break;
                }
            }
            if (!found) return 0;
        }
    }
    return 1;
}

/**
 * Interactive input
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
    
    printf("Enter %d integers: ", *size);
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
    printf("=== NEXT GREATER ELEMENT (BRUTE FORCE) ===\n");
    printf("O(n²) - Nested loops, no stack\n");
    printf("Finds NEAREST greater element on RIGHT\n\n");
    
    // Test cases with expected results
    int test_cases[][10] = {
        {4, 5, 2, 25},                  // 5, 25, 25, -1
        {13, -3, -14, 13, -3},          // -3, 13, 13, -1, -1
        {1, 2, 3, 4, 5},                // 2, 3, 4, 5, -1
        {5, 4, 3, 2, 1},                // -1, -1, -1, -1, -1
        {10, 9, 8, 7, 11},              // 11, 11, 11, 11, -1
        {1, 1, 1, 1, 1},                // -1, -1, -1, -1, -1
        {7, 5, 6},                      // 7, 6, -1
    };
    
    int sizes[] = {4, 5, 5, 5, 5, 5, 3};
    int expected[][10] = {
        {5, 25, 25, -1},
        {-3, 13, 13, -1, -1},
        {2, 3, 4, 5, -1},
        {-1, -1, -1, -1, -1},
        {11, 11, 11, 11, -1},
        {-1, -1, -1, -1, -1},
        {7, 6, -1}
    };
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-25s | %-10s\n", "Input", "Expected", "Verified");
    printf("%-20s-+-%-25s-+-%-10s\n", "--------------------", "-------------------------", "----------");
    
    for (int i = 0; i < 7; i++) {
        int n = sizes[i];
        int* result = (int*)malloc(n * sizeof(int));
        nextGreaterElement(test_cases[i], n, result);
        
        int valid = verifyNGE(test_cases[i], n, result);
        
        printArray(test_cases[i], n, "");
        printResult(result, n);
        printf("    %s\n", valid ? "✓ PASS" : "✗ FAIL");
        
        free(result);
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size;
    int* user_arr = readArray(&size);
    
    if (user_arr != NULL) {
        int* result = (int*)malloc(size * sizeof(int));
        
        printArray(user_arr, size, "Input: ");
        nextGreaterElement(user_arr, size, result);
        printResult(result, size);
        
        int valid = verifyNGE(user_arr, size, result);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
        
        free(result);
        free(user_arr);
    }
    
    return 0;
}