#include "io.h"

void init_terminal(){
    initscr();
	raw();
	noecho();
	curs_set(0);

	int i;
	for(i = 0; i < 80; i++){
		mvaddch(0, i, ACS_HLINE);
	}
	mvaddstr(2, 33, "STATS CALC");
	for(int i = 0; i < 80; i++){
		mvaddch(5, i, ACS_HLINE);
	}
    
    ms_init_choice();
	//ms_select_choice();
}

void ms_init_choice(){
	attron(A_REVERSE);
	mvaddstr(DEFAULT_Y, 0, "What would you like to do?(Press f to select)");
	attroff(A_REVERSE);
	mvaddstr(DEFAULT_Y + 2, 0, "Combinations and Permutations");
	mvaddstr(DEFAULT_Y + 4, 0, "Distributions");
	mvaddstr(DEFAULT_Y + 6, 0, "Matricies and Markov Chains");
}

int ms_select_choice(){
    int key, selected;
    refresh();
	while((key = getch()) != 'q'){
		switch(key){
			case '1':
				attroff(A_STANDOUT);
				ms_init_choice();
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
				ms_init_choice();
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
				ms_init_choice();
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 6, 0, "Matricies and Markov Chains");
				refresh();
				selected = 3;
				move(DEFAULT_Y + 8,  0);
				clrtoeol();
				break;
				//return 2;

			case 'f':
                return selected;

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

void pc_init(){
    move(DEFAULT_Y, 0);
	clrtobot();
    attron(A_STANDOUT);
    mvaddstr(DEFAULT_Y, 0, "Welcome to the Permutations and Combinations Calculator!\n(press q or select back to go back)");
    attroff(A_STANDOUT);
    mvaddstr(DEFAULT_Y + 3, 0, "Permutations");
    mvaddstr(DEFAULT_Y + 5, 0, "Combinations");
    mvaddstr(DEFAULT_Y + 7, 0, "Back");
}

int pc_choice(){
    int key, selected;
    refresh();
    while((key = getch()) != 'q'){
        switch(key){
            case '1':
				attroff(A_STANDOUT);
				pc_init();
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 3, 0, "Permutations");
				refresh();
				selected = 1;
				move(DEFAULT_Y + 8,  0);
				clrtoeol();
				break;

			case '2':
				attroff(A_STANDOUT);
				pc_init();
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 5, 0, "Combinations");
				refresh();
				selected = 2;
				move(DEFAULT_Y + 8,  0);
				clrtoeol();
				break;
			
			case '3':
				attroff(A_STANDOUT);
				pc_init();
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 7, 0, "Back");
				refresh();
				selected = 3;
				move(DEFAULT_Y + 8,  0);
				clrtoeol();
				break;

			case 'f':
                return selected;

			default:
				mvaddstr(DEFAULT_Y + 9, 0, "Press another key");
				refresh();
				break;
		}
		//attroff(A_BOLD);
		refresh();
    }
    return selected;
}