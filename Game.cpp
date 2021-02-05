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
	board();
	Inventory inv;
	Weapon w1(1);
	Armor a1(1);
	this->player.addItem(w1);
	this->player.addItem(a1);

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
	/*readFile("classes.txt");
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
	}*/

	this->player.initialize(name, command);

}
void Game::back_to_menu(int which) {
	cout << "Chcesz wrocic do menu? Wpisz litere T i zatwierdz enterem" << endl << "= ";
	string input;
	bool isGood = true;
	while (isGood) {
		cin >> input;
		if (input.size() > 1) {
			cout << "Wprowadzono za duzo znakow!" << endl << "= ";
			Sleep(1000);
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
		Sleep(1000);
		menuInGame();
	}
	switch (command) {
	case '1': // RUCH
		makeAMove(this->player);
		ev.generateEvent(this->player);
		break;
	case '2': //Statystyki
		this->player.getStats();
		back_to_menu(1);
		break;
	case '3': // EKWIPUNEK
		menuInventory(this->player);
		back_to_menu(1);
		break;
	case '4': // Sklep (kupowanie poziomu)
		shop();
		menuInGame();
		break;
	case '5': // Wyjœcie
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
		break;
	}
}
void Game::menuInventory(Player& player) {
	int choice{};
	readFile("menuInventory.txt");
	cout << "= ";
	string input;
	cin >> input;
	if (input.size() > 1) {
		cout << "Wprowadzono za duzo znakow!";
		Sleep(1500);
		cin.ignore(100, '\n');
		menuInventory(this->player);
	}
	command = input[0];
	cin.ignore(1000, '\n');
	switch (command) {
	case '1': // za³ó¿ przedmiot	
		cout << this->player.getInvAsString(); 
		cout << "Index przedmiotu: " << endl << "= ";
		cin >> choice;

		while (cin.fail() || choice < 0 || choice >= this->player.getInventorySize()) {
			cout << "Niepoprawne dane!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Index przedmiotu: " << endl << "= ";
			cin >> choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		this->player.equipItem(choice);
		this->player.updateStrength();

		break;
	case '2': // poka¿ przedmioty
		cout << player.getInvAsString();
		break;
	case '3': // powrot do mapy
		menuInGame();
		break;
	case '4': // Wyjœcie z gry
		cout << "Gra zostanie wylaczona...";
		Sleep(1000);
		play = false;
		end();
		exit(0);
		break;
	default:
		cout << "Nie ma takiej opcji!";
		Sleep(1500);
		menuInventory(this->player);
	}
}

void Game::makeAMove(Player& player) {
	system("cls");
	string input;
	char command;
	bool isGood = true;
	while (isGood) {
		cout << endl <<
			" = Twoja pozycja: " << this->player.getX() << ", " << this->player.getY() << endl;
		this->showBoard();
		cout << "= W ktora strone? = " << endl
			<< "= 1. W lewo. =" << endl
			<< "= 2. W prawo. =" << endl
			<< "= 3. W gore. =" << endl
			<< "= 4. W dol. =" << endl
			<< "= ";
		cin >> input;
		if (input.size() > 1) {

			cout << "Wprowadzono za duzo znakow!" << endl << "= ";
			cin.ignore(100, '\n');
			continue;
		}
		command = input[0];
		cin.ignore(1000, '\n');
		system("cls");
		switch (command) {
		case '1': //Lewo
			if (this->player.getY() == 0
				|| (this->player.getX() >= 1 && this->player.getX() <= 5 && this->player.getY() == 1)
				|| (this->player.getX() >= 2 && this->player.getX() <= 4 && this->player.getY() == 2))
				cout << "Nie mozesz tam zejsc!" << endl;
			else if (((this->player.getX() >= 1 && this->player.getX() <= 5 && this->player.getY() == 6 && this->player.getLvl() <= 4)
				|| (this->player.getX() >= 2 && this->player.getX() <= 4 && this->player.getY() == 5 && this->player.getLvl() <= 6)
				|| (this->player.getX() == 3 && this->player.getY() == 5 && this->player.getLvl() <= 9)))
				cout << "Nie mozesz tam wejsc!" << endl;
			else {
				isGood = false;
				this->map[this->player.getX()][this->player.getY()] = 'X';
				this->player.travel(1);
				this->map[this->player.getX()][this->player.getY()] = '@';
			}
			break;
		case '2': //Prawo
			if (this->player.getY() == 6
				|| (this->player.getX() >= 1 && this->player.getX() <= 5 && this->player.getY() == 5)
				|| (this->player.getX() >= 2 && this->player.getX() <= 4 && this->player.getY() == 4))
				cout << "Nie mozesz tam zejsc!" << endl;
			else if (((this->player.getX() >= 1 && this->player.getX() <= 5) && this->player.getY() == 0 && this->player.getLvl() <= 4)
				|| ((this->player.getX() >= 2 && this->player.getX() <= 4) && this->player.getY() == 1 && this->player.getLvl() <= 6)
				|| (this->player.getX() == 3 && this->player.getY() == 5 && this->player.getLvl() <= 9))
				cout << "Nie mozesz tam wejsc!" << endl;
			else {
				isGood = false;
				this->map[this->player.getX()][this->player.getY()] = 'X';
				this->player.travel(2);
				this->map[this->player.getX()][this->player.getY()] = '@';
			}
			break;
		case '3': //Góra
			if (this->player.getX() == 0
				|| (this->player.getY() >= 1 && this->player.getY() <= 5 && this->player.getX() == 1)
				|| (this->player.getY() >= 2 && this->player.getY() <= 4 && this->player.getX() == 2))
				cout << "Nie mozesz tam zejsc!" << endl;
			else if (((this->player.getY() >= 1 && this->player.getY() <= 5 && this->player.getX() == 6 && this->player.getLvl() <= 4)
				|| (this->player.getY() >= 2 && this->player.getY() <= 4 && this->player.getX() == 5 && this->player.getLvl() <= 6)
				|| (this->player.getY() == 3 && this->player.getX() == 5 && this->player.getLvl() <= 9)))
				cout << "Nie mozesz tam wejsc!" << endl;
			else {
				isGood = false;
				this->map[this->player.getX()][this->player.getY()] = 'X';
				this->player.travel(3);
				this->map[this->player.getX()][this->player.getY()] = '@';
			}
			break;
		case '4': //Dó³
			if (this->player.getX() == 6
				|| (this->player.getY() >= 1 && this->player.getY() <= 5 && this->player.getX() == 5)
				|| (this->player.getY() >= 2 && this->player.getY() <= 4 && this->player.getX() == 4))
				cout << "Nie mozesz tam zejsc!" << endl;
			else if (((this->player.getY() >= 1 && this->player.getY() <= 5 && this->player.getX() == 0 && this->player.getLvl() <= 4)
				|| (this->player.getY() >= 2 && this->player.getY() <= 4 && this->player.getX() == 1 && this->player.getLvl() <= 6)
				|| (this->player.getY() == 3 && this->player.getX() == 2 && this->player.getLvl() <= 9)))
				cout << "Nie mozesz tam wejsc!" << endl;
			else {
				isGood = false;
				this->map[this->player.getX()][this->player.getY()] = 'X';
				this->player.travel(4);
				this->map[this->player.getX()][this->player.getY()] = '@';
			}
			break;
		default:
			cout << "Nie ma takiej opcji!";
			Sleep(1500);
			break;
		}
	}
		cout << endl<< 
			"Twoja pozycja: " << this->player.getX() << ", " << this->player.getY() << endl;
		this->showBoard();
		Sleep(2000);
	
}
void Game::shop() {
	system("cls");
	cout << "===========================" << endl
		<< "=	Sklep		  =" << endl 
		<< "=			  =" << endl
		<< "= Co chcesz zrobic?	  =" << endl
		<< "= 1. Kup poziom.	  =" << endl
		<< "= 2. Sprzedaj przedmioty. =" << endl
		<< "= 3. Powrot do mapy.	  ="<< endl
		<< "= Twoje zloto: " << this->player.getGold() << endl 
		<< "===========================" << endl << endl;
	cout << "= ";
	string input;
	int choice{};
	cin >> input;
	if (input.size() > 1) {
		cout << "Wprowadzono za duzo znakow!";
		Sleep(1500);
		cin.ignore(100, '\n');
		menuInventory(this->player);
	}
	command = input[0];
	cin.ignore(1000, '\n');
	switch (command) {
	case '1'://Kup poziom

		if (this->player.getLvl() == 9) {
			cout << "Nie mozesz kupic ostatniego poziomu!" << endl;

		}
		else if (this->player.getGold() >= 1000) {
			this->player.payGold(1000);
			this->player.levelUp();
			cout << "Kupiles poziom!" << endl;
		}
		else {
			cout << "Nie masz wystarczajaco zlota!" << endl;
		}
		break;
	case '2'://Sprzedaj przedmioty

		cout << this->player.getInvAsString() << endl;
		cout << " - Twoje zloto: " << this->player.getGold() << endl << endl;

		if (this->player.getInventorySize() > 0){
			cout << "Zloto: " << this->player.getGold() << endl;
			cout << "Wybierz przedmiot (-1 anuluj tranzakcje): ";
			cin >> choice;

			while (cin.fail() || choice > this->player.getInventorySize() || choice < -1){
				system("CLS");

				cout << "Niepoprawne dane!" << endl;
				cin.clear();
				cin.ignore(100, '\n');

				cout << "Zloto: " << this->player.getGold() << endl;
				cout << "Wybierz przedmiot (-1 anuluj tranzakcje): ";
				cin >> choice;
			}

			cin.ignore(100, '\n');
			cout << endl;

			if (choice == -1)
			{
				cout << "Anulowano..." << endl;
			}
			else
			{
				this->player.gainGold(this->player.getItem(choice).getValue());

				cout << "Sprzedane!" << endl;
				cout << "Otrzymane zloto: " << this->player.getItem(choice).getValue() << endl << endl;
				this->player.removeItem(choice);
			}
		}
		else
		{
			cout << "Ekwipunek jest pusty..." << endl;
		}
		break;
	case '3'://Powrót do menu
		menuInGame();
		break;
	default:
		cout << "Nie ma takiej opcji!";
		Sleep(1500);
		break;
	}
	cout << "Wpisz cokolwiek i wcisnij Enter, by kontynuowac..." << endl;
	cin.get();
	cin.ignore();

}

void Game::board() {
	string line;
	int i;

	system("cls");
	ifstream file("text_files/board.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 7; b++)
				{
					file >> i;
					switch (i) {
					case 0: //Poziom 1
						this->map[a][b] = '#';
						break;
					case 1: //Poziom 2
						this->map[a][b] = '%';
						break;
					case 2: //Poziom 3
						this->map[a][b] = '&';
						break;
					case 3: //Szczyt
						this->map[a][b] = '$';
						break;
					case 4: //Gracz
						this->map[a][b] = '@';
						break;
					}
				}
			}
		
		}
	}
	else {
		cout << "Nie mozna otworzyc pliku!" << endl;
	}
	file.close();
}
void Game::showBoard() {
	cout << endl << endl;
	cout << setfill(' ') << setw(5);
	for (int y = 0; y < 7; y++){
		for (int x = 0; x < 7; x++){
			cout << this->map[y][x];
		}
		cout << setfill(' ') << setw(5);
		cout << endl;
	}
	cout << endl << endl;
}
void Game::end() {
	//czyszczenie danych o graczach
	ofstream file;
	file.open("text_files/players/players.txt", ios::trunc);
	file << "";
	file.close();
}