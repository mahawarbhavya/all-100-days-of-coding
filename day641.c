#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Longest Substring Without Repeating Characters - O(n) Sliding Window
 * 
 * LOGIC ENHANCERS:
 * 1. SLIDING WINDOW: left, right pointers with char set tracking
 * 2. ASCII ARRAY: O(1) duplicate detection (128 chars)
 * 3. EARLY SHRINK: Move left to last occurrence + 1 when duplicate found
 * 4. Single pass: O(n) time, O(1) space
 * 5. Handles edge cases: empty, single char, all unique, all duplicates
 * 
 * Time: O(n) | Space: O(1)
 */
int lengthOfLongestSubstring(char* s) {
    if (s == NULL) return 0;
    
    int n = strlen(s);
    if (n == 0) return 0;
    
    int char_index[128] = {0};  // Last seen index of each ASCII char
    for (int i = 0; i < 128; i++) char_index[i] = -1;
    
    int left = 0;
    int max_length = 0;
    
    for (int right = 0; right < n; right++) {
        // If duplicate found, shrink window
        if (char_index[(int)s[right]] >= left) {
            left = char_index[(int)s[right]] + 1;
        }
        
        // Update last seen index
        char_index[(int)s[right]] = right;
        
        // Update max length
        int current_length = right - left + 1;
        if (current_length > max_length) {
            max_length = current_length;
        }
    }
    
    return max_length;
}

/**
 * Brute Force O(n³) for verification
 */
int lengthOfLongestSubstringBrute(char* s) {
    int n = strlen(s);
    int max_len = 0;
    
    for (int i = 0; i < n; i++) {
        int seen[128] = {0};
        int current_len = 0;
        
        for (int j = i; j < n; j++) {
            if (seen[(int)s[j]]) {
                break;
            }
            seen[(int)s[j]] = 1;
            current_len++;
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
    }
    
    return max_len;
}

/**
 * Print substring visualization
 */
void printLongestSubstring(char* s, int max_len) {
    int n = strlen(s);
    int best_left = 0, best_right = 0;
    
    int char_index[128];
    for (int i = 0; i < 128; i++) char_index[i] = -1;
    
    int left = 0;
    int current_max = 0;
    
    for (int right = 0; right < n; right++) {
        if (char_index[(int)s[right]] >= left) {
            left = char_index[(int)s[right]] + 1;
        }
        char_index[(int)s[right]] = right;
        
        int current_len = right - left + 1;
        if (current_len > current_max) {
            current_max = current_len;
            best_left = left;
            best_right = right;
        }
    }
    
    if (max_len > 0) {
        printf("Longest: \"");
        for (int i = best_left; i <= best_right; i++) {
            printf("%c", s[i]);
        }
        printf("\" (length %d)\n", max_len);
    }
}

/**
 * Verify correctness
 */
int verifyLongestSubstring(char* s, int result) {
    return (result == lengthOfLongestSubstringBrute(s));
}

/**
 * Interactive input
 */
char* readString() {
    int len = 100;
    char* s = (char*)malloc(len * sizeof(char));
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    printf("Enter string: ");
    fgets(s, len, stdin);
    
    // Remove newline if present
    int n = strlen(s);
    if (n > 0 && s[n-1] == '\n') {
        s[n-1] = '\0';
    }
    
    return s;
}

/**
 * Comprehensive test harness
 */
int main() {
    printf("=== LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS ===\n");
    printf("O(n) Sliding Window Algorithm\n");
    printf("ASCII array for O(1) duplicate detection\n\n");
    
    // Test cases
    struct TestCase {
        char* s;
        int expected;
    };
    
    struct TestCase test_cases[] = {
        {"abcabcbb", 3},        // "abc"
        {"bbbbb", 1},           // "b"
        {"pwwkew", 3},          // "wke"
        {"", 0},                // empty
        {"abcdef", 6},          // all unique
        {"dvdf", 3},            // "vdf"
        {"a", 1},               // single
        {"abab", 2},            // "ab"
        {"tmmzuxt", 5},         // "mzuxt"
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-15s | %-10s | %-10s\n", "Input", "Sliding", "Verified");
    printf("%-15s-+-%-10s-+-%-10s\n", "---------------", "----------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        int result = lengthOfLongestSubstring(test_cases[i].s);
        int valid = verifyLongestSubstring(test_cases[i].s, result);
        
        printf("%-15s | %8d  | %s\n",
               test_cases[i].s, result,
               valid ? "✓ PASS" : "✗ FAIL");
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    char* user_s = readString();
    
    if (user_s != NULL && strlen(user_s) > 0) {
        int result = lengthOfLongestSubstring(user_s);
        printf("Input:  \"%s\"\n", user_s);
        printf("Length: %d\n", result);
        
        int valid = verifyLongestSubstring(user_s, result);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
        
        printLongestSubstring(user_s, result);
        
        free(user_s);
    }
    
    return 0;
}