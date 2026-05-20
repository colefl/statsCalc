#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "io.cpp"

int main(int argc, char *argv[]){
// 	mvaddstr(0, 0, "________________________________________________________________________________

// 	█     ███        █        ███                ██        █        █                ██
//        █            █        █    █        █                █           █    █    █             █
//  	█	 █        █    █        █                █           █    █    █             █
//        █		 █        █    █        █                    ██   █     █    ███         ██

// ________________________________________________________________________________");
	init_terminal();
	int ms_selection = ms_select_choice();
	if(ms_selection == 1){
		pc_init();
		pc_choice();
	}
	return ms_selection;
}