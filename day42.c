//Q8: Write a program to find and display the sum of the first n natural numbers.

/*
Sample Test Cases:
Input 1:
5
Output 1:
Sum=15

Input 2:
10
Output 2:
Sum=55

*/
#include <stdio.h>

int main() {
    int n, sum;

    // Input the value of n
    printf("Enter a positive integer (n): ");
    scanf("%d", &n);

    // Check if n is positive
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Calculate sum using formula: sum = n*(n+1)/2
    sum = n * (n + 1) / 2;

    // Display the result
    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}