//Q28: Write a program to print the product of even numbers from 1 to n.

/*
Sample Test Cases:
Input 1:
4
Output 1:
8 (2 * 4)

Input 2:
6
Output 2:
48 (2 * 4 * 6)

*/
#include <stdio.h>

int main() {
    int n, i;
    long long product = 1;  // Use long long to handle large results

    // Input the value of n
    printf("Enter a positive integer (n): ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    printf("Even numbers from 1 to %d are: ", n);

    // Loop through numbers from 1 to n
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {  // Check if number is even
            printf("%d ", i);
            product *= i;

            // Optional: Prevent overflow for very large n
            if (product < 0) {
                printf("\n\nWarning: Product overflow occurred!\n");
                printf("Final product may be incorrect.\n");
                break;
            }
        }
    }

    // Display the result
    printf("\n\nProduct of even numbers from 1 to %d = %lld\n", n, product);

    return 0;
}