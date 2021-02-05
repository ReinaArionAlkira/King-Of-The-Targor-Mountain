#include "Armor.h"

Armor::Armor() 
	:Item() {
	this->type = 0;
	this->strength = 0;
}

Armor::Armor(int strength)
	:Item(itemTypes::ARMOR)
{
	this->strength = rand() % 5 + 1;
	this->type = rand() % 4;

	switch (this->type)
	{
	case armorType::HEAD:
		this->typeStr = "Head";
		break;
	case armorType::CHEST:
		this->typeStr = "Chest";
		break;
	case armorType::ARMS:
		this->typeStr = "Arms";
		break;
	case armorType::LEGS:
		this->typeStr = "Legs";
		break;
	default:
		this->typeStr = "ERROR INVALID!";
		break;
	}

	this->setName(this->names[rand() % 5]);
}

Armor::Armor(int type, int strength, string name, int value)
	: Item(itemTypes::ARMOR, name, value)
{
	this->type = type;
	this->strength = strength;
}

Armor::~Armor() {

}

Armor* Armor::clone()const {
	return new Armor(*this);
}
string Armor::getStatsAsString() const {
	string str =
		this->getName()
		+ " | Typ: "
		+ this->getTypeStr()
		+ " | Sila: "
		+ to_string(this->getStrength())
		+ " | Wartosc: "
		+ to_string(this->getValue());

	return str;
}