#include <stdio.h>
#include <stdlib.h>

/**
 * Maximum Element in Each Sliding Window of Size K - O(n) Deque Approach
 * 
 * LOGIC ENHANCERS:
 * 1. DEQUE stores INDICES in decreasing order of values
 * 2. Front always has maximum of current window
 * 3. Remove elements outside window (left side)
 * 4. Remove smaller elements (optimization for future)
 * 5. O(n) amortized: Each element enqueued/dequeued at most once
 * 
 * Time: O(n) | Space: O(k)
 */
void maxSlidingWindow(int* arr, int n, int k, int* result, int* result_size) {
    if (n <= 0 || k <= 0 || k > n) {
        *result_size = 0;
        return;
    }
    
    int deque[k];  // Store indices
    int front = -1, rear = -1;
    
    // Process first window [0, k-1]
    for (int i = 0; i < k; i++) {
        // Remove indices of smaller elements (optimization)
        while (front >= 0 && arr[deque[front]] < arr[i]) {
            front--;
        }
        rear++;
        deque[rear] = i;
    }
    
    result[0] = arr[deque[front]];  // First window max
    
    // Process remaining windows
    for (int i = k; i < n; i++) {
        // Remove elements outside current window
        if (deque[front] == i - k) {
            front++;
        }
        
        // Remove smaller elements from back
        while (front >= 0 && arr[deque[front]] < arr[i]) {
            front--;
        }
        
        rear++;
        deque[rear] = i;
        
        // Add max of current window to result
        result[i - k + 1] = arr[deque[front]];
    }
    
    *result_size = n - k + 1;
}

/**
 * Brute Force O(n*k) for verification
 */
void maxSlidingWindowBrute(int* arr, int n, int k, int* result, int* result_size) {
    if (n < k || k <= 0) {
        *result_size = 0;
        return;
    }
    
    *result_size = n - k + 1;
    for (int i = 0; i <= n - k; i++) {
        int max_val = arr[i];
        for (int j = i; j < i + k; j++) {
            if (arr[j] > max_val) {
                max_val = arr[j];
            }
        }
        result[i] = max_val;
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
 * Print result with space separation
 */
void printResult(int* result, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", result[i]);
        if (i < size - 1) printf(" ");
    }
    printf("\n");
}

/**
 * Verify correctness
 */
int verifyMaxWindow(int* arr, int n, int k, int* result, int result_size) {
    int* brute_result = (int*)malloc(result_size * sizeof(int));
    int brute_size;
    maxSlidingWindowBrute(arr, n, k, brute_result, &brute_size);
    
    int valid = 1;
    for (int i = 0; i < result_size; i++) {
        if (result[i] != brute_result[i]) {
            valid = 0;
            break;
        }
    }
    
    free(brute_result);
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
    printf("=== MAXIMUM SLIDING WINDOW ===\n");
    printf("O(n) Deque Algorithm\n");
    printf("Maximum element in each window of size k\n\n");
    
    // Test cases
    struct TestCase {
        int arr[12];
        int n;
        int k;
        int expected[10];
    };
    
    struct TestCase test_cases[] = {
        {{1, 3, -1, -3, 5, 3, 6, 7}, 8, 3, {3, 3, 5, 5, 6, 7}},
        {{1}, 1, 1, {1}},
        {{1, -1}, 2, 1, {1, -1}},
        {{9, 11}, 2, 2, {11}},
        {{4, -2}, 2, 1, {4, -2}},
        {{1, 3, -1, -3, 5, 3, 6, 7}, 8, 4, {3, 3, 5, 6}},
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-25s | %-8s | %-20s | %-10s\n", "Input", "k", "Output", "Verified");
    printf("%-25s-+-%-8s-+-%-20s-+-%-10s\n", "-------------------------", "--------", "--------------------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        int result_size;
        int* result = (int*)malloc((test_cases[i].n - test_cases[i].k + 1) * sizeof(int));
        
        maxSlidingWindow(test_cases[i].arr, test_cases[i].n, test_cases[i].k, result, &result_size);
        int valid = verifyMaxWindow(test_cases[i].arr, test_cases[i].n, test_cases[i].k, result, result_size);
        
        printf("arr[%d,%d,...] | %2d     | ", test_cases[i].arr[0], test_cases[i].arr[1], test_cases[i].k);
        printResult(result, result_size);
        printf("    %s\n", valid ? "✓ PASS" : "✗ FAIL");
        
        free(result);
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
    
    int result_size;
    int* result = (int*)malloc((size - k + 1) * sizeof(int));
    
    printArray(user_arr, size, "Array: ");
    printf(" k = %d\n", k);
    
    maxSlidingWindow(user_arr, size, k, result, &result_size);
    printf("Output: ");
    printResult(result, result_size);
    
    int valid = verifyMaxWindow(user_arr, size, k, result, result_size);
    printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
    
    free(user_arr);
    free(result);
    return 0;
}