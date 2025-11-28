//Q90: Toggle case of each character in a string.

/*
Sample Test Cases:
Input 1:
Hello
Output 1:
hELLO

*/
#include <stdio.h>

int main() {
    char str[301];  // Only string – your rule 100% followed!

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character added by fgets
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }
    str[i] = '\0';

    printf("\nOriginal string : \"%s\"\n", str);

    // Toggle case of each character
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Lowercase → Uppercase
            str[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            // Uppercase → Lowercase
            str[i] = str[i] + 32;
        }
        // Non-alphabetic characters remain unchanged
    }

    printf("Toggled string  : \"%s\"\n", str);

    return 0;
}