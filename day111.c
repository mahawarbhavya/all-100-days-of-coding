//Q21: Write a program to display the month name and number of days using switch-case for a given month number.

/*
Sample Test Cases:
Input 1:
2
Output 1:
February, 28 days

Input 2:
12
Output 2:
December, 31 days

*/
#include <stdio.h>

int main() {
    int month;

    // Input month number
    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    // Display month name and number of days
    switch (month) {
        case 1:
            printf("Month: JANUARY\n");
            printf("Days : 31\n");
            break;
        case 2:
            printf("Month: FEBRUARY\n");
            printf("Days : 28 (29 in a leap year)\n");
            break;
        case 3:
            printf("Month: MARCH\n");
            printf("Days : 31\n");
            break;
        case 4:
            printf("Month: APRIL\n");
            printf("Days : 30\n");
            break;
        case 5:
            printf("Month: MAY\n");
            printf("Days : 31\n");
            break;
        case 6:
            printf("Month: JUNE\n");
            printf("Days : 30\n");
            break;
        case 7:
            printf("Month: JULY\n");
            printf("Days : 31\n");
            break;
        case 8:
            printf("Month: AUGUST\n");
            printf("Days : 31\n");
            break;
        case 9:
            printf("Month: SEPTEMBER\n");
            printf("Days : 30\n");
            break;
        case 10:
            printf("Month: OCTOBER\n");
            printf("Days : 31\n");
            break;
        case 11:
            printf("Month: NOVEMBER\n");
            printf("Days : 30\n");
            break;
        case 12:
            printf("Month: DECEMBER\n");
            printf("Days : 31\n");
            break;
        default:
            printf("Invalid month number!\n");
            printf("Please enter a number between 1 and 12.\n");
    }

    return 0;
}