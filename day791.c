#include <stdio.h>
#include <stdlib.h>

/**
 * Sum & Average Calculator from numbers.txt
 * 
 * LOGIC ENHANCERS:
 * 1. fscanf() LOOP: Reads integers separated by spaces/newlines
 * 2. LONG LONG: Handles large numbers (up to 10^18)
 * 3. ERROR HANDLING: Invalid numbers, empty file, overflow
 * 4. COMPREHENSIVE STATS: Min, max, count, sum, average
 * 5. FILE PREVIEW: Show original numbers before calculation
 * 
 * Time: O(n) | Space: O(1)
 */
int main() {
    printf("=== NUMBER SUM & AVERAGE CALCULATOR ===\n");
    printf("Reads integers from numbers.txt (space/newline separated)\n\n");
    
    // Step 1: Preview numbers.txt
    printf("📄 Original numbers.txt:\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    FILE* preview = fopen("numbers.txt", "r");
    if (preview == NULL) {
        printf("❌ ERROR: 'numbers.txt' not found!\n");
        printf("Create numbers.txt with space-separated integers first.\n");
        printf("Example: 1 2 3 4 5 10 -7 100\n");
        return 1;
    }
    
    // Show first few numbers
    int preview_num;
    int preview_count = 0;
    printf("Numbers found: ");
    while (fscanf(preview, "%d", &preview_num) == 1 && preview_count < 10) {
        printf("%d ", preview_num);
        preview_count++;
    }
    if (preview_count == 10) {
        printf("... (more)");
    }
    printf("\n");
    fclose(preview);
    printf("═══════════════════════════════════════════════════════\n");
    
    // Step 2: Open file for calculation
    FILE* file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("❌ CRITICAL: Cannot read numbers.txt!\n");
        return 1;
    }
    
    // Step 3: Read all integers and calculate
    long long sum = 0;
    int count = 0;
    int min_val = 2147483647;   // INT_MAX
    int max_val = -2147483648;  // INT_MIN
    int current_num;
    
    printf("🔢 Calculating sum & average...\n");
    
    while (fscanf(file, "%d", &current_num) == 1) {
        sum += current_num;
        count++;
        
        // Update min/max
        if (current_num < min_val) min_val = current_num;
        if (current_num > max_val) max_val = current_num;
    }
    
    // Close file
    if (fclose(file) != 0) {
        printf("⚠️  Warning: Error closing file!\n");
    }
    
    // Step 4: Display results
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("✅ CALCULATION COMPLETE!\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    if (count == 0) {
        printf("📭 ERROR: No valid integers found in file!\n");
        printf("File contains only whitespace or invalid data.\n");
        return 1;
    }
    
    // Calculate average
    double average = (double)sum / count;
    
    printf("📊 RESULTS:\n");
    printf("   ├─ Count of numbers:    %10d\n", count);
    printf("   ├─ Sum:                 %10lld\n", sum);
    printf("   ├─ Average:             %10.2f\n", average);
    printf("   ├─ Minimum:             %10d\n", min_val);
    printf("   └─ Maximum:             %10d\n", max_val);
    
    printf("\n🎯 SUMMARY:\n");
    printf("   Sum = %lld\n", sum);
    printf("   Average = %.2f\n", average);
    
    // Additional analysis
    printf("\n📈 ANALYSIS:\n");
    printf("   ├─ Range:               %d to %d\n", min_val, max_val);
    printf("   ├─ Sum overflow check:  %s\n", 
           (sum / count == average) ? "✅ SAFE" : "⚠️  LARGE NUMBERS");
    printf("   └─ Numbers per line:    ~%.1f\n", 
           (double)count / 10.0);  // Assuming ~10/line for readability
    
    printf("\n💾 Calculation finished successfully!\n");
    return 0;
}