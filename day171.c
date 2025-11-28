//Q33: Write a program to check if a number is an Armstrong number.

/*
Sample Test Cases:
Input 1:
153
Output 1:
Armstrong

Input 2:
123
Output 2:
Not Armstrong

*/
#include <stdio.h>
#include <math.h>

int main() {
    int num, original_num, digits = 0, sum = 0, digit;

    // Input the number
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    original_num = num;

    // Handle negative numbers
    if (num < 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    // Special case: 0 is an Armstrong number
    if (num == 0) {
        printf("%d is an ARMSTRONG NUMBER\n", num);
        return 0;
    }

    // Count number of digits
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Calculate sum of digits raised to power of number of digits
    temp = num;
    while (temp > 0) {
        digit = temp % 10;
        sum += pow(digit, digits);  // digit^digits
        temp /= 10;
    }

    // Check if it's Armstrong
    if (sum == original_num) {
        printf("%d is an ARMSTRONG NUMBER\n", original_num);
        printf("%d = ", original_num);
        // Optional: Show calculation
        temp = original_num;
        int first = 1;
        while (temp > 0) {
            digit = temp % 10;
            if (!first) printf(" + ");
            printf("%d^%d", digit, digits);
            first = 0;
            temp /= 10;
        }
        printf(" = %d\n", sum);
    }
    else {
        printf("%d is NOT an Armstrong number\n", original_num);
        printf("Sum of digits^%d = %d\n", digits, sum);
    }

    return 0;
}