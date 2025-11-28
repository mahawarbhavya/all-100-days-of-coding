//Q93: Check if two strings are anagrams of each other.

/*
Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams

*/
#include <iostream>
#include <cstring>
using namespace std;

bool areAnagrams(string s1, string s2) {
    // If lengths are different, they can't be anagrams
    if (s1.length() != s2.length())
        return false;

    // 2D array: row 0 for string1, row 1 for string2
    // Each row has 26 columns for 'a' to 'z'
    int count[2][26] = {0};

    };

    // Convert both strings to lowercase (optional, depending on requirement)
    for (int i = 0; i < s1.length(); i++) {
        if (isupper(s1[i])) s1[i] = tolower(s1[i]);
        if (isupper(s2[i])) s2[i] = tolower(s2[i]);
    }

    // Count frequency of characters
    for (int i = 0; i < s1.length(); i++) {
        count[0][s1[i] - 'a']++;
        count[1][s2[i] - 'a']++;
    }

    // Compare frequency counts
    for (int i = 0; i < 26; i++) {
        if (count[0][i] != count[1][i])
            return false;
    }

    return true;
}

int main() {
    string str1 = "Listen";
    string str2 = "Silent";

    if (areAnagrams(str1, str2))
        cout << "\"" << str1 << "\" and \"" << str2 << "\" are anagrams." << endl;
    else
        cout << "Not anagrams." << endl;

    return 0;
}