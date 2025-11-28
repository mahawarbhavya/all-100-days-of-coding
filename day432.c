//Q86: Check if a string is a palindrome.

/*
Sample Test Cases:
Input 1:
madam
Output 1:
Palindrome

Input 2:
hello
Output 2:
Not palindrome

*/
#include <stdio.h>

int isPalindrome(char str[]) {
    int i = 0, j;
    char temp;

    // Remove newline from fgets
    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }
    str[i] = '\0';  // Terminate string properly

    // Find length manually
    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    int len = i;

    // Compare characters from start and end
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;  // Not palindrome
        }
    }
    return 1;  // Is palindrome
}

int main() {
    char str[201];  // Only string – as per your rule!

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("\nYour string: \"%s\"\n", str);

    if (isPalindrome(str)) {
        printf("PALINDROME\n");
    } else {
        printf("NOT A PALINDROME\n");
    }

    return 0;
}