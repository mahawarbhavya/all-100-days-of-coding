//Q88: Replace spaces with hyphens in a string.

/*
Sample Test Cases:
Input 1:
hello world
Output 1:
hello-world

*/
#include <stdio.h>

int main() {
    char str[301];  // Only string – your rule 100% respected!

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from fgets
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }
    str[i] = '\0';

    printf("\nOriginal string : \"%s\"\n", str);

    // Replace every space with hyphen '-'
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = '-';
        }
    }

    printf("Modified string : \"%s\"\n", str);

    return 0;
}