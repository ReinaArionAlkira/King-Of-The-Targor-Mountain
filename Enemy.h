#pragma once
#include "GlobalFunctions.h"

class Enemy {
private:
	int strength;
	int index;
	int adds;

public:
	Enemy();
	virtual ~Enemy();
	//Functions
	inline bool isAlive() { return this->strength != 0; };
	//Modifiers
	void changeStrength();
	void getStats(int index = 0);
};

