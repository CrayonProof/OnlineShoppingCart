//#include "stdafx.h"
#include "ItemToPurchase.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

string itemName;
double itemPrice;
int itemQuantity;
string itemDescription;

ItemToPurchase::ItemToPurchase()
{
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0.0;
	itemQuantity = 0;

}

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, double itemPrice, int itemQuantity)
{
	cout << fixed << setprecision(2);
	this->itemName = itemName;
	this->itemDescription = itemDescription;
	this->itemPrice = itemPrice;
	this->itemQuantity = itemQuantity;
}

ItemToPurchase::~ItemToPurchase()
{
}

void ItemToPurchase::SetName(string name) {
	itemName = name;
}

string ItemToPurchase::GetName() {
	return itemName;
}

void ItemToPurchase::SetPrice(double price) {
	itemPrice = price;
}

double ItemToPurchase::GetPrice() {
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
	itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() {
	return itemQuantity;
}

string ItemToPurchase::GetRundown() {

	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	return this->GetName() + " " + std::to_string(this->GetQuantity()) +
		" @ $" + std::to_string(this->GetPrice()) + " = $" +
		std::to_string(((double)this->GetPrice())*(this->GetQuantity()));
}

void ItemToPurchase::SetDescription(string description) {
	itemDescription = description;
}

string ItemToPurchase::GetDescription() {
	return itemDescription;
}

void ItemToPurchase::PrintCost() {
	cout << fixed << setprecision(2);

	cout << this->GetName() << " " << std::to_string(this->GetQuantity()) <<
		" @ $" << this->GetPrice() << " = $" <<
		((double)this->GetPrice())*(this->GetQuantity()) << endl;
}

void ItemToPurchase::PrintDescription() {

	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	cout << itemName << ": " << itemDescription << endl;
}