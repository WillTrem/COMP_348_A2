#include <stdio.h>
static int* findmax(int*, int);
static void printArr(int*, int);

int* (*fun_ptr)(int*, int) = findmax;

typedef struct {
    int * unsortedarray;
} intArray;

int main() {
    
    intArray * toSort;
    toSort = (intArray *)malloc(sizeof(intArray));
    toSort->unsortedarray = {1,4,5,6,-1};
    
    printf("pre-sorted array:");
    printArr(array, 5);
    //fun_ptr(array,5);
    printArr(array, 5);
    
    free(toSort);
    return 0;
}

static int* findmax(int* arr, int size){
    return arr;
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