//Q7: Write a program to swap two numbers without using a third variable.

/*
Sample Test Cases:
Input 1:
10 20
Output 1:
After swap: 20 10

Input 2:
7 14
Output 2:
After swap: 14 7

*/
#include <stdio.h>

int main() {
    int a, b;

    // Input two numbers
    printf("Enter first number (a): ");
    scanf("%d", &a);
    printf("Enter second number (b): ");
    scanf("%d", &b);

    printf("\nBefore swapping:\n");
    printf("a = %d, b = %d\n\n", a, b);

    // Swapping without using third variable
    a = a + b;
    b = a - b;
    a = a - b;

    // After swapping
    printf("After swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}