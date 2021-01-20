#pragma once
#include "Item.h"
class Inventory{
private:
	int nrOfItems;
	Item** itemArr;
	void initialize(const int from);


public:
	Inventory();
	virtual ~Inventory();

	void addItem(const Item& item);
	void removeItem(int index);
};

