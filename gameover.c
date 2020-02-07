
//This file includes functions about if the game is over

#include "gameover.h"

bool is_game_over(Board mineBoard){
    //win or lose?
    return is_win(mineBoard) || is_lose(mineBoard);
}

bool is_win(Board mineBoard){
    int i = 0;
    int j = 0;
    
    for (i = 0; i < mineBoard.num_rows; i++){
        for (j = 0; j < mineBoard.num_cols; j++){
            if (mineBoard.mineOrNot[i][j] == -1){
    //if any mine has not been marked, return false
                if (mineBoard.status[i][j] != 2){
                    return false;
                }
            }
            else if (mineBoard.mineOrNot[i][j] != -1){
    //if any safe tile has not be revealed, return false
                if (mineBoard.status[i][j] != 0){
                    return false;
                }
            }
        }
    }
    return true;//otherwise, true
}

bool is_lose(Board mineBoard){
    int i = 0;
    int j = 0;
    
    for (i = 0; i < mineBoard.num_rows; i++){
        for (j = 0; j < mineBoard.num_cols; j++){
            if (mineBoard.mineOrNot[i][j] == -1){
    //if any mine tile has been revealed, true
                if (mineBoard.status[i][j] == 0){
                    return true;
                }
            }
        }
    }
    return false;//otherwise, false
}
