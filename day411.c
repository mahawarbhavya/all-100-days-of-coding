//Q81: Count characters in a string without using built-in length functions.

/*
Sample Test Cases:
Input 1:
Hello
Output 1:
5

Input 2:
 
Output 2:
1

*/
#include <stdio.h>

int countLength(char str[]) {
    int count = 0;
    
    // Traverse the string until null character '\0' is found
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    
    return count;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    // scanf("%s", str);  // Only reads until space
    // Better: use gets() or fgets() for full line with spaces
    fgets(str, 100, stdin);
    
    // Remove the newline character added by fgets
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0') i++;
    str[i] = '\0';  // Replace '\n' with '\0'

    int length = countLength(str);

    printf("Your string: \"%s\"\n", str);
    printf("Length of string = %d\n", length);

    return 0;
}