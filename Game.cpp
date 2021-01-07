#include "Game.h"


Game::Game() {
	this->command = 0;
	this->max_lvl = 0;
	this->play = true;
}
Game::~Game() {
}

//Functions
void Game::menu() {
	string line;
	system("cls");
	ifstream file("pliki_tekstowe/menu.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			cout << line << endl;
		}
	}
	else {
		cout << "Nie mozna otworzyc pliku!" << endl;
	}
	file.close();
	cout << "= ";
	cin >> command;
	switch (command) {
	case '1':
		start();
		break;
	case '2':
		option("about.txt");
		break;
	case '3':
		option("guide.txt");
		break;
	case '4':
		cout << "Gra zostanie wylaczona...";
		Sleep(1000);
		play = false;
		exit(0);
		break;
	default:
		cout << "Nie ma takiej opcji!";
		Sleep(1500);
		menu();
	}
}
void Game::start() {

}

void Game::back_to_menu() {
	cout << "Chcesz wrocic do menu? Wpisz litere T i zatwierdz enterem" << endl;
	cin >> command;
	bool isGood = true;
	while (isGood) {
		if (command == 'T' || command == 't') {
			isGood = false;
			menu();
		}
		else {
			cout << "Podales zly znak!" << endl;
			cin >> command;
		}
	}
}
void Game::option(string f) {
	string line;
	system("cls");
	ifstream file("pliki_tekstowe/"+f);
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			cout << line << endl;
		}
	}
	else {
		cout << "Nie mozna otworzyc pliku!" << endl;
	}
	file.close();
	back_to_menu();
}

void Game::board() {


}

