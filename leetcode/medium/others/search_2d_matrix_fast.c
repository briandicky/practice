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

    int row = matrixRowSize - 1;
    int col = 0;

    while( row >= 0 && col < matrixColSize ) {
        if( target == matrix[row][col] )
            return true;
        else if( target < matrix[row][col] )
            row--;
        else 
            col++;
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
