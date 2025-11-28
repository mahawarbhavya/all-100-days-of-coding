#include <stdio.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Person {
    char name[20];
    enum Gender gender;
    int age;
};

int main() {
    struct Person person = {"John", MALE, 25};
    
    switch (person.gender) {
        case MALE:
            printf("%s's gender: Male\n", person.name);
            break;
        case FEMALE:
            printf("%s's gender: Female\n", person.name);
            break;
        case OTHER:
            printf("%s's gender: Other\n", person.name);
            break;
    }
    
    return 0;
}