#include <stdio.h>
#include <stdlib.h>

/**
 * First Negative in Each Sliding Window of Size K - O(n) Deque Approach
 * 
 * LOGIC ENHANCERS:
 * 1. DEQUE stores INDICES of NEGATIVE numbers only
 * 2. Front always has FIRST negative in current window
 * 3. Remove elements outside window (left side)
 * 4. Remove non-negative elements immediately
 * 5. O(n) amortized: Each element enqueued/dequeued at most once
 * 
 * Time: O(n) | Space: O(k)
 */
void firstNegativeSlidingWindow(int* arr, int n, int k, int* result, int* result_size) {
    if (n <= 0 || k <= 0 || k > n) {
        *result_size = 0;
        return;
    }
    
    int deque[k];  // Store indices of negative numbers
    int front = -1, rear = -1;
    
    // Process first window [0, k-1]
    for (int i = 0; i < k; i++) {
        // Remove elements outside window (won't happen in first window)
        while (front >= 0 && deque[front] <= i - k) {
            front++;
        }
        
        // If current element is negative, add to deque
        if (arr[i] < 0) {
            // Remove from front if deque has older negatives (keep first)
            while (front >= 0 && deque[front] < i) {
                front++;
            }
            rear++;
            deque[rear] = i;
        }
    }
    
    // First window result
    result[0] = (front >= 0) ? arr[deque[front]] : 0;
    
    // Process remaining windows
    for (int i = k; i < n; i++) {
        // Remove elements outside current window
        while (front >= 0 && deque[front] <= i - k) {
            front++;
        }
        
        // Add current element
        if (arr[i] < 0) {
            // Remove older negatives from front (keep first negative)
            while (front >= 0 && deque[front] < i) {
                front++;
            }
            rear++;
            deque[rear] = i;
        }
        
        // Result for current window
        result[i - k + 1] = (front >= 0) ? arr[deque[front]] : 0;
    }
    
    *result_size = n - k + 1;
}

/**
 * Brute Force O(n*k) for verification
 */
void firstNegativeSlidingWindowBrute(int* arr, int n, int k, int* result, int* result_size) {
    if (n < k || k <= 0) {
        *result_size = 0;
        return;
    }
    
    *result_size = n - k + 1;
    for (int i = 0; i <= n - k; i++) {
        int found = 0;
        for (int j = i; j < i + k; j++) {
            if (arr[j] < 0) {
                result[i] = arr[j];
                found = 1;
                break;
            }
        }
        if (!found) {
            result[i] = 0;
        }
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
int verifyFirstNegative(int* arr, int n, int k, int* result, int result_size) {
    int* brute_result = (int*)malloc(result_size * sizeof(int));
    int brute_size;
    firstNegativeSlidingWindowBrute(arr, n, k, brute_result, &brute_size);
    
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
    printf("=== FIRST NEGATIVE IN SLIDING WINDOW ===\n");
    printf("O(n) Deque Algorithm\n");
    printf("First negative in each window of size k (0 if none)\n\n");
    
    // Test cases
    struct TestCase {
        int arr[12];
        int n;
        int k;
        int expected[10];
    };
    
    struct TestCase test_cases[] = {
        {{12, -1, -7, 8, -15, 30, 16, 28}, 8, 3, {-1, -1, -7, -15, -15, 0}},
        {{1, 2, 3, 4, 5}, 5, 3, {0, 0, 0}},
        {{-1, 2, 3}, 3, 2, {-1, -1}},
        {{1, -1, 2, -2, 3}, 5, 3, {-1, -1, -2}},
        {{4, 5, 6}, 3, 1, {4, 5, 6}},
        {{1, -2, 3, -4, 5, -6}, 6, 3, {-2, -2, -4, -4, -6}},
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-25s | %-8s | %-20s | %-10s\n", "Input", "k", "Output", "Verified");
    printf("%-25s-+-%-8s-+-%-20s-+-%-10s\n", "-------------------------", "--------", "--------------------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        int result_size;
        int* result = (int*)malloc((test_cases[i].n - test_cases[i].k + 1) * sizeof(int));
        
        firstNegativeSlidingWindow(test_cases[i].arr, test_cases[i].n, test_cases[i].k, result, &result_size);
        int valid = verifyFirstNegative(test_cases[i].arr, test_cases[i].n, test_cases[i].k, result, result_size);
        
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
    
    firstNegativeSlidingWindow(user_arr, size, k, result, &result_size);
    printf("Output: ");
    printResult(result, result_size);
    
    int valid = verifyFirstNegative(user_arr, size, k, result, result_size);
    printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
    
    free(user_arr);
    free(result);
    return 0;
}