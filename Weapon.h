#pragma once

#include "Item.h"

class Weapon:
	public Item {

private:
	int strength;
	
public:
	Weapon();
	Weapon(int strength);
	Weapon(int strength, string name, int value);
	virtual~Weapon();
	//Pure virtual
	virtual Weapon* clone() const;

	//Functions

	//Accessors
	inline int getStrength() const { return this->strength; }
	string getStatsAsString() const;
	//Modifiers

	//Static
	string names[5] = { "Noz do masla",
		"Nozyce",
		"Katana",
		"Potezny mlot",
		"Marna palka"
	};
};


