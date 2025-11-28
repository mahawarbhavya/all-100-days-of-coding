//Q92: Find the first repeating lowercase alphabet in a string.

/*
Sample Test Cases:
Input 1:
stress
Output 1:
s

*/
#include <stdio.h>

int main() {
    char str[301];  // Only string – your rule 100% followed!
    int i, j;
    char firstRepeat = '\0';  // To store the first repeating lowercase letter

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++);
    str[i] = '\0';

    printf("\nYour string: \"%s\"\n", str);

    // Check only lowercase letters a-z
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            char current = str[i];

            // Check if this lowercase letter appeared before
            for (j = 0; j < i; j++) {
                if (str[j] == current) {
                    firstRepeat = current;
                    goto found;  // Exit both loops – first repeating found!
                }
            }
        }
    }

found:
    if (firstRepeat != '\0') {
        printf("First repeating lowercase alphabet: '%c'\n", firstRepeat);
    } else {
        printf("No repeating lowercase alphabet found.\n");
    }

    return 0;
}