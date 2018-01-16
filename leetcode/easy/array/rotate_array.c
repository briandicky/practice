#include <stdio.h>
#include <stdlib.h>

void reverse(int* nums, int start, int end) {
    while( start < end ) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
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
