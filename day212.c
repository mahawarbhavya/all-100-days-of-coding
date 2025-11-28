//Q42: Write a program to check if a number is a perfect number.

/*
Sample Test Cases:
Input 1:
6
Output 1:
Perfect number

Input 2:
10
Output 2:
Not perfect number

*/
#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    
    // Find sum of proper divisors
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    
    // If sum of proper divisors equals the number, it's perfect
    return (sum == num);
}

int main() {
    int num;
    
    printf("Enter a positive number: ");
    scanf("%d", &num);
    
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    if (isPerfect(num)) {
        printf("%d is a Perfect Number.\n", num);
    } else {
        printf("%d is NOT a Perfect Number.\n", num);
    }
    
    // Optional: Print the divisors and their sum
    printf("\nProper divisors of %d are: ", num);
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
            sum += i;
        }
    }
    printf("\nSum of proper divisors = %d\n", sum);
    
    return 0;
}