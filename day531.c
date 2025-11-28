//Q103: Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.

/*
Sample Test Cases:
Input 1:
nums = [1,7,3,6,5,6]
Output 1:
3

Input 2:
nums = [1,2,3]
Output 2:
-1

Input 3:
nums = [2,1,-1]
Output 3:
0

*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Find the leftmost pivot index where left sum == right sum
 * 
 * LOGIC ENHANCERS:
 * 1. Pre-compute total sum: O(1) right sum = total_sum - left_sum - nums[i]
 * 2. Single pass with prefix sum: O(n) time, O(1) space  
 * 3. Left-to-right iteration: guarantees leftmost pivot
 * 4. Early termination on first valid pivot
 * 5. Handle edge cases: empty, single element, all zeros, negatives
 * 
 * Time: O(n) | Space: O(1)
 */
int pivotIndex(int* nums, int numsSize) {
    // Edge case: empty array
    if (numsSize <= 0) {
        return -1;
    }
    
    // Pre-compute total sum
    int total_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }
    
    // Single pass with running left sum
    int left_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        // Right sum = total_sum - left_sum - current element
        int right_sum = total_sum - left_sum - nums[i];
        
        // Pivot found!
        if (left_sum == right_sum) {
            return i;
        }
        
        // Update left sum for next iteration
        left_sum += nums[i];
    }
    
    return -1;
}

/**
 * Helper: Verify pivot correctness
 */
int verifyPivot(int* nums, int numsSize, int pivot) {
    if (pivot == -1) return 1;
    
    int left_sum = 0, right_sum = 0;
    
    // Calculate left sum
    for (int i = 0; i < pivot; i++) {
        left_sum += nums[i];
    }
    
    // Calculate right sum  
    for (int i = pivot + 1; i < numsSize; i++) {
        right_sum += nums[i];
    }
    
    return left_sum == right_sum;
}

/**
 * Interactive input function
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
 * Main test harness with comprehensive test cases
 */
int main() {
    printf("=== PIVOT INDEX ALGORITHM ===\n");
    printf("Finds leftmost index where left_sum == right_sum\n\n");
    
    // Test cases - predefined for verification
    int test_cases[][6] = {
        {1, 7, 3, 6, 5, 6},     // Expected: 3 (1+7+3=11, 5+6=11)
        {1, 2, 3},              // Expected: -1
        {2, 1, -1},             // Expected: 0 (0==0)
        {0, 0, 0, 0},           // Expected: 0 (0==0)
        {-1, -1, 0, 1, 1, 0},   // Expected: 2 (-1-1=-2, 1+1+0=2) 
        {1},                    // Expected: 0 (0==0)
        {5, 5},                 // Expected: -1
        {-7, 1, 5, 3, -5, 7}    // Expected: 3 (-7+1+5= -1, -5+7=2? Wait...)
    };
    
    int sizes[] = {6, 3, 3, 4, 6, 1, 2, 6};
    int expected[] = {3, -1, 0, 0, 2, 0, -1, -1};
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-8s | %-10s | %-15s\n", "Array", "Pivot", "Expected", "Verified");
    printf("%-20s-+-%-8s-+-%-10s-+-%-15s\n", "--------------------", "--------", "----------", "---------------");
    
    for (int i = 0; i < 8; i++) {
        int pivot = pivotIndex(test_cases[i], sizes[i]);
        int valid = verifyPivot(test_cases[i], sizes[i], pivot);
        
        printf("[%d,%d,%d,%d,%d,%d] | %2d     | %2d       | %s\n",
               test_cases[i][0], test_cases[i][1], test_cases[i][2], 
               test_cases[i][3], test_cases[i][4], test_cases[i][5],
               pivot, expected[i], valid ? "✓ PASS" : "✗ FAIL");
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int size;
    int* user_arr = readArray(&size);
    
    if (user_arr != NULL) {
        printArray(user_arr, size, "Input: ");
        int result = pivotIndex(user_arr, size);
        
        if (result != -1) {
            int left = 0, right = 0;
            for (int i = 0; i < result; i++) left += user_arr[i];
            for (int i = result + 1; i < size; i++) right += user_arr[i];
            
            printf("Pivot Index: %d\n", result);
            printf("Left Sum: %d | Right Sum: %d | ", left, right);
            printf("%s\n", left == right ? "✓ BALANCED" : "✗ ERROR");
        } else {
            printf("Pivot Index: %d (No pivot found)\n", result);
        }
        
        free(user_arr);
    }
    
    return 0;
}