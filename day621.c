#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Kadane's Algorithm - O(n) Maximum Subarray Sum
 * 
 * LOGIC ENHANCERS:
 * 1. DYNAMIC PROGRAMMING: max_ending_here tracks best subarray ending at i
 * 2. Two choices per position: Start new subarray OR extend existing
 * 3. Global maximum tracking: max_so_far
 * 4. Handles ALL NEGATIVE case: Returns largest single element
 * 5. Single pass: O(n) time, O(1) space
 * 
 * Time: O(n) | Space: O(1)
 */
long long kadaneAlgorithm(int* arr, int n) {
    if (n <= 0) return LLONG_MIN;
    
    long long max_so_far = arr[0];      // Global maximum
    long long max_ending_here = arr[0]; // Best ending at current position
    
    for (int i = 1; i < n; i++) {
        // Choice: Start new subarray OR extend existing?
        max_ending_here = (arr[i] > max_ending_here + arr[i]) ? 
                         arr[i] : max_ending_here + arr[i];
        
        // Update global maximum
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
    }
    
    return max_so_far;
}

/**
 * Brute Force O(n³) for verification
 */
long long kadaneBrute(int* arr, int n) {
    if (n <= 0) return LLONG_MIN;
    
    long long max_sum = LLONG_MIN;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long current_sum = 0;
            for (int k = i; k <= j; k++) {
                current_sum += arr[k];
            }
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    
    return max_sum;
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
int verifyKadane(int* arr, int n, long long result) {
    long long brute_result = kadaneBrute(arr, n);
    return (result == brute_result);
}

/**
 * Find and print the actual subarray (bonus)
 */
void printMaxSubarray(int* arr, int n, long long max_sum) {
    long long current_sum = 0;
    long long best_sum = LLONG_MIN;
    int start = 0, best_start = 0, best_end = 0;
    
    for (int i = 0; i < n; i++) {
        if (current_sum <= 0) {
            current_sum = arr[i];
            start = i;
        } else {
            current_sum += arr[i];
        }
        
        if (current_sum > best_sum) {
            best_sum = current_sum;
            best_start = start;
            best_end = i;
        }
    }
    
    if (best_sum == max_sum) {
        printf("Subarray [%d", arr[best_start]);
        for (int i = best_start + 1; i <= best_end; i++) {
            printf(", %d", arr[i]);
        }
        printf("] = %lld ✓\n", max_sum);
    }
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
    printf("=== KADANE'S ALGORITHM ===\n");
    printf("O(n) Maximum Subarray Sum\n");
    printf("Handles ALL NEGATIVE case ✓\n\n");
    
    // Test cases
    struct TestCase {
        int arr[12];
        int n;
        long long expected;
    };
    
    struct TestCase test_cases[] = {
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 9, 6},           // [4,-1,2,1] = 6
        {{1}, 1, 1},                                        // Single positive
        {{-1}, 1, -1},                                      // Single negative
        {{-2, -3, -1, -4}, 4, -1},                          // All negative
        {{5, 4, -1, 7, 8}, 5, 23},                          // [5,4,-1,7,8] = 23
        {{1, -2, 3, -4, 5}, 5, 5},                          // [5] or [3,-4,5] = 5
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-25s | %-10s | %-10s\n", "Input", "Kadane", "Verified");
    printf("%-25s-+-%-10s-+-%-10s\n", "-------------------------", "----------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        long long result = kadaneAlgorithm(test_cases[i].arr, test_cases[i].n);
        int valid = verifyKadane(test_cases[i].arr, test_cases[i].n, result);
        
        printf("arr[%d,%d,...] | %8lld  | %s\n",
               test_cases[i].arr[0], test_cases[i].arr[1],
               result, valid ? "✓ PASS" : "✗ FAIL");
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size;
    int* user_arr = readArray(&size);
    
    if (user_arr != NULL) {
        printArray(user_arr, size);
        long long result = kadaneAlgorithm(user_arr, size);
        printf("Maximum subarray sum: %lld\n", result);
        
        int valid = verifyKadane(user_arr, size, result);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
        
        // Bonus: Show the actual subarray
        printf("Actual subarray: ");
        printMaxSubarray(user_arr, size, result);
        
        free(user_arr);
    }
    
    return 0;
}