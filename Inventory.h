#pragma once
#include "Weapon.h"
#include "Armor.h"

class Inventory{
private:
	int capacity;
	int nrOfItems;
	Item** itemArr;
	void initialize(const int from);
	void expand();

public:
	Inventory();
	virtual ~Inventory();

	void addItem(const Item& item);
	void removeItem(int index);
	inline void debug() const {
		for (int i = 0; i < this->nrOfItems; i++)
		{
			cout << this->itemArr[i]->debug() << endl;
		}
	}
};

