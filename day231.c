//Q45: Write a program to find the sum of the series: 2/3 + 4/7 + 6/11 + 8/15 + ... up to n terms.

/*
Sample Test Cases:
Input 1:
3
Output 1:
Approximate sum: 1.56

Input 2:
5
Output 2:
Approximate sum: 2.22

*/
#include <stdio.h>

int main() {
    int n, i;
    float sum = 0.0;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive number of terms.\n");
        return 1;
    }
    
    printf("Series:\n");
    
    for (i = 1; i <= n; i++) {
        int numerator = 2 * i;                    // 2, 4, 6, 8, ...
        int denominator = 4 * i - 1;              // 3, 7, 11, 15, ...
        float term = (float)numerator / denominator;
        
        sum += term;
        
        // Print the term
        printf("%d/%d", numerator, denominator);
        if (i < n)
            printf(" + ");
    }
    
    printf("\n\nSum of %d terms = %.6f\n", n, sum);
    
    return 0;
}