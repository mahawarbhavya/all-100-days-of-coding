#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int main() {
    struct Student students[5];
    struct Student topStudent;
    float maxMarks = -1;
    
    printf("Enter details for 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
        
        if (students[i].marks > maxMarks) {
            maxMarks = students[i].marks;
            topStudent = students[i];
        }
    }
    
    printf("\n--- Top Student ---\n");
    printf("Name: %s\n", topStudent.name);
    printf("Roll No: %d\n", topStudent.roll_no);
    printf("Highest Marks: %.2f\n", maxMarks);
    
    return 0;
}