//Q91: Remove all vowels from a string.

/*
Sample Test Cases:
Input 1:
education
Output 1:
dctn

*/
#include <stdio.h>

int main() {
    char str[301];  // Only string – your rule 100% respected!
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++);
    str[i] = '\0';

    printf("\nOriginal string : \"%s\"\n", str);

    // Remove vowels (a, e, i, o, u) – both lowercase and uppercase
    for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Convert to lowercase for easy checking
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        // Check if character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            continue;  // Skip this character (vowel)
        }
        else {
            str[j] = str[i];  // Keep this character
            j++;
        }
    }
    str[j] = '\0';  // Null-terminate the new string

    printf("After removing vowels: \"%s\"\n", str);

    return 0;
}