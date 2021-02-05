#pragma once

#include "Event.h"


class Game {
	
private:
	//variables
	char command;
	string input;
	int max_lvl;
	bool play;
	Player player;
	char map[7][7];
	
	//Enemies
	Enemy enemy;

public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void createCharacter();
	void start();
	void back_to_menu(int which = 0);
	void board();
	void showBoard();
	void end();
	void shop();
	void makeAMove(Player& player);

	//Menu
	void menu();
	void menuInGame();
	void menuInventory(Player& player);

	//Accessors
	bool Play() const { return this->play; };

};




