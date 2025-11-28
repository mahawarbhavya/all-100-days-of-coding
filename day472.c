//Q94: Find the longest word in a sentence.

/*
Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "I love programming very much";
    char words[20][20];  // 2D array: up to 20 words, each up to 19 chars

    int w = 0, c = 0;

    // Split into 2D array
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] != ' ') {
            words[w][c++] = sentence[i];
        } else {
            words[w][c] = '\0';
            w++;
            c = 0;
        }
    }
    words[w][c] = '\0'; // terminate last word
    int totalWords = w + 1;

    // Find longest word
    int maxLen = 0;
    int maxIndex = 0;

    for (int i = 0; i < totalWords; i++) {
        int len = strlen(words[i]);
        if (len > maxLen) {
            maxLen = len;
            maxIndex = i;
        }
    }

    printf("Longest word: %s\n", words[maxIndex]);
    return 0;
}
