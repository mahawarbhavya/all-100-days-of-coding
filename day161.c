//Q31: Write a program to take a number as input and print its equivalent binary representation.

/*
Sample Test Cases:
Input 1:
10
Output 1:
1010

Input 2:
7
Output 2:
111

*/
#include <stdio.h>

int main() {
    int num, original_num;
    
    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    original_num = num;

    // Input validation
    if (num < 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    // Special case for 0
    if (num == 0) {
        printf("Binary of %d = 0\n", original_num);
        return 0;
    }

    printf("Binary of %d = ", original_num);

    // Array to store binary digits (max 32 bits for int)
    int binary[32];
    int i = 0;

    // Extract bits from LSB to MSB
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    // Print binary digits in reverse order (MSB first)
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\n");

    return 0;
}