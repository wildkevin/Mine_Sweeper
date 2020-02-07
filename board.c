
//This file includes the functions for dealing with the board

#include "board.h"

void mineLeftStatement(Board* mineBoard){
    //calculate how many mines left according to the user's thought
    int i = 0;
    int j = 0;
    
    mineBoard->num_mines_left = mineBoard->num_mines;
    
    for(i = 0; i < mineBoard->num_rows; i++){
        for (j= 0; j < mineBoard->num_cols; j++){
            if (mineBoard->status[i][j] == 2){
            //if user mark a tile, minus one
                mineBoard->num_mines_left--;
            }
        }
    }
    
    printf("There are %d mines left\n", mineBoard->num_mines_left);
}

void make_board(Board* mineBoard){
    /*
     This function set up the board, including the location of the mine
     and the number of mines surronding each tile
     */
    int i = 0;
    int j = 0;
    int n = 0;
    
    int row = 0;
    int col = 0;
    
    for (i = 0; i < (*mineBoard).num_rows; i++){
        for (j = 0; j <(*mineBoard).num_cols; j++){
            (*mineBoard).mineOrNot[i][j] = 0;//no mine
            (*mineBoard).status[i][j] = -1;//no action
        }
    }
    
    while(n < (*mineBoard).num_mines){
        row = rand() % (*mineBoard).num_rows;
        col = rand() % (*mineBoard).num_cols;
        //get random location of the mine
        
        if ((*mineBoard).mineOrNot[convert_row_num(row, (*mineBoard))][col] != -1){
        //check if there has already a mine in the location
            printf("Placing mine at %d, %d\n", row, col);
            
            row = convert_row_num(row, (*mineBoard));//convert to the true row number
            (*mineBoard).mineOrNot[row][col] = -1;//put the mine
            n++;//count plus one
            
            //The following if statements count the number of mines surronding each tile
            if (row + 1 < (*mineBoard).num_rows && (*mineBoard).mineOrNot[row + 1][col] != -1){
                (*mineBoard).mineOrNot[row + 1][col]++;
            }
            if (row + 1 < (*mineBoard).num_rows && col - 1 >= 0 && (*mineBoard).mineOrNot[row + 1][col - 1] != -1){
                (*mineBoard).mineOrNot[row + 1][col - 1]++;
            }
            if (row + 1 < (*mineBoard).num_rows && col + 1 < (*mineBoard).num_cols && (*mineBoard).mineOrNot[row + 1][col + 1] != -1){
                (*mineBoard).mineOrNot[row + 1][col + 1]++;
            }
            if (row - 1 >= 0 && (*mineBoard).mineOrNot[row - 1][col] != -1){
                (*mineBoard).mineOrNot[row - 1][col]++;
            }
            if (row - 1 >= 0 && col - 1 >= 0 && (*mineBoard).mineOrNot[row - 1][col - 1] != -1){
                (*mineBoard).mineOrNot[row - 1][col - 1]++;
            }
            if (row - 1 >= 0 && col + 1 < (*mineBoard).num_cols && (*mineBoard).mineOrNot[row - 1][col + 1] != -1){
                (*mineBoard).mineOrNot[row - 1][col + 1]++;
            }
            if (col - 1 >= 0 && (*mineBoard).mineOrNot[row][col - 1] != -1){
                (*mineBoard).mineOrNot[row][col - 1]++;
            }
            if (col + 1 < (*mineBoard).num_cols && (*mineBoard).mineOrNot[row][col + 1] != -1){
                (*mineBoard).mineOrNot[row][col + 1]++;
            }
        }
    }
}

void display_final_board(Board mineBoard){
    //if game is over, display the revealed board
    int row = 0;
    int col = 0;
    int i   = 0;
    int j   = 0;
    
    for(i = mineBoard.num_rows - 1, row = 0; i >= 0 ; --i, ++row){
        /*this loop will print the row number from largest to 0, and
         print each element in the board
         */
        printf("%d ", i);
        for(col = 0; col < mineBoard.num_cols; ++col){
            if (mineBoard.mineOrNot[row][col] == -1){
                //if it is mine
                printf("* ");
            }
            else{
                printf("%d ", mineBoard.mineOrNot[row][col]);
                //display the number
            }
        }
        printf("\n");
    }
    
    printf("  ");
    for(j = 0; j < mineBoard.num_cols; ++j){
        //print the column number
        printf("%d ", j);
    }
    printf("\n");
}

void display_board(Board mineBoard){
    //This function will be called each time when user has made a valid move
    int row = 0;
    int col = 0;
    int i   = 0;
    int j   = 0;
    
    mineLeftStatement(&mineBoard);
    //show the num_mine_left
    
    for(i = mineBoard.num_rows - 1, row = 0; i >= 0 ; --i, ++row){
        /*this loop will print the row number from largest to 0, and
         print each element in the board
         */
        printf("%d ", i);
        for(col = 0; col < mineBoard.num_cols; ++col){
            
            if (mineBoard.status[row][col] == -1){
                //if no action has been made on this tile
                printf("# ");
            }
            else if (mineBoard.status[row][col] == 0){
                //if this tile has been revealed
                printf("%d ", mineBoard.mineOrNot[row][col]);
            }
            else if (mineBoard.status[row][col] == 1){
                //if it is a potential mine tile
                printf("? ");
            }
            else if (mineBoard.status[row][col] == 2){
                //if user marks this tile
                printf("! ");
            }
        }
        printf("\n");
    }
    
    printf("  ");
    for(j = 0; j < mineBoard.num_cols; ++j){
        //print the column number
        printf("%d ", j);
    }
    printf("\n");
}

