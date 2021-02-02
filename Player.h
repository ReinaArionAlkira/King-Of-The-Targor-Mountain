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

	int lvl;
	int strength;
	string nickname;
	string sex;
	string cClass;
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
	Player initialize(const string nickname, string sex, string clas);

	//Accessors
	inline const int& getX() const { return this->xPos; };
	inline const int& getY() const { return this->yPos; };
	inline const int& getLvl() const { return this->lvl; };
	inline const int& getStrength() const { return this->strength; };
	inline const string& getNickname() const { return this->nickname; };
	inline const string& getSex() const { return this->sex; };
	inline const string& getcClass() const { return this->cClass; };

	inline void levelUp() { this->lvl++; }
	inline void levelDown() { if(this->lvl > 1) this->lvl--; }
	inline void changeSex() { this->sex == "F" ? this->sex = "M" : this->sex = "F"; }
	/*void add_class();
	void change_sex();
	void wear();*/
	//void cClas(); //character class
};

