#include "Event.h"

Event::Event() {
	this->nrOfEvents = 2;
}
Event::~Event() {

}

void Event::generateEvent(Player &player, DynamicArray<Enemy>& enemies) {
	int i = rand() % this->nrOfEvents;
	switch (i) {
	case 0:
		//Natrafienie na wroga
		enemyEncounter(player, enemies);
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

void Event::enemyEncounter(Player &player, DynamicArray<Enemy>& enemies) {
	char command;
	string input;
	bool escape = false;
	bool playerDefeted = false;
	bool enemiesDefeted = false;

	int nrOfEnemies = rand() % 3 + 1;
	for (int i = 0; i < nrOfEnemies; i++)
	{
		int idx = rand() % 4;
		enemies.push(Enemy(idx));
	}
	
	while (!escape && !enemiesDefeted && !playerDefeted) {
		//Menu
		readFile("menuBattle.txt");
		cout << "= ";
		cin >> input;
		if (input.size() > 1) {
			cout << "Wprowadzono za duzo znakow!" << endl << "= ";
			Sleep(1500);
			cin.ignore(100, '\n');
			cin >> input;
			continue;
		}
		command = input[0];
		cin.ignore(1000, '\n');
		switch (command) {
		case '1': //Ucieczka

			break;
		case '2': //Atak

			break;
		case '3': //U¿ycie przedmiotu
			
			break;
		case '4':
			cout << "Gra zostanie wylaczona...";
			Sleep(1000);
			exit(0);
			break;
		default:
			cout << "Nie ma takiej opcji!";
			Sleep(1000);

		}
		//conditions
		//if (!player.isAlive()) {
		//	playerDefeted = true;
		//}
		//else if (enemies.size()) {
		//	enemiesDefeted = true;
		//}
	}
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