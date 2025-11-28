//Q74: Find the transpose of a matrix.

/*
Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
1 4
2 5
3 6

*/
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    // Original matrix (real 2D array)
    int matrix[ROWS][COLS];
    int transpose[COLS][ROWS];  // Note: dimensions swapped!

    // Input the original matrix
    printf("Enter elements of %dx%d matrix:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate transpose
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Display original matrix
    printf("\nOriginal Matrix (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // Display transpose
    printf("\nTranspose Matrix (%dx%d):\n", COLS, ROWS);
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%6d", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}