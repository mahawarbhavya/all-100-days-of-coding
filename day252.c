//Q50: Write a program to print the following pattern:
*****
 ****
  ***
   **
    *

/*
Sample Test Cases:
Input 1:

Output 1:
*****
 ****
  ***
   **
    *

Input 2:

Output 2:
Note: Spaces indicate indentation.

*/
#include <stdio.h>

int main() {
    int i, j;

    // Outer loop for 5 rows
    for (i = 1; i <= 5; i++) {
        
        // Print leading spaces: 0 in first row, 1 in second, ..., 4 in last row
        for (j = 1; j < i; j++) {
            printf(" ");
        }
        
        // Print stars: 5 in first row, 4 in second, ..., 1 in last row
        for (j = 1; j <= 6 - i; j++) {
            printf("*");
        }
        
        printf("\n");  // New line after each row
    }

    return 0;
}