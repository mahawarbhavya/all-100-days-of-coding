//Q24: Write a program to calculate electricity bill based on units consumed with these rates: 
First 100 units at ₹5/unit 
Next 100 units at ₹7/unit 
Next 100 units at ₹10/unit 
Above at ₹12/unit

/*
Sample Test Cases:
Input 1:
50
Output 1:
Bill: ₹250

Input 2:
150
Output 2:
Bill: ₹850

Input 3:
250
Output 3:
Bill: ₹1700

*/
#include <stdio.h>

int main() {
    int units;
    float bill = 0.0;

    // Input total units consumed
    printf("Enter the number of units consumed: ");
    scanf("%d", &units);

    // Validate input
    if (units < 0) {
        printf("Invalid input! Units cannot be negative.\n");
        return 1;
    }

    // Calculate bill based on slab rates
    if (units <= 100) {
        // First 100 units @ ₹5 per unit
        bill = units * 5;
    }
    else if (units <= 200) {
        // First 100 @ ₹5 + Next 100 @ ₹7
        bill = (100 * 5) + ((units - 100) * 7);
    }
    else if (units <= 300) {
        // First 100 @ ₹5 + Next 100 @ ₹7 + Next 100 @ ₹10
        bill = (100 * 5) + (100 * 7) + ((units - 200) * 10);
    }
    else {
        // First 300 as above + remaining @ ₹12
        bill = (100 * 5) + (100 * 7) + (100 * 10) + ((units - 300) * 12);
    }

    // Display detailed bill
    printf("\n");
    printf("===========================\n");
    printf("   ELECTRICITY BILL\n");
    printf("===========================\n");
    printf("Units Consumed      : %d\n", units);
    printf("Total Bill Amount   : ₹%.2f\n", bill);
    printf("===========================\n");

    // Optional: Show slab-wise breakdown
    printf("\nSlab-wise Charges:\n");
    if (units > 0)    printf("First 100 units     : ₹5/unit\n");
    if (units > 100)  printf("Next 100 units      : ₹7/unit\n");
    if (units > 200)  printf("Next 100 units      : ₹10/unit\n");
    if (units > 300)  printf("Above 300 units     : ₹12/unit\n");

    return 0;
}