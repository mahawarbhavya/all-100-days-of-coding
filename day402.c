//Q80: Multiply two matrices.

/*
Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
3 2
7 8
9 10
11 12
Output 1:
58 64
139 154

*/
#include <stdio.h>

#define ROW1 3
#define COL1 4
#define COL2 2   // ROW2 must be equal to COL1 → ROW2 = COL1

int main() {
    int A[ROW1][COL1];
    int B[COL1][COL2];      // COL1 must match
    int C[ROW1][COL2] = {0}; // Result matrix initialized to zero

    // Input Matrix A
    printf("Enter elements of Matrix A (%dx%d):\n", ROW1, COL1);
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL1; j++) {
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    // Input Matrix B
    printf("\nEnter elements of Matrix B (%dx%d):\n", COL1, COL2);
    for (int i = 0; i < COL1; i++) {
        for (int j = 0; j < COL2; j++) {
            printf("B[%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix Multiplication: C[i][k] = sum(A[i][j] * B[j][k])
    for (int i = 0; i < ROW1; i++) {
        for (int k = 0; k < COL2; k++) {
            for (int j = 0; j < COL1; j++) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }

    // Display Matrix A
    printf("\nMatrix A:\n");
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL1; j++) {
            printf("%6d", A[i][j]);
        }
        printf("\n");
    }

    // Display Matrix B
    printf("\nMatrix B:\n");
    for (int i = 0; i < COL1; i++) {
        for (int j = 0; j < COL2; j++) {
            printf("%6d", B[i][j]);
        }
        printf("\n");
    }

    // Display Result C = A × B
    printf("\nResult: C = A x B (%dx%d):\n", ROW1, COL2);
    for (int i = 0; i < ROW1; i++) {
        for (int k = 0; k < COL2; k++) {
            printf("%8d", C[i][k]);
        }
        printf("\n");
    }

    return 0;
}