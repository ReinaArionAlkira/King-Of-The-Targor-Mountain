#include "Player.h"
#include "GlobalFunctions.h"

Player::Player() {

	this->nickname = " ";
	this->sex = ' ';
	this->cClass = " ";
	this->lvl = 0;
	this->strength = 0;
	this->xPos = 0;
	this->yPos = 0;
}
Player::~Player() {

}
Player Player::initialize(const string name, char gender, string clas) {

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
	file1.open("text_files/players/players.txt", ios::trunc);
	if (file1.is_open()) {
		file1 << this->nickname << " " << this->sex
			<< " " << this->cClass << " " << this->lvl
			<< " " << this->strength << " " << this->luck << "\n";
	}
	else {
		cout << "Nie mozna otworzyc pliku!" << endl;
		Sleep(1000);
		exit(0);
	}
	file1.close();
	return *this;
}
void Player::getStats() {

	system("cls");
	cout << "= Statystyki Postaci =" << endl
		<< "= Nazwa: " << this->nickname << endl
		<< "= Plec: " << this->sex << endl
		<< "= Klasa: " << this->cClass << endl 
		<< "= Poziom: " << this->lvl << endl
		<< "= Sila: " << this->strength << endl
		<< "= Szczescie: " << this->luck << endl;
}
//void Player::cClas() {
	
//}
void Player::move() {}
void Player::fight() {}
void Player::escape() {}
