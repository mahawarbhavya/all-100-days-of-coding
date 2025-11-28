//Q22: Write a program to find profit or loss percentage given cost price and selling price.

/*
Sample Test Cases:
Input 1:
1000 1200
Output 1:
Profit 20%

Input 2:
1000 800
Output 2:
Loss 20%

Input 3:
1000 1000
Output 3:
No Profit No Loss

*/
#include <stdio.h>

int main() {
    float cost_price, selling_price;
    float profit, loss, percentage;

    // Input cost price and selling price
    printf("Enter Cost Price: ");
    scanf("%f", &cost_price);

    printf("Enter Selling Price: ");
    scanf("%f", &selling_price);

    // Check for valid input
    if (cost_price < 0 || selling_price < 0) {
        printf("Error: Prices cannot be negative!\n");
        return 1;
    }

    // Calculate profit or loss
    if (selling_price > cost_price) {
        // Profit case
        profit = selling_price - cost_price;
        percentage = (profit / cost_price) * 100;

        printf("\n--- Result ---\n");
        printf("You made a PROFIT\n");
        printf("Profit Amount     = %.2f\n", profit);
        printf("Profit Percentage = %.2f%%\n", percentage);
    }
    else if (selling_price < cost_price) {
        // Loss case
        loss = cost_price - selling_price;
        percentage = (loss / cost_price) * 100;

        printf("\n--- Result ---\n");
        printf("You incurred a LOSS\n");
        printf("Loss Amount       = %.2f\n", loss);
        printf("Loss Percentage   = %.2f%%\n", percentage);
    }
    else {
        // No profit, no loss
        printf("\n--- Result ---\n");
        printf("NO PROFIT, NO LOSS\n");
        printf("Cost Price = Selling Price = %.2f\n", cost_price);
    }

    return 0;
}