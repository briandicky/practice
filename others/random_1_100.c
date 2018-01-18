#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand( time(NULL) );

    // Range from 1 to 100
    int min = 1;
    int max = 100;

    // [min, max] = [1, 100]
    int x = rand() % (max - min + 1) + min;

    printf("x = %d\n", x);
    return 0;
}
