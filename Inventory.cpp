#include "Inventory.h"


Inventory::Inventory() {
	this->capacity = 5;
	this->nrOfItems = 0;
	this->itemArr = new Item*[5];

}
Inventory::~Inventory() {

	for (int i = 0; i < this->nrOfItems; i++){

		delete this->itemArr[i];
	}
	delete[] itemArr;
}

void Inventory::initialize(const int from){
	for (int i = 0; i < from; i++) {
		itemArr[i] = nullptr;
	}
}
void Inventory::expand() {
	this->capacity++;

	Item** tempArr = new Item * [this->capacity];
	for (int i = 0; i < this->nrOfItems; i++) {
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;
	this->itemArr = tempArr;
	this->initialize(this->nrOfItems);
}
void Inventory::addItem(const Item& item) {
	if (this->nrOfItems >= this->capacity) {
		expand();
	}
	this->itemArr[this->nrOfItems++] = item.clone();
}
void Inventory::removeItem(int index) {


}