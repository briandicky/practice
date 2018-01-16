#include <stdio.h>
#include <stdlib.h>

typedef enum{ false = 0, true = 1 } bool;

#define hash_prime 1610612741
bool hash[hash_prime] = {false};

int hash_func(int num) {
   return num%hash_prime;
}

bool containsDuplicate(int* nums, int numsSize) {
   int i;

   if( numsSize == 0 || numsSize == 1 )
       return false;

   for( i = 0 ; i < numsSize ; i++ ) {
       if( hash[hash_func( abs(nums[i]) )] )
           return true;

       hash[hash_func( abs(nums[i]) )] = true;
   }

   return false;
}

int main(void) {
    //int arr[] = {1, 2, 2, 3, 4};
    int arr[] = {3, 1};
    size_t n = sizeof(arr) / sizeof(int);


    if( containsDuplicate(arr, (int)n) )
        printf("A value appears at least twice in the array.\n");
    else
        printf("Every element is distinct.\n");

    printf("size of enum: %lu\n", sizeof(bool));
    printf("false=%u\n", false);
    printf("true=%u\n", true);

    return 0;
}
