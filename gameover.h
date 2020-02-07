
//

#ifndef gameover_h
#define gameover_h

#include <stdio.h>
#include <stdbool.h>
#include "initial.h"

bool is_game_over(Board mineboard);
bool is_win(Board mineBoard);
bool is_lose(Board mineBoard);

#endif /* gameover_h */
