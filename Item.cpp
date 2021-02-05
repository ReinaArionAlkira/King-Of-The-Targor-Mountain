#include "Item.h"


Item::Item() {
	this->name = "PUSTO";
	this->value = 0;
	this->itemType = -1;
}

Item::Item(int itemType)
{
	this->name = "RANDOM";
	this->value = (rand()% 15 + 1) * 50;
	this->itemType = itemType;
}

Item::Item(int itemType, string name, int value)
{
	this->itemType = itemType;
	this->name = name;
	this->value = value;
}

Item::~Item() {


}