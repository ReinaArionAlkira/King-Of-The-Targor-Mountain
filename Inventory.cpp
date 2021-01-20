#include "Inventory.h"


Inventory::Inventory() {

	this->nrOfItems = 0;
	this->itemArr = nullptr;

}
Inventory::~Inventory() {

	for (int i = 0; i < this->nrOfItems; i++){

		delete this->itemArr[i];
	}
	delete[] itemArr;
}

void Inventory::initialize(const int from){

}
void addItem(const Item& item) {


}
void removeItem(int index) {


}