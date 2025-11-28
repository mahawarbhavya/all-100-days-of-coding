//
Q35: Write a program to print all factors of a given number.

/*
Sample Test Cases:
Input 1:
6
Output 1:
1 2 3 6

Input 2:
10
Output 2:
1 2 5 10

*/
#include <stdio.h>

int main() {
    int num, i;

    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Input validation
    if (num <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    printf("All factors of %d are: ", num);

    // Loop from 1 to num to find factors
    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}