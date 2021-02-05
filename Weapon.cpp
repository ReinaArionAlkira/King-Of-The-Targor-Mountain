#include "Weapon.h"

Weapon::Weapon()
	:Item() {

	this->strength = 0;
}
Weapon::Weapon(int strength)
	:Item(itemTypes::WEAPON){
	
	this->strength = rand() % 5 + 1;
	this->setName(this->names[(rand()% 5)]);

}

Weapon::Weapon(int strength, string name, int value)
	: Item(itemTypes::WEAPON, name, value)
{
	this->strength = strength;
}
Weapon::~Weapon() {

}

Weapon* Weapon::clone()const {
	return new Weapon(*this);
}
string Weapon::getStatsAsString() const {
	string str =
		this->getName()
		+ " | Sila: "
		+ std::to_string(this->getStrength())
		+ " | Wartosc: "
		+ std::to_string(this->getValue());

	return str;
 }