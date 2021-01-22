#include "Armor.h"

Armor::Armor() {

}
Armor::~Armor() {

}

Armor* Armor::clone()const {
	return new Armor(*this);
}