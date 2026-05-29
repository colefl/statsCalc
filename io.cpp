#include "io.h"
#include "ComAndPerm.cpp"

void init_terminal(){
    initscr();
	raw();
	noecho();
	curs_set(0);
    keypad(stdscr, TRUE);

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
    mvaddstr(DEFAULT_Y + 8, 0, "Back");
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
				move(DEFAULT_Y + 10,  0);
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
				move(DEFAULT_Y + 10,  0);
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
				move(DEFAULT_Y + 10,  0);
				clrtoeol();
				break;
				//return 2;

			case '4':
				attroff(A_STANDOUT);
				ms_init_choice();
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 8, 0, "Quit");
				refresh();
				selected = 4;
				move(DEFAULT_Y + 10,  0);
				clrtoeol();
				break;

			case 'f':
                return selected;

			default:
				mvaddstr(DEFAULT_Y + 10, 0, "Press another key");
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
                move(DEFAULT_Y, 0);
                clrtobot();
                attroff(A_STANDOUT);
                return selected;

			default:
				mvaddstr(DEFAULT_Y + 9, 0, "Press another key");
				refresh();
				break;
		}
		//attroff(A_BOLD);
		//refresh();

    }
    attroff(A_STANDOUT);
    move(DEFAULT_Y, 0);
    clrtobot();
    return selected;
}

int perm_screen(){
    mvaddstr(DEFAULT_Y, 0, "Please input the values(select using arrow keys):");
    mvaddstr(DEFAULT_Y + 2, 0, "input 1: ___");
	mvaddstr(DEFAULT_Y + 4, 0, "input 2: ___");
	mvaddstr(DEFAULT_Y + 6, 0, "With Replacement? Yes No");
	mvaddstr(DEFAULT_Y + 8, 0, "Calculate:");
    int value1, value2;
	bool w_replacement;
    int key, selected;
    refresh();
	while((key = getch() != 'q')){
		//Kinda just a scroll
		while((key = getch()) != 'f'){
			switch(key){
				case KEY_LEFT:
				selected -= 1;
				//Okay so I still need to light up the correct one
				//mvaddstr(DEFAULT_Y + 2, 3, value1);
				
				case KEY_RIGHT:
				selected += 1;
			}
			if(selected == 0){
				selected = 3;
			} else if(selected == 1){
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 2, 9, "___");
				refresh();
			} else if(selected == 2){
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 4, 9, "___");
				refresh();
			} else if(selected == 3){
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 6, 0, "With Replacement?");
				refresh();
			} else if(selected == 4){
				attron(A_STANDOUT);
				mvaddstr(DEFAULT_Y + 6, 0, "Calculate");
				refresh();
			}
		}
        //refresh();
		if(selected == 1){
			value1 = init_selection();
			//std::cout << value1 << std::endl;
			attroff(A_STANDOUT);
			mvaddstr(DEFAULT_Y + 2, 9, "___");
			move(DEFAULT_Y + 2, 9);
			printw("%f", value1);
		} else if(selected == 2){
			value2 = init_selection();
			move(DEFAULT_Y + 4, 9);
			attroff(A_STANDOUT);
			printw("%f", value2);
		} else if(selected == 3){
			//mvaddstr(DEFAULT_Y + 6, 18, "Yes");
			int key2, selected2;
			while((key2 = getch()) != 'f'){
				switch(key2){
					case KEY_LEFT:
						selected2--;
						break;
					case KEY_RIGHT:
						selected2++;
						break;
				}
				if(selected2 <= 0){
					selected2 = 1;
					mvaddstr(DEFAULT_Y + 6, 18, "Yes");
					attroff(A_STANDOUT);
					mvaddstr(DEFAULT_Y + 6, 21, "No");
					w_replacement = true;
				}
				if(selected2 > 1){
					selected2 = 0;
					mvaddstr(DEFAULT_Y + 6, 21, "No");
					attroff(A_STANDOUT);
					mvaddstr(DEFAULT_Y + 6, 18, "Yes");
					w_replacement = false;
				}

			}
			attroff(A_STANDOUT);
		} else if(selected == 4){
			// if(value1 == NULL || value2 == NULL){
			// 	mvaddstr(DEFAULT_Y + 10, 0, "Please input values for both numbers");
			// } else {
			calcPermutations(value1, value2, w_replacement);
			//}
		}

		refresh();
    }
    return selected;
}

int init_selection(){
    //char[100] placeholder;
    //char* returnValStr = new char [256];
    int returnVal;
	std::cin >> returnVal;
	//std::cout << returnVal << std::endl;
    //int key;
    //while((key = getch()) != 'q'){
        //const char* str_msg = String("%f3", returnVal);
        //std::cin >> returnValStr; //I don't think I understand how this works
        // switch(key){
        //     case KEY_DL:
        //         if(strlen(returnValStr) < 0){
        //             std::cout << "I make it to where the string doesn't" << std::endl;
        //             break;
        //         } else {
        //             std::cout << "I make it to where the string has capacity" << std::endl;
        //             strncpy(returnValStr, returnValStr, sizeof (char) * (strlen(returnValStr) - 1)); //Deleting the last string
        //             break;
        //         }
        //     default:
        //         std::cout << "I make it to default "  << returnValStr << " hello" << std::endl;
        //         returnValStr += key;
        // }
        // //returnValStr += key;
        // returnVal = strtof(returnValStr, NULL);
        // std::cout << returnVal << std::endl;
        // //move(DEFAULT_Y + 2, 2);
        // //printw("%3.0f", returnVal);
        // refresh();

        
    //}
    return returnVal;
}

