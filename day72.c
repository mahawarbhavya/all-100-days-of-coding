//Q14: Write a program to input a character and check whether it is a vowel or consonant using if–else.

/*
Sample Test Cases:
Input 1:
a
Output 1:
Vowel

Input 2:
b
Output 2:
Consonant

*/
#include <stdio.h>

int main() {
    char ch;

    // Input a character
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Convert to lowercase to handle both cases
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;  // Convert uppercase to lowercase
    }

    // Check if it's an alphabet first
    if (ch >= 'a' && ch <= 'z') {
        // Check for vowels
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            printf("'%c' is a VOWEL\n", ch);
        }
        else {
            printf("'%c' is a CONSONANT\n", ch);
        }
    }
    else {
        printf("'%c' is NOT an alphabet\n", ch);
    }

    return 0;
}