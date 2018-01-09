/**
 * Note: The returned array must be malloced, assume caller calls free().
*/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int* ans = (int*) malloc( sizeof(int) * 2 );
    int i, j;

    for( i = 0 ; i < numsSize ; i++ ) {
       for( j = i + 1 ; j < numsSize ; j++ ) {
           if( (nums[i] + nums[j]) == target ) {
               ans[0] = i;
               ans[1] = j;

               return ans;
           }
       }
    }

    return NULL;
}

int main(void) {
    int arr[] = {2, 7, 11, 15};
    int target = 9;

    size_t n = sizeof(arr) / sizeof(int);

    int* result = twoSum( arr, n, target );
    printf("The index1=%d; the index2=%d\n", result[0], result[1]);
    free(result);//memory deallocation

    return 0;
}
