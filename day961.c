#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int emp_id;
    float salary;
    struct Date joining_date;
};

int main() {
    struct Employee emp;
    
    printf("Enter employee details:\n");
    printf("Name: ");
    scanf("%s", emp.name);
    printf("Employee ID: ");
    scanf("%d", &emp.emp_id);
    printf("Salary: ");
    scanf("%f", &emp.salary);
    
    printf("Joining Date:\n");
    printf("Day: ");
    scanf("%d", &emp.joining_date.day);
    printf("Month: ");
    scanf("%d", &emp.joining_date.month);
    printf("Year: ");
    scanf("%d", &emp.joining_date.year);
    
    printf("\n--- Employee Details ---\n");
    printf("Name: %s\n", emp.name);
    printf("Employee ID: %d\n", emp.emp_id);
    printf("Salary: %.2f\n", emp.salary);
    printf("Joining Date: %02d/%02d/%d\n", 
           emp.joining_date.day, 
           emp.joining_date.month, 
           emp.joining_date.year);
    
    return 0;
}