#include <stdio.h>

static int* findmin(int *arr, int size){
    int *minptr = arr;
    for(int i = 0; i<size; i++){
        if (*minptr > arr[i]){
            minptr = &arr[i];
        }
    }
    
    return minptr;
}

void selectionsort(int* arr, int size, int* (*fun_ptr)(int*,int)){

    if(fun_ptr == NULL){
        fun_ptr = findmin;
    }
    
    for(int i = 0; i<size; i++){
        int *min =  fun_ptr((arr+i), size-i);
        int temp = arr[i];
        arr[i] = *min;
        *min = temp;
    }
}