#include "stdafx.h"
#include "ItemToPurchase.h"
#include <string>
using namespace std;

string itemName;
double itemPrice;
int itemQuantity;

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