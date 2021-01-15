#include "Player.h"
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
void Player::initialize(const string name, string gender, string clas) {

	this->nickname = name;
	this->sex = gender;
	this->cClass = clas;
	this->lvl = 1;
	this->strength = 1;
	this->xPos = 0;
	this->yPos = 0;
}

void Player::create() {

	cout << "Gracz 1: " << endl;
	cout << "Ustaw nick: ";
	cin >> this->nickname;
	cout << endl << "Podaj swoja plec: [F/M]";
	cin >> this->sex;
}
void Player::getStats() {

	cout << "= Statystyki Postaci =" << endl;
	cout << "= Imie: " << this->nickname << endl;
	cout << "= Plec:" << this->sex << setw(10) << setfill(' ') << "\n";
	cout << "= Poziom:" << this->lvl << endl;
	cout << "= Sila:" << this->strength<< endl;
}
void cClas() {
	
}
void Player::fight() {}
void Player::escape() {}