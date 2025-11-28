//Q82: Print each character of a string on a new line.

/*
Sample Test Cases:
Input 1:
Hi
Output 1:
H
i

*/
#include <stdio.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Remove the newline character added by fgets (optional)
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        i++;
    }
    str[i] = '\0';  // Replace '\n' with '\0'

    printf("\nEach character on a new line:\n\n");

    // Print each character on a new line
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c\n", str[i]);
    }

    return 0;
}