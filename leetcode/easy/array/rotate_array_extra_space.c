#include <stdio.h>
#include <stdlib.h>

void rotate(int* nums, int numsSize, int k) {
    int temp[numsSize];
    int i;

    for( i = 0 ; i < numsSize ; i++ ) 
        temp[(i + k) % numsSize] = nums[i];

    for( i = 0 ; i < numsSize ; i++ )
        nums[i] = temp[i];
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    size_t n = sizeof(arr) / sizeof(int);

    rotate(arr, n, k);
    
    int i;
    for( i = 0 ; i < (int)n ; i++ )
        printf("%d", arr[i]);

    printf("\n");

    return 0;
}
