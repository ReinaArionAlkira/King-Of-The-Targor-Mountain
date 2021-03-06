#pragma once

#include "GlobalFunctions.h"

class Enemy {
private:
	int index;
	string name;
	int strength;
	//dodatkowe lub ujemne obra�enia przeciw danej klasie
	int clasAd;
	int adds;

public:
	Enemy(int idx = 0, string = "mobs.txt");
	virtual ~Enemy();
	//Functions
	inline bool isAlive() { return this->strength != 0; };
	inline const int& getStrength() const { return this->strength; };
	inline const string& getName() const { return this->name; };
	//Modifiers
	void changeStrength();
	void getStats();
};