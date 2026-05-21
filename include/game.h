#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "display.h"
#include "player.h"

/*

// Function to get position input from player
int player_pos_input(struct player *a);

// Function to check if there is error in position
void position_error_check(struct player *a, char *t_arr);

// Function to check for win, tie or next player move condition
char check_winning decision(struct player *a, char *t_arr);

// Function to execute win, tie or next player conditions
void end_sequence(char decision, struct player *a, struct player *b, int match_input, int match_count);

*/

// Overall game function
void tictactoe_game(struct player *a, struct player *b, char *t_arr, int match_in);

#endif
