//Q73: Find the sum of each row of a matrix and store it in an array.

/*
Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
6 15

*/
#include <stdio.h>

#define ROWS 4
#define COLS 5

int main() {
    // Real 2D array for matrix
    int matrix[ROWS][COLS];
    
    // 1D array to store sum of each row
    int rowSum[ROWS] = {0};  // Automatically initialized to 0

    // Input the matrix
    printf("Enter elements of %dx%d matrix:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate sum of each row
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rowSum[i] += matrix[i][j];
        }
    }

    // Display the matrix
    printf("\nYour matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("   -->  Sum = %d\n", rowSum[i]);
    }

    // Print all row sums separately
    printf("\nRow sums stored in array:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d sum = %d\n", i + 1, rowSum[i]);
    }

    return 0;
}