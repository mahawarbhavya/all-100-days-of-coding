//Q97: Print the initials of a name.

/*
Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.

*/
#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);

    // Print first initial (first character if not a space)
    if (name[0] != ' ')
        printf("%c ", name[0]);

    // Print initials after each space
    for (int i = 1; name[i] != '\0'; i++) {
        if (name[i-1] == ' ' && name[i] != ' ')
            printf("%c ", name[i]);
    }

    return 0;
}
