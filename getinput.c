
//This file includes the functions about getting valid input, and the effect of each input

#include "getinput.h"

bool in_board(Input userInput, Board mineBoard){
    //if the move is in the board
    return (userInput.user_row >= 0 && userInput.user_row < mineBoard.num_rows && userInput.user_col >= 0 && userInput.user_col < mineBoard.num_cols);
}

Input get_coordinates(Board mineBoard){
    //get the location user wants to act, and validate it
    Input userInput;
    
    do{
        printf("Enter row a row between 0-%d and a column between 0-%d: \n", (mineBoard.num_rows - 1), (mineBoard.num_cols - 1));
        scanf("%d %d", &(userInput.user_row), &(userInput.user_col));
    }while (!in_board(userInput, mineBoard));
    
    userInput.user_row = convert_row_num(userInput.user_row, mineBoard);
    //convert to the real location on the board
    return userInput;
}

void get_action(Board* mineBoard){
    /*
     This function first call the get_coordinate function, and
     make the action function, put all of them in a loop. In the
     end, it will also include the effect of the valid move
    */
    
    Input userInput;
    
    do{
        userInput = get_coordinates((*mineBoard));
        
        if ((*mineBoard).status[userInput.user_row][userInput.user_col] == 0){
            userInput.action = 3;//re-enter the input from beginning
            printf("This tile is already revealed.\n");
            continue;
        }
        //till here, means the position is valid
        
        printf("Enter Action\n");
        if ((*mineBoard).status[userInput.user_row][userInput.user_col] == 1){
            //if the tile has already be a question
            printf("0. UnQuestion\n1. Cancel\nAction: \n");
            scanf("%d", &userInput.action);
            
            if (userInput.action == 0){
                (*mineBoard).status[userInput.user_row][userInput.user_col] = -1;
                //changes to no action
            }
            else{
                userInput.action = 3;//re-enter
            }
        }
        
        else if ((*mineBoard).status[userInput.user_row][userInput.user_col] == 2){
            //if the tile has already be a mark
            printf("0. UnMark\n1. Cancel\nAction: \n");
            scanf("%d", &userInput.action);
            
            if (userInput.action == 0){
                (*mineBoard).status[userInput.user_row][userInput.user_col] = -1;
                //changes to no action
            }
            else{
                userInput.action = 3;//re-enter
            }
        }
        else{
            printf("0. Reveal\n1. Question\n2. Mark\n3. Cancel\nAction: \n");
            //normal action choose
            scanf("%d", &userInput.action);
            
            if (userInput.action == 3 || userInput.action < 0 || userInput.action > 3){
                //if action is not valid, re-enter
                continue;
            }
            
            (*mineBoard).status[userInput.user_row][userInput.user_col] = userInput.action;
            //eveything is valid, change the status to user's idea
        }
        
    } while(userInput.action == 3 || userInput.action < 0 || userInput.action > 3);
    
    changeSurStatus(userInput.user_row, userInput.user_col, mineBoard);
    //get the effect of the action user has made (anything need to be revealed)
}

void changeSurStatus(int row, int col, Board* mineBoard){
    /*
     This is a recursive function which is about if a new tile is encountered
     that has 0 mines surrounding it, the process repeats.
    */
    
    if ((*mineBoard).status[row][col] == 0 && (*mineBoard).mineOrNot[row][col] == 0){
    //if the tile is revealed and not mine
        
        /*
         The follwing if statements checks if the surronding tiles have mine or not,
         if not and has 0 mines surronding its tile, repeating the check
        */
        if (row + 1 < (*mineBoard).num_rows && (*mineBoard).mineOrNot[row + 1][col] != -1 && (*mineBoard).status[row + 1][col] == -1){
            (*mineBoard).status[row + 1][col] = 0;
            if ((*mineBoard).mineOrNot[row + 1][col] == 0){

                changeSurStatus(row + 1, col, mineBoard);
            }
        }
        
        if (row + 1 < (*mineBoard).num_rows && col - 1 >= 0 && (*mineBoard).mineOrNot[row + 1][col - 1] != -1 && (*mineBoard).status[row + 1][col - 1] == -1){
            (*mineBoard).status[row + 1][col - 1] = 0;
            if ((*mineBoard).mineOrNot[row + 1][col - 1] == 0){

                changeSurStatus(row + 1, col - 1, mineBoard);
            }
        }
        
        if (row + 1 < (*mineBoard).num_rows && col + 1 < (*mineBoard).num_cols && (*mineBoard).mineOrNot[row + 1][col + 1] != -1 && (*mineBoard).status[row + 1][col + 1] == -1){
            (*mineBoard).status[row + 1][col + 1] = 0;
            if ((*mineBoard).mineOrNot[row + 1][col + 1] == 0){

                changeSurStatus(row + 1, col + 1, mineBoard);
            }
        }
        
        if (row - 1 >= 0 && (*mineBoard).mineOrNot[row - 1][col] != -1 && (*mineBoard).status[row - 1][col] == -1){
            (*mineBoard).status[row - 1][col] = 0;
            if ((*mineBoard).mineOrNot[row - 1][col] == 0){

                changeSurStatus(row - 1, col, mineBoard);
            }
        }
        
        if (row - 1 >= 0 && col - 1 >= 0 && (*mineBoard).mineOrNot[row - 1][col - 1] != -1 && (*mineBoard).status[row - 1][col - 1] == -1){
            (*mineBoard).status[row - 1][col - 1] = 0;
            if ((*mineBoard).mineOrNot[row - 1][col - 1] == 0){

                changeSurStatus(row - 1, col - 1, mineBoard);
            }
        }
        
        if (row - 1 >= 0 && col + 1 < (*mineBoard).num_cols && (*mineBoard).mineOrNot[row - 1][col + 1] != -1 && (*mineBoard).status[row - 1][col + 1] == -1){
            (*mineBoard).status[row - 1][col + 1] = 0;
            if ((*mineBoard).mineOrNot[row - 1][col + 1] == 0){

                changeSurStatus(row - 1, col + 1, mineBoard);
            }
        }
        
        if (col - 1 >= 0 && (*mineBoard).mineOrNot[row][col - 1] != -1 && (*mineBoard).status[row][col - 1] == -1){
            (*mineBoard).status[row][col - 1] = 0;
            if ((*mineBoard).mineOrNot[row][col - 1] == 0){

                changeSurStatus(row, col - 1, mineBoard);
            }
        }
        
        if (col + 1 < (*mineBoard).num_cols && (*mineBoard).mineOrNot[row][col + 1] != -1 && (*mineBoard).status[row][col + 1] == -1){
            (*mineBoard).status[row][col + 1] = 0;
            if ((*mineBoard).mineOrNot[row][col + 1] == 0){

                changeSurStatus(row, col + 1, mineBoard);
            }
        }
    }
    
}
