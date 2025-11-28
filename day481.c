//Q95: Check if one string is a rotation of another.

/*
Sample Test Cases:
Input 1:
abcde
deabc
Output 1:
Rotation

Input 2:
abc
acb
Output 2:
Not rotation

*/
#include <stdio.h>
#include <string.h>

int isRotation(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2))
        return 0;

    char temp[200];
    strcpy(temp, s1);
    strcat(temp, s1);   // temp = s1 + s1

    return strstr(temp, s2) != NULL;
}

int main() {
    char s1[] = "hello";
    char s2[] = "lohel";

    if (isRotation(s1, s2))
        printf("Yes, it is a rotation.\n");
    else
        printf("No, not a rotation.\n");

    return 0;
}
