#include <stdio.h>
#include <stdlib.h>

void change(int a[]) {
    int temp;
    temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}

int main(void) {
    int arr[] = {1, 2, 3};
    int i;

    printf("Before:\n");
    for( i = 0 ; i < 3 ; i++ )
        printf("%d ", arr[i]);
    printf("\n");

    change(arr);

    printf("After:\n");
    for( i = 0 ; i < 3 ; i++ )
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
