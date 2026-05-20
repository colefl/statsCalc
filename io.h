#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <cstdlib>

#define DEFAULT_Y 6
#define SCREEN_WIDTH 80
#define SCREEN_HEIGH 22

//MAIN SCREEN
void init_terminal();
void ms_init_choice();
int ms_select_choice();

//PERMUTATIONS AND COMBINATIONS
void pc_init();
int pc_choice();