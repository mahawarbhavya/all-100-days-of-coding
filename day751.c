#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * File Append Mode - Add New Line Without Overwriting
 * 
 * LOGIC ENHANCERS:
 * 1. APPEND MODE "a": Adds to END of existing file
 * 2. fgets() SAFETY: Safe line input with max length
 * 3. BEFORE/AFTER PREVIEW: Show file state change
 * 4. LINE NUMBERING: Track total lines added
 * 5. ERROR HANDLING: File missing, write failure, empty input
 * 
 * Time: O(1) per append | Space: O(max_line_length)
 */
int main() {
    printf("=== FILE APPEND MODE ===\n");
    printf("Adds new line to END of existing file (\"a\" mode)\n\n");
    
    // Input filename
    char filename[256];
    printf("Enter filename to append to: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    
    if (strlen(filename) == 0) {
        printf("❌ ERROR: Filename cannot be empty!\n");
        return 1;
    }
    
    // Show file contents BEFORE appending
    printf("\n📄 BEFORE APPEND - Current contents:\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    FILE* preview = fopen(filename, "r");
    if (preview != NULL) {
        char line[1024];
        int line_num = 0;
        while (fgets(line, sizeof(line), preview) != NULL) {
            line_num++;
            int len = strlen(line);
            if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
            printf("%3d: %s\n", line_num, line);
        }
        fclose(preview);
        printf("   (Total: %d lines)\n", line_num);
    } else {
        printf("ℹ️  File '%s' does not exist yet - will be created!\n", filename);
    }
    printf("═══════════════════════════════════════════════════════\n");
    
    // Input new line to append
    char new_line[1024];
    printf("\n✏️  Enter text to append (press Enter twice to finish):\n");
    
    FILE* file = fopen(filename, "a");  // APPEND MODE
    if (file == NULL) {
        printf("❌ ERROR: Cannot open '%s' in append mode!\n", filename);
        printf("Check permissions and disk space.\n");
        return 1;
    }
    
    int lines_appended = 0;
    printf(">>> ");
    
    while (fgets(new_line, sizeof(new_line), stdin) != NULL) {
        // Remove trailing newline for clean display
        int len = strlen(new_line);
        if (len > 0 && new_line[len-1] == '\n') {
            new_line[len-1] = '\0';
        }
        
        // Skip empty lines (just Enter)
        if (strlen(new_line) == 0) {
            printf("✅ FINISHED! No more lines to append.\n");
            break;
        }
        
        // Append to file (fgets already removed \n, so add it back)
        fprintf(file, "%s\n", new_line);
        lines_appended++;
        
        // Confirmation
        printf("   ✓ Appended: \"%s\"\n", new_line);
        printf(">>> ");
    }
    
    // Close file
    if (fclose(file) != 0) {
        printf("⚠️  Warning: Error closing file!\n");
        return 1;
    }
    
    // Show file contents AFTER appending
    printf("\n📄 AFTER APPEND - Updated contents:\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    FILE* after_preview = fopen(filename, "r");
    if (after_preview != NULL) {
        char line[1024];
        int line_num = 0;
        while (fgets(line, sizeof(line), after_preview) != NULL) {
            line_num++;
            int len = strlen(line);
            if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
            printf("%3d: %s\n", line_num, line);
        }
        fclose(after_preview);
        printf("   (Total: %d lines, %d newly appended)\n", line_num, lines_appended);
    }
    
    // Success summary
    printf("═══════════════════════════════════════════════════════\n");
    printf("✅ APPEND OPERATION COMPLETED!\n");
    printf("📊 SUMMARY:\n");
    printf("   ├─ File:            '%s'\n", filename);
    printf("   ├─ Lines appended:  %d\n", lines_appended);
    printf("   └─ Mode used:       \"a\" (append)\n");
    
    if (lines_appended > 0) {
        printf("\n🎉 SUCCESS! %d new line(s) added to end of file.\n", lines_appended);
    } else {
        printf("\nℹ️  No lines were appended.\n");
    }
    
    printf("\n💾 File '%s' closed successfully!\n", filename);
    return 0;
}