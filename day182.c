//Q36: Write a program to find the HCF (GCD) of two numbers.

/*
Sample Test Cases:
Input 1:
12 18
Output 1:
6

Input 2:
7 9
Output 2:
1

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

int main() {
    int num1, num2, hcf;

    // Input two positive integers
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // Input validation
    if (num1 <= 0 || num2 <= 0) {
        printf("Please enter positive integers only!\n");
        return 1;
    }

    // Ensure num1 is greater than or equal to num2 (optional)
    if (num1 < num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // Calculate HCF
    hcf = findHCF(num1, num2);

    // Display result
    printf("\n");
    printf("Number 1 = %d\n", num1);
    printf("Number 2 = %d\n", num2);
    printf("HCF/GCD  = %d\n", hcf);

    // Show all common factors (optional)
    printf("\nCommon factors: ");
    for (int i = 1; i <= hcf; i++) {
        if (hcf % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}