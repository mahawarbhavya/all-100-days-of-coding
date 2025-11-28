//Q44: Write a program to find the sum of the series: 1 + 3/4 + 5/6 + 7/8 + … up to n terms.

/*
Sample Test Cases:
Input 1:
3
Output 1:
Approximate sum: 3.3

Input 2:
5
Output 2:
Approximate sum: 4.4

*/
#include <stdio.h>

int main() {
    int n;
    float sum = 0.0;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive number of terms.\n");
        return 1;
    }
    
    printf("Series:\n");
    
    for (int i = 1; i <= n; i++) {
        int numerator = 2 * i - 1;    // 1, 3, 5, 7, ...
        int denominator;
        
        if (i == 1)
            denominator = 1;
        else
            denominator = 2 * i + 2;  // 4, 6, 8, 10, ...
        
        float term = (float)numerator / denominator;
        sum += term;
        
        // Print the term
        if (i == 1)
            printf("1");
        else
            printf(" + %d/%d", numerator, denominator);
    }
    
    printf("\n\nSum of the series = %.6f\n", sum);
    
    return 0;
}