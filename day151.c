//Q29: Write a program to calculate the factorial of a number.

/*
Sample Test Cases:
Input 1:
5
Output 1:
120

Input 2:
3
Output 2:
6

*/
#include <stdio.h>

int main() {
    int n, i;
    long long factorial = 1;  // Use long long to handle larger values

    // Input the number
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Input validation
    if (n < 0) {
        printf("Error: Factorial of a negative number doesn't exist.\n");
        return 1;
    }

    // Special case for 0
    if (n == 0 || n == 1) {
        printf("Factorial of %d = 1\n", n);
        return 0;
    }

    // Calculate factorial using loop
    for (i = 1; i <= n; i++) {
        factorial *= i;
    }

    // Display result
    printf("Factorial of %d = %lld\n", n, factorial);

    return 0;
}