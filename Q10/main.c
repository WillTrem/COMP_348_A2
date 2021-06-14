#include <stdio.h>
#include "selectionsort.h"
#include "selectionsort.h"

int* (*fun_ptr)(int*,int) = NULL;
int array[] = {1, 4, 5, 6, -1};
int array2[] = {1, 4, 5, 6, -1};
static void printArr(int*, int);
int main() {
    
    printf("Pre-sorted array: ");
    printArr(array, 5);
    printf("\n");

    printf("Using selectionsort(int*, int): ");
    selectionsort(array,5);
    printArr(array, 5);
    
    printf("Using selectionsort2(int*, int, int* (*fp)(int*,int)): ");
    selectionsort2(array2,5,(*fun_ptr));
    printArr(array2, 5);
    
    return 0;
}
static void printArr(int *arr, int size){
    for (int i = 0; i < size; ++i) {
        if(i < size-1){
            printf("%d, ", arr[i]);
        }
        else{
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}