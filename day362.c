//Q72: Find the sum of all elements in a matrix.

/*
Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
21

*/
#include <stdio.h>

#define ROWS 4
#define COLS 5

int main() {
    // Real 2D array
    int matrix[ROWS][COLS];
    long long int sum = 0;  // Use long long to avoid overflow with large numbers

    // Input the matrix
    printf("Enter elements of %dx%d matrix:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
            sum += matrix[i][j];  // Add each element to sum
        }
    }

    // Print the matrix
    printf("\nYour matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // Print the final sum
    printf("\nSum of all elements = %lld\n", sum);

    return 0;
}