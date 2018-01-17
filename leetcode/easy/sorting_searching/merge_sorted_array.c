#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n, int* nums3) {
    int n1 = m - 1;
    int n2 = n - 1;
    int n3 = m + n - 1;

    while( (n1 >= 0) && (n2 >= 0) ) {
        if( nums1[n1] > nums2[n2] ) {
            nums3[n3] = nums1[n1];
            n3--;
            n1--;
        }
        else {
            nums3[n3] = nums2[n2];
            n3--;
            n2--;
        }
    }

    while( n1 >= 0 ) {
        nums3[n3] = nums1[n1];
        n3--;
        n1--;
    }

    while( n2 >= 0 ) {
        nums3[n3] = nums2[n2];
        n3--;
        n2--;
    }
}

int main(void) {
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    int arr3[n1+n2];
    merge(arr1, n1, arr2, n2, arr3);

    printf("Array after merging\n");
    int i;
    for ( i = 0 ; i < n1+n2 ; i++ )
        printf("%d ", arr3[i]);
    printf("\n");

    return 0;
}
