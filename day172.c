//Q34: Write a program to check if a number is prime.

/*
Sample Test Cases:
Input 1:
7
Output 1:
Prime

Input 2:
10
Output 2:
Not prime

*/
#include <stdio.h>

int main() {
    int num, i, is_prime = 1;  // Assume number is prime initially

    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Handle special cases
    if (num <= 1) {
        printf("%d is NOT a prime number.\n", num);
        return 0;
    }

    if (num == 2) {
        printf("2 is a PRIME number.\n");
        return 0;
    }

    if (num % 2 == 0) {
        printf("%d is NOT a prime number. (Divisible by 2)\n", num);
        return 0;
    }

    // Check for factors from 3 to sqrt(num)
    for (i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            is_prime = 0;  // Found a factor
            break;
        }
    }

    // Display result
    if (is_prime == 1) {
        printf("%d is a PRIME number.\n", num);
    }
    else {
        printf("%d is NOT a prime number.\n", num);
        printf("It is divisible by %d.\n", i);
    }

    return 0;
}