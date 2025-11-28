#include <stdio.h>

enum UserRole {
    ADMIN,
    USER,
    GUEST
};

int main() {
    enum UserRole roles[] = {ADMIN, USER, GUEST};
    char *roleNames[] = {"ADMIN", "USER", "GUEST"};
    
    for (int i = 0; i < 3; i++) {
        printf("%s: %d\n", roleNames[i], roles[i]);
    }
    
    return 0;
}