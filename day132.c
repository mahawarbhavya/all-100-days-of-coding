//Q26: Write a program to print numbers from 1 to n.

/*
Sample Test Cases:
Input 1:
5
Output 1:
1 2 3 4 5

Input 2:
3
Output 2:
1 2 3

*/
#include <stdio.h>

int main() {
    int n, i;

    // Input the value of n
    printf("Enter a positive integer (n): ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Print numbers from 1 to n
    printf("Numbers from 1 to %d are:\n", n);

    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    printf("\n");  // New line at the end

    return 0;
}