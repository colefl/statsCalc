#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	initscr();
	raw();
	noecho();
	curs_set(0);
	int key;
	mvaddstr(0, 0, "Initial statement");
	refresh();
	while((key = getch()) != 'g'){
		switch(key){
			case '1':
				mvaddstr(0, 0, "You pressed 1");
				refresh();
				return 1;
			case '2':
				mvaddstr(0, 0, "You pressed 2");
				refresh();
				return 2;
			default:
				mvaddstr(0, 0, "Press another key");
				refresh();
				break;
		}
		refresh();
	}	
	return 0; 
}

