
// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

#include <stdio.h>
#include <string.h>
#include "dynamic_input.c"

int isAnagram(char* a, char* b, int len_of_first_word, int len_of_second_word);

int main() {

    printf("Enter the First word : ");
    int len_of_frst_word;
    char* first_word = get_string_input(&len_of_frst_word);

    int len_of_second_word;
    printf("Enter the second word : ");
    char* second_word = get_string_input(&len_of_second_word);

    if(isAnagram(first_word, second_word, len_of_frst_word, len_of_second_word)) {printf("They are Anagrams");}
    else {printf("They are not Anagrams");}

    return 0;
}

int isAnagram(char* a, char* b, int len_of_first_word, int len_of_second_word) {

    int c=0;

    if (len_of_first_word != len_of_second_word) {return 0;}

    for (int i=0; i<len_of_second_word; i++){
        for (int j=0; j<len_of_second_word; j++){
            //printf("\t a: %c, b: %c\n", a[i], b[j]);
            if (a[i] == b[j]) {
                //printf("\t\tc: %d\n", c);
                b[j] = (char)"*";
                c++;
            }
        }
    }

    //printf("c: %d, len of a = %d\n", c, strlen(a));
    if (c == strlen(a)){return 1;}
    else {return 0;} 

}

