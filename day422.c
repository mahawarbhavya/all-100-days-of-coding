//Q84: Convert a lowercase string to uppercase without using built-in functions.

/*
Sample Test Cases:
Input 1:
hello
Output 1:
HELLO

*/
#include <stdio.h>

int main() {
    char str[201];  // String only – as per your rule!

    printf("Enter a lowercase string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    printf("\nOriginal string : \"%s\"\n", str);

    // Convert lowercase → uppercase manually
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if character is lowercase 'a' to 'z'
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  
            // Difference between 'a' and 'A' in ASCII is 32
            // 'a' = 97 → 'A' = 65 → subtract 32
        }
    }

    printf("Uppercase string: \"%s\"\n", str);

    return 0;
}