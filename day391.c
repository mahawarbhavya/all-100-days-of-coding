//Q77: Check if the elements on the diagonal of a matrix are distinct.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 1
Output 1:
False

Input 2:
3 3
1 2 3
4 5 6
7 8 9
Output 2:
True

*/
#include <stdio.h>
#define N 4  // Size of square matrix

int areDiagonalElementsDistinct(int matrix[N][N], int size) {
    // Check each pair of diagonal elements
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (matrix[i][i] == matrix[j][j]) {
                return 0;  // Duplicate found
            }
        }
    }
    return 1;  // All distinct
}

int main() {
    int matrix[N][N];

    // Input the matrix
    printf("Enter elements of %dx%d matrix:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("matrix[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("\nYour matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                printf("(%4d)", matrix[i][j]);  // Highlight diagonal
            else
                printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // Print diagonal elements
    printf("\nDiagonal elements: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", matrix[i][i]);
    }

    // Check and display result
    if (areDiagonalElementsDistinct(matrix, N)) {
        printf("\nAll diagonal elements are DISTINCT\n");
    } else {
        printf("\nDuplicate found! Diagonal elements are NOT distinct\n");
    }

    return 0;
}