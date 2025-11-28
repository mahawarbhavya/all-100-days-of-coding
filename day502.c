//Q100: Print all sub-strings of a string.

/*
Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c

*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);

    printf("All substrings:\n");

    for (int i = 0; i < n; i++) {         // Start
        for (int j = i; j < n; j++) {     // End
            for (int k = i; k <= j; k++)  // Print substring
                printf("%c", str[k]);
            printf("\n");
        }
    }

    return 0;
}
