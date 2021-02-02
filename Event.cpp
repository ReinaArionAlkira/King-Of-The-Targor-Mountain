#include "Event.h"

Event::Event() {
	this->nrOfEvents = 2;
}
Event::~Event() {

}

void Event::generateEvent(Player &player) {
	int i = rand() % this->nrOfEvents;
	switch (i) {
	case 0:
		//Natrafienie na wroga
		enemyEncounter(player);
		break;
	case 1:
		//Kl¹twa
		getCurse(player);
		break;
	case 2:
		//Skarb
		break;

	}
}

void Event::enemyEncounter(Player &player) {

}

void Event::getCurse(Player &player){
	int i = rand() % 3;
	switch (i) {
	case 0:
		cout << "Kl¹twa! Tracisz poziom." << endl;
		player.levelDown();
		break;
	case 1:
		cout << "Kl¹twa! Zmieniasz p³eæ." << endl;
		player.changeSex();
		break;
	case 2:

		break;

	}
	
}