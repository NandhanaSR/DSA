#include <stdio.h>
#include <stdlib.h>

char* get_string_input(int* size){
    char *ip_string = NULL;
    int capacity = 0;
    int char_count = 0;
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF){

        if (char_count >= capacity){
            
            capacity = (capacity == 0)? 1 : capacity*2;

            //printf("ip_str: %s, tot memory: %d\n", ip_string, capacity*sizeof(char));

            char* temp = (char *)realloc(ip_string, capacity * sizeof(char));

            if (temp == NULL) {
                fprintf(stderr, "Memory Allocation Failed!(1)\n");
                //printf("char_count: %d\n", char_count);
                free(ip_string);
                return NULL;
            }

            ip_string = temp;
        }
        ip_string[char_count++] = (char)ch;
        ip_string[char_count] = '\0';
        //printf("str: %s\n", ip_string);

    }

    //printf("char_count : %d, capacity: %d\n", char_count, capacity);
    if (char_count >= capacity){
        char* temp = (char *)realloc(ip_string, (char_count+1)*sizeof(char));
        if (temp == NULL) {
                fprintf(stderr, "Memory Allocation Failed!(2)\n");
                free(ip_string);
                return NULL;
        }
        ip_string = temp;
    }
    ip_string[char_count] = '\0';

    *size = char_count;
    return ip_string;
}


int* get_int_input(int* size){
    int* arr = NULL;
    int count = 0;
    int capacity = 0;
    int ip_val;

    while (scanf("%d", &ip_val) == 1){
        if (count == capacity){
            capacity = (capacity == 0)? 1 : capacity*2;
            
            int* temp = (int*)realloc(arr, capacity*sizeof(int));
            if (temp == NULL) {
                fprintf(stderr, "Memory Allocation Failed!(2)\n");
                free(arr);
                return NULL;
            }
            arr = temp;
        }
        arr[count++] = ip_val;
    }

    if (count >= capacity){
        int* temp = (int*)realloc(arr, (count)*sizeof(int));
        if (temp == NULL) {
                fprintf(stderr, "Memory Allocation Failed!(2)\n");
                free(arr);
                return NULL;
        }

        arr = temp;
    }

    *size = count;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return arr;
}