#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Create info.txt with User Name and Age - File I/O with Error Handling
 * 
 * LOGIC ENHANCERS:
 * 1. FILE SAFETY: Check if file opened successfully
 * 2. INPUT VALIDATION: Verify age is reasonable (0-150)
 * 3. FORMATTED OUTPUT: Clean, readable file format
 * 4. CONFIRMATION: Display success message with data preview
 * 5. ERROR RECOVERY: Graceful exit on failure
 * 
 * Time: O(1) | Space: O(1)
 */
int main() {
    printf("=== USER INFO SAVER ===\n");
    printf("Creates info.txt with your name and age\n\n");
    
    // Variables
    char name[100];
    int age;
    FILE* file;
    
    // Input: User's name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline
    
    if (strlen(name) == 0) {
        printf("Error: Name cannot be empty!\n");
        return 1;
    }
    
    // Input: User's age with validation
    printf("Enter your age: ");
    if (scanf("%d", &age) != 1 || age < 0 || age > 150) {
        printf("Error: Invalid age! Please enter 0-150.\n");
        return 1;
    }
    
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    // Create/overwrite info.txt in write mode
    file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Error: Cannot create info.txt!\n");
        printf("Check permissions or disk space.\n");
        return 1;
    }
    
    // Write formatted data to file using fprintf()
    fprintf(file, "=== USER INFORMATION ===\n");
    fprintf(file, "Name: %s\n", name);
    fprintf(file, "Age: %d\n", age);
    fprintf(file, "Date: %s", __DATE__);
    fprintf(file, "Time: %s\n", __TIME__);
    fprintf(file, "========================\n");
    
    // Close file
    if (fclose(file) != 0) {
        printf("Warning: Error closing file!\n");
        return 1;
    }
    
    // Success confirmation
    printf("\n✅ SUCCESS! Data saved to info.txt\n");
    printf("📄 File contents:\n");
    printf("   === USER INFORMATION ===\n");
    printf("   Name: %s\n", name);
    printf("   Age: %d\n", age);
    printf("   Date: %s\n", __DATE__);
    printf("   Time: %s\n", __TIME__);
    printf("========================\n");
    
    printf("\n💾 File 'info.txt' created successfully!\n");
    
    return 0;
}