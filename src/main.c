#include "game.h"

int main()
{
	// Initialize the required values
	struct player A;
	struct player B;
	char tictactoe_array[] = {'_','_','_','_','_','_','_','_','_'};
	
	// Intro and rules
	display_rules();
	
	// Get the player details
	player_input(&A, &B);

	// Get the number of matches to be played this game
	int match_in = match_input();
	printf("\n\t match input = %d",match_in);
	// Play the game!
	tictactoe_game(&A, &B, tictactoe_array, match_in);

	return 0;
}

