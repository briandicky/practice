#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000001

int main(void) {
    srand(time(NULL));

    int i;
    int sum = 0;
    double x, y;

    for( i = 1 ; i < N ; i++ ) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;

        if( (x * x + y * y) < 1 )
            sum++;
    }

    printf("PI = %f\n", (double) 4 * sum / (N - 1));

    return 0;
}
