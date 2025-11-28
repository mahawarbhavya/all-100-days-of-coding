//Q85: Reverse a string.

/*
Sample Test Cases:
Input 1:
abcd
Output 1:
dcba

*/
#include <stdio.h>

int main() {
    char str[201];      // Only string – as per your rule!
    int i, j;
    char temp;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    printf("\nOriginal string : \"%s\"\n", str);

    // Find length manually (no strlen!)
    for (i = 0; str[i] != '\0'; i++) {
        // Just counting length
    }
    int len = i;  // i is now at '\0'

    // Reverse the string in-place
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string : \"%s\"\n", str);

    return 0;
}