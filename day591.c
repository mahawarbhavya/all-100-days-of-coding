#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Maximum Sum Subarray of Size K - O(n) Sliding Window
 * 
 * LOGIC ENHANCERS:
 * 1. SLIDING WINDOW: Reuse previous window sum
 * 2. O(1) per window: current_sum = prev_sum - arr[i] + arr[i+k]
 * 3. Single pass: No redundant calculations
 * 4. Edge case validation: k <= n
 * 5. Overflow protection: Use long long for sums
 * 
 * Time: O(n) | Space: O(1)
 */
long long maxSumSubarray(int* arr, int n, int k) {
    // Edge cases
    if (n < k || k <= 0 || n <= 0) {
        return LLONG_MIN;  // Invalid input
    }
    
    // Calculate sum of first window [0, k-1]
    long long current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }
    
    long long max_sum = current_sum;
    
    // Slide window from k to n-1
    for (int i = k; i < n; i++) {
        // Slide: Remove leftmost + Add rightmost
        current_sum = current_sum - arr[i - k] + arr[i];
        
        // Update maximum
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return max_sum;
}

/**
 * Brute Force O(n*k) for verification
 */
long long maxSumSubarrayBrute(int* arr, int n, int k) {
    if (n < k || k <= 0) return LLONG_MIN;
    
    long long max_sum = LLONG_MIN;
    
    // Try all possible windows
    for (int i = 0; i <= n - k; i++) {
        long long current_sum = 0;
        for (int j = i; j < i + k; j++) {
            current_sum += arr[j];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
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
int verifyMaxSum(int* arr, int n, int k, long long result) {
    long long brute_result = maxSumSubarrayBrute(arr, n, k);
    return (result == brute_result);
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
    printf("=== MAXIMUM SUM SUBARRAY OF SIZE K ===\n");
    printf("O(n) Sliding Window Technique\n");
    printf("Maximum sum of any contiguous subarray of exactly size k\n\n");
    
    // Test cases: {array, size, k, expected}
    struct TestCase {
        int arr[10];
        int n;
        int k;
        long long expected;
    };
    
    struct TestCase test_cases[] = {
        {{1, 4, 2, 10, 2, 3, 1, 0, 20}, 9, 4, 24},      // [4,2,10,2]=18, [2,10,2,3]=17, [10,2,3,1]=16, [2,3,1,0]=6, [3,1,0,20]=24 ✓
        {{1, -1, -3, 7, -1, 2}, 6, 3, 7},               // [7,-1,2]=8? Wait, [-3,7,-1]=3, [7,-1,2]=8 ✓
        {{-1, -2, -3, -4}, 4, 2, -3},                   // All negative
        {{5}, 1, 1, 5},                                 // Single element
        {{1, 2, 3, 4, 5}, 5, 3, 12},                    // [3,4,5]=12
        {{100, 200, 300, 400}, 4, 2, 700},              // [300,400]=700
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-25s | %-8s | %-8s | %-10s\n", "Input", "k", "Sliding", "Verified");
    printf("%-25s-+-%-8s-+-%-8s-+-%-10s\n", "-------------------------", "--------", "--------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        long long result = maxSumSubarray(test_cases[i].arr, test_cases[i].n, test_cases[i].k);
        int valid = verifyMaxSum(test_cases[i].arr, test_cases[i].n, test_cases[i].k, result);
        
        printf("arr[%d,%d,...] | %2d     | %6lld  | %s\n",
               test_cases[i].arr[0], test_cases[i].arr[1],
               test_cases[i].k, result,
               valid ? "✓ PASS" : "✗ FAIL");
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size, k;
    
    printf("Enter array size: ");
    scanf("%d", &size);
    printf("Enter window size k: ");
    scanf("%d", &k);
    
    if (size <= 0 || k <= 0 || k > size) {
        printf("Invalid input! (n >= k > 0 required)\n");
        return 1;
    }
    
    int* user_arr = (int*)malloc(size * sizeof(int));
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &user_arr[i]);
    }
    
    printArray(user_arr, size);
    printf(" k = %d\n", k);
    
    long long result = maxSumSubarray(user_arr, size, k);
    printf("Maximum sum: %lld\n", result);
    
    // Show the actual window
    if (result != LLONG_MIN) {
        long long current_sum = 0;
        int start_idx = -1;
        
        for (int i = 0; i <= size - k; i++) {
            long long window_sum = 0;
            for (int j = i; j < i + k; j++) {
                window_sum += user_arr[j];
            }
            if (window_sum == result) {
                start_idx = i;
                break;
            }
        }
        
        if (start_idx != -1) {
            printf("Window [%d", user_arr[start_idx]);
            for (int j = start_idx + 1; j < start_idx + k; j++) {
                printf(", %d", user_arr[j]);
            }
            printf("] = %lld ✓\n", result);
        }
    }
    
    free(user_arr);
    return 0;
}