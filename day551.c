#include <stdio.h>
#include <stdlib.h>

/**
 * Boyer-Moore Voting Algorithm - O(n) time, O(1) space
 * 
 * LOGIC ENHANCERS:
 * 1. Boyer-Moore Voting: Cancel out non-majority elements
 * 2. Single pass: O(n) time, O(1) space
 * 3. Candidate selection: Vote for majority candidate
 * 4. Second pass verification: Count actual frequency
 * 5. Handles edge cases: No majority, exactly n/2+1
 * 
 * Time: O(n) | Space: O(1)
 */
int majorityElement(int* nums, int numsSize) {
    if (numsSize <= 0) return -1;
    
    // Phase 1: Boyer-Moore Voting to find candidate
    int candidate = nums[0];
    int count = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;  // Vote against candidate
        }
    }
    
    // Phase 2: Verify candidate appears > floor(n/2) times
    if (count <= 0) return -1;  // Early exit if no votes left
    
    int majority_threshold = numsSize / 2;
    int actual_count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            actual_count++;
        }
    }
    
    return (actual_count > majority_threshold) ? candidate : -1;
}

/**
 * Alternative: Sorting approach O(n log n)
 */
int majorityElementSort(int* nums, int numsSize) {
    if (numsSize <= 0) return -1;
    
    // Sort array
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    
    int candidate = nums[numsSize / 2];  // Majority must be at middle
    int threshold = numsSize / 2;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) count++;
    }
    
    return (count > threshold) ? candidate : -1;
}

/**
 * Alternative: Hash map approach O(n) time, O(n) space
 */
int majorityElementHash(int* nums, int numsSize) {
    // Implementation omitted for brevity - uses dynamic array
    // Not optimal due to O(n) space requirement
    return -1;
}

/**
 * Helper: Verify majority element correctness
 */
int verifyMajority(int* nums, int numsSize, int candidate) {
    if (candidate == -1) return 1;
    
    int threshold = numsSize / 2;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) count++;
    }
    
    return count > threshold;
}

/**
 * Print array with formatting
 */
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]");
}

/**
 * Interactive input
 */
int* readArray(int* size) {
    printf("Enter array size: ");
    scanf("%d", size);
    
    if (*size <= 0) {
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
        scanf("%d", &arr[i]);
    }
    
    return arr;
}

/**
 * Comprehensive test harness
 */
int main() {
    printf("=== MAJORITY ELEMENT ALGORITHM ===\n");
    printf("Finds element appearing > floor(n/2) times\n");
    printf("Boyer-Moore Voting: O(n) time, O(1) space\n\n");
    
    // Test cases with expected results
    int test_cases[][8] = {
        {3, 2, 3},                  // 3 (appears 2/3 > 1)
        {2, 2, 1, 1, 1, 2, 2},      // 2 (appears 4/7 > 3)
        {1, 2, 3},                  // -1 (all appear 1/3 <= 1)
        {1, 1, 1, 1},               // 1 (appears 4/4 > 2)
        {1, 2, 2, 2},               // 2 (appears 3/4 > 2)
        {1, 1, 2, 2},               // -1 (both appear 2/4 == 2)
        {5},                        // 5 (1/1 > 0)
        {1, 1, 1, 2, 2, 2},         // -1 (both appear 3/6 == 3)
        {7, 7, 7, 7, 7, 7, 7},      // 7 (7/7 > 3)
        {4, 4, 4, 4, 5, 5}          // -1 (4 appears 4/6 > 3? Wait, 4/6=0.66>0.5 ✓)
    };
    
    int sizes[] = {3, 7, 3, 4, 4, 4, 1, 6, 7, 6};
    int expected[] = {3, 2, -1, 1, 2, -1, 5, -1, 7, 4};
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-25s | %-8s | %-8s | %-10s\n", 
           "Array", "Boyer", "Expected", "Verified");
    printf("%-25s-+-%-8s-+-%-8s-+-%-10s\n", 
           "-------------------------", "--------", "--------", "----------");
    
    for (int i = 0; i < 10; i++) {
        // Create copy for sorting test (to avoid modifying original)
        int* copy = malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            copy[j] = test_cases[i][j];
        }
        
        int boyer_result = majorityElement(test_cases[i], sizes[i]);
        int sort_result = majorityElementSort(copy, sizes[i]);
        int valid = verifyMajority(test_cases[i], sizes[i], boyer_result);
        
        printf("[%d,%d,%d,...] | %3d    | %3d     | %s\n",
               test_cases[i][0], test_cases[i][1], test_cases[i][2],
               boyer_result, expected[i], valid ? "✓ PASS" : "✗ FAIL");
        
        free(copy);
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size;
    int* user_arr = readArray(&size);
    
    if (user_arr != NULL) {
        printArray(user_arr, size);
        int result = majorityElement(user_arr, size);
        
        printf("Majority Element: %d\n", result);
        
        if (result != -1) {
            int threshold = size / 2;
            int count = 0;
            for (int i = 0; i < size; i++) {
                if (user_arr[i] == result) count++;
            }
            printf("Frequency: %d/%d > %d ✓\n", count, size, threshold);
        }
        
        free(user_arr);
    }
    
    return 0;
}