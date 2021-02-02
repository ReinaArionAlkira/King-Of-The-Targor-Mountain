#include "Player.h"
#include "GlobalFunctions.h"
#include "GlobalFunctions.cpp"

Player::Player() {

	this->nickname = " ";
	this->sex = " ";
	this->cClass = " ";
	this->lvl = 0;
	this->strength = 0;
	this->xPos = 0;
	this->yPos = 0;
}
Player::~Player() {

}
Player Player::initialize(const string name, string gender, string clas) {

	this->nickname = name;
	this->sex = gender;
	this->cClass = clas;
	this->lvl = 1;
	this->strength = 1;
	this->xPos = 0;
	this->yPos = 0;
	this->luck = 0;

	//Zapisanie do pliku statystyk gracza (chwilowo nadpisanie)
	//(na przysz³oœæ do rozwoju gry - zapisy)
	ofstream file1;
	file1.open("pliki_tekstowe/" + name + ".txt", ios::trunc);
	if (file1.is_open()) {
		file1 << "Imie: " << name << "\nPlec: " << gender
			<< "\nKlasa: " << clas << "\nPoziom: " << lvl 
			<< "\nSila: " << strength << "\n";
	}
	else {
		cout << "Nie mozna otworzyc pliku!" << endl;
	}
	file1.close();
	return *this;
}
void Player::getStats() {

	system("cls");
	cout << "= Statystyki Postaci =" << endl;
	cout << "= Nazwa: " << this->nickname << endl
		<< "= Plec: " << this->sex << endl
		<< "= Klasa: " << this->cClass << endl 
		<< "= Poziom: " << this->lvl << endl
		<< "= Sila: " << this->strength << endl
		<< "= Szczescie: " << this->luck << endl;
	cout << "=";
}
void cClas() {
	
}
void Player::fight() {}
void Player::escape() {}