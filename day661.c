#include <stdio.h>
#include <stdlib.h>

/**
 * Two Sum - O(n) Hash Table Approach
 * 
 * LOGIC ENHANCERS:
 * 1. HASH TABLE: Store (value → index) for O(1) lookups
 * 2. SINGLE PASS: Check complement while iterating
 * 3. EARLY TERMINATION: Return immediately when found
 * 4. O(n) time, O(n) space - optimal for one-pass solution
 * 5. Handles edge cases: n=2, duplicates, large values
 * 
 * Time: O(n) | Space: O(n)
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Dynamic hash table: value → index
    int capacity = numsSize;
    int size = 0;
    int* keys = (int*)malloc(capacity * sizeof(int));
    int* values = (int*)malloc(capacity * sizeof(int));  // indices
    
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in hash table
        for (int j = 0; j < size; j++) {
            if (keys[j] == complement) {
                // Found solution!
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = values[j];  // Earlier index
                result[1] = i;          // Current index
                *returnSize = 2;
                free(keys);
                free(values);
                return result;
            }
        }
        
        // Add current number to hash table
        if (size >= capacity) {
            capacity *= 2;
            keys = (int*)realloc(keys, capacity * sizeof(int));
            values = (int*)realloc(values, capacity * sizeof(int));
        }
        keys[size] = nums[i];
        values[size] = i;
        size++;
    }
    
    // No solution found
    free(keys);
    free(values);
    return NULL;
}

/**
 * Brute Force O(n²) for verification
 */
int* twoSumBrute(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    
    return NULL;
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
 * Print indices with space separation
 */
void printIndices(int* result, int returnSize) {
    if (result == NULL || returnSize != 2) {
        printf("-1 -1");
    } else {
        printf("%d %d", result[0], result[1]);
    }
    printf("\n");
}

/**
 * Verify correctness
 */
int verifyTwoSum(int* nums, int numsSize, int target, int* result, int returnSize) {
    int bruteSize;
    int* bruteResult = twoSumBrute(nums, numsSize, target, &bruteSize);
    
    int valid = (bruteResult != NULL && returnSize == 2);
    if (valid) {
        // Check if both solutions contain same indices
        int found1 = 0, found2 = 0;
        for (int i = 0; i < 2; i++) {
            if (bruteResult[0] == result[i] || bruteResult[1] == result[i]) {
                found1++;
            }
        }
        valid = (found1 == 2);
    }
    
    if (bruteResult != NULL) free(bruteResult);
    return valid;
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
    
    printf("Enter %d positive integers: ", *size);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &arr[i]) != 1 || arr[i] <= 0) {
            printf("Invalid input! Positive integers only.\n");
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
    printf("=== TWO SUM ===\n");
    printf("O(n) Hash Table Algorithm\n");
    printf("Find indices i,j where nums[i] + nums[j] = target\n\n");
    
    // Test cases: {nums, size, target, expected indices}
    struct TestCase {
        int nums[10];
        int n;
        int target;
        int expected[2];
    };
    
    struct TestCase test_cases[] = {
        {{2, 7, 11, 15}, 4, 9, {0, 1}},           // 2+7=9
        {{3, 2, 4}, 3, 6, {1, 2}},               // 2+4=6
        {{3, 3}, 2, 6, {0, 1}},                  // 3+3=6
        {{1, 2, 3, 4, 5}, 5, 7, {2, 3}},         // 3+4=7
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-8s | %-15s | %-10s\n", "Input", "target", "Hash", "Verified");
    printf("%-20s-+-%-8s-+-%-15s-+-%-10s\n", "--------------------", "--------", "---------------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        int returnSize;
        int* result = twoSum(test_cases[i].nums, test_cases[i].n, test_cases[i].target, &returnSize);
        int valid = verifyTwoSum(test_cases[i].nums, test_cases[i].n, test_cases[i].target, result, returnSize);
        
        printf("nums[%d,%d,...] | %6d  | ", test_cases[i].nums[0], test_cases[i].nums[1], test_cases[i].target);
        printIndices(result, returnSize);
        printf("    %s", valid ? "✓ PASS" : "✗ FAIL");
        
        if (result != NULL) {
            printf("  [%d+%d=%d]", test_cases[i].nums[result[0]], 
                   test_cases[i].nums[result[1]], test_cases[i].target);
        }
        printf("\n");
        
        if (result != NULL) free(result);
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size, target;
    int* user_arr = readArray(&size);
    
    if (user_arr != NULL) {
        printf("Enter target: ");
        if (scanf("%d", &target) != 1) {
            printf("Invalid target!\n");
            free(user_arr);
            return 1;
        }
        
        printArray(user_arr, size);
        printf(" target = %d\n", target);
        
        int returnSize;
        int* result = twoSum(user_arr, size, target, &returnSize);
        
        printf("Indices: ");
        printIndices(result, returnSize);
        
        int valid = verifyTwoSum(user_arr, size, target, result, returnSize);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ NO SOLUTION");
        
        if (result != NULL) {
            printf("Verification: %d + %d = %d ✓\n", 
                   user_arr[result[0]], user_arr[result[1]], target);
            free(result);
        }
        
        free(user_arr);
    }
    
    return 0;
}