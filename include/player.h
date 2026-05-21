#ifndef	PLAYER_H
#define PLAYER_H

// Including stdio.h for printf() and scanf() utilization

#include <stdio.h>

// Struct for storing player input
struct player
{
	char player_name[20];
	char player_symbol;
	int games_won;
	int current_player_token;
};


// Player input function
void player_input(struct player *a, struct player *b);

// Function to retrieve number of matches (max 10)
int match_input();

// Function to announce tie
void tie_announce(struct player *a, struct player *b);

// Function to announce winner of current match and display scoreboard
void player_winner(struct player *a, struct player *b);

// Function to announce final winner of game
void final_winner(struct player *a);

// Function to decide final winner of game
void winner_decision(struct player *a, struct player *b);

// Function to swap player
void player_swap(struct player *a, struct player *b);

#endif
	
