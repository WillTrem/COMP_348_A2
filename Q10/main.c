#include <stdio.h>
#include "selectionsort.h"
#include "selectionsort.h"

int* (*fun_ptr)(int*,int) = NULL;
int array[] = {1, 4, 5, 6, -1};
int array2[] = {1, 4, 5, 6, -1};
static void printArr(int*, int);
int main() {
    
    printf("selectionsort: \n");
    printArr(array, 5);
    selectionsort(array,5);
    printArr(array, 5);
    
    printf("selectionsort2: \n");
    printArr(array2, 5);
    selectionsort2(array2,5,(*fun_ptr));
    printArr(array2, 5);
    
    return 0;
}
static void printArr(int *arr, int size){
    for (int i = 0; i < size; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}