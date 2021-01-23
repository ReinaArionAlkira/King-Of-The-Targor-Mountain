#include "Inventory.h"


Inventory::Inventory() {
	this->capacity = 5;
	this->nrOfItems = 0;
	this->itemArr = new Item*[capacity];
	this->initialize();
}

Inventory::~Inventory() {

	for (int i = 0; i < this->nrOfItems; i++){

		delete this->itemArr[i];
	}
	delete[] itemArr;
}

Inventory::Inventory(const Inventory& obj) {
	this->capacity = obj.capacity;
	this->nrOfItems = obj.nrOfItems;
	this->itemArr = new Item * [this->capacity];

	for (int i = 0; i < this->nrOfItems; i++) {
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->nrOfItems);
}
Item& Inventory::operator[](const int index) {
	if (index < 0 || index >= this->nrOfItems)
		throw("BAD INDEX!");

	return *this->itemArr[index];
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