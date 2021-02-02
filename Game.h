#pragma once

#include "Event.h"

class Game {
	
private:
	//variables
	int max_lvl;
	string command;
	bool play;
	Player player;
public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void createCharacter();
	void start();
	void option(string file);
	void back_to_menu(int which = 0);
	void board();
	void end();
	void shop();

	//Menu
	void menu();
	void menuInGame();
	void menuInventory(Player& player);

	//Accessors
	bool Play() const { return this->play; };

};




