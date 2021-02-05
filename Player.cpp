#include "Player.h"
#include "GlobalFunctions.h"

Player::Player(){

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
Player Player::initialize(const string name, char gender) {

	this->nickname = name;
	this->sex = gender;
	//this->cClass = clas;
	this->lvl = 1;
	this->strength = 1;
	this->xPos = 0;
	this->yPos = 0;
	this->luck = 0;
	this->gold = 0;

	//Zapisanie do pliku statystyk gracza (chwilowo nadpisanie)
	//(na przysz³oœæ do rozwoju gry - zapisy)
	//ofstream file1;
	//file1.open("text_files/players/players.txt", ios::trunc);
	//if (file1.is_open()) {
	//	file1 << this->nickname << " " << this->sex
	//		<< " " << this->cClass << " " << this->lvl
	//		<< " " << this->strength << " " << this->luck << "\n";
	//}
	//else {
	//	cout << "Nie mozna otworzyc pliku!" << endl;
	//	Sleep(1000);
	//	exit(0);
	//}
	//file1.close();
	return *this;
}
const Item& Player::getItem(const int index)
{
	if (index < 0 || index >= this->inventory.size())
	{
		cout << "Error" << "\n\n";
		throw("Error");
	}

	return this->inventory[index];
}

string Player::getInvAsString() {
	string inv;
	for (int i = 0; i < this->inventory.size(); i++){
		inv += to_string(i) + " " + this->inventory[i].getStatsAsString() + "\n";
	}
	return inv;
}
void Player::equipItem(unsigned index) {
	if (index < 0 || index >= this->inventory.size()) {
		cout << "Error..." << endl;
	}
	else {
		Weapon* w = nullptr;
		w = dynamic_cast<Weapon*>(&this->inventory[index]);

		Armor* a = nullptr;
		a = dynamic_cast<Armor*>(&this->inventory[index]);
		//
		if (w != nullptr) {
			if (this->weapon.getStrength() != 0)
				this->inventory.addItem(this->weapon);
			this->weapon = *w;
			this->inventory.removeItem(index);
		}
		else if (a != nullptr) {
			switch (a->getType())
			{
			case armorType::HEAD:
				if (this->armor_head.getStrength() != 0)
					this->inventory.addItem(this->armor_head);
				this->armor_head = *a;
				this->inventory.removeItem(index);
				break;
			case armorType::CHEST:
				if (this->armor_chest.getStrength() != 0)
					this->inventory.addItem(this->armor_chest);
				this->armor_chest = *a;
				this->inventory.removeItem(index);
				break;
			case armorType::ARMS:
				if (this->armor_arms.getStrength() != 0)
					this->inventory.addItem(this->armor_arms);
				this->armor_arms = *a;
				this->inventory.removeItem(index);
				break;
			case armorType::LEGS:
				if (this->armor_legs.getStrength() != 0)
					this->inventory.addItem(this->armor_legs);
				this->armor_legs = *a;
				this->inventory.removeItem(index);
				break;
			default:
				cout << "ERROR Zly typ zbroi..." << "\n\n";
				break;
			}
		}
		else {
			cout << "Problemy z zalozeniem przedmiotu..." << endl;
		}
	}

}
void Player::removeItem(const int index){
	if (index < 0 || index >= this->inventory.size())
		cout << "Blad! Nie mozna zdjac przedmiotu..." << "\n\n";
	else
	{
		this->inventory.removeItem(index);
	}
}

void Player::getStats() {

	system("cls");
	cout << "= Statystyki Postaci =" << endl
		<< "= Nazwa: " << this->nickname << endl
		<< "= Plec: " << this->sex << endl
		//<< "= Klasa: " << this->cClass << endl
		<< "= Poziom: " << this->lvl << endl
		<< "= Sila: " << this->getStrength() << endl
		<< "= Szczescie: " << this->luck << endl << endl
		<< "= Zloto: " << this->gold << endl << endl
		<< "= Bron: " << this->weapon.getName()
			<< " Sila: " << this->weapon.getStrength() << endl
		<< "= Zbroja: " << endl
		<< "= Glowa: " << this->armor_head.getName()
			<< " Sila: " << this->armor_head.getStrength() << endl
		<< "= Tors: " << this->armor_chest.getName()
			<< " Sila: " << this->armor_chest.getStrength() << endl
		<< "= Rece: " << this->armor_arms.getName()
			<< " Sila: " << this->armor_arms.getStrength() << endl
		<< "= Nogi: " << this->armor_legs.getName()
			<< " Sila: " << this->armor_legs.getStrength() << endl;
}
//void Player::cClas() {
	
//}
void Player::travel(int direction) {
	switch (direction) {
	case 1: //Lewo
		this->yPos--;
		break;
	case 2: //Prawo
		this->yPos++;
		break;
	case 3: //Góra
		this->xPos--;
		break;
	case 4: //Dó³
		this->xPos++;
		break;
	}
}

