#include "Enemy.h"


Enemy::Enemy(int idx, string f) {
	//Miejsce początku danych danego obiektuA
	int startObj = idx * 5;
	string line = "";
	ifstream file("text_files/" + f);
	//Przeskakiwanie nieistotnych w danej chwili linijek tekstu
	//Czyli ustawienie wskaźnika do pliku na starcie obiektu)
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
		case 3:
			getline(file, line);
			this->clasAd = stoi(line);
			break;
		case 4:
			getline(file, line);
			this->adds = stoi(line);
			break;
		}
	}
	file.close();
}

Enemy::~Enemy() {

}

//Zmiana warunku niezbędnego do uznania wygranej gracza
void Enemy::changeStrength() {
	this->strength = 0;
}

//Wczytywanie statystyk obiektu na ekran
void Enemy::getStats() {
	cout << this->index << endl << "Nazwa stwora: " << this->name << endl
		<< "Sila: " << this->strength << endl
		<< "Bonus do obrazen przeciw: " << this->clasAd << endl
		<< "Wartosc bonusu: " << this->adds << endl;
}

//Tworzenie obiektu z pliku na podstawie indexu
//Index to pierwsza linia o stworze w pliku
