#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <iomanip> 

using namespace std;

class Game {
	
private:
	//variables
	int max_lvl;
	char command;
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




