#pragma once

#include "Inventory.h"
#include "Enemy.h"

class Player{
private:
	int xPos;
	int yPos;

	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;
	int gold;

	string nickname;
	char sex;
	string cClass;
	int lvl;
	int strength;
	int luck;

public:
	Player();
	virtual ~Player();

	//Initialize
	Player initialize(const string nickname, char sex);

	//Accessors
	inline const int& getX() const { return this->xPos; };
	inline const int& getY() const { return this->yPos; };
	inline const int& getLvl() const { return this->lvl; };
	inline const int& getStrength() const { return this->strength; };
	inline const int& getLuck() const { return this->luck; };
	inline const string& getNickname() const { return this->nickname; };
	inline const char& getSex() const { return this->sex; };
	inline const int getInventorySize()const { return this->inventory.size(); }
	//inline const string& getcClass() const { return this->cClass; };

	//Functions
	void addItem(const Item& item) { this->inventory.addItem(item);  }
	void getStats();
	string getInvAsString();
	inline void levelUp() { this->lvl++; this->strength++; }
	inline void levelDown() { if(this->lvl > 1) this->lvl--; }
	inline void changeSex() { this->sex == 'F' ? this->sex = 'M' : this->sex = 'F'; }
	void updateStrength() {
		this->strength = (this->strength 
			+ this->weapon.getStrength()
			+ this->armor_head.getStrength()
			+ this->armor_chest.getStrength()
			+ this->armor_arms.getStrength()
			+ this->armor_legs.getStrength());
	};
	void travel(int direction);
	void equipItem(unsigned index);
	void removeItem(const int index);

	//void add_class();
	//void cClas(); //character class
};

