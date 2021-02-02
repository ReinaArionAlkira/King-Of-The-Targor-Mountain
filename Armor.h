#pragma once

#include "Item.h"

class Armor:
	public Item{
private:

public:
	Armor();
	virtual~Armor();

	//Pure virtual
	virtual Armor* clone() const;
};

