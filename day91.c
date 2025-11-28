//Q17: Write a program to find the roots of a quadratic equation and categorize them.

/*
Sample Test Cases:
Input 1:
1 -3 2
Output 1:
Roots are real and different: 2, 1

Input 2:
1 -2 1
Output 2:
Roots are real and same: 1

Input 3:
1 2 5
Output 3:
Roots are complex

*/
#include <stdio.h>
#include <math.h>   // For sqrt() function

int main() {
    float a, b, c;
    float discriminant, root1, root2;
    float real_part, imag_part;

    // Input coefficients
    printf("Enter coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    // Check if a is zero (not a quadratic equation)
    if (a == 0) {
        printf("Error: 'a' cannot be zero. Not a quadratic equation.\n");
        return 1;
    }

    // Calculate discriminant
    discriminant = b * b - 4 * a * c;

    // Categorize and find roots based on discriminant
    if (discriminant > 0) {
        // Two real and distinct roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are REAL and DISTINCT.\n");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    }
    else if (discriminant == 0) {
        // One real and repeated root
        root1 = -b / (2 * a);
        printf("Roots are REAL and EQUAL.\n");
        printf("Root = %.2f\n", root1);
    }
    else {
        // Complex (imaginary) roots
        real_part = -b / (2 * a);
        imag_part = sqrt(-discriminant) / (2 * a);
        printf("Roots are COMPLEX and IMAGINARY.\n");
        printf("Root 1 = %.2f + %.2fi\n", real_part, imag_part);
        printf("Root 2 = %.2f - %.2fi\n", real_part, imag_part);
    }

    return 0;
}