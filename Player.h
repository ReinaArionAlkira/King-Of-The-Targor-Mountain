#pragma once
#include "Game.h"


class Player{
private:
	int xPos;
	int yPos;

	int lvl;
	int strength;
	string nickname;
	string sex;

public:
	Player();
	virtual ~Player();
	//Functions
	void getStats();
	void create();
	void fight();
	void escape();

	//Initialize
	void initialize(const string nickname, string sex);

	//Accessors
	inline const int& getX() const { return this->xPos; };
	inline const int& getY() const { return this->yPos; };
	inline const int& getLvl() const { return this->lvl; };
	inline const int& getStrength() const { return this->strength; };
	inline const string& getNickname() const { return this->nickname; };
	inline const string& getSex() const { return this->sex; };
	/*void add_class();
	void change_sex();
	void wear();*/
};

