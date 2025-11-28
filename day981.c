#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int areIdentical(struct Student s1, struct Student s2) {
    return (strcmp(s1.name, s2.name) == 0 &&
            s1.roll_no == s2.roll_no &&
            s1.marks == s2.marks);
}

int main() {
    struct Student student1, student2;
    
    printf("Enter details for Student 1:\n");
    printf("Name: ");
    scanf("%s", student1.name);
    printf("Roll No: ");
    scanf("%d", &student1.roll_no);
    printf("Marks: ");
    scanf("%f", &student1.marks);
    
    printf("\nEnter details for Student 2:\n");
    printf("Name: ");
    scanf("%s", student2.name);
    printf("Roll No: ");
    scanf("%d", &student2.roll_no);
    printf("Marks: ");
    scanf("%f", &student2.marks);
    
    printf("\n--- Student Details ---\n");
    printf("Student 1: %s, Roll: %d, Marks: %.2f\n", 
           student1.name, student1.roll_no, student1.marks);
    printf("Student 2: %s, Roll: %d, Marks: %.2f\n", 
           student2.name, student2.roll_no, student2.marks);
    
    if (areIdentical(student1, student2)) {
        printf("\nBoth students are IDENTICAL.\n");
    } else {
        printf("\nStudents are NOT identical.\n");
    }
    
    return 0;
}