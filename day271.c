//Q53: Write a program to print the following pattern:
*
***
*****
*******
*********
*******
*****
***
*

/*
Sample Test Cases:
Input 1:

Output 1:
*
***
*****
*******
*********
*******
*****
***
*

*/
#include <stdio.h>

int main()
{
    int i, j;

    // Upper part (increasing: 1, 3, 5, 7, 9 stars)
    
    // 1 star
    for(i = 1; i <= 1; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }
    
    // 3 stars
    for(i = 1; i <= 3; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }
    
    // 5 stars
    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }
    
    // 7 stars
    for(i = 1; i <= 7; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }
    
    // 9 stars (middle row)
    for(i = 1; i <= 9; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }
    
    // Lower part (decreasing: 7, 5, 3, 1 stars)
    
    // 7 stars
    for(i = 1; i <= 7; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }
    
    // 5 stars
    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }
    
    // 3 stars
    for(i = 1; i <= 3; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }
    
    // 1 star
    for(i = 1; i <= 1; i++)
    {
        for(j = 1; j <= 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}