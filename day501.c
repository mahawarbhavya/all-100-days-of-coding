//Q99: Change the date format from dd/04/yyyy to dd-Apr-yyyy.

/*
Sample Test Cases:
Input 1:
15/04/2025
Output 1:
15-Apr-2025

*/
#include <stdio.h>
#include <string.h>

int main() {
    char date[20];
    char day[3], year[5];

    printf("Enter date in dd/04/yyyy format: ");
    scanf("%s", date);   // example: 15/04/2022

    // Extract day (first two characters)
    strncpy(day, date, 2);
    day[2] = '\0';

    // Extract year (characters after "04/")
    strcpy(year, date + 5);

    // Print in new format
    printf("%s-Apr-%s\n", day, year);

    return 0;
}
