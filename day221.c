//Q43: Write a program to check if a number is a strong number.

/*
Sample Test Cases:
Input 1:
145
Output 1:
Strong number

Input 2:
123
Output 2:
Not strong number

*/
#include <stdio.h>

// Function to calculate factorial of a digit
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to check if a number is Strong
int isStrong(int num) {
    int original = num;
    int sum = 0;
    int digit;

    // Extract each digit and add its factorial
    while (num > 0) {
        digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }

    // Return 1 if sum equals original number
    return (sum == original);
}

int main() {
    int num;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    if (isStrong(num)) {
        printf("%d is a Strong Number.\n", num);
    } else {
        printf("%d is NOT a Strong Number.\n", num);
    }

    // Optional: Show calculation
    if (num > 0) {
        printf("\nCalculation:\n");
        int temp = num;
        int total = 0;
        printf("%d = ", num);
        while (temp > 0) {
            int digit = temp % 10;
            int fact = factorial(digit);
            printf("%d!", digit);
            if (temp > 10) printf(" + ");
            total += fact;
            temp /= 10;
        }
        printf(" = %d\n", total);
    }

    return 0;
}