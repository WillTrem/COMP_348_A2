#include <stdio.h>
#include <math.h>
#include "selectionsort.h"
#include "selectionsort.h"

double pow(double x, double y);
static int* findmax(int*, int);
static void printArr(int*, int);

int* (*fun_ptr)(int*, int) = NULL;
int array[] = {1, 4, 5, 6, -1};
int min, max, i;
int avg = 0;
float sd = 0;

typedef struct {
    int * unsortedarray;
} intArray;

int main() {
    /* cant dynamically allocate mem on online compiler ...
    int size = 5;
    intArray * toSort;
    toSort = malloc(size*sizeof(intArray));
    toSort[0] = 1;
    toSort[1] = 4;
    toSort[2] = 5;
    toSort[3] = 6;
    toSort[4] = -1;
    
    !**** CHANGE array TO toSort ****!

    */

    printf("Pre-sorted array: ");
    printArr(array, 5);
    printf("\n");
    
    printf("Ascending order: ");
    selectionsort(array, 5, fun_ptr);
    printArr(array, 5);
    min = array[0];
    
    printf("Descending order: ");
    fun_ptr = findmax;
    selectionsort(array,5, fun_ptr);
    printArr(array, 5);
    max = array[0];
    
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    
    for(i = 0; i < 5; i++){
        avg += array[i];
    }
    avg /= 5;
    
    printf("Average: %d\n", avg);
    
    for(i = 0; i < 5; i++){
        sd += pow((array[i] - avg),2);
        
    }
    sd = sqrt(sd/4);
    
    printf("Standard Deviation: %.12f\n", sd);
    //free(toSort);
    return 0;
}

static int* findmax(int* arr, int size){
    int *maxptr = arr;
    for(int i = 0; i<size; i++){
        if (*maxptr < arr[i]){
            maxptr = &arr[i];
        }
    }
    
    return maxptr;
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