#pragma once

#include "Includes.h"
#include "Player.h"

class Event{
private:
	int nrOfEvents;
public:
	Event();
	virtual~Event();

	void generateEvent(Player& player);
	void enemyEncounter(Player& player);
	void getCurse(Player& player);
	void escape(Player& player, Enemy& enemy, bool &escaped, bool &playerDefeted);
};

