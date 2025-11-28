//Q3: Write a program to calculate the area and perimeter of a rectangle given its length and breadth.

/*
Sample Test Cases:
Input 1:
5 10
Output 1:
Area=50, Perimeter=30

Input 2:
3 7
Output 2:
Area=21, Perimeter=20

*/
#include <stdio.h>

int main() {
    float length, breadth;
    float area, perimeter;

    // Input length and breadth
    printf("Enter length of the rectangle: ");
    scanf("%f", &length);

    printf("Enter breadth of the rectangle: ");
    scanf("%f", &breadth);

    // Calculate area and perimeter
    area      = length * breadth;
    perimeter = 2 * (length + breadth);

    // Display results
    printf("\n");
    printf("Length    = %.2f\n", length);
    printf("Breadth   = %.2f\n", breadth);
    printf("Area      = %.2f square units\n", area);
    printf("Perimeter = %.2f units\n", perimeter);

    return 0;
}