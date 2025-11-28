//Q71: Read and print a matrix.

/*
Sample Test Cases:
Input 1:
2 2
1 2
3 4
Output 1:
1 2
3 4

*/
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    // Real 2D array declaration
    int matrix[ROWS][COLS];

    // Reading the matrix
    printf("Enter %d x %d matrix (%d elements):\n", ROWS, COLS, ROWS * COLS);
    for (int i = 0; i < ROWS; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Printing the matrix neatly
    printf("\nYour matrix is:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}