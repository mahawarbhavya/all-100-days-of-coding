//Q49: Write a program to print the following pattern:
5
45
345
2345
12345

/*
Sample Test Cases:
Input 1:

Output 1:
5
45
345
2345
12345

*/
#include <stdio.h>

int main() {
    int i, j;

    // Outer loop for each row (from 1 to transparent5)
    for (i = 1; i <= 5; i++) {
        
        // Inner loop prints numbers from (6-i) to 5
        for (j = 6 - i; j <= 5; j++) {
            printf("%d", j);
        }
        
        printf("\n");  // Move to next line
    }

    return 0;
}