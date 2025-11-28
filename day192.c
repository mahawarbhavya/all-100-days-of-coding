//Q38: Write a program to find the sum of digits of a number.

/*
Sample Test Cases:
Input 1:
123
Output 1:
6

Input 2:
999
Output 2:
27

*/
#include <stdio.h>

int main() {
    int num, original_num, digit, sum = 0;

    // Input a number
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    original_num = num;

    // Handle negative numbers
    if (num < 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    // Special case: 0
    if (num == 0) {
        printf("Sum of digits of 0 = 0\n");
        return 0;
    }

    // Calculate sum of digits
    while (num > 0) {
        digit = num % 10;      // Extract last digit
        sum += digit;          // Add digit to sum
        num = num / 10;        // Remove last digit
    }

    // Display result
    printf("Number = %d\n", original_num);
    printf("Sum of its digits = %d\n", sum);

    return 0;
}