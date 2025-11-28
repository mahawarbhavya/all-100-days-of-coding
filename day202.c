//Q40: Write a program to find the 1’s complement of a binary number and print it.

/*
Sample Test Cases:
Input 1:
1010
Output 1:
0101

Input 2:
1111
Output 2:
0000

*/
#include <stdio.h>
#include <string.h>

int main() {
    char binary[65];  // To store up to 64-bit binary + null terminator
    int i, len;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    len = strlen(binary);

    // Validate if the input contains only 0s and 1s
    for (i = 0; i < len; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Error: Invalid binary number!\n");
            return 1;
        }
    }

    printf("Original binary: %s\n", binary);

    // Compute 1's complement by flipping each bit
    for (i = 0; i < len; i++) {
        if (binary[i] == '0')
            binary[i] = '1';
        else
            binary[i] = '0';
    }

    printf("1's Complement:  %s\n", binary);

    return 0;
}