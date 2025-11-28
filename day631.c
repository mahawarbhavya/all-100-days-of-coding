#include <stdio.h>
#include <stdlib.h>

/**
 * Kth Smallest Element - QuickSelect Algorithm (Average O(n))
 * 
 * LOGIC ENHANCERS:
 * 1. QUICKSELECT: Partition like QuickSort, recurse on relevant partition
 * 2. Average O(n), Worst O(n²) → Randomized pivot for practical O(n)
 * 3. Early termination: Return when partition index == k-1
 * 4. In-place partitioning: O(1) extra space
 * 5. Handles edge cases: k=1, k=n, duplicates
 * 
 * Time: Average O(n) | Worst O(n²) | Space: O(1)
 */
int partition(int* arr, int low, int high) {
    // Randomized pivot for average O(n)
    int pivot_idx = low + rand() % (high - low + 1);
    int temp = arr[pivot_idx];
    arr[pivot_idx] = arr[high];
    arr[high] = temp;
    
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

int quickSelect(int* arr, int low, int high, int k) {
    if (low == high) return arr[low];
    
    int pi = partition(arr, low, high);
    
    if (k == pi) {
        return arr[pi];
    } else if (k < pi) {
        return quickSelect(arr, low, pi - 1, k);
    } else {
        return quickSelect(arr, pi + 1, high, k);
    }
}

int kthSmallest(int* arr, int n, int k) {
    if (n <= 0 || k < 1 || k > n) return INT_MIN;
    
    // Make copy to avoid modifying original array
    int* copy = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }
    
    int result = quickSelect(copy, 0, n - 1, k - 1);  // k-1 for 0-based indexing
    free(copy);
    return result;
}

/**
 * Brute Force O(n log n) - Sorting for verification
 */
int kthSmallestBrute(int* arr, int n, int k) {
    if (n <= 0 || k < 1 || k > n) return INT_MIN;
    
    int* copy = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }
    
    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (copy[j] > copy[j + 1]) {
                int temp = copy[j];
                copy[j] = copy[j + 1];
                copy[j + 1] = temp;
            }
        }
    }
    
    int result = copy[k - 1];
    free(copy);
    return result;
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
int verifyKthSmallest(int* arr, int n, int k, int result) {
    int brute_result = kthSmallestBrute(arr, n, k);
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
    printf("=== KTH SMALLEST ELEMENT ===\n");
    printf("QuickSelect Algorithm - Average O(n)\n");
    printf("Finds kth smallest element (1-indexed)\n\n");
    
    // Test cases
    struct TestCase {
        int arr[12];
        int n;
        int k;
        int expected;
    };
    
    struct TestCase test_cases[] = {
        {{3, 2, 1, 5, 6, 4}, 6, 2, 2},                    // Sorted: [1,2,3,4,5,6]
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 9, 4, 3},          // 4th: 3
        {{7, 10, 4, 3, 20, 15}, 6, 3, 7},                 // 3rd: 7
        {{1}, 1, 1, 1},                                   // Edge: k=1
        {{5, 5, 5, 5}, 4, 2, 5},                          // Duplicates
        {{-1, -2, 0, 1}, 4, 2, -2},                       // Negatives
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-25s | %-5s | %-10s | %-10s\n", "Input", "k", "QuickSelect", "Verified");
    printf("%-25s-+-%-5s-+-%-10s-+-%-10s\n", "-------------------------", "-----", "----------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        int result = kthSmallest(test_cases[i].arr, test_cases[i].n, test_cases[i].k);
        int valid = verifyKthSmallest(test_cases[i].arr, test_cases[i].n, test_cases[i].k, result);
        
        printf("arr[%d,%d,...] | %2d  | %8d  | %s\n",
               test_cases[i].arr[0], test_cases[i].arr[1],
               test_cases[i].k, result,
               valid ? "✓ PASS" : "✗ FAIL");
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size, k;
    
    printf("Enter array size: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size!\n");
        return 1;
    }
    
    printf("Enter k (1 <= k <= n): ");
    if (scanf("%d", &k) != 1 || k < 1 || k > size) {
        printf("Invalid k!\n");
        return 1;
    }
    
    int* user_arr = (int*)malloc(size * sizeof(int));
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &user_arr[i]);
    }
    
    printArray(user_arr, size);
    printf(" k = %d\n", k);
    
    int result = kthSmallest(user_arr, size, k);
    printf("kth smallest: %d\n", result);
    
    int valid = verifyKthSmallest(user_arr, size, k, result);
    printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
    
    // Bonus: Show sorted array for verification
    int* sorted = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) sorted[i] = user_arr[i];
    
    // Simple bubble sort for display
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted:      ");
    printArray(sorted, size);
    printf("Expected:    %d ✓\n", sorted[k - 1]);
    
    free(user_arr);
    free(sorted);
    return 0;
}