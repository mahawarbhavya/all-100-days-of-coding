#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Valid Anagram Check - O(n) Frequency Count
 * 
 * LOGIC ENHANCERS:
 * 1. FIXED ARRAY: 26 lowercase letters → O(1) space/time
 * 2. TWO PASS: Count s → Count t → Compare arrays
 * 3. EARLY TERMINATION: Length mismatch → immediate "Not Anagram"
 * 4. NO SORTING: Avoids O(n log n) overhead
 * 5. Handles edge cases: empty strings, different lengths
 * 
 * Time: O(n) | Space: O(1)
 */
int isAnagram(char* s, char* t) {
    // Early termination: different lengths
    if (strlen(s) != strlen(t)) {
        return 0;
    }
    
    int count[26] = {0};  // Frequency array for a-z
    
    // Count frequencies in s
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }
    
    // Decrement frequencies in t
    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i] - 'a']--;
    }
    
    // Check if all frequencies are zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

/**
 * Alternative: Sorting O(n log n) for verification
 */
int isAnagramSort(char* s, char* t) {
    if (strlen(s) != strlen(t)) return 0;
    
    int len = strlen(s);
    char* s_copy = (char*)malloc((len + 1) * sizeof(char));
    char* t_copy = (char*)malloc((len + 1) * sizeof(char));
    
    strcpy(s_copy, s);
    strcpy(t_copy, t);
    
    // Bubble sort both strings
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (s_copy[j] > s_copy[j + 1]) {
                char temp = s_copy[j];
                s_copy[j] = s_copy[j + 1];
                s_copy[j + 1] = temp;
            }
            if (t_copy[j] > t_copy[j + 1]) {
                char temp = t_copy[j];
                t_copy[j] = t_copy[j + 1];
                t_copy[j + 1] = temp;
            }
        }
    }
    
    int result = (strcmp(s_copy, t_copy) == 0);
    free(s_copy);
    free(t_copy);
    return result;
}

/**
 * Print frequency visualization
 */
void printFrequency(char* s, char* t) {
    int count[26] = {0};
    
    printf("s frequency: ");
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c:%d ", 'a' + i, count[i]);
        }
    }
    
    memset(count, 0, sizeof(count));
    printf("\nt frequency: ");
    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c:%d ", 'a' + i, count[i]);
        }
    }
    printf("\n");
}

/**
 * Verify correctness
 */
int verifyAnagram(char* s, char* t, int result) {
    return (result == isAnagramSort(s, t));
}

/**
 * Interactive input
 */
void readStrings(char** s, char** t) {
    int len_s = 100, len_t = 100;
    *s = (char*)malloc(len_s * sizeof(char));
    *t = (char*)malloc(len_t * sizeof(char));
    
    if (*s == NULL || *t == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Enter string s: ");
    fgets(*s, len_s, stdin);
    (*s)[strcspn(*s, "\n")] = 0;  // Remove newline
    
    printf("Enter string t: ");
    fgets(*t, len_t, stdin);
    (*t)[strcspn(*t, "\n")] = 0;  // Remove newline
}

/**
 * Comprehensive test harness
 */
int main() {
    printf("=== VALID ANAGRAM CHECK ===\n");
    printf("O(n) Frequency Count Algorithm\n");
    printf("Fixed 26-array for lowercase letters\n\n");
    
    // Test cases
    struct TestCase {
        char* s;
        char* t;
        int expected;
    };
    
    struct TestCase test_cases[] = {
        {"anagram", "nagaram", 1},
        {"rat", "car", 0},
        {"", "", 1},
        {"a", "a", 1},
        {"ab", "ba", 1},
        {"abc", "abcd", 0},
        {"abcdef", "fedcba", 1},
        {"aabbcc", "abcabc", 1},
        {"abc", "cba", 1},
        {"aa", "bb", 0},
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-12s | %-12s | %-10s | %-10s\n", "s", "t", "Result", "Verified");
    printf("%-12s-+-%-12s-+-%-10s-+-%-10s\n", "------------", "------------", "----------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        int result = isAnagram(test_cases[i].s, test_cases[i].t);
        int valid = verifyAnagram(test_cases[i].s, test_cases[i].t, result);
        
        printf("%-12s | %-12s | %-10s | %s\n",
               test_cases[i].s, test_cases[i].t,
               result ? "Anagram" : "Not Anagram",
               valid ? "✓ PASS" : "✗ FAIL");
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    char* s, *t;
    readStrings(&s, &t);
    
    int result = isAnagram(s, t);
    printf("s: \"%s\"\n", s);
    printf("t: \"%s\"\n", t);
    printf("Result: %s\n", result ? "Anagram" : "Not Anagram");
    
    int valid = verifyAnagram(s, t, result);
    printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
    
    if (result) {
        printf("Frequency Check:\n");
        printFrequency(s, t);
    }
    
    free(s);
    free(t);
    return 0;
}