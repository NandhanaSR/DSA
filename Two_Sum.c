#include <stdio.h>
#include <stdlib.h>
#include "dynamic_input.c"

int main(){

    int flag = 0;

    printf("Enter the array (enter a non-integer to stop):\n");
    int arr_size;
    int* arr = get_int_input(&arr_size);

    int target;
    printf("Enter the target number: ");
    scanf("%d", &target);

    for (int i=0; i<arr_size; i++){
        for (int j=i; j<arr_size; j++){
            //printf("%d %d\n", i, j);
            if(arr[i]+arr[j] == target){
                printf("[%d, %d]", i, j);
                flag = 1;
                break;
            }
        }
    }
    if(!flag) {printf("There are no elements in the array that add up to %d.\n", target);}

    return 0;
}