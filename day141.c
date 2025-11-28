//Q27: Write a program to print the sum of the first n odd numbers.

/*
Sample Test Cases:
Input 1:
3
Output 1:
9

Input 2:
5
Output 2:
25

*/
#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;

    // Input the value of n
    printf("Enter a positive integer (n): ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    // Print first n odd numbers and calculate their sum
    printf("First %d odd numbers are: ", n);
    for (i = 1; i <= n; i++) {
        int odd_number = 2 * i - 1;  // Formula for ith odd number
        printf("%d ", odd_number);
        sum += odd_number;
    }

    // Display the result
    printf("\n\nSum of first %d odd numbers = %d\n", n, sum);

    // Bonus: Show the pattern (Sum = n²)
    printf("Note: Sum of first n odd numbers is always n²\n");
    printf("Verification: %d × %d = %d\n", n, n, n * n);

    return 0;
}