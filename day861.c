#include <stdio.h>

enum MenuChoice {
    ADD,
    SUBTRACT,
    MULTIPLY,
    EXIT
};

int main() {
    enum MenuChoice choice = ADD;
    int a = 10, b = 5;
    
    switch (choice) {
        case ADD:
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case SUBTRACT:
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case MULTIPLY:
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case EXIT:
            printf("Exiting...\n");
            break;
    }
    
    return 0;
}