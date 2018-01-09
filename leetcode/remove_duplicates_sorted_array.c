#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    int i = 0;
    int j;
    for ( j = 1 ; j < numsSize ; j++ ) {
        if ( nums[i] != nums[j] ) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

int main(void) {
    int arr[] = {1, 1, 2};
    size_t n = sizeof(arr) / sizeof(int);

    int length = removeDuplicates(arr, n);
    printf("ans=%d\n", length);

    return 0;
}
