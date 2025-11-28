//Q47: Write a program to print the following pattern:
*
**
***
****
*****

/*
Sample Test Cases:
Input 1:

Output 1:
*
**
***
****
*****

*/
#include <stdio.h>

int main() {
    int i, j;

    // Outer loop for each row (1 to 5)
    for (i = 1; i <= 5; i++) {
        
        // Inner loop prints exactly i stars in the i-th row
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        printf("\n");   // Go to next line after finishing a row
    }

    return 0;
}