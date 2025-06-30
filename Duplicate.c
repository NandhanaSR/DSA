// Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

#include <stdio.h>
#include <stdlib.h>
#include "dynamic_input.c"

int main() {

    int arr_size;
    printf("Enter the number list (enter a non-integer to end) : ");
    int* arr = get_int_input(&arr_size);
    int flag = 0;

    for (int i=0; i<arr_size; i++){
        for (int j=0; j<arr_size; j++){
            if (arr[i] == arr[j] && i != j) {
                printf("flase\n");
                flag = 1;
            }
            if (flag) {
                break;
            }
        }
    }

    if (!flag){
        printf("true");
    }

    return 0;
}
