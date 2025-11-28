#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int main() {
    struct Student student;
    
    printf("Enter student name: ");
    scanf("%s", student.name);
    
    printf("Enter roll number: ");
    scanf("%d", &student.roll_no);
    
    printf("Enter marks: ");
    scanf("%f", &student.marks);
    
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Roll No: %d\n", student.roll_no);
    printf("Marks: %.2f\n", student.marks);
    
    return 0;
}