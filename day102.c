//Q20: Write a program to display the day of the week based on a number (1–7) using switch-case.

/*
Sample Test Cases:
Input 1:
1
Output 1:
Monday

Input 2:
5
Output 2:
Friday

*/
#include <stdio.h>

int main() {
    int day;

    // Input a number between 1 and 7
    printf("Enter a number (1-7) to display the day of the week: ");
    scanf("%d", &day);

    // Display day using switch-case
    switch (day) {
        case 1:
            printf("Day %d = SUNDAY\n", day);
            break;
        case 2:
            printf("Day %d = MONDAY\n", day);
            break;
        case 3:
            printf("Day %d = TUESDAY\n", day);
            break;
        case 4:
            printf("Day %d = WEDNESDAY\n", day);
            break;
        case 5:
            printf("Day %d = THURSDAY\n", day);
            break;
        case 6:
            printf("Day %d = FRIDAY\n", day);
            break;
        case 7:
            printf("Day %d = SATURDAY\n", day);
            break;
        default:
            printf("Invalid input! Please enter a number between 1 and 7.\n");
    }

    return 0;
}