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
	
	//Enemies
	DynamicArray<Enemy> enemies;

public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void createCharacter();
	void start();
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




