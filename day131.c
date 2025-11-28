//Q25: Write a program to implement a basic calculator using switch-case for +, -, *, /, %.

/*
Sample Test Cases:
Input 1:
4 2 +
Output 1:
6

Input 2:
10 3 %
Output 2:
1

Input 3:
15 5 /
Output 3:
3

*/
#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    // Input two numbers and operator
    printf("=== BASIC CALCULATOR ===\n");
    printf("Enter first number : ");
    scanf("%f", &num1);

    printf("Enter an operator (+, -, *, /, %): ");
    scanf(" %c", &operator);  // Note space before %c to consume newline

    printf("Enter second number: ");
    scanf("%f", &num2);

    // Perform calculation using switch-case
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("\nResult: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
            else {
                printf("\nError: Division by zero is not allowed!\n");
            }
            break;

        case '%':
            // Modulus works only with integers
            if ((int)num2 != 0) {
                result = (int)num1 % (int)num2;
                printf("\nResult: %d %% %d = %.0f\n", (int)num1, (int)num2, result);
            }
            else {
                printf("\nError: Modulus by zero is not allowed!\n");
            }
            break;

        default:
            printf("\nError: Invalid operator! Please use +, -, *, /, or %%\n");
    }

    return 0;
}