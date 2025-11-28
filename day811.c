#include <stdio.h>

enum Day {
    SUNDAY = 0,
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6
};

int main() {
    enum Day days[] = {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
    
    for (int i = 0; i < 7; i++) {
        printf("%s: %d\n", 
               i == 0 ? "SUNDAY" :
               i == 1 ? "MONDAY" :
               i == 2 ? "TUESDAY" :
               i == 3 ? "WEDNESDAY" :
               i == 4 ? "THURSDAY" :
               i == 5 ? "FRIDAY" : "SATURDAY", 
               days[i]);
    }
    
    return 0;
}