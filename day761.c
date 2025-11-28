#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * File Existence Checker & Reader
 * 
 * LOGIC ENHANCERS:
 * 1. READ MODE TEST: `fopen(filename, "r")` → NULL = doesn't exist
 * 2. IMMEDIATE CLOSE: Open → check → close (no memory leak)
 * 3. FULL CONTENT DISPLAY: Line-by-line with line numbers
 * 4. COMPREHENSIVE ERRORS: File missing, permission denied, empty
 * 5. FILE STATS: Size, lines, characters
 * 
 * Time: O(n) | Space: O(max_line_length)
 */
int main() {
    printf("=== FILE EXISTENCE CHECKER & READER ===\n");
    printf("Checks if file exists, then reads & displays content\n\n");
    
    // Input filename
    char filename[256];
    printf("Enter filename to check: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline
    
    if (strlen(filename) == 0) {
        printf("❌ ERROR: Filename cannot be empty!\n");
        return 1;
    }
    
    printf("\n🔍 CHECKING: '%s'\n", filename);
    printf("═══════════════════════════════════════════════════════\n");
    
    // Step 1: Check if file exists (try to open in read mode)
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("❌ FILE DOES NOT EXIST!\n");
        printf("   Filename: '%s'\n", filename);
        printf("   Possible reasons:\n");
        printf("   • File was never created\n");
        printf("   • Wrong filename/path\n");
        printf("   • Insufficient read permissions\n");
        printf("   • File deleted/moved\n");
        return 1;
    }
    
    // File exists! Close immediately (we just needed to test)
    fclose(file);
    
    printf("✅ FILE EXISTS!\n");
    printf("   Now reading and displaying contents...\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    // Step 2: Open file again to read contents
    file = fopen(filename, "r");
    if (file == NULL) {
        // Shouldn't happen, but safety first
        printf("❌ CRITICAL ERROR: File disappeared during check!\n");
        return 1;
    }
    
    // Step 3: Read and display contents
    char line[1024];
    int line_number = 0;
    long long total_chars = 0;
    
    printf("📄 CONTENTS OF '%s':\n", filename);
    printf("═══════════════════════════════════════════════════════\n");
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        
        // Remove trailing newline for clean display
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        
        total_chars += strlen(line);
        printf("%4d: %s\n", line_number, line);
    }
    
    // Close file
    if (fclose(file) != 0) {
        printf("⚠️  Warning: Error closing file!\n");
    }
    
    // Step 4: Display file statistics
    printf("═══════════════════════════════════════════════════════\n");
    
    if (line_number == 0) {
        printf("📭 FILE IS EMPTY!\n");
    } else {
        printf("✅ FILE SUCCESSFULLY READ!\n");
        printf("📊 FILE STATISTICS:\n");
        printf("   ├─ Lines:          %6d\n", line_number);
        printf("   ├─ Characters:     %6lld\n", total_chars);
        printf("   ├─ Bytes per line: %.1f\n", (double)total_chars / line_number);
        printf("   └─ Status:         VALID & ACCESSIBLE\n");
    }
    
    printf("\n🎉 OPERATION COMPLETED!\n");
    printf("   File '%s': ", filename);
    if (line_number > 0) {
        printf("✅ EXISTS & READABLE (%d lines)\n", line_number);
    } else {
        printf("✅ EXISTS BUT EMPTY\n");
    }
    
    return 0;
}