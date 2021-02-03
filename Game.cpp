#include "Game.h"

//zrobiæ pozycjonowanie na boardzie !!!

Game::Game() {
	this->max_lvl = 0;
	this->play = true;
}
Game::~Game() {
}

//Functions
void Game::menu() {
	readFile("menu.txt");
	cout << "= ";
	string input;
	cin >> input;
	
	if (input.size() == 1) {
		command = input[0];
		switch (command) {
		case '1':
			start();
			break;
		case '2':
			readFile("about.txt");
			back_to_menu();
			break;
		case '3':
			readFile("guide.txt");
			back_to_menu();
			break;
		case '4':
			cout << "Gra zostanie wylaczona...";
			Sleep(1000);
			play = false;
			break;
		default:
			cout << "Nie ma takiej opcji!";
			Sleep(1000);
			menu();
		}
	}
	else {
		cout << "Wprowadzono za duzo znakow!";
		Sleep(1500);
		menu();
	}
}
void Game::start() {
	createCharacter();
	this->player.getStats();

}
void Game::createCharacter() {
	string name;
	int command2{};
	string clas;
	string input;
	cout << "Podaj imie twojej postaci" << endl << "= ";
	cin.ignore();
	getline(cin, name);
	cout << "Podaj plec postaci [F/M]" << endl << "= ";
	while (true) {
		cin >> input;
		if (input.size() > 1) {
			cout << "Wprowadzono za duzo znakow!" << endl << "= ";
			cin.ignore(100, '\n');
			continue;
		}
		command = input[0];
		if (command == 'F' || command == 'f' || command == 'm' || command == 'M') {
			break;
		}
		cout << "Niepoprawne dane!" << endl << "= ";
	}
	cout << endl;
	system("cls");
	readFile("classes.txt");
	cout << "Ktora klase wybierasz?" << endl << "= ";
	bool isGood = true;
	while (isGood) {
		isGood = false;
		cin >> command2;
		if (cin.fail()) {
			cout << "Nie ma takiej komendy!" << endl << "= ";
			cin.ignore(100, '\n');
			isGood = true;
			continue;
		}
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
		case 4:
			clas = "Pirat";
			break;
		default:
			cout << "Nie ma takiej komendy!" << endl;
			isGood = true;
			break;
		}
	}
	this->player.initialize(name, command, clas);

}
void Game::back_to_menu(int which) {
	cout << "Chcesz wrocic do menu? Wpisz litere T i zatwierdz enterem" << endl << "= ";
	string input;
	cin >> input;
	//cin.ignore(100, '\n');
	//cout << com;
	bool isGood = true;
	while (isGood) {
		cin >> input;
		if (input.size() > 1) {
			cout << "Wprowadzono za duzo znakow!" << endl << "= ";
			Sleep(1500);
			cin.ignore(100, '\n');
			continue;
		}
		command = input[0];
		if (command == 'T' || command == 't') {
			isGood = false;
			switch (which) {
			case 0:
				menu();
				break;
			case 1:
				menuInGame();
				break;
			case 2:
				menuInventory(this->player);
				break;
			}
		}
		else {
			cout << "Podales zly znak!" << endl << "= ";
			cin >> input;
		}
	}

}

void Game::menuInGame() {
	Event ev;
	readFile("menuInGame.txt");
	cout << "= ";
	string input;
	cin >> input;
	command = input[0];
	if (input.size() > 1) {
		cout << "Wprowadzono za duzo znakow!";
		Sleep(1500);
		menuInGame();
	}
	switch (command) {
	case '1': // RUCH
		this->player.move();
		ev.generateEvent(this->player, this->enemies);
		break;
	case '2': // EKWIPUNEK
		menuInventory(this->player);
		back_to_menu(1);
		break;
	case '3': // SKLEP (kupowanie poziomu)
		shop();
		back_to_menu(1);
		break;
	case '4': // Wyjœcie
		cout << "Gra zostanie wylaczona...";
		Sleep(1000);
		play = false;
		end();
		exit(0);
		break;
	default:
		cout << "Nie ma takiej opcji!";
		Sleep(1500);
		menuInGame();
	}
}
void Game::menuInventory(Player& player) {
	readFile("menuInventory.txt");
	cout << "= ";
	string input;
	cin >> input;
	command = input[0];
	if (input.size() > 1) {
		cout << "Wprowadzono za duzo znakow!";
		Sleep(1500);
		menuInventory(player);
	}
	switch (command) {
	case '1': // uzyj przedmiotu

		break;
	case '2': // sprzedaj przedmiot

		break;
	case '3': // kup poziom
		break;
	case '4': // powrot do mapy
		menuInGame();
		break;
	case '5':
		cout << "Gra zostanie wylaczona...";
		Sleep(1000);
		play = false;
		end();
		exit(0);
		break;
	default:
		cout << "Nie ma takiej opcji!";
		Sleep(1500);
		menuInventory(player);
	}
}

void Game::shop() {

}

void Game::board() {


}

void Game::end() {
	//czyszczenie danych o graczach
	ofstream file;
	file.open("text_files/players/players.txt", ios::trunc);
	file << "";
	file.close();
}