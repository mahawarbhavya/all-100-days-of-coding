Q32: Write a program to check if a number is a palindrome.

/*
Sample Test Cases:
Input 1:
121
Output 1:
Palindrome

Input 2:
123
Output 2:
Not palindrome

*/
#include <stdio.h>

int main() {
    int num, original_num, reversed = 0, digit;

    // Input the number
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    original_num = num;

    // Handle negative numbers and zero
    if (num < 0) {
        printf("Negative numbers are not considered palindromes.\n");
        return 1;
    }

    if (num == 0) {
        printf("%d is a PALINDROME\n", original_num);
        return 0;
    }

    // Reverse the number
    while (num > 0) {
        digit = num % 10;                    // Extract last digit
        reversed = reversed * 10 + digit;    // Build reversed number
        num = num / 10;                      // Remove last digit
    }

    // Check if original number equals reversed number
    if (original_num == reversed) {
        printf("%d is a PALINDROME\n", original_num);
    }
    else {
        printf("%d is NOT a palindrome\n", original_num);
        printf("Reversed number = %d\n", reversed);
    }

    return 0;
}