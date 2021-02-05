#pragma once

#include "Item.h"

enum armorType {HEAD = 0, CHEST, ARMS, LEGS};

class Armor:
	public Item{
private:
	int type;
	int strength;
	string typeStr;
	
public:
	Armor();
	Armor(int strength);
	Armor(int type, int strength, string name, int value);
	virtual~Armor();

	//Pure virtual
	virtual Armor* clone() const;
	string getStatsAsString()const;

	//Accessors
	inline int getStrength() const { return this->strength; }
	inline int getType() const { return this->type; }
	inline const string& getTypeStr() const { return this->typeStr; }
	//Static
	
	string names[5] = { "Bawelniana Szmatka",
		"Fajne Binokle",
		"Nocne Portki",
		"Czapka Ogrodnika",
		"Zelazne Rekawice" 
	};
};

