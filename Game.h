#pragma once
#include <windows.h>
#include <fstream>
#include "Player.h"

class Game {
	
private:
	//variables
	int max_lvl;
	string command;
	bool play;
public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void menu();
	void start();
	void option(string file);
	void back_to_menu();
	void board();

	//Accessors
	bool Play() const { return this->play; };

};




