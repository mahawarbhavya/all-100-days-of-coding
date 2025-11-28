//Q19: Write a program to classify a triangle as Equilateral, Isosceles, or Scalene based on its side lengths.

/*
Sample Test Cases:
Input 1:
3 3 3
Output 1:
Equilateral

Input 2:
3 3 4
Output 2:
Isosceles

Input 3:
2 3 4
Output 3:
Scalene

*/
#include <stdio.h>

int main() {
    float side1, side2, side3;

    // Input three sides
    printf("Enter the lengths of three sides of a triangle: ");
    scanf("%f %f %f", &side1, &side2, &side3);

    // Check if sides are valid (positive)
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        printf("Invalid input! All sides must be positive.\n");
        return 1;
    }

    // Check triangle inequality theorem
    if ((side1 + side2 <= side3) || 
        (side2 + side3 <= side1) || 
        (side1 + side3 <= side2)) {
        printf("Not a valid triangle! (Triangle inequality violated)\n");
        return 1;
    }

    // Classify the triangle
    printf("Triangle type: ");
    if (side1 == side2 && side2 == side3) {
        printf("EQUILATERAL\n");
        printf("All three sides are equal.\n");
    }
    else if (side1 == side2 || side2 == side3 || side1 == side3) {
        printf("ISOSCELES\n");
        printf("Exactly two sides are equal.\n");
    }
    else {
        printf("SCALENE\n");
        printf("All sides are different.\n");
    }

    return 0;
}