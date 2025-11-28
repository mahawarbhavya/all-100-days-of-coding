#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * Convert String to Sentence Case - O(n) Single Pass
 * 
 * LOGIC ENHANCERS:
 * 1. FIRST CHAR UPPERCASE: Capitalize first non-space character
 * 2. REST LOWERCASE: Convert all subsequent characters to lowercase
 * 3. PRESERVE SPACES: Keep original spacing intact
 * 4. Single pass: O(n) time, O(n) space (in-place possible)
 * 5. Handles edge cases: empty, all spaces, mixed case, numbers
 * 
 * Time: O(n) | Space: O(n)
 */
void toSentenceCase(char* s) {
    if (s == NULL || strlen(s) == 0) return;
    
    int n = strlen(s);
    int first_word = 1;  // Flag for first non-space character
    
    for (int i = 0; i < n; i++) {
        if (first_word && !isspace(s[i])) {
            // First non-space character → uppercase
            s[i] = toupper(s[i]);
            first_word = 0;
        } else if (!first_word) {
            // All subsequent characters → lowercase
            s[i] = tolower(s[i]);
        }
        // Spaces reset nothing (sentence case = one sentence)
    }
}

/**
 * Alternative: Multiple sentences (each sentence starts with uppercase)
 */
void toSentenceCaseMulti(char* s) {
    if (s == NULL || strlen(s) == 0) return;
    
    int n = strlen(s);
    int in_sentence = 0;
    
    for (int i = 0; i < n; i++) {
        if (isspace(s[i])) {
            in_sentence = 0;  // Potential sentence end
        } else if (!in_sentence) {
            // Start of new sentence
            s[i] = toupper(s[i]);
            in_sentence = 1;
        } else {
            // Inside sentence
            s[i] = tolower(s[i]);
        }
    }
}

/**
 * Print string with formatting
 */
void printString(char* s, const char* label) {
    printf("%s\"%s\"\n", label, s);
}

/**
 * Verify correctness (basic checks)
 */
int verifySentenceCase(char* original, char* result) {
    int n = strlen(original);
    
    // Check first non-space is uppercase
    int first_found = 0;
    for (int i = 0; i < n; i++) {
        if (!isspace(original[i])) {
            if (!isupper(result[i])) return 0;
            first_found = 1;
            break;
        }
    }
    
    // Check rest are lowercase (excluding first)
    if (first_found) {
        for (int i = 0; i < n; i++) {
            if (!isspace(original[i]) && !isspace(result[i])) {
                if (isupper(original[i]) && isupper(result[i])) {
                    // Skip the first uppercase
                    first_found = 0;
                } else if (!islower(result[i])) {
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

/**
 * Interactive input
 */
char* readString() {
    int len = 256;
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
    printf("=== SENTENCE CASE CONVERTER ===\n");
    printf("O(n) Single Pass Algorithm\n");
    printf("First letter UPPERCASE, rest lowercase\n\n");
    
    // Test cases
    struct TestCase {
        char* input;
        char* expected;
    };
    
    char test1[] = "hELLO wORLD";
    char test2[] = "tODAY iS gOOD";
    char test3[] = "  leading spaces  ";
    char test4[] = "ALL UPPERCASE";
    char test5[] = "mixed CaSe";
    char test6[] = "";
    char test7[] = "   ";
    char test8[] = "123 ABC def";
    
    struct TestCase test_cases[] = {
        {test1, "Hello world"},
        {test2, "Today is good"},
        {test3, "  Leading spaces  "},
        {test4, "All uppercase"},
        {test5, "Mixed case"},
        {test6, ""},
        {test7, "   "},
        {test8, "123 abc def"},
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("AUTOMATED TEST RESULTS:\n");
    printf("%-20s | %-20s | %-10s\n", "Input", "Output", "Verified");
    printf("%-20s-+-%-20s-+-%-10s\n", "--------------------", "--------------------", "----------");
    
    for (int i = 0; i < num_tests; i++) {
        char* input_copy = (char*)malloc(strlen(test_cases[i].input) + 1);
        strcpy(input_copy, test_cases[i].input);
        
        toSentenceCase(input_copy);
        
        int valid = verifySentenceCase(test_cases[i].input, input_copy);
        
        printf("%-20s | %-20s | %s\n",
               test_cases[i].input, input_copy,
               valid ? "✓ PASS" : "✗ FAIL");
        
        free(input_copy);
    }
    printf("\n");
    
    // Interactive mode
    printf("=== INTERACTIVE MODE ===\n");
    char* user_s = readString();
    
    if (user_s != NULL) {
        printf("Original:  ");
        printString(user_s, "");
        
        char* original = (char*)malloc(strlen(user_s) + 1);
        strcpy(original, user_s);
        
        toSentenceCase(user_s);
        printf("Sentence:  ");
        printString(user_s, "");
        
        int valid = verifySentenceCase(original, user_s);
        printf("    %s\n", valid ? "✓ VERIFIED" : "✗ ERROR");
        
        // Bonus: Multi-sentence version
        printf("\n=== MULTI-SENTENCE VERSION ===\n");
        strcpy(user_s, original);
        toSentenceCaseMulti(user_s);
        printf("Multi-sentence: ");
        printString(user_s, "");
        
        free(original);
        free(user_s);
    }
    
    return 0;
}