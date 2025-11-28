//Q30: Write a program to reverse a given number.

/*
Sample Test Cases:
Input 1:
1234
Output 1:
4321

Input 2:
100
Output 2:
1

*/
#include <stdio.h>

int main() {
    int num, reversed = 0, digit;
    int original_num;

    // Input the number
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Store original number for display
    original_num = num;

    // Handle negative numbers
    if (num < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Special case: if number is 0
    if (num == 0) {
        printf("Reverse of %d is: 0\n", original_num);
        return 0;
    }

    // Reverse the number
    while (num > 0) {
        digit = num % 10;           // Extract last digit
        reversed = reversed * 10 + digit;  // Build reversed number
        num = num / 10;             // Remove last digit
    }

    // Display result
    printf("Reverse of %d is: %d\n", original_num, reversed);

    return 0;
}