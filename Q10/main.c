#include <stdio.h>
#include "selectionsort.h"
#include "selectionsort.h"

int array[] = {1, 4, 5, 6, -1};
static void printArr(int*, int);
int main() {

    printArr(array, 5);
    selectionsort(array, 5);
    printArr(array, 5);
    return 0;
}
static void printArr(int *arr, int size){
    for (int i = 0; i < size; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}


