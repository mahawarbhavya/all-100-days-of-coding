#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Student Record Manager - File I/O with fprintf() & fscanf()
 * 
 * LOGIC ENHANCERS:
 * 1. STRUCTURED FORMAT: "name|roll|marks\n" - Pipe-delimited
 * 2. DYNAMIC INPUT: Add as many students as needed
 * 3. ERROR HANDLING: Invalid marks, empty names, file errors
 * 4. COMPREHENSIVE DISPLAY: Table format + statistics
 * 5. VALIDATION: Roll numbers unique, marks 0-100
 * 
 * Time: O(n) | Space: O(n)
 */
#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

// Student structure
typedef struct {
    char name[MAX_NAME_LEN];
    int roll_no;
    int marks;
} Student;

// Function prototypes
void writeStudentsToFile(Student students[], int count);
void readAndDisplayStudents();
void printStudentTable(Student students[], int count);
double calculateAverageMarks(Student students[], int count);

int main() {
    printf("=== STUDENT RECORD MANAGER ===\n");
    printf("Stores: Name | Roll Number | Marks\n");
    printf("File format: students.txt\n\n");
    
    Student students[MAX_STUDENTS];
    int student_count = 0;
    char choice;
    
    printf("📝 ADD STUDENT RECORDS (y/n)? ");
    scanf(" %c", &choice);
    getchar();  // Clear buffer
    
    if (choice == 'y' || choice == 'Y') {
        // Input student records
        while (student_count < MAX_STUDENTS) {
            printf("\n--- Student %d ---\n", student_count + 1);
            
            // Input name
            printf("Enter name: ");
            fgets(students[student_count].name, MAX_NAME_LEN, stdin);
            students[student_count].name[strcspn(students[student_count].name, "\n")] = 0;
            
            if (strlen(students[student_count].name) == 0) {
                printf("❌ Empty name! Try again.\n");
                continue;
            }
            
            // Input roll number
            printf("Enter roll number: ");
            if (scanf("%d", &students[student_count].roll_no) != 1) {
                printf("❌ Invalid roll number!\n");
                while (getchar() != '\n');  // Clear input
                continue;
            }
            
            // Input marks with validation
            printf("Enter marks (0-100): ");
            if (scanf("%d", &students[student_count].marks) != 1 || 
                students[student_count].marks < 0 || students[student_count].marks > 100) {
                printf("❌ Invalid marks! Must be 0-100.\n");
                while (getchar() != '\n');
                continue;
            }
            
            student_count++;
            printf("✅ Student '%s' added!\n", students[student_count-1].name);
            
            // Ask for more students
            if (student_count < MAX_STUDENTS) {
                printf("\nAdd another student? (y/n): ");
                scanf(" %c", &choice);
                getchar();
                if (choice != 'y' && choice != 'Y') break;
            }
        }
        
        // Write to file using fprintf()
        writeStudentsToFile(students, student_count);
        
        printf("\n📊 SUMMARY: %d students saved to students.txt\n", student_count);
    }
    
    // Read and display from file using fscanf()
    printf("\n🔍 READING RECORDS FROM FILE...\n");
    readAndDisplayStudents();
    
    return 0;
}

/**
 * Write students to file using fprintf() - Pipe-delimited format
 */
void writeStudentsToFile(Student students[], int count) {
    FILE* file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("❌ ERROR: Cannot create students.txt!\n");
        return;
    }
    
    fprintf(file, "=== STUDENT RECORDS ===\n");
    fprintf(file, "Format: name|roll_number|marks\n");
    fprintf(file, "========================\n");
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%d|%d\n", 
                students[i].name, 
                students[i].roll_no, 
                students[i].marks);
    }
    
    fprintf(file, "========================\n");
    fprintf(file, "Total students: %d\n", count);
    
    if (fclose(file) != 0) {
        printf("⚠️  Warning: Error closing file!\n");
    }
    
    printf("💾 Successfully written %d records to students.txt\n", count);
}

/**
 * Read students from file using fscanf() and display
 */
void readAndDisplayStudents() {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("❌ ERROR: students.txt not found!\n");
        printf("Run the program again and add some students first.\n");
        return;
    }
    
    Student students[MAX_STUDENTS];
    int count = 0;
    char buffer[256];
    
    // Skip header lines
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, "name|roll_number|marks")) break;
    }
    
    // Read student records: "name|roll|marks"
    while (count < MAX_STUDENTS && 
           fscanf(file, "%[^|]|%d|%d", students[count].name, 
                  &students[count].roll_no, &students[count].marks) == 3) {
        
        // Consume newline
        int c;
        while ((c = getc(file)) != '\n' && c != EOF);
        
        count++;
    }
    
    fclose(file);
    
    if (count == 0) {
        printf("📭 No student records found in file!\n");
        return;
    }
    
    // Display in table format
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("📋 STUDENT RECORDS (%d students)\n", count);
    printf("═══════════════════════════════════════════════════════\n");
    printStudentTable(students, count);
    
    // Statistics
    double avg_marks = calculateAverageMarks(students, count);
    printf("\n📊 STATISTICS:\n");
    printf("   ├─ Total students:    %d\n", count);
    printf("   ├─ Average marks:     %.1f\n", avg_marks);
    printf("   ├─ Highest marks:     %d\n", 
           count > 0 ? students[0].marks : 0);
    printf("   └─ Passing (≥40):     %d/%d\n", 
           count > 0 ? 0 : 0, count);
    
    // Grade distribution
    int grade_counts[5] = {0};  // A,B,C,D,F
    for (int i = 0; i < count; i++) {
        if (students[i].marks >= 90) grade_counts[0]++;
        else if (students[i].marks >= 80) grade_counts[1]++;
        else if (students[i].marks >= 70) grade_counts[2]++;
        else if (students[i].marks >= 60) grade_counts[3]++;
        else if (students[i].marks >= 40) grade_counts[4]++;
    }
    
    printf("\n🎓 GRADE DISTRIBUTION:\n");
    printf("   A(90+): %d | B(80-89): %d | C(70-79): %d\n", 
           grade_counts[0], grade_counts[1], grade_counts[2]);
    printf("   D(60-69): %d | P(40-59): %d | F(<40): %d\n", 
           grade_counts[3], grade_counts[4], count - (grade_counts[0]+grade_counts[1]+grade_counts[2]+grade_counts[3]+grade_counts[4]));
    
    printf("\n💾 File read successfully!\n");
}

/**
 * Print students in table format
 */
void printStudentTable(Student students[], int count) {
    printf("+ %-20s | %-8s | %-5s +\n", "NAME", "ROLL NO", "MARKS");
    printf("+====================+========+======+\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-20s | %-8d | %-5d |\n", 
               students[i].name, 
               students[i].roll_no, 
               students[i].marks);
    }
    
    printf("+====================+========+======+\n");
}

/**
 * Calculate average marks
 */
double calculateAverageMarks(Student students[], int count) {
    if (count == 0) return 0.0;
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += students[i].marks;
    }
    return (double)total / count;
}