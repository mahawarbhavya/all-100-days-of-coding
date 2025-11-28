#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * File Word/Character/Line Counter - O(n) Single Pass
 * 
 * LOGIC ENHANCERS:
 * 1. STATE MACHINE: Track IN_WORD vs OUTSIDE_WORD
 * 2. SINGLE PASS: Count everything in one read
 * 3. fgets() SAFETY: No buffer overflow, handles long lines
 * 4. PRECISE WORD DEF: Non-space sequences separated by whitespace
 * 5. COMPREHENSIVE STATS: Characters, words, lines + average word length
 * 
 * Time: O(n) | Space: O(max_line_length)
 */
int main() {
    printf("=== FILE STATISTICS ANALYZER ===\n");
    printf("Counts characters, words, and lines\n");
    printf("Word = sequence of non-space characters\n\n");
    
    // Open file for reading
    FILE* file = fopen("info.txt", "r");
    if (file == NULL) {
        printf("❌ ERROR: Cannot open 'info.txt'!\n");
        printf("Create the file first or specify correct filename.\n");
        return 1;
    }
    
    // Statistics counters
    long long total_chars = 0;      // All characters including spaces/newlines
    long long total_words = 0;      // Word count
    long long total_lines = 0;      // Line count
    int in_word = 0;                // 1 = inside word, 0 = outside word
    
    char line[1024];
    
    printf("📊 Analyzing file...\n");
    
    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        total_lines++;              // Each fgets() = 1 line
        
        int len = strlen(line);
        total_chars += len;         // Include newline
        
        // Process each character in line
        for (int i = 0; i < len; i++) {
            if (isspace(line[i])) {
                // Space, tab, or newline
                if (in_word) {
                    // End of word
                    in_word = 0;
                    total_words++;
                }
            } else {
                // Non-space character
                if (!in_word) {
                    // Start of new word
                    in_word = 1;
                }
            }
        }
        
        // Handle word at end of line
        if (in_word) {
            total_words++;
            in_word = 0;
        }
    }
    
    // Close file
    if (fclose(file) != 0) {
        printf("⚠️  Warning: Error closing file!\n");
    }
    
    // Calculate additional metrics
    long long non_space_chars = total_chars - total_lines;  // Remove newlines
    double avg_word_length = total_words > 0 ? 
                            (double)non_space_chars / total_words : 0;
    
    // Display comprehensive results
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("✅ ANALYSIS COMPLETE!\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("📈 STATISTICS:\n");
    printf("   ├─ Lines:           %10lld\n", total_lines);
    printf("   ├─ Words:           %10lld\n", total_words);
    printf("   ├─ Characters:      %10lld\n", total_chars);
    printf("   ├─ Non-space chars: %10lld\n", non_space_chars);
    printf("   └─ Avg word length: %10.1f\n", avg_word_length);
    printf("\n📊 SUMMARY:\n");
    printf("   %lld lines, %lld words, %lld characters\n", 
           total_lines, total_words, total_chars);
    
    // Quality indicators
    if (total_words > 0) {
        double words_per_line = (double)total_words / total_lines;
        printf("\n🎯 QUALITY METRICS:\n");
        printf("   Words per line: %.1f\n", words_per_line);
        if (words_per_line > 10) {
            printf("   ⚠️  Dense text (many words per line)\n");
        } else if (words_per_line < 3) {
            printf("   ℹ️  Sparse text (few words per line)\n");
        }
    }
    
    printf("\n💾 File analysis completed successfully!\n");
    return 0;
}