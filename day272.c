//Q54: Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *


/*
Sample Test Cases:
Input 1:

Output 1:
Pattern with layers of stars as shown.

*/
#include <stdio.h>

int main()
{
    int i, j;

    // Row 1: 3 spaces + 1 star
    for(i = 1; i <= 3; i++) printf(" ");
    for(i = 1; i <= 1; i++) printf("*");
    printf("\n");

    // Row 2: 2 spaces + 3 stars
    for(i = 1; i <= 2; i++) printf(" ");
    for(i = 1; i <= 3; i++) printf("*");
    printf("\n");

    // Row 3: 1 space + 5 stars
    for(i = 1; i <= 1; i++) printf(" ");
    for(i = 1; i <= 5; i++) printf("*");
    printf("\n");

    // Row 4: 0 spaces + 7 stars
    for(i = 1; i <= 7; i++) printf("*");
    printf("\n");

    // Row 5: 1 space + 5 stars
    for(i = 1; i <= 1; i++) printf(" ");
    for(i = 1; i <= 5; i++) printf("*");
    printf("\n");

    // Row 6: 2 spaces + 3 stars
    for(i = 1; i <= 2; i++) printf(" ");
    for(i = 1; i <= 3; i++) printf("*");
    printf("\n");

    // Row 7: 3 spaces + 1 star
    for(i = 1; i <= 3; i++) printf(" ");
    for(i = 1; i <= 1; i++) printf("*");
    printf("\n");

    return 0;
}