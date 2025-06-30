// Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
// Each product is guaranteed to fit in a 32-bit integer.


#include <stdio.h>
#include <stdlib.h>
#include "dynamic_input.c"

int main(){

    int num_size;
    printf("Enter the number list (enter a non-intger to end) : ");
    int* num = get_int_input(&num_size);
    int output[num_size];

    for (int i=0; i<num_size; i++){
        int prod = 1;
        for (int j=0; j<num_size; j++){
            if (j != i){
                prod *= num[j];
            }
        }
        output[i] = prod;
    }

    for (int i=0; i<num_size; i++){
        printf("%d ", output[i]);

    }


    return 0;
}
