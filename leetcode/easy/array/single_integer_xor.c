#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int i = 0, sum = 0;

    for (i = 0; i < numsSize; i++)
        sum = sum ^ nums[i];

    return sum;
}

int main(void) {
    int arr[] = {2, 3, 3, 1, 1, 2, 5};
    int size = sizeof(arr) / sizeof(int);

    printf("%d\n", singleNumber(arr, size));

    return 0;
}
