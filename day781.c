#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Vowel & Consonant Counter - Case Insensitive
 * 
 * LOGIC ENHANCERS:
 * 1. CASE INSENSITIVE: `toupper()` for uniform counting
 * 2. VOWEL SET: 'A','E','I','O','U' (both cases handled)
 * 3. IGNORE NON-LETTERS: Digits, punctuation, spaces skipped
 * 4. SINGLE PASS: O(n) time, counts everything
 * 5. DETAILED STATS: Percentage, ratio, letter distribution
 * 
 * Time: O(n) | Space: O(1)
 */
int main() {
    printf("=== VOWEL & CONSONANT COUNTER ===\n");
    printf("Ignores digits, spaces, and special characters\n\n");
    
    // Open file
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("❌ ERROR: 'input.txt' not found!\n");
        printf("Create input.txt first with some text.\n");
        return 1;
    }
    
    // Counters
    long long vowels = 0;
    long long consonants = 0;
    long long total_letters = 0;
    long long total_chars = 0;
    long long ignored_chars = 0;
    
    // Vowel frequency (case insensitive)
    long long vowel_count[5] = {0};  // A,E,I,O,U
    
    int ch;
    printf("🔍 Analyzing 'input.txt'...\n");
    
    // Character-by-character analysis
    while ((ch = fgetc(file)) != EOF) {
        total_chars++;
        
        // Convert to uppercase for uniform counting
        ch = toupper(ch);
        
        // Count ONLY alphabetic characters
        if (isalpha(ch)) {
            total_letters++;
            
            // Check for vowels
            switch (ch) {
                case 'A': vowel_count[0]++; vowels++; break;
                case 'E': vowel_count[1]++; vowels++; break;
                case 'I': vowel_count[2]++; vowels++; break;
                case 'O': vowel_count[3]++; vowels++; break;
                case 'U': vowel_count[4]++; vowels++; break;
                default:  consonants++; break;  // All other letters
            }
        } else {
            ignored_chars++;  // Digits, spaces, punctuation
        }
    }
    
    // Close file
    if (fclose(file) != 0) {
        printf("⚠️  Warning: Error closing file!\n");
    }
    
    // Calculate percentages
    double vowel_percent = total_letters > 0 ? 
                          (double)vowels / total_letters * 100 : 0;
    double consonant_percent = total_letters > 0 ? 
                              (double)consonants / total_letters * 100 : 0;
    double vowel_consonant_ratio = consonants > 0 ? 
                                  (double)vowels / consonants : 0;
    
    // Display results
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("✅ ANALYSIS COMPLETE!\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("📊 LETTER COUNTS:\n");
    printf("   ├─ Vowels:      %10lld  (%.1f%%)\n", vowels, vowel_percent);
    printf("   ├─ Consonants:  %10lld  (%.1f%%)\n", consonants, consonant_percent);
    printf("   └─ Total letters:%10lld\n", total_letters);
    
    printf("\n🎯 VOWEL BREAKDOWN:\n");
    printf("   A: %4lld  | E: %4lld  | I: %4lld  | O: %4lld  | U: %4lld\n",
           vowel_count[0], vowel_count[1], vowel_count[2], 
           vowel_count[3], vowel_count[4]);
    
    printf("\n📈 FILE STATISTICS:\n");
    printf("   ├─ Total characters:  %10lld\n", total_chars);
    printf("   ├─ Ignored characters:%10lld\n", ignored_chars);
    printf("   └─ Letter density:    %.1f%%\n", 
           total_letters > 0 ? (double)total_letters / total_chars * 100 : 0);
    
    if (total_letters > 0) {
        printf("\n🎓 LINGUISTIC ANALYSIS:\n");
        printf("   ├─ Vowel/Consonant ratio:  %.2f:1\n", vowel_consonant_ratio);
        printf("   ├─ Expected ratio (English): ~0.4:1\n");
        
        if (vowel_percent >= 40 && vowel_percent <= 45) {
            printf("   └─ ✅ NORMAL English text!\n");
        } else if (vowel_percent > 45) {
            printf("   └─ 🗣️  Vowel-heavy (poetry/song?)\n");
        } else {
            printf("   └─ 🔤 Consonant-heavy (technical?)\n");
        }
    }
    
    printf("\n💾 Analysis finished!\n");
    return 0;
}