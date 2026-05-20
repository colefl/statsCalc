#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_Y 6
#define SCREEN_WIDTH 80
#define SCREEN_HEIGH 22

void init_choice();

int main(int argc, char *argv[]){
	initscr();
	raw();
	noecho();
	curs_set(0);
	int key;

	int i;
	for(i = 0; i < 80; i++){
		mvaddch(0, i, ACS_HLINE);
	}
	mvaddstr(2, 33, "STATS CALC");
	for(int i = 0; i < 80; i++){
		mvaddch(5, i, ACS_HLINE);
	}
// 	mvaddstr(0, 0, "________________________________________________________________________________

// 	█     ███        █        ███                ██        █        █                ██
//        █            █        █    █        █                █           █    █    █             █
//  	█	 █        █    █        █                █           █    █    █             █
//        █		 █        █    █        █                    ██   █     █    ███         ██

// ________________________________________________________________________________");
	init_choice();
	refresh();
	int selected;
	while((key = getch()) != 'q'){
		switch(key){
			case '1':
				attroff(A_STANDOUT);
				init_choice();
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 2, 0, "Combinations and Permutations");
				refresh();
				selected = 1;
				move(DEFAULT_Y + 8,  0);
				clrtoeol();
				break;
				//return 1;
			case '2':
				attroff(A_STANDOUT);
				init_choice();
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 4, 0, "Distributions");
				refresh();
				selected = 2;
				move(DEFAULT_Y + 8,  0);
				clrtoeol();
				break;
				//return 2;
			
			case '3':
				attroff(A_STANDOUT);
				init_choice();
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 6, 0, "Matricies and Markov Chains");
				refresh();
				selected = 2;
				move(DEFAULT_Y + 8,  0);
				clrtoeol();
				break;
				//return 2;
			case 'f':

			default:
				mvaddstr(DEFAULT_Y + 8, 0, "Press another key");
				refresh();
				break;
		}
		//attroff(A_BOLD);
		refresh();
	}	
	endwin();
	return selected; 
}

void init_choice(){
	attron(A_REVERSE);
	mvaddstr(DEFAULT_Y, 0, "What would you like to do?(Press f to select)");
	attroff(A_REVERSE);
	mvaddstr(DEFAULT_Y + 2, 0, "Combinations and Permutations");
	mvaddstr(DEFAULT_Y + 4, 0, "Distributions");
	mvaddstr(DEFAULT_Y + 6, 0, "Matricies and Markov Chains");
}