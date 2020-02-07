
//

#ifndef board_h
#define board_h

#include <stdio.h>
#include <stdlib.h>
#include "initial.h"

void make_board(Board* mineBoard);
void display_board(Board mineBoard);
void display_final_board(Board mineBoard);
void mineLeftStatement(Board* mineBoard);

#endif /* board_h */
