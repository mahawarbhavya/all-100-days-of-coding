//Q96: Reverse each word in a sentence without changing the word order.

/*
Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc

*/
#include <stdio.h>
#include <string.h>

void reverseWord(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char sentence[] = "I love programming very much";
    int start = 0;

    for (int i = 0; i <= strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            reverseWord(sentence, start, i - 1);
            start = i + 1;
        }
    }

    printf("Result: %s\n", sentence);
    return 0;
}
