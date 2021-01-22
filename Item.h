#pragma once
#include "Includes.h"

class Item {
private:
	string name;
	int value;

public:
	Item(string name = "Nic", int value = 0);
	~Item();

	inline string debug() const { return name; }
	virtual Item* clone() const = 0;
	//Accessors
	inline const string& getName() const { return this->name; };
	inline const int& getValue() const {return this->value; };

	//Modifiers
	
};

