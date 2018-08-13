#include "stdafx.h"
#include "ItemToPurchase.h"
#include <string>
#include <iostream>
using namespace std;

string itemName;
double itemPrice;
int itemQuantity;
string itemDescription;

ItemToPurchase::ItemToPurchase()
{
	itemName = "none";
	itemPrice = 0.0;
	itemQuantity = 0;
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
	cout << this->GetRundown() << endl;
}

void ItemToPurchase::PrintDescription() {
	cout << itemDescription << endl;
}