#pragma once

#include "Includes.h"
#include "Player.h"
#include "DynamicArray.h"

class Event{
private:
	int nrOfEvents;
public:
	Event();
	virtual~Event();

	void generateEvent(Player& player, DynamicArray<Enemy>& enemies);
	void enemyEncounter(Player& player, DynamicArray<Enemy>& enemies);
	void getCurse(Player& player);
};

