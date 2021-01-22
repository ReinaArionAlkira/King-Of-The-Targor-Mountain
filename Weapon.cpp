#include "Weapon.h"

Weapon::Weapon(int strenght, string name, int value) :Item(name, value){
	this->strenght;
}
Weapon::~Weapon() {

}

Weapon* Weapon::clone()const {
	return new Weapon(*this);
}