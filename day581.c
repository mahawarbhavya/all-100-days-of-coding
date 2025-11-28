#include <stdio.h>
#include <stdlib.h>

/**
 * Product Except Self - O(n) time, O(1) space
 * 
 * LOGIC ENHANCERS:
 * 1. TWO PASS APPROACH: Left products → Right products
 * 2. Left-to-right: answer[i] = product of all left of i
 * 3. Right-to-left: answer[i] *= product of all right of i  
 * 4. No division: Avoids precision/zero issues
 * 5. In-place: Uses result array as temporary storage
 * 6. O(1) extra space: Only result array (required for output)
 * 
 * Time: O(n) | Space: O(1)
 */
void productExceptSelf(int* nums, int numsSize, int* answer) {
    if (numsSize <= 0) return;
    
    // Phase 1: Left-to-right pass
    // answer[i] = product of all elements LEFT of i
    answer[0] = 1;  // No elements left of index 0
    
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }
    
    // Phase 2: Right-to-left pass  
    // Multiply by product of all elements RIGHT of i
    int right_product = 1;
    
    for (int i = numsSize - 2; i >= 0; i--) {
        right_product *= nums[i + 1];
        answer[i] *= right_product;
    }
}

/**
 * Brute Force O(n²) for verification
 */
void productExceptSelfBrute(int* nums, int numsSize, int* answer) {
    for (int i = 0; i < numsSize; i++) {
        int product = 1;
        for (int j = 0; j < numsSize; j++) {
            if (j != i) {
                product *= nums[j];
            }
        }
        answer[i] = product;
    }
}

/**
 * Print array with formatting
 */
void printArray(int* arr, int size, const char* label) {
    printf("%s[", label);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/**
 * Verify correctness
 */
int verifyProduct(int* nums, int numsSize, int* answer) {
    int* brute = (int*)malloc(numsSize * sizeof(int));
    productExceptSelfBrute(nums, numsSize, brute);
    
    for (int i = 0; i < numsSize; i++) {
        if (answer[i] != brute[i]) {
            free(brute);
            return 0;
        }
    }
    free(brute);
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
    printf("=== PRODUCT EXCEPT SELF ===\n");
    printf("O(n) time, O(1) space - Two pass approach\n");
    printf("answer[i] = product of all nums[j] where j != i\n\n");
    
    // Test cases
    int test_cases[][6] = {
        {1, 2, 3, 4},           // [24, 12, 8, 6]
        {-1, 1, 0, -3, 3},      // [0, 0, -9, 9, 9]
        {2, 2, 2, 2},           // [8, 8, 8, 8] 
        {0, 0, 0},              // [0, 0, 0]
        {1},                    // [1]
        {-4, -3, -2, -1, 60},   // [3628800, -3628800, 7257600, -14515200, -302400]
    };
    
    int sizes[] = {4, 5, 4, 3, 1, 5};
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-25s | %-10s\n", "Input", "Output", "Verified");
    printf("%-20s-+-%-25s-+-%-10s\n", "--------------------", "-------------------------", "----------");
    
    for (int i = 0; i < 6; i++) {
        int n = sizes[i];
        int* result = (int*)malloc(n * sizeof(int));
        int* input_copy = (int*)malloc(n * sizeof(int));
        
        // Copy input for verification
        for (int j = 0; j < n; j++) {
            input_copy[j] = test_cases[i][j];
        }
        
        productExceptSelf(test_cases[i], n, result);
        int valid = verifyProduct(input_copy, n, result);
        
        printArray(test_cases[i], n, "Input:  ");
        printArray(result, n, "Output: ");
        printf("    %s\n", valid ? "✓ PASS" : "✗ FAIL");
        
        free(result);
        free(input_copy);
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size;
    int* user_arr = readArray(&size);
    
    if (user_arr != NULL) {
        int* result = (int*)malloc(size * sizeof(int));
        
        printArray(user_arr, size, "Input:  ");
        productExceptSelf(user_arr, size, result);
        printArray(result, size, "Output: ");
        
        int valid = verifyProduct(user_arr, size, result);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
        
        free(result);
        free(user_arr);
    }
    
    return 0;
}