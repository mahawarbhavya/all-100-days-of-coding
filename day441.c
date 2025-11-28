//Q87: Count spaces, digits, and special characters in a string.

/*
Sample Test Cases:
Input 1:
a b1&2
Output 1:
Spaces=1, Digits=2, Special=1

*/
#include <stdio.h>

int main() {
    char str[301];  // Only string – as per your rule!
    int spaces = 0, digits = 0, special = 0, alphabets = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character added by fgets
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }
    str[i] = '\0';  // Proper termination

    printf("\nYour string: \"%s\"\n\n", str);

    // Traverse each character manually
    for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == ' ') {
            spaces++;
        }
        else if (ch >= '0' && ch <= '9') {
            digits++;
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            alphabets++;
        }
        else {
            special++;  // Everything else: @, #, $, %, &, *, !, etc.
        }
    }

    // Display results
    printf("Spaces          : %d\n", spaces);
    printf("Digits          : %d\n", digits);
    printf("Alphabets       : %d\n", alphabets);
    printf("Special Chars   : %d\n", special);
    printf("Total Characters: %d\n", spaces + digits + alphabets + special);

    return 0;
}