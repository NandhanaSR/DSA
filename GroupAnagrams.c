// Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isAnagram(char* a, char* b, int len1, int len2) {
    int c = 0;
    if (len1 != len2) return 0;

    char temp[100];
    strcpy(temp, b);  // work on a copy of b

    for (int i = 0; i < len2; i++) {
        for (int j = 0; j < len2; j++) {
            if (a[i] == temp[j]) {
                temp[j] = '*';  // now safe
                c++;
                break;
            }
        }
    }

    return (c == len1);
}

int main(){

    char* strs[] = {"act","pots","tops","cat","stop","hat"};
    int strs_size = sizeof(strs)/sizeof(strs[0]);

    int visited[100] = {0};
    char*** grps;
    grps = (char***)malloc(strs_size*sizeof(char**));
    int grps_cntr = 0;

    for (int i=0; i<strs_size; i++){

        if (!visited[i]){

            grps[grps_cntr] = (char**)malloc(strs_size*sizeof(char*));
            int strs_cntr = 0;

            grps[grps_cntr][strs_cntr++] = strs[i];
            visited[i] = 1;

            for (int j=i; j<strs_size; j++){
                if (!visited[j] && isAnagram(strs[i], strs[j], strlen(strs[i]), strlen(strs[j]))){

                    grps[grps_cntr][strs_cntr++] = strs[j];
                    visited[j] = 1;
                    
                }
            }

            char** temp = realloc(grps[grps_cntr], strs_cntr * sizeof(char*));
            if (temp == NULL) {
                fprintf(stderr, "Memory Allocation Failed!(2)\n");
                free(grps[grps_cntr]);
                return NULL;
            }
            grps[grps_cntr] = temp;
            grps[grps_cntr][strs_cntr] = NULL;
            grps_cntr++;

        }      

    }

    char*** temp = realloc(grps, grps_cntr * sizeof(char**));
    if (temp == NULL) {
                fprintf(stderr, "Memory Allocation Failed!(2)\n");
                free(grps);
                return NULL;
    }
    grps = temp;

    for (int i = 0; i < grps_cntr; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; grps[i][j] != NULL; j++) {
            printf("%s ", grps[i][j]);
        }
        printf("\n");
        free(grps[i]);
    }

    return 0;
}
