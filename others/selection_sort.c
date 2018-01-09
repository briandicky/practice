#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;                                                                                             
}

int main() {

    int array[5] = {3, 6, 9, -8, 1};

    for (int i = 0 ; i < 5 ; i++) 
    {
        int min_index = i;
        for ( int j = i + 1 ; j < 5 ; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }
        
        swap(&array[i], &array[min_index]);
    }

    for (int i = 0 ; i < 5 ; i++)
        printf("%d ", array[i]);
    
    printf("\n"); 

    return 0;
}
