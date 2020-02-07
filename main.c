
//The main function for playing mine_sweeper

#include "getinput.h"
#include "initial.h"
#include "gameover.h"
#include "board.h"

void play_minesweeper(Board mineBoard);

void play_minesweeper(Board mineBoard){
    
    make_board(&mineBoard);
   
    do{
        display_board(mineBoard);
        get_action(&mineBoard);
        
    } while(!is_game_over(mineBoard));
    
    display_final_board(mineBoard);
    if (is_win(mineBoard)){
        printf("You Won!!\n");
    }
    else if (is_lose(mineBoard)){
        printf("You Lost :(\n");
    }
}

int main(int argc, char* argv[]){
    
    valid_input_commandline(argc, argv);
    
    Board mineBoard;
    //change the number(string) to integer
    mineBoard.num_rows      = atoi(argv[1]);
    mineBoard.num_cols      = atoi(argv[2]);
    mineBoard.num_mines     = atoi(argv[3]);
    
    seedRandom(argc, argv);
    
    play_minesweeper(mineBoard);
    
    return 0;
}
