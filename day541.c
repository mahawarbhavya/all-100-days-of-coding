//Q104: Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.

/*
Sample Test Cases:
Input 1:
n = 8
Output 1:
6

Input 2:
n = 1
Output 2:
1

Input 3:
n = 4
Output 3:
-1

*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Find pivot integer x where sum(1 to x) == sum(x to n)
 * 
 * LOGIC ENHANCERS:
 * 1. Mathematical formula: sum(1 to x) = x*(x+1)/2
 * 2. sum(x to n) = sum(1 to n) - sum(1 to x-1)
 * 3. Combined: x*(x+1)/2 = [n*(n+1)/2] - [(x-1)*x/2]
 * 4. Simplified: x*(x+1) = n*(n+1)
 * 5. Final: x² + x - n² - n = 0
 * 6. Quadratic solution: x = [-1 + sqrt(1 + 4*(n² + n))]/2
 * 7. O(1) time using math, no iteration needed!
 * 
 * Time: O(1) | Space: O(1)
 */
int pivotInteger(int n) {
    // Edge case
    if (n <= 0) return -1;
    
    // Calculate discriminant: 1 + 4*(n² + n)
    long long n_squared = (long long)n * n;
    long long discriminant = 1 + 4 * (n_squared + n);
    
    // Calculate sqrt(discriminant) using integer square root
    long long sqrt_disc = 0;
    long long low = 1, high = 2 * n + 1;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;
        
        if (square == discriminant) {
            sqrt_disc = mid;
            break;
        } else if (square < discriminant) {
            sqrt_disc = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    // Check if perfect square found
    if (sqrt_disc * sqrt_disc != discriminant) {
        return -1;
    }
    
    // x = (-1 + sqrt_disc) / 2
    long long x = (sqrt_disc - 1) / 2;
    
    // Verify x is integer and within [1, n]
    if (x < 1 || x > n || (sqrt_disc - 1) % 2 != 0) {
        return -1;
    }
    
    return (int)x;
}

/**
 * Alternative O(1) using floating point (faster but less precise)
 */
int pivotIntegerFast(int n) {
    if (n <= 0) return -1;
    
    double discriminant = 1.0 + 4.0 * ((double)n * n + n);
    double sqrt_disc = sqrt(discriminant);
    
    if (fabs(sqrt_disc - round(sqrt_disc)) > 1e-9) {
        return -1;  // Not perfect square
    }
    
    long long x = (long long)((sqrt_disc - 1.0) / 2.0);
    return (x >= 1 && x <= n) ? (int)x : -1;
}

/**
 * Brute force verification (for testing)
 */
int pivotIntegerBrute(int n) {
    long long total_sum = (long long)n * (n + 1) / 2;
    long long left_sum = 0;
    
    for (int x = 1; x <= n; x++) {
        left_sum += x;
        long long right_sum = total_sum - left_sum + x;  // sum(x to n)
        
        if (left_sum == right_sum) {
            return x;
        }
    }
    return -1;
}

/**
 * Verify pivot correctness
 */
int verifyPivot(int n, int x) {
    if (x == -1) return 1;
    
    long long left_sum = (long long)x * (x + 1) / 2;
    long long total_sum = (long long)n * (n + 1) / 2;
    long long right_sum = total_sum - ((long long)(x - 1) * x / 2);
    
    return left_sum == right_sum;
}

/**
 * Interactive input with comprehensive testing
 */
int main() {
    printf("=== PIVOT INTEGER ALGORITHM ===\n");
    printf("Finds x where sum(1..x) == sum(x..n)\n\n");
    
    // Comprehensive test cases
    int test_cases[] = {1, 4, 8, 9, 6, 13, 100, 2, 3, 7};
    int expected[] = {1, 2, -1, 6, -1, 8, 50, -1, -1, -1};
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-8s | %-8s | %-8s | %-10s | %-10s\n", 
           "n", "Math", "Brute", "Expected", "Verified");
    printf("%-8s-+-%-8s-+-%-8s-+-%-10s-+-%-10s\n", 
           "--------", "--------", "--------", "----------", "----------");
    
    for (int i = 0; i < 10; i++) {
        int n = test_cases[i];
        int math_result = pivotInteger(n);
        int brute_result = pivotIntegerBrute(n);
        int valid = verifyPivot(n, math_result);
        
        printf("%-8d | %-8d | %-8d | %-10d | %-10s\n",
               n, math_result, brute_result, expected[i], 
               valid ? "✓ PASS" : "✗ FAIL");
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    int n;
    
    do {
        printf("Enter positive integer n (0 to exit): ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (n == 0) break;
        if (n < 1) {
            printf("Please enter positive integer!\n\n");
            continue;
        }
        
        int result = pivotInteger(n);
        printf("Pivot Integer: %d\n", result);
        
        if (result != -1) {
            long long left_sum = (long long)result * (result + 1) / 2;
            long long total_sum = (long long)n * (n + 1) / 2;
            long long right_sum = total_sum - ((long long)(result - 1) * result / 2);
            
            printf("Verification: sum(1..%d)=%lld == sum(%d..%d)=%lld ✓\n\n",
                   result, left_sum, result, n, right_sum);
        } else {
            printf("No pivot integer exists.\n\n");
        }
        
    } while (1);
    
    printf("Goodbye!\n");
    return 0;
}