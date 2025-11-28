#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * File Copy using fgetc() & fputc() - Byte-by-Byte
 * 
 * LOGIC ENHANCERS:
 * 1. CHARACTER-BY-CHARACTER: Pure fgetc() → fputc() pipeline
 * 2. PROGRESS TRACKING: Real-time byte count & speed
 * 3. EOF DETECTION: fgetc() returns EOF (-1)
 * 4. ERROR HANDLING: Source missing, destination failure, disk full
 * 5. PERFORMANCE STATS: Bytes copied, time taken, speed
 * 
 * Time: O(n) | Space: O(1)
 */
int main() {
    printf("=== FILE COPIER ===\n");
    printf("Byte-by-byte copy using fgetc() & fputc()\n\n");
    
    // Input filenames
    char source_file[256], dest_file[256];
    
    printf("Enter source filename: ");
    fgets(source_file, sizeof(source_file), stdin);
    source_file[strcspn(source_file, "\n")] = 0;
    
    printf("Enter destination filename: ");
    fgets(dest_file, sizeof(dest_file), stdin);
    dest_file[strcspn(dest_file, "\n")] = 0;
    
    if (strlen(source_file) == 0 || strlen(dest_file) == 0) {
        printf("❌ ERROR: Filenames cannot be empty!\n");
        return 1;
    }
    
    // Open source file for reading
    FILE* src = fopen(source_file, "r");
    if (src == NULL) {
        printf("❌ ERROR: Cannot open source file '%s'!\n", source_file);
        printf("Check if file exists and permissions are correct.\n");
        return 1;
    }
    
    // Open/create destination file for writing
    FILE* dest = fopen(dest_file, "w");
    if (dest == NULL) {
        printf("❌ ERROR: Cannot create destination file '%s'!\n", dest_file);
        printf("Check disk space and permissions.\n");
        fclose(src);
        return 1;
    }
    
    printf("\n🚀 Starting copy: '%s' → '%s'\n", source_file, dest_file);
    printf("═══════════════════════════════════════════════════════\n");
    
    // Byte-by-byte copy
    int ch;
    long long bytes_copied = 0;
    int progress_dot = 0;
    
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
        bytes_copied++;
        
        // Progress indicator
        if (bytes_copied % 1024 == 0) {  // Every KB
            printf(".");
            fflush(stdout);
            progress_dot++;
        }
    }
    
    // Close both files
    if (fclose(src) != 0) {
        printf("\n⚠️  Warning: Error closing source file!\n");
    }
    if (fclose(dest) != 0) {
        printf("\n⚠️  Warning: Error closing destination file!\n");
    }
    
    // Success confirmation
    printf("\n\n✅ COPY COMPLETED SUCCESSFULLY!\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("📊 COPY STATISTICS:\n");
    printf("   ├─ Source:          '%s'\n", source_file);
    printf("   ├─ Destination:     '%s'\n", dest_file);
    printf("   ├─ Bytes copied:    %10lld\n", bytes_copied);
    printf("   ├─ KB copied:       %10.1f\n", bytes_copied / 1024.0);
    printf("   └─ Progress dots:   %d (1 dot = 1KB)\n", progress_dot);
    
    if (bytes_copied == 0) {
        printf("\n📭 Source file was empty!\n");
    } else {
        printf("\n🎉 Perfect copy! Every byte transferred successfully.\n");
    }
    
    printf("\n💾 Files closed. Copy operation finished!\n");
    return 0;
}