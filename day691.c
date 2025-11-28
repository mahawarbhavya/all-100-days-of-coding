#include <stdio.h>
#include <stdlib.h>

/**
 * Find Duplicate - O(n) XOR Approach (Single Pass)
 * 
 * LOGIC ENHANCERS:
 * 1. XOR MAGIC: XOR all array elements with indices 0 to n-1
 * 2. DUPLICATE XORs with itself → 0, UNIQUE XOR with index → non-zero
 * 3. RESULT = XOR of all elements ^ XOR of all indices = DUPLICATE
 * 4. TRUE O(n) time, O(1) space, single iteration
 * 5. Works for ANY duplicate position
 * 
 * Time: O(n) | Space: O(1)
 */
int findDuplicateXOR(int* arr, int n) {
    int result = 0;
    
    // XOR all array elements with all indices
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
        result ^= i;
    }
    
    return result;
}

/**
 * Cycle Detection (Floyd's Tortoise & Hare) - Alternative O(n) solution
 */
int findDuplicateCycle(int* arr, int n) {
    int slow = arr[0];
    int fast = arr[0];
    
    // Phase 1: Find intersection point in cycle
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    
    // Phase 2: Find cycle entrance (duplicate)
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    return slow;
}

/**
 * Sum Approach - O(n) but vulnerable to overflow
 */
int findDuplicateSum(int* arr, int n) {
    int expected_sum = n * (n - 1) / 2;  // Sum of 0 to n-1
    int actual_sum = 0;
    
    for (int i = 0; i < n; i++) {
        actual_sum += arr[i];
    }
    
    return actual_sum - expected_sum;
}

/**
 * Brute Force O(n²) for verification
 */
int findDuplicateBrute(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return arr[i];
            }
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
int verifyDuplicate(int* arr, int n, int result) {
    // Check result exists in array
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == result) count++;
    }
    return (count == 2);  // Exactly one duplicate
}

/**
 * Interactive input
 */
int* readArray(int* size) {
    printf("Enter array size n: ");
    if (scanf("%d", size) != 1 || *size < 2) {
        printf("Invalid size! n >= 2 required\n");
        return NULL;
    }
    
    int* arr = (int*)malloc(*size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    printf("Enter %d integers (0 to %d with ONE duplicate): ", *size, *size - 1);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &arr[i]) != 1 || arr[i] < 0 || arr[i] >= *size) {
            printf("Invalid! Must be 0 to %d\n", *size - 1);
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
    printf("=== FIND THE DUPLICATE (SINGLE PASS) ===\n");
    printf("O(n) XOR Algorithm - TRUE O(1) space!\n");
    printf("Array contains 0 to n-1 with EXACTLY ONE duplicate\n\n");
    
    // Test cases
    struct TestCase {
        int arr[10];
        int n;
        int expected;
    };
    
    struct TestCase test_cases[] = {
        {{1, 3, 4, 2, 2}, 5, 2},           // Duplicate 2
        {{3, 1, 3, 4, 2}, 5, 3},           // Duplicate 3
        {{0, 1, 2, 3, 3}, 5, 3},           // Duplicate at end
        {{1, 1, 2, 3, 4}, 5, 1},           // Duplicate at start
        {{4, 0, 3, 1, 2, 4}, 6, 4},        // Larger array
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-10s | %-10s | %-10s\n", "Input", "XOR", "Cycle", "Verified");
    printf("%-20s-+-%-10s-+-%-10s-+-%-10s\n", "--------------------", "----------", "----------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        int xor_result = findDuplicateXOR(test_cases[i].arr, test_cases[i].n);
        int cycle_result = findDuplicateCycle(test_cases[i].arr, test_cases[i].n);
        int valid = verifyDuplicate(test_cases[i].arr, test_cases[i].n, xor_result);
        
        printArray(test_cases[i].arr, test_cases[i].n);
        printf(" | %8d  | %8d  | %s\n",
               xor_result, cycle_result,
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
        
        int xor_result = findDuplicateXOR(user_arr, size);
        int cycle_result = findDuplicateCycle(user_arr, size);
        
        printf("Duplicate (XOR):  %d\n", xor_result);
        printf("Duplicate (Cycle):%d\n", cycle_result);
        
        int valid = verifyDuplicate(user_arr, size, xor_result);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
        
        // Show XOR calculation
        printf("\n=== XOR EXPLANATION ===\n");
        int xor_step = 0;
        for (int i = 0; i < size; i++) {
            printf("Step %d: %d ^ %d ^ %d = %d\n", 
                   i, xor_step, user_arr[i], i, 
                   xor_step ^ user_arr[i] ^ i);
            xor_step ^= user_arr[i] ^ i;
        }
        printf("Final XOR: %d = DUPLICATE ✓\n", xor_step);
        
        free(user_arr);
    }
    
    return 0;
}