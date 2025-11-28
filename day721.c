#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Read File Line-by-Line using fgets() - Until EOF
 * 
 * LOGIC ENHANCERS:
 * 1. fgets() SAFETY: Reads exact line length, handles long lines
 * 2. EOF DETECTION: `NULL` return from fgets()
 * 3. LINE NUMBERING: Track & display line numbers
 * 4. FILE SIZE: Display total lines & characters
 * 5. ERROR HANDLING: File not found, permission denied
 * 
 * Time: O(n) | Space: O(max_line_length)
 */
int main() {
    printf("=== FILE READER ===\n");
    printf("Reads info.txt line-by-line using fgets()\n\n");
    
    // Open existing file for reading
    FILE* file = fopen("info.txt", "r");
    if (file == NULL) {
        printf("❌ ERROR: Cannot open 'info.txt'!\n");
        printf("Possible causes:\n");
        printf("  • File does not exist\n");
        printf("  • Insufficient permissions\n");
        printf("  • File is locked by another process\n");
        return 1;
    }
    
    // Read & display file contents
    char line[1024];  // Max line length + 1 for null terminator
    int line_number = 0;
    int total_chars = 0;
    int total_lines = 0;
    
    printf("📄 Contents of 'info.txt':\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        total_lines++;
        
        // Remove trailing newline for clean display
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        
        total_chars += strlen(line);
        
        // Print line with number
        printf("%3d: %s\n", line_number, line);
    }
    
    // Close file
    if (fclose(file) != 0) {
        printf("⚠️  Warning: Error closing file!\n");
    }
    
    // EOF reached - display statistics
    if (total_lines == 0) {
        printf("\n📭 File is empty!\n");
    } else {
        printf("═══════════════════════════════════════════════════════\n");
        printf("✅ SUCCESS! File read completely.\n");
        printf("📊 STATISTICS:\n");
        printf("   Lines: %d\n", total_lines);
        printf("   Characters: %d (excluding newlines)\n", total_chars);
        printf("   Last line number: %d\n", line_number);
    }
    
    printf("\n💾 File 'info.txt' closed successfully!\n");
    return 0;
}