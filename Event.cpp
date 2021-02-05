#include "Event.h"

Event::Event() {
	this->nrOfEvents = 1;
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
	//case 2:
	//	//Skarb
	//	break;
	}
}

void Event::enemyEncounter(Player &player) {
	int enemiesStrength = 0;
	char command;
	string input;

	//Losowanie rodzaju przeciwnika
	int idx = rand() % 5;
	Enemy enemy(idx);

	//Warunki zakoñczenia walki
	bool escaped = false;
	bool playerDefeted = false;
	bool enemiesDefeted = false;


	//Przebieg walki
	while (!escaped && !enemiesDefeted && !playerDefeted) {
		//Menu
		readFile("menuBattle.txt");
		enemy.getStats();
		cout << endl;
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
		case '1': //Atak
		//Sprawdzenie si³y obu stron
			if (enemy.getStrength() >= player.getStrength()) {
				playerDefeted = true;
			}
			//Wygrana gracza
			else {
				enemiesDefeted = true;
			}
			break;
		case '2': //Ucieczka, czyli rzut koœci¹ + szczêœcie postaci
				escape(player, enemy, escaped, playerDefeted);
			break;
		
		//case '3': //U¿ycie przedmiotu
		case '3':
			cout << "Gra zostanie wylaczona...";
			Sleep(1000);
			exit(0);
			break;
		default:
			cout << "Nie ma takiej opcji!";
			Sleep(1000);

		}
	}
	//Jeœli ciê pokonali (lub nie uda³o ci siê uciec) to przyjmujesz karê i tracisz poziom
	if (playerDefeted) {
		cout << endl << "Przegrales!" << endl;
		if (player.getLvl() > 1) {
			cout << "Tracisz poziom!" << endl;
			player.levelDown();
		}
	}
	else if (escaped) {
		cout << "Uciekasz!" << endl;
	}
	else {
		cout << "Pokonales wroga!" << endl 
			<< "Zyskujesz poziom!" << endl;
		player.levelUp();
		//Losowanie przedmiotow i ich iloœci
		int rollNr = rand() % 2 + 1;
		int roll = rand() % 100;
		for (int i = 0; i < rollNr; i++){
			if (roll > 0 && roll <= 45) {
				Weapon tempW(1);
				player.addItem(tempW);
				cout << "Zdobywasz bron!" << endl;
			}
			else if (roll > 45 && roll <= 90) {
				Armor tempA(1);
				player.addItem(tempA);
				cout << "Zdobywasz zbroje!" << endl;
			}
			else {
				player.levelUp();
				cout << "Zdobywasz skarb: DODATKOWY POZIOM!" << endl;
			}
		}
		
	}
	cout << "Wpisz cokolwiek i wcisnij Enter, by kontynuowac..." << endl;
	cin.get();
	cin.ignore();

}
void Event::escape(Player& player, Enemy& enemy, bool& escaped, bool& playerDefeted) {
	int diceToss;
	diceToss = (rand() % 6 + 1) + player.getLuck();
	cout << "= Aby uciec potrzebujesz wyrzucic na kosci wiecej niz 4 (twoje szczescie zwieksza mozliwosci)" << endl;
	cout <<"= Wylosowales: " << diceToss;
	if (diceToss >= 5) {
		cout << "Udalo ci sie zwiac!" << endl;
		escaped = true;
	}
	else {
		cout << "Nie udalo ci sie uciec!" << endl;
		playerDefeted = true;
	}
}
void Event::getCurse(Player &player){
	int i = rand() % 2;
	switch (i) {
	case 0:
		cout << "Kl¹twa! Tracisz poziom." << endl;
		player.levelDown();
		break;
	case 1:
		cout << "Kl¹twa! Zmieniasz p³eæ." << endl;
		player.changeSex();
		break;
	}
	Sleep(1500);
	
}