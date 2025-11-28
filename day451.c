//Q89: Count frequency of a given character in a string.

/*
Sample Test Cases:
Input 1:
programming
g
Output 1:
2

*/
#include <stdio.h>

int main() {
    char str[301];        // Only string – your rule fully respected!
    char target;
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character added by fgets
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }
    str[i] = '\0';

    printf("Enter character to search: ");
    scanf(" %c", &target);  // Note: space before %c to consume newline

    printf("\nYour string: \"%s\"\n", str);
    printf("Searching for: '%c'\n\n", target);

    // Count frequency manually
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            count++;
        }
    }

    // Display result
    if (count > 0) {
        printf("Character '%c' appears %d time(s).\n", target, count);
    } else {
        printf("Character '%c' not found in the string.\n", target);
    }

    return 0;
}