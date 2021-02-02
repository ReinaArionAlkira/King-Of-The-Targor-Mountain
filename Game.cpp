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
	createCharacter();
	player.getStats();

}
void Game::createCharacter() {
	string command1;
	int command2{};
	string clas;
	cout << "Podaj imie twojej postaci" << endl;
	cin.ignore();
	getline(cin, command);
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
		case 0:
			clas = "Lotr";
			break;
		case 1:
			clas = "Mag";
			break;
		case 2:
			clas = "Wojownik";
			break;
		case 3:
			clas = "";
			break;
		default:
			cout << "Nie ma takiej komendy!" << endl;
			isGood = true;
			break;
		}
	}
	player.initialize(command, command1, clas);

}
void Game::back_to_menu(int which) {
	cout << "Chcesz wrocic do menu? Wpisz litere T i zatwierdz enterem" << endl;
	cin >> command;
	char com = command[0];
	bool isGood = true;
	while (isGood) {
		if (com == 'T' || com == 't') {
			isGood = false;
			switch (which) {
			case 0:
				menu();
			case 1:
				menuInGame();
			case 2:
				menuInventory();
			}
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

void Game::menuInGame() {
	option("menuInGame.txt");
	cout << "= ";
	cin >> command;
	char com = command[0];
	switch (com) {
	case '1':
		player.move();
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
void Game::menuInventory(Player& player) {
	option("menuInventory.txt");
	cout << "= ";
	cin >> command;
	char com = command[0];
	switch (com) {
	case '1':
		player.move();
		break;
	case '2':
		menuInventory(player);
		break;
	case '3':
		shop();
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

void Game::shop() {

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