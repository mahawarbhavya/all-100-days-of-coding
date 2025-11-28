//Q46: Write a program to print the following pattern:
*****
*****
*****
*****
*****

/*
Sample Test Cases:
Input 1:

Output 1:
*****
*****
*****
*****
*****

*/
#include <stdio.h>

int main() {
    int rows = 5;
    int cols = 5;
    int i, j;

    // Outer loop for rows
    for (i = 1; i <= rows; i++) {
        
        // Inner loop for columns (printing 5 stars in each row)
        for (j = 1; j <= cols; j++) {
            printf("*");
        }
        
        printf("\n");  // Move to next line after each row
    }

    return 0;
}