#include <stdio.h>

enum Values {
    ZERO = 0,
    ONE = 1,
    TEN = 10,
    HUNDRED = 100,
    NEGATIVE = -5
};

int main() {
    printf("Enum values as integers:\n");
    printf("ZERO     = %d\n", ZERO);
    printf("ONE      = %d\n", ONE);
    printf("TEN      = %d\n", TEN);
    printf("HUNDRED  = %d\n", HUNDRED);
    printf("NEGATIVE = %d\n", NEGATIVE);
    
    printf("\nSize of enum: %zu bytes\n", sizeof(enum Values));
    
    return 0;
}