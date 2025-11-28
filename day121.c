//Q23: Write a program to calculate library fine based on late days as follows: 
First 5 days late: ₹2/day 
Next 5 days late: ₹4/day 
Next 20 days days late: ₹6/day 
More than 30 days: Membership Cancelled.

/*
Sample Test Cases:
Input 1:
4
Output 1:
Fine ₹8

Input 2:
8
Output 2:
Fine ₹22

Input 3:
15
Output 3:
Fine ₹60

Input 4:
31
Output 4:
Membership Cancelled

*/
#include <stdio.h>

int main() {
    int days_late;
    float fine = 0.0;

    // Input number of late days
    printf("Enter the number of days the book is returned late: ");
    scanf("%d", &days_late);

    // Validate input
    if (days_late < 0) {
        printf("Invalid input! Days cannot be negative.\n");
        return 1;
    }

    // Calculate fine based on rules
    if (days_late == 0) {
        printf("No fine. Book returned on time!\n");
    }
    else if (days_late <= 5) {
        // First 5 days: ₹2 per day
        fine = days_late * 2;
        printf("Fine = ₹%.2f (₹2/day for first 5 days)\n", fine);
    }
    else if (days_late <= 10) {
        // First 5 days: ₹2/day, Next 5 days: ₹4/day
        fine = (5 * 2) + ((days_late - 5) * 4);
        printf("Fine = ₹%.2f\n", fine);
        printf("(₹2/day for first 5 days + ₹4/day for next %d days)\n", days_late - 5);
    }
    else if (days_late <= 30) {
        // First 10 days as above + next days: ₹6/day
        fine = (5 * 2) + (5 * 4) + ((days_late - 10) * 6);
        printf("Fine = ₹%.2f\n", fine);
        printf("(₹2/day for first 5 + ₹4/day for next 5 + ₹6/day for next %d days)\n", days_late - 10);
    }
    else {
        // More than 30 days
        printf("Membership CANCELLED!\n");
        printf("Book is %d days late. Fine not applicable. Membership revoked.\n", days_late);
    }

    // Show total fine if applicable
    if (days_late > 0 && days_late <= 30) {
        printf("\nTotal Fine to be paid: ₹%.2f\n", fine);
    }

    return 0;
}