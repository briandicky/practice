#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int target = 11;
const int row = 3, col = 4;

bool searchMatrix(int matrix[row][col], int matrixRowSize, int matrixColSize, int target) {
    if( matrixRowSize == 0 || matrixColSize == 0 )
        return false;

    if( target < matrix[0][0] || target > matrix[matrixRowSize-1][matrixColSize-1] )
        return false;

    int i;
    int left, right, mid;
    for( i = 0 ; i < matrixRowSize ; i++ ) {
        left = 0;
        right = matrixColSize - 1;

        while( left <= right ) {
            mid = left + (right - left) / 2;

            if( matrix[i][mid] == target )
                return true;
            else if( matrix[i][mid] > target )
                right = mid - 1;
            else 
                left = mid + 1;
        }
    }
    
    return false;
}

int main(void) {
    int matrix[][4] = { {1, 3, 5, 7},
                       {10, 11, 16, 20},
                       {23, 30, 34, 50}};

    printf("%s\n", searchMatrix(matrix, row, col, target) ? "true" : "false");

    return 0;
}
