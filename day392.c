//Q78: Find the sum of main diagonal elements for a square matrix.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
15

*/
#include <stdio.h>

#define N 4  // Size of square matrix (change as needed)

int main() {
    int matrix[N][N];
    int diagonalSum = 0;

    // Input the matrix
    printf("Enter elements of %dx%d square matrix:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate sum of main diagonal (i == j)
    for (int i = 0; i < N; i++) {
        diagonalSum += matrix[i][i];
    }

    // Display the matrix with diagonal highlighted
    printf("\nYour matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                printf("(%4d)", matrix[i][j]);  // Highlight main diagonal
            } else {
                printf("%6d", matrix[i][j]);
            }
        }
        printf("\n");
    }

    // Print diagonal elements and sum
    printf("\nMain diagonal elements: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", matrix[i][i]);
    }

    printf("\n\nSum of main diagonal (Trace) = %d\n", diagonalSum);

    return 0;
}