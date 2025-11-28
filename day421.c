//Q83: Count vowels and consonants in a string.

/*
Sample Test Cases:
Input 1:
hello
Output 1:
Vowels=2, Consonants=3

*/
#include <stdio.h>

int main() {
    char str[201];          // String (character array)
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character added by fgets
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    printf("\nYour string: \"%s\"\n\n", str);

    // Traverse the string manually
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Convert uppercase to lowercase
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;           // 'A' → 'a', etc.
        }

        // Check if it's an alphabet letter
        if (ch >= 'a' && ch <= 'z') {
            // Vowel check
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        // Non-alphabets (spaces, digits, symbols) are ignored
    }

    printf("Number of Vowels     : %d\n", vowels);
    printf("Number of Consonants : %d\n", consonants);

    return 0;
}