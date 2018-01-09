#include <stdio.h>

int main() {
    int num;
    int amp, freq;

    int i, j, m, n, p, q;

    while( scanf("%d", &num) != EOF ) {
        for( i = 0 ; i < num ; i++ ) {
            scanf("%d%d", &amp, &freq);

            if( i != 0 )
                printf("\n");

            for( j = 0 ; j < freq ; j++ ) {
                if( j != 0 )
                    printf("\n");

                for( m = 1 ; m <= amp ; m++ ) {
                    for( n = 1 ; n <= m ; n++ )
                        printf("%d", m);

                    printf("\n");
                }

                for( p = amp - 1 ; p > 0 ; p-- ) {
                    for( q = 1 ; q <= p ; q++)
                        printf("%d", p);

                    printf("\n");
                }
            }
        }
    }

    return 0;
}
