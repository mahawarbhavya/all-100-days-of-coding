//Q76: Check if a matrix is symmetric.

/*
Sample Test Cases:
Input 1:
2 2
1 2
2 1
Output 1:
True

Input 2:
2 2
1 0
2 1
Output 2:
False

*/
#include <stdio.h>

#define N 4  // Change this for different sizes (must be square)

int isSymmetric(int matrix[N][N], int size) {
    // Step 1: Check if it's square (already enforced by N x N)
    // Step 2: Compare matrix[i][j] with matrix[j][i]
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;  // Not symmetric
            }
        }
    }
    return 1;  // Symmetric
}

int main() {
    int matrix[N][N];
    
    printf("Enter elements of %dx%d matrix:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("\nYour matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // Check and display result
    if (isSymmetric(matrix, N)) {
