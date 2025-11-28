#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Case Converter: input.txt → output.txt (lowercase → UPPERCASE)
 * 
 * LOGIC ENHANCERS:
 * 1. CHARACTER-BY-CHARACTER: `fgetc()` → `toupper()` → `fputc()`
 * 2. PRESERVE NON-LETTERS: Spaces, numbers, punctuation unchanged
 * 3. PROGRESS TRACKING: Real-time conversion display
 * 4. BEFORE/AFTER PREVIEW: Show original vs converted
 * 5. COMPREHENSIVE STATS: Letters converted, file size
 * 
 * Time: O(n) | Space: O(1)
 */
int main() {
    printf("=== CASE CONVERTER ===\n");
    printf("Converts input.txt (lowercase → UPPERCASE) → output.txt\n\n");
    
    // Step 1: Preview input.txt BEFORE conversion
    printf("📄 ORIGINAL input.txt:\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    FILE* input_preview = fopen("input.txt", "r");
    if (input_preview == NULL) {
        printf("❌ ERROR: 'input.txt' not found!\n");
        printf("Create input.txt first or check filename.\n");
        return 1;
    }
    
    char line[1024];
    printf("BEFORE CONVERSION:\n");
    int line_num = 0;
    while (fgets(line, sizeof(line), input_preview) != NULL) {
        line_num++;
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
        printf("%3d: %s\n", line_num, line);
    }
    fclose(input_preview);
    printf("   (Total: %d lines)\n", line_num);
    
    // Step 2: Open files for conversion
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    
    if (input == NULL) {
        printf("❌ CRITICAL: Cannot read input.txt!\n");
        return 1;
    }
    if (output == NULL) {
        printf("❌ CRITICAL: Cannot create output.txt!\n");
        fclose(input);
        return 1;
    }
    
    printf("\n🔄 CONVERTING: lowercase → UPPERCASE...\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    // Step 3: Character-by-character conversion
    int ch;
    long long total_chars = 0;
    long long converted_chars = 0;
    int progress_dot = 0;
    
    while ((ch = fgetc(input)) != EOF) {
        total_chars++;
        
        // Convert ONLY lowercase letters → uppercase
        if (ch >= 'a' && ch <= 'z') {
            ch = toupper(ch);
            converted_chars++;
        }
        
        fputc(ch, output);
        
        // Progress indicator
        if (total_chars % 50 == 0) {
            printf(".");
            fflush(stdout);
            progress_dot++;
        }
    }
    
    // Close files
    if (fclose(input) != 0) {
        printf("\n⚠️  Warning: Error closing input file!\n");
    }
    if (fclose(output) != 0) {
        printf("\n⚠️  Warning: Error closing output file!\n");
    }
    
    printf("\n\n✅ CONVERSION COMPLETED!\n");
    
    // Step 4: Preview output.txt AFTER conversion
    printf("\n📄 RESULT output.txt:\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    FILE* output_preview = fopen("output.txt", "r");
    if (output_preview != NULL) {
        line_num = 0;
        while (fgets(line, sizeof(line), output_preview) != NULL) {
            line_num++;
            int len = strlen(line);
            if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
            printf("%3d: %s\n", line_num, line);
        }
        fclose(output_preview);
        printf("   (Total: %d lines)\n", line_num);
    }
    
    // Step 5: Display statistics
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("📊 CONVERSION STATISTICS:\n");
    printf("   ├─ Total characters:     %10lld\n", total_chars);
    printf("   ├─ Letters converted:    %10lld\n", converted_chars);
    printf("   ├─ Conversion rate:      %7.1f%%\n", 
           total_chars > 0 ? (double)converted_chars / total_chars * 100 : 0);
    printf("   ├─ Input file:           input.txt\n");
    printf("   └─ Output file:          output.txt\n");
    
    if (converted_chars > 0) {
        printf("\n🎉 SUCCESS! %lld lowercase letters converted to UPPERCASE!\n", converted_chars);
    } else {
        printf("\nℹ️  No lowercase letters found - file unchanged.\n");
    }
    
    printf("\n💾 Files closed. Conversion finished!\n");
    return 0;
}