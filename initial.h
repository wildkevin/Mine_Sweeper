
//

#ifndef initial_h
#define initial_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Board_struct{
    int num_rows;
    int num_cols;
    int num_mines;
    int num_mines_left;
    int mineOrNot[100][100];
    //-1 = mine, >= 0 means numMine surroding
    int status[100][100];
    //-1 means no action, 0 means reveal, 1 means question, 2 means mark
} Board;

typedef struct Input_struct{
    int user_row;
    int user_col;
    int action;
    //-1 means no action, 0 means reveal, 1 means question, 2 means mark
} Input;

void valid_input_commandline(int argc, char* argv[]);
void seedRandom(int argc, char* argv[]);
int convert_row_num(int row, Board mineBoard);

#endif /* initial_h */
