#include "player.h"

int match_count = 0;

// Function to receive player input
void player_input(struct player *a, struct player *b)
{
	// Receive player 1 name and preffered symbol
	printf("\n\t Enter player 1 name: ");
	scanf("%s",a->player_name);
		
	// Check if player 1 symbol input is valid
	while(a->player_symbol != 'X' && a->player_symbol != 'O')
	{
		printf("\n\t Enter symbol (X or O): ");
		scanf(" %c",&a->player_symbol);
		if(a->player_symbol != 'X' &&  a->player_symbol != 'O')
			printf("\n\t Invalid input! Try again!\n");
	}

	// Initialize games won as 0 for both players
	a->games_won = 0;
	b->games_won = 0;

	// Receive player 2 name and set symbol
	printf("\n\t Enter player 2 name: ");
	scanf("%s",b->player_name);
	if(a->player_symbol == 'X')
		b->player_symbol = 'O';
	else
		b->player_symbol = 'X';


	// Set the current player token for player A
	// Player to go first is considered player A
	a->current_player_token = 1;
	b->current_player_token = 0;

	return;
}

// Function to retrieve number of matches to play this game
int match_input()
{
	int num_of_matches = 0;
	// Error handling for 0 matches or >10 matches
	while(num_of_matches <= 0 || num_of_matches > 10)
	{
		printf("\n\t Enter the number of matches this game [max 10]: ");
		scanf("%d",&num_of_matches);
		if(num_of_matches <= 0 || num_of_matches > 10)
			printf("\n\t Invalid input! Try again!\n");
	}

	// Number of matches is stored in main function
	return num_of_matches;
}

// Function to announce winner of current match
// Function is called when a winning decision is made
// Winner is based on which player made the final move
void player_winner(struct player *a, struct player *b)
{
	// Announce the player won as winner.
	// Check the current player token to determine winner
	if (a->current_player_token == 1)
	{
		printf("\n\t WINNER - MATCH %d: %s",match_count,a->player_name);
		a->games_won += 1;
	}
	else if (b->current_player_token == 1)
	{	
		printf("\n\t WINNER - MATCH %d: %s",match_count,b->player_name);
		b->games_won += 1;
	}
	// Print Player scoreboard
	
	printf("\n\t PLAYER SCOREBOARD:\n");
	printf("\n\t %s: %d\n",a->player_name,a->games_won);
	printf("\n\t %s: %d\n",b->player_name,b->games_won);
	return;
}

// Function to announce tie
void tie_announce(struct player *a, struct player *b){
	printf("\n\t IT'S A TIE!\n");
	printf("\n\t PLAYER SCOREBOARD:\n");
	printf("\n\t %s: %d\n",a->player_name,a->games_won);
	printf("\n\t %s: %d\n",b->player_name, b->games_won);
	return;
}

// Function to announce overall winner of the game
void final_winner(struct player *a)
{
	printf("\n\t WINNER OF TIC - TAC - TOE: %s",a->player_name);
	printf("\n\t CONGRATULATIONS! THANKS FOR PLAYING!\n\n");
	return;
}

// Function to decide final winner
// This is called only when match_input = match_count
void winner_decision(struct player *a, struct player *b)
{
	if (a->games_won > b->games_won)
		final_winner(a);
	else if (b->games_won > a->games_won)
		final_winner(b);
	else
	{	
		printf("\n\n\t TIC - TAC - TOE RESULT: ");
		printf("\n\t IT'S A TIE!");
		printf("\n\t THANKS FOR PLAYING!\n\n");
	}
	return;
}


// Function to swap the player for their next turn
void player_swap(struct player *a, struct player *b)
{
	// basically switches token value between 0 and 1 for players
	int tmp;
	tmp = a->current_player_token;
	a->current_player_token = b->current_player_token;
	b->current_player_token = tmp;
	return;
}


