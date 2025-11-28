//Q98: Print initials of a name with the surname displayed in full.

/*
Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe

*/
#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);

    int len = strlen(name);

    // Remove newline from fgets if present
    if (name[len - 1] == '\n')
        name[len - 1] = '\0';

    int lastSpace = -1;

    // Find the last space → surname starts after this
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ')
            lastSpace = i;
    }

    // Print initials for all words before the surname
    printf("Output: ");
    if (name[0] != ' ')
        printf("%c ", name[0]);

    for (int i = 1; i < lastSpace; i++) {
        if (name[i - 1] == ' ' && name[i] != ' ')
            printf("%c ", name[i]);
    }

    // Print the surname fully
    printf("%s\n", &name[lastSpace + 1]);

    return 0;
}
