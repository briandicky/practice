#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int i;
    int ret = 0;

    for( i = 1 ; i < pricesSize ; i++ ) {
        if( prices[i] > prices[i-1] ) 
            ret += ( prices[i] - prices[i-1] );
    }
    
    return ret;
}

int main(void) {
    int arr[] = {4, 7, 8, 2, 8};
    size_t n = sizeof(arr) / sizeof(int);

    int ans = maxProfit(arr, n); 
    printf("ans=%d\n", ans);

    return 0;
}
