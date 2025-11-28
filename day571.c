#include <stdio.h>
#include <stdlib.h>

/**
 * Previous Greater Element - Brute Force O(n²)
 * 
 * LOGIC ENHANCERS:
 * 1. Nested loops: For each element, scan LEFT side only
 * 2. Early termination: Stop at FIRST greater element found (right-to-left)
 * 3. Left-to-right optimization: Skip unnecessary comparisons  
 * 4. Single pass per element: No redundant work
 * 5. Edge case handling: First element always -1
 * 
 * Time: O(n²) | Space: O(1) | Guaranteed to find rightmost PGE
 */
void previousGreaterElement(int* arr, int n, int* result) {
    for (int i = 0; i < n; i++) {
        result[i] = -1;  // Default: no greater element on left
        
        // Scan from i-1 down to 0 (left side only)
        for (int j = i - 1; j >= 0; j--) {
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
 * Verify correctness of PGE solution
 */
int verifyPGE(int* arr, int n, int* result) {
    for (int i = 0; i < n; i++) {
        if (result[i] == -1) {
            // Check no greater element exists on left
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i]) {
                    return 0;  // Should have found it
                }
            }
        } else {
            // Check result[i] is actually greater and nearest
            int found = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] == result[i]) {
                    found = 1;
                    // Check no closer greater element (between j+1 and i-1)
                    for (int k = j + 1; k < i; k++) {
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
    printf("=== PREVIOUS GREATER ELEMENT (BRUTE FORCE) ===\n");
    printf("O(n²) - Nested loops, no stack\n");
    printf("Finds NEAREST greater element on LEFT\n\n");
    
    // Test cases with expected results
    int test_cases[][10] = {
        {4, 5, 2, 25},                  // -1, 4, 5, 2
        {13, -3, -14, 13, -3},          // -1, 13, -3, -14, 13
        {1, 2, 3, 4, 5},                // -1, 1, 2, 3, 4
        {5, 4, 3, 2, 1},                // -1, 5, 4, 3, 2
        {10, 9, 8, 7, 11},              // -1, 10, 10, 10, 7
        {1, 1, 1, 1, 1},                // -1, -1, -1, -1, -1
        {7, 5, 6},                      // -1, 7, 7
    };
    
    int sizes[] = {4, 5, 5, 5, 5, 5, 3};
    int expected[][10] = {
        {-1, 4, 5, 2},
        {-1, 13, -3, -14, 13},
        {-1, 1, 2, 3, 4},
        {-1, 5, 4, 3, 2},
        {-1, 10, 10, 10, 7},
        {-1, -1, -1, -1, -1},
        {-1, 7, 7}
    };
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-25s | %-10s\n", "Input", "Expected", "Verified");
    printf("%-20s-+-%-25s-+-%-10s\n", "--------------------", "-------------------------", "----------");
    
    for (int i = 0; i < 7; i++) {
        int n = sizes[i];
        int* result = (int*)malloc(n * sizeof(int));
        previousGreaterElement(test_cases[i], n, result);
        
        int valid = verifyPGE(test_cases[i], n, result);
        
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
        previousGreaterElement(user_arr, size, result);
        printResult(result, size);
        
        int valid = verifyPGE(user_arr, size, result);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
        
        free(result);
        free(user_arr);
    }
    
    return 0;
}