//Q64: Find the digit that occurs the most times in an integer number.

/*
Sample Test Cases:
Input 1:
112233
Output 1:
1

Input 2:
887799
Output 2:
7

*/
#include <stdio.h>

int findMostFrequentDigit(long long int num) {
    // Handle negative numbers
    if (num < 0) {
        num = -num;  // Make it positive
    }
    
    // Special case: if number is 0
    if (num == 0) {
        return 0;
    }
    
    // 1D array to store frequency of digits 0 to 9
    int freq[10] = {0};  // Only 1D array used!
    
    // Extract each digit and count frequency
    while (num > 0) {
        int digit = num % 10;
        freq[digit]++;       // Increment count for this digit
        num = num / 10;
    }
    
    // Find the digit with maximum frequency
    int maxCount = 0;
    int mostFrequentDigit = 0;
    
    for (int i = 0; i < 10; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            mostFrequentDigit = i;
        }
    }
    
    return mostFrequentDigit;
}

int main() {
    long long int number;
    
    printf("Enter a number: ");
    scanf("%lld", &number);
    
    int result = findMostFrequentDigit(number);
    
    printf("Most frequent digit: %d\n", result);
    
    // Optional: Print frequency of all digits
    printf("\nFrequency of each digit:\n");
    if (number < 0) number = -number;
    if (number == 0) {
        printf("0 appears 1 time\n");
    } else {
        int freq[10] = {0};
        long long int temp = number == 0 ? 1 : number;
        do {
            freq[temp % 10]++;
            temp /= 10;
        } while (temp > 0);
