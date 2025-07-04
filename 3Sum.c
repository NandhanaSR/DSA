
//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

#include <stdio.h>
#include <stdlib.h>
#include "dynamic_input.c"

int main(){

    printf("Enter the array (enter a non-integer to stop):\n");
    int size;
    int* num = get_int_input(&size);

    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                  
                if (num[i]+num[j]+num[k] == 0){
                    printf("[%d, %d, %d]\n", num[i], num[j], num[k]);
                }

            }
        }
    }

    return 0;
}