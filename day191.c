//Q37: Write a program to find the LCM of two numbers.

/*
Sample Test Cases:
Input 1:
4 5
Output 1:
20

Input 2:
7 3
Output 2:
21

*/
#include <stdio.h>

// Function to find HCF/GCD using Euclidean Algorithm
int findHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find LCM using HCF
int findLCM(int a, int b) {
    return (a * b) / findHCF(a, b);
}

int main() {
    int num1, num2, lcm, hcf;

    // Input two positive integers
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // Input validation
    if (num1 <= 0 || num2 <= 0) {
        printf("Error: Please enter positive integers only!\n");
        return 1;
    }

    // Calculate HCF and LCM
    hcf = findHCF(num1, num2);
    lcm = findLCM(num1, num2);

    // Display results
    printf("\n");
    printf("Number 1     = %d\n", num1);
    printf("Number 2     = %d\n", num2);
    printf("HCF/GCD      = %d\n", hcf);
    printf("LCM          = %d\n", lcm);

    // Show some common multiples (optional)
    printf("\nSome common multiples: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", lcm * i);
    }
    printf("...\n");

    return 0;
}