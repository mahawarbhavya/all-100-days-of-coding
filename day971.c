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
    FILE *file;
    
    // Write to file
    file = fopen("employees.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    printf("Enter employee details:\n");
    printf("Name: ");
    scanf("%s", emp.name);
    printf("Employee ID: ");
    scanf("%d", &emp.emp_id);
    printf("Salary: ");
    scanf("%f", &emp.salary);
    printf("Joining Date (dd mm yyyy): ");
    scanf("%d %d %d", &emp.joining_date.day, 
          &emp.joining_date.month, &emp.joining_date.year);
    
    fwrite(&emp, sizeof(struct Employee), 1, file);
    fclose(file);
    printf("Employee data written to file.\n");
    
    // Read from file
    file = fopen("employees.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    struct Employee readEmp;
    fread(&readEmp, sizeof(struct Employee), 1, file);
    fclose(file);
    
    printf("\n--- Read Employee Details ---\n");
    printf("Name: %s\n", readEmp.name);
    printf("Employee ID: %d\n", readEmp.emp_id);
    printf("Salary: %.2f\n", readEmp.salary);
    printf("Joining Date: %02d/%02d/%d\n", 
           readEmp.joining_date.day, 
           readEmp.joining_date.month, 
           readEmp.joining_date.year);
    
    return 0;
}