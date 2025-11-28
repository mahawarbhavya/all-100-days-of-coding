#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int main() {
    struct Student *student;
    
    // Allocate memory dynamically
    student = (struct Student *)malloc(sizeof(struct Student));
    
    if (student == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", student->name);
    printf("Roll No: ");
    scanf("%d", &student->roll_no);
    printf("Marks: ");
    scanf("%f", &student->marks);
    
    printf("\n--- Student Details ---\n");
    printf("Name: %s\n", student->name);
    printf("Roll No: %d\n", student->roll_no);
    printf("Marks: %.2f\n", student->marks);
    
    // Free allocated memory
    free(student);
    
    return 0;
}