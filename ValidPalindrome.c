
// Given a string s, return true if it is a palindrome, otherwise return false.

// A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

// Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dynamic_input.c"

int isPalindrome(char *str_arr){
    char rev[strlen(str_arr)+1]; 
    strcpy(rev, str_arr);
    strrev(rev);
    
    return strcmp(rev, str_arr) == 0;

}

int main(){
    printf("Enter the string : ");
    int size_of_ip = 9;
    char* ip_str = get_string_input(&size_of_ip);
    char* str = malloc(size_of_ip * sizeof(char));
    int size = 0;

    for (int i = 0; i < size_of_ip; i++){
        if((ip_str[i] >= 'A' && ip_str[i] <= 'Z') || (ip_str[i] >= 'a' && ip_str[i] <= 'z') || (ip_str[i] >= '0' && ip_str[i] <= '9')){
            str[size++] = tolower(ip_str[i]);
        }
    }

    str = realloc(str, (size+1)*sizeof(char));
    str[size] = '\0';
    if (isPalindrome(str)){
        printf("true");
    }
    else {printf("false");}

    return 0;
}