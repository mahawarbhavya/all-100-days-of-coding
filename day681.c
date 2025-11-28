#include <stdio.h>
#include <stdlib.h>

/**
 * Find Missing Number - O(n) Mathematical Formula
 * 
 * LOGIC ENHANCERS:
 * 1. MATHEMATICAL FORMULA: Expected sum = n*(n+1)/2
 * 2. ACTUAL SUM: Calculate sum of given array
 * 3. MISSING = expected - actual → O(n) time, O(1) space
 * 4. XOR APPROACH: XOR all indices + array elements
 * 5. Handles edge cases: n=1, n=2, large n
 * 
 * Time: O(n) | Space: O(1)
 */
int missingNumberSum(int* arr, int n) {
    // Expected sum of 0 to n: n*(n+1)/2
    long long expected_sum = (long long)n * (n + 1) / 2;
    
    // Actual sum of given array
    long long actual_sum = 0;
    for (int i = 0; i < n; i++) {
        actual_sum += arr[i];
    }
    
    return expected_sum - actual_sum;
}

/**
 * XOR Approach - Alternative O(n) solution
 */
int missingNumberXOR(int* arr, int n) {
    int result = 0;
    
    // XOR all indices 0 to n
    for (int i = 0; i <= n; i++) {
        result ^= i;
    }
    
    // XOR all array elements
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    
    return result;
}

/**
 * Brute Force O(n²) for verification
 */
int missingNumberBrute(int* arr, int n) {
    for (int num = 0; num <= n; num++) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return num;
        }
    }
    return -1;
}

/**
 * Print array with formatting
 */
void printArray(int* arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

/**
 * Verify correctness
 */
int verifyMissing(int* arr, int n, int result) {
    // Check if result is in expected range
    if (result < 0 || result > n) return 0;
    
    // Check if result exists in array
    for (int i = 0; i < n; i++) {
        if (arr[i] == result) return 0;
    }
    
    // Verify with brute force
    return (result == missingNumberBrute(arr, n));
}

/**
 * Interactive input
 */
int* readArray(int* size) {
    printf("Enter array size n: ");
    if (scanf("%d", size) != 1 || *size <= 0) {
        printf("Invalid size!\n");
        return NULL;
    }
    
    int* arr = (int*)malloc(*size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    printf("Enter %d integers (0 to %d except one missing): ", *size, *size);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &arr[i]) != 1 || arr[i] < 0 || arr[i] > *size) {
            printf("Invalid input! Must be 0 to %d\n", *size);
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
    printf("=== FIND MISSING NUMBER ===\n");
    printf("O(n) Mathematical Formula\n");
    printf("Array contains 0 to n except ONE missing number\n\n");
    
    // Test cases: {array, size, expected_missing}
    struct TestCase {
        int arr[10];
        int n;
        int expected;
    };
    
    struct TestCase test_cases[] = {
        {{1, 2, 0, 4}, 4, 3},           // Missing 3
        {{0, 1}, 2, 2},                 // Missing 2
        {{1}, 1, 0},                    // Missing 0
        {{3, 0, 1}, 3, 2},              // Missing 2
        {{9, 8, 7, 6, 5, 4, 3, 2, 1}, 9, 0}, // Missing 0
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, 0}, // Missing 0
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-10s | %-10s | %-10s\n", "Input", "Formula", "XOR", "Verified");
    printf("%-20s-+-%-10s-+-%-10s-+-%-10s\n", "--------------------", "----------", "----------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        int formula_result = missingNumberSum(test_cases[i].arr, test_cases[i].n);
        int xor_result = missingNumberXOR(test_cases[i].arr, test_cases[i].n);
        int valid = verifyMissing(test_cases[i].arr, test_cases[i].n, formula_result);
        
        printArray(test_cases[i].arr, test_cases[i].n);
        printf(" | %8d  | %8d  | %s\n",
               formula_result, xor_result,
               valid ? "✓ PASS" : "✗ FAIL");
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size;
    int* user_arr = readArray(&size);
    
    if (user_arr != NULL) {
        printArray(user_arr, size);
        printf("\n");
        
        int formula_result = missingNumberSum(user_arr, size);
        int xor_result = missingNumberXOR(user_arr, size);
        
        printf("Missing number (Formula): %d\n", formula_result);
        printf("Missing number (XOR):    %d\n", xor_result);
        
        int valid = verifyMissing(user_arr, size, formula_result);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
        
        // Show expected range
        printf("Expected range: 0 to %d\n", size);
        printf("Expected sum: %lld\n", (long long)size * (size + 1) / 2);
        
        free(user_arr);
    }
    
    return 0;
}