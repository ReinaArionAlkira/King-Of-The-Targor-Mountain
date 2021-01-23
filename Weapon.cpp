#include "Weapon.h"

Weapon::Weapon(int strength, string name, int value) :Item(name, value){
	this->strength;
}
Weapon::~Weapon() {

}

Weapon* Weapon::clone()const {
	return new Weapon(*this);
}