#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

struct Student findTopStudent(struct Student students[], int size) {
    struct Student topStudent = students[0];
    
    for (int i = 1; i < size; i++) {
        if (students[i].marks > topStudent.marks) {
            topStudent = students[i];
        }
    }
    
    return topStudent;
}

int main() {
    struct Student students[5];
    
    printf("Enter details for 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }
    
    struct Student topStudent = findTopStudent(students, 5);
    
    printf("\n--- Top Student ---\n");
    printf("Name: %s\n", topStudent.name);
    printf("Roll No: %d\n", topStudent.roll_no);
    printf("Highest Marks: %.2f\n", topStudent.marks);
    
    return 0;
}