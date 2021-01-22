#include "Game.h"


Game::Game() {
	this->command = "";
	this->max_lvl = 0;
	this->play = true;
}
Game::~Game() {
}

//Functions
void Game::menu() {
	option("menu.txt");
	cout << "= ";
	cin >> command;
	char com = command[0];
	switch (com) {
	case '1':
		start();
		break;
	case '2':
		option("about.txt");
		back_to_menu();
		break;
	case '3':
		option("guide.txt");

		break;
	case '4':
		cout << "Gra zostanie wylaczona...";
		Sleep(1000);
		play = false;
		end();
		exit(0);
		break;
	default:
		cout << "Nie ma takiej opcji!";
		Sleep(1500);
		menu();
	}
}
void Game::start() {
	Player player1;
	string command1;
	int command2{};
	string clas;
	cout << "Podaj imie twojej postaci" << endl;
	cin.ignore();
	cin >> command;
	while (true) {
		cout << "Podaj plec postaci [F/M]" << endl;
		cin >> command1;
		command1 = command1[0];
		if (command1 == "f" || command1 == "F" || command1 == "M" || command1 == "m") {
			break;
		}
		cout << "Niepoprawne dane!" << endl;
	}
	cout << endl;
	system("cls");
	option("classes.txt");
	cout << "Ktora klase wybierasz?" << endl;
	bool isGood = true;
	while (isGood) {
		isGood = false;
		cin >> command2;
		switch (command2) {
		case 1:
			clas = "Lotr";
			break;
		case 2:
			clas = "Mag";
			break;
		case 3:
			clas = "Wojownik";
			break;
		default:
			cout << "Nie ma takiej komendy!" << endl;
			isGood = true;
			break;
		}
	}
	player1.initialize(command, command1, clas);
}

void Game::back_to_menu() {
	cout << "Chcesz wrocic do menu? Wpisz litere T i zatwierdz enterem" << endl;
	cin >> command;
	char com = command[0];
	bool isGood = true;
	while (isGood) {
		if (com == 'T' || com == 't') {
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
}


void Game::board() {


}

void Game::end() {
	//czyszczenie danych o graczach
	ofstream file;
	file.open("pliki_tekstowe/players.txt", ios::trunc);
	file << "";
	file.close();
}