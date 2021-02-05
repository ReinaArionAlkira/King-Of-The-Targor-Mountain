#pragma once

#include "Includes.h"

enum itemTypes { WEAPON = 0, ARMOR };

class Item {
private:
	string name;
	int value;
	int itemType;

public:
	Item();
	Item(int itemType);
	Item(int itemType, string name, int value);
	~Item();

	inline string debug() const { return name; }
	virtual Item* clone() const = 0;
	virtual string getStatsAsString() const = 0;
	//virtual std::string toStringSave()const = 0;
	//Accessors
	inline const string& getName() const { return this->name; };
	inline const int& getValue() const {return this->value; };
	inline const int& getItemType() const { return this->itemType; }

	//Modifiers
	inline void setName(string name) { this->name = name; }


};

