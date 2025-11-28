//Q79: Perform diagonal traversal of a matrix.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9

*/
#include <stdio.h>

#define ROWS 4
#define COLS 5

void printDiagonals(int matrix[ROWS][COLS]) {
    printf("Diagonal Traversal (top-right direction):\n");

    // Traverse all diagonals starting from first row
    for (int i = 0; i < ROWS; i++) {
        int row = i;
        int col = 0;
        printf("Diagonal %d: ", i + 1);
        while (row >= 0 && col < COLS) {
            printf("%d ", matrix[row][col]);
            row--;
            col++;
        }
        printf("\n");
    }

    // Traverse diagonals starting from columns (excluding first row)
    for (int j = 1; j < COLS; j++) {
        int row = ROWS - 1;
        int col = j;
        printf("Diagonal %d: ", ROWS + j);
        while (row >= 0 && col < COLS) {
            printf("%d ", matrix[row][col]);
            row--;
            col++;
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printDiagonals(matrix);

    return 0;
}