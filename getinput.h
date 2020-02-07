
//

#ifndef getinput_h
#define getinput_h

#include <stdio.h>
#include <stdbool.h>
#include "initial.h"

bool in_board(Input userInput, Board mineBoard);
Input get_coordinates(Board mineBoard);
void get_action(Board* mineBoard);
void changeSurStatus(int row, int col, Board* mineBoard);

#endif /* getinput_h */
