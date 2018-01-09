#include <stdio.h>

#define SET_BIT3(x) (x|(1<<2))
#define CLEAR_BIT3(x) (x&~(1<<2))
#define INVERSE_BIT3(x) (x^(1<<2))

int main(void){
    int n;
    scanf("%d", &n);
    printf("a) %d\nb) %d\nc) %d\n", SET_BIT3(n), CLEAR_BIT3(n), INVERSE_BIT3(n));
}
