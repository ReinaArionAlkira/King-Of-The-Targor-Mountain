#pragma once

#include "Weapon.h"
#include "Armor.h"

class Inventory{
private:
	int capacity;
	int nrOfItems;
	Item** itemArr;
	void initialize(const int from = 0);
	void expand();

public:
	Inventory();
	virtual ~Inventory();
	Inventory(const Inventory& obj);
	
	inline int size()const { return this->nrOfItems; };
	Item& operator[](const int index);
	void operator=(const Inventory& obj);
	void addItem(const Item& item);
	void removeItem(int index);
	inline void debug() const {
		for (int i = 0; i < this->nrOfItems; i++)
		{
			cout << this->itemArr[i]->debug() << endl;
		}
	}
};

