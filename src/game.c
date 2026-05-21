#include "game.h"

extern int match_count;
extern int match_in;

// Position input can be from 1 to 9
// But, array input must be considered from 0 to 8

int player_pos_input(struct player *a, char *t_arr)
{
	int pos = 0;
	tic_tac_toe_display(t_arr);
	printf("\n\t %s's turn!",a->player_name);
	// Error checking for invalid value - must be within 1 to 9
	while( !(( pos > 0 ) &&  ( pos < 10 )) )
	{
		printf("\n\t Enter position: ");
		scanf("%d",&pos);
		if( !((pos > 0)  && (pos < 10)) )
			printf("\n\t Invalid input; Try again!");
	}
	return (pos-1);
}


// Check if the entered position is free and update the array with symbol
void position_error_check(struct player *a, char *t_arr)
{
	int pos = 0;
	int error_state = 1;
	pos = (player_pos_input(a, t_arr));
	while(error_state)
	{
		if(t_arr[pos] == '_')
		{
			t_arr[pos] = a->player_symbol;
			error_state = 0;
		}
		else
		{
			printf("\n\t Invalid input! Try again!");
			pos = (player_pos_input(a, t_arr));
		}
	}
	return;
}

// Function to call to check if a player's move has created a:
// 1. winning decision
// 2. tie decision
// 3. next move needed from next player
char check_winning_decision(struct player *a, char *t_arr) 
{
	// Need to check all winning combinations
	// There are 8 possible winning combinations
	// Need to check them manually
	if (t_arr[0] == a->player_symbol)
	{	
		// check top horizontal row
		if (t_arr[1] == a->player_symbol)
		{
			if (t_arr[2] == a->player_symbol)
			{
				return 'W';
				// 0,1,2 same symbol - win
			}
		}

		// check top right to bottom left diagonal
		if (t_arr[4] == a->player_symbol)
		{
			if (t_arr[8] == a->player_symbol)
			{
				return 'W';
				// 0,4,8 same symbol - win
			}
		}

		// left vertical column check
		if (t_arr[3] == a->player_symbol)
		{
			if (t_arr[6] == a->player_symbol)
			{
				return 'W';
				// 0,3,6 same symbol - win
			}
		}

	}
	
	// middle vertical column check
	if (t_arr[1] == a->player_symbol)
	{
		if (t_arr[4] == a->player_symbol)
		{
			if (t_arr[7] == a->player_symbol)
			{
				return 'W';
				// 1,4,7 same symbol - win
			}
		}
	}
	
	// top right to bottom left diagonal check - 2,4,6
	// left vertical column check - 2,5,8
	if (t_arr[2] == a->player_symbol)
	{
		if (t_arr[4] == a->player_symbol)
		{
			if (t_arr[6] == a->player_symbol)
			{
				return 'W';
				// 2,4,6 same symbol - win
			}
		}

		if (t_arr[5] == a->player_symbol)
		{
			if (t_arr[8] == a->player_symbol)
			{
				return 'W';
				// 2,5,8 same symbol - win
			}
		}
	}

	// middle horizontal row  check
	if (t_arr[3] == a->player_symbol)
	{
		if (t_arr[4] == a->player_symbol)
		{
			if (t_arr[5] == a->player_symbol)
			{
				return 'W';
				// 3,4,5 same symbol - win
			}
		}
	}

	// bottom horizontal row check
	if (t_arr[6] == a->player_symbol)
	{
		if (t_arr[7] == a->player_symbol)
		{
			if (t_arr[8] == a->player_symbol)
			{
				return 'W';
				// 6,7,8 same symbol - win
			}
		}
	}


	// If no winning condition is observed, need to check if any empty pos
	if(tic_tac_toe_check(t_arr,'_') )
		return 'S';

	// If no empty spaces and winning conditions, it is a tie
	return 'T';
}

// Function to decide ending flow after a move / match / game
void end_sequence(char decision, struct player *a, struct player *b, char *t_arr, int match_in)
{
	switch (decision)
  	{
    		case 'W':
			match_count++;
      			if (match_count <  match_in)
			{
	  			tic_tac_toe_display(t_arr);
				player_winner(a,b);
				tic_tac_toe_clear(t_arr);	
	  			break;
			}
      			else
			{
				tic_tac_toe_display(t_arr);
				player_winner(a,b);
				winner_decision(a,b);
				break;
			}

    		case 'T':
			match_count++;
      			if (!(match_count < match_in))
			{
	  			tic_tac_toe_display(t_arr);
				winner_decision(a,b);
	  			break;
			}
      			else
			{
	  			tic_tac_toe_display(t_arr);
				tie_announce(a,b);
				tic_tac_toe_clear(t_arr);
				break;
			}

    		case 'S':
      			player_swap (a, b);
      			break;

  		default: break;
	};
}
	    

void tictactoe_game(struct player *a, struct player *b, char *t_arr, int match_in)
{
	char decision;
	
	// clearing array for first time
	tic_tac_toe_clear(t_arr);

	// we need to exi  the while loop when match_count == match_input
	while (match_count <  match_in)
	{
		if (!(decision == 'S'))
			printf("\n\t MATCH %d\n",match_count+1);
		// check which player needs to play
		// current_player_token must be 1
		// need to get the decision - W, T or S
		// based on end decision, perform instruction
		
		if(a->current_player_token)
		{
			position_error_check(a,t_arr);
			decision = check_winning_decision(a,t_arr);
			end_sequence(decision, a, b, t_arr, match_in);
		}
		
		else if (b->current_player_token)
		{
			position_error_check(b,t_arr);
			decision = check_winning_decision(b,t_arr);
			end_sequence(decision, a, b, t_arr, match_in);
		}
	}
	
	return;		
}
