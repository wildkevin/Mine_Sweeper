
//This file includes the beginning of the game

#include "initial.h"

int convert_row_num(int row, Board mineBoard){
    //convert the user's row to the true row number
    return mineBoard.num_rows - 1 - row;
}

void valid_input_commandline(int argc, char* argv[]){
    //check the initial input are valid or not
    
    if (argc < 4) {
        printf("Not enough arguments. Usage: ./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
        exit(0);
    }
    else if (argc > 5){
        printf("Too many arguments. Usage: ./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
        exit(0);
    }
    else if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0 || (atoi(argv[1]) * atoi(argv[2])) <= atoi(argv[3])){
        printf("Invalid input\n");
        exit(0);
    }
    else{
        return;
    }
}

void seedRandom(int argc, char* argv[]){
    //seed the random number
    //if user does not enter the seed, use current time
    if (argc == 5){
        srand(atoi(argv[4]));
    }
    else{
        srand((int)time(0));
    }
}
