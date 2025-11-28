//Q13: Write a program to input a year and check whether it is a leap year or not using conditional statements.

/*
Sample Test Cases:
Input 1:
2020
Output 1:
Leap year

Input 2:
1900
Output 2:
Not a leap year

Input 3:
2000
Output 3:
Leap year

*/
#include <stdio.h>

int main() {
    int year;

    // Input the year
    printf("Enter a year: ");
    scanf("%d", &year);

    // Check if it's a leap year
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                printf("%d is a LEAP YEAR\n", year);
            }
            else {
                printf("%d is NOT a leap year\n", year);
            }
        }
        else {
            printf("%d is a LEAP YEAR\n", year);
        }
    }
    else {
        printf("%d is NOT a leap year\n", year);
    }

    return 0;
}