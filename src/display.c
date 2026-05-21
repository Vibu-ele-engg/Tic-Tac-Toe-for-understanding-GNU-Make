#include "display.h"

// Function to display the tic-tac-toe array
void tic_tac_toe_display(char *t_arr)
{
	printf("\n\n");
	for(int i = 0; i < 9; i += 3)
	{
		printf("\t%c\t%c\t%c\n\n",t_arr[i],t_arr[i+1],t_arr[i+2]);
	}
	return;
}

// Function to check presence of symbol in array
int tic_tac_toe_check(char *t_arr, char symbol)
{
	int error_check = 0;
	// Loop to check all elements in array
	for(int i = 0; i < 9; i++)
	{
		// condition to check presence of symbol
		if(t_arr[i] == symbol)
		{
			error_check = 1;	// 1 if symbol present
			break;
		}
	}
	return error_check;
}

// Function to clear the array of all elements and initialize with '_'
void tic_tac_toe_clear(char *t_arr)
{
	for(int i = 0; i < 9; i++)
	{
		t_arr[i] = '_';
	}
	return;
}

void display_rules()
{
	printf("\n\t TIC - TAC - TOE\n\n");
	printf("\n\tRULES:");
	printf("\n\t\t1. Enter the position when your turn comes");
	printf("\n\t\t2. Try to get three in a row!");
	printf("\n\t\t3. Enter the position based on the given layout:");
	printf("\n\n\t\t1\t2\t3");
	printf("\n\n\t\t4\t5\t6");
	printf("\n\n\t\t7\t8\t9");
	printf("\n\n\tGOOD LUCK!\n\n");
	return;
}

