#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "io.cpp"

int main(int argc, char *argv[]){

	int ms_selection = 0;

	while(ms_selection != 4){
		init_terminal();
		ms_selection = ms_select_choice();
		if(ms_selection == 1){
			pc_init();
			int pc_selection = pc_choice();
			if(pc_selection == 3){
                move(DEFAULT_Y, 0);
                clrtoeol();
				continue;
			}else if (pc_selection == 1){
				move(DEFAULT_Y, 0);
				clrtoeol();
				perm_screen();
			}
		}
	}
	return ms_selection;
}