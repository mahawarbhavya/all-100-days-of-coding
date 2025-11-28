//Q41: Write a program to swap the first and last digit of a number.

/*
Sample Test Cases:
Input 1:
1234
Output 1:
4231

Input 2:
1001
Output 2:
1001

*/
#include <stdio.h>
#include <math.h>

int main() {
    int num, original_num, first_digit, last_digit;
    int digit_count = 0, temp;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }
    
    original_num = num;
    
    if (num == 0) {
        printf("Swapped number: 0\n");
        return 0;
    }
    
    // Get the last digit
    last_digit = num % 10;
    
    // Count total digits and get the first digit
    temp = num;
    while (temp >= 10) {
        temp /= 10;
        digit_count++;
    }
    first_digit = temp;
    digit_count++;  // Total number of digits
    
    // If number has only one digit, no swap needed
    if (digit_count == 1) {
        printf("Swapped number: %d\n", num);
        return 0;
    }
    
    // Remove the first and last digits and reconstruct the number
    // Step 1: Remove last digit
    num /= 10;
    
    // Step 2: Remove first digit by dividing by 10^(digit_count-2)
    int middle_part = num % (int)pow(10, digit_count - 2);
    
    // Now construct the new number:
    // New number = last_digit * 10^(digit_count-1) + middle_part * 10 + first_digit
    int swapped_num = last_digit * (int)pow(10, digit_count - 1) + 
                      middle_part * 10 + 
                      first_digit;
    
    printf("Original number: %d\n", original_num);
    printf("After swapping first and last digit: %d\n", swapped_num);
    
    return 0;
}