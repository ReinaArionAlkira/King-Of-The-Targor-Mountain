#include "Enemy.h"


Enemy::Enemy(int idx, string f) {
	//Miejsce pocz¹tku danych danego obiektuA
	int startObj = idx * 3;
	string line = "";
	ifstream file("text_files/" + f);
	//Przeskakiwanie nieistotnych w danej chwili linijek tekstu
	//Czyli ustawienie wskaŸnika do pliku na starcie obiektu)
	if (startObj > 1) {
		for (int i = 0; i < startObj; i++)
		{
			getline(file, line);
		}
	}
	//Zapisywanie kolejnych linii do odpowiednich miejsc obiektu
	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:
			getline(file, line);
			this->index = stoi(line);
			break;
		case 1:
			getline(file, line);
			this->name = line;
			cout << this->name;
			break;
		case 2:
			getline(file, line);
			this->strength = stoi(line);
			break;
		}
	}
	file.close();
}

Enemy::~Enemy() {

}

//Zmiana warunku niezbêdnego do uznania wygranej gracza
void Enemy::changeStrength() {
	this->strength = 0;
}

//Wczytywanie statystyk obiektu na ekran
void Enemy::getStats() {
	cout << "Nazwa stwora: " << this->name << endl
		<< "Sila: " << this->strength << endl;
}

//Tworzenie obiektu z pliku na podstawie indexu
//Index to pierwsza linia o stworze w pliku
