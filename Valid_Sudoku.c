
// You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

// Each row must contain the digits 1-9 without duplicates.
// Each column must contain the digits 1-9 without duplicates.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
// Return true if the Sudoku board is valid, otherwise return false

// Note: A board does not need to be full or be solvable to be valid.

#include <stdio.h>
#include <stdlib.h>

int main() {

    char arr[9][9];

    int rowCount = 9;
    int eleCount = 9;
    int flag = 1;

    printf("Enter the board: \n");
    for (int i = 0; i < rowCount; i++){
        printf("Row %d: ", i+1);
        for (int j = 0; j < eleCount; j++){
            scanf(" %c", &arr[i][j]);
        }
        printf("\n");
    }

//// Row
    for (int i = 0; i < rowCount && flag; i++){
        int check[10] = {0};

        for (int j = 0; j < eleCount; j++) {

            if (arr[i][j] >= '0' && arr[i][j] <= '9'){
                int val = arr[i][j] - '0';
                if (check[val]){
                    flag = 0;
                    break;
                }
                
                check[val] = 1;
            }
        }
    }

//// Column

    if (flag){
        for (int i = 0; i < rowCount && flag; i++){
            int check[10] = {0};

            for (int j = 0; j < eleCount; j++) {

                if (arr[j][i] >= '0' && arr[j][i] <= '9'){
                    int val = arr[j][i] - '0';
                    if (check[val]){
                        flag = 0;
                        break;
                    }
                    
                    check[val] = 1;
                }
            }
        }
    }

////Box
    if (flag){
        int c = 0;
        for (int i = 0; i < rowCount && flag; i+=3){

            for (int j = 0; j < rowCount && flag; j += 3){

                int check[10] = {0};
                for (int a = i; a < i+3 && flag; a++){
                    

                    for (int b = j; b < j+3; b++){

                        if (arr[b][a] >= '0' && arr[b][a] <= '9'){
                            int val = arr[b][a] - '0';
                            if (check[val]){
                                flag = 0;
                                break;
                            }
                    
                            check[val] = 1;
                        }
                    }
                }
            }
        }
    }

    if (flag) {printf("true");}
    else {printf("flase");}


    return 0;
}



