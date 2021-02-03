#pragma once

#include "Inventory.h"
#include "Enemy.h"

class Player{
private:
	int xPos;
	int yPos;

	Inventory inventory;
	Weapon weapon;
	Armor armor;

	string nickname;
	char sex;
	string cClass;
	int lvl;
	int strength;
	int luck;

public:
	Player();
	virtual ~Player();
	//Functions
	void getStats();
	void fight();
	void escape();
	void move();
	//Initialize
	Player initialize(const string nickname, char sex, string clas);

	//Accessors
	inline const int& getX() const { return this->xPos; };
	inline const int& getY() const { return this->yPos; };
	inline const int& getLvl() const { return this->lvl; };
	inline const int& getStrength() const { return this->strength; };
	inline const string& getNickname() const { return this->nickname; };
	inline const char& getSex() const { return this->sex; };
	inline const string& getcClass() const { return this->cClass; };


	//Modifiers
	inline void levelUp() { this->lvl++; }
	inline void levelDown() { if(this->lvl > 1) this->lvl--; }
	inline void changeSex() { this->sex == 'F' ? this->sex = 'M' : this->sex = 'F'; }
	/*void add_class();
	void change_sex();
	void wear();*/
	//void cClas(); //character class
};

