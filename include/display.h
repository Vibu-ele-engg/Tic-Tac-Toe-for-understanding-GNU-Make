#ifndef DISPLAY_H
#define DISPLAY_H

// Including for printf()
#include <stdio.h>

// Function to display tic tac toe array
void tic_tac_toe_display(char *t_arr);

// Function to check tic tac toe array for specific symbol
int tic_tac_toe_check(char *t_arr, char symbol);

// Function to reset tic tac toe array
void tic_tac_toe_clear(char *t_arr);

// Function to dsiplay basic rules for tic tac toe
void display_rules();

#endif
