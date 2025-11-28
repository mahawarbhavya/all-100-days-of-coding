//Q9: Write a program to calculate simple and compound interest for given principal, rate, and time.

/*
Sample Test Cases:
Input 1:
1000 5 2
Output 1:
Simple Interest=100, Compound Interest=102.5

Input 2:
5000 7 3
Output 2:
Simple Interest=1050, Compound Interest=1125.76

*/
#include <stdio.h>
#include <math.h>   // Required for pow() function

int main() {
    float principal, rate, time;
    float simple_interest, compound_interest, amount;

    // Input principal, rate, and time
    printf("Enter Principal Amount: ");
    scanf("%f", &principal);

    printf("Enter Rate of Interest (%% per year): ");
    scanf("%f", &rate);

    printf("Enter Time (in years): ");
    scanf("%f", &time);

    // Calculate Simple Interest
    // Formula: SI = (P × R × T) / 100
    simple_interest = (principal * rate * time) / 100;

    // Calculate Compound Interest
    // Formula: A = P(1 + R/100)^t
    // CI = A - P
    amount = principal * pow((1 + rate / 100), time);
    compound_interest = amount - principal;

    // Display results
    printf("\n--- Results ---\n");
    printf("Principal Amount       = %.2f\n", principal);
    printf("Rate of Interest       = %.2f%%\n", rate);
    printf("Time                   = %.2f years\n\n", time);

    printf("Simple Interest        = %.2f\n", simple_interest);
    printf("Amount (SI)            = %.2f\n\n", principal + simple_interest);

    printf("Compound Interest      = %.2f\n", compound_interest);
    printf("Amount (CI)            = %.2f\n", amount);

    return 0;
}