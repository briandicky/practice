#include <stdio.h>

struct str {
    char a;
    int b;
    double c;
};

union uni {
    char a;
    int b;
    double c;
};

enum enu{a, b, c};

int main(void) {
    struct str s;
    union uni u;
    enum enu e;

    printf("struct size is: %lu\n", sizeof(s));
    printf("union size is: %lu\n", sizeof(u));
    printf("enum size is: %lu\n", sizeof(e));

    return 0;
}
