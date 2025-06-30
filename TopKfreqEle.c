// Given an integer array nums and an integer k, return the k most frequent elements within the array.
// The test cases are generated such that the answer is always unique.
// You may return the output in any order.


#include <stdio.h>
#include <stdlib.h>
#include "dynamic_input.c"

int main() {

    int arr_size;
    printf("Enter the number list (enter a non-intger to end) : ");
    int* arr = get_int_input(&arr_size);
    printf("Enter a number k : ");
    int k;
    scanf("%d", &k);
    int* k_freq_ele = calloc(arr_size, sizeof(int));
    int cnt = 0;
    int visited[100] = {0};

    for (int i=0; i < arr_size; i++){
        int ele_cnt = 1;
        if (!visited[arr[i]]){
            for (int j=i+1; j < arr_size; j++){
                if (arr[i] == arr[j]){
                    ele_cnt++;
                }
            }

            if (ele_cnt >= k){
                k_freq_ele[cnt++] = arr[i];
            }

            visited[arr[i]] = 1;
        }
    }

    k_freq_ele = realloc(k_freq_ele, cnt*sizeof(int));

    printf("\n");
    for(int i=0; i<cnt; i++){
        printf("%d ", k_freq_ele[i]);
    }

    return 0;
}
