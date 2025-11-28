//Q39: Write a program to find the product of odd digits of a number.

/*
Sample Test Cases:
Input 1:
12345
Output 1:
15 (1*3*5)

Input 2:
2468
Output 2:
1 (no odd digits, assume 1)

*/
#include <stdio.h>

int main() {
    int num, original_num, digit;
    int product = 1;
    int has_odd_digit = 0;  // Flag to check if there is any odd digit

    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    original_num = num;

    // Handle negative numbers
    if (num < 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    // Special case: number is 0
    if (num == 0) {
        printf("Number = 0\n");
        printf("It contains digit 0 (even), so no odd digits.\n");
        printf("Product of odd digits = 1 (by convention)\n");
        return 0;
    }

    printf("Number = %d\n", original_num);
    printf("Odd digits: ");

    // Extract each digit and check if it's odd
    while (num > 0) {
        digit = num % 10;           // Get last digit

        if (digit % 2 == 1) {       // Check if digit is odd
            printf("%d ", digit);
            product *= digit;
            has_odd_digit = 1;
        }

        num = num / 10;             // Remove last digit
    }

    // Display result
    if (has_odd_digit) {
        printf("\nProduct of odd digits = %d\n", product);
    }
    else {
        printf("None\n");
        printf("There are no odd digits in the number.\n");
        printf("Product = 1 (by convention, empty product is 1)\n");
    }

    return 0;
}