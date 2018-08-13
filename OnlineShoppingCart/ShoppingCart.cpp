#include "stdafx.h"
#include "ShoppingCart.h"
#include <string>
#include <iostream>
using namespace std;

string customerName;
string date;
vector<ItemToPurchase> items;


ShoppingCart::ShoppingCart()
{
	customerName = "none";
	date = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customerName, string date)
{
	this->customerName = customerName;
	this->date = date;
}


ShoppingCart::~ShoppingCart()
{
}

string ShoppingCart::GetName() {
	return customerName;
}

string ShoppingCart::GetDate() {
	return date;
}

bool ShoppingCart::AddItem(ItemToPurchase item) {
	items.resize(items.size() + 1);
	items.at(items.size() - 1) = item;
	return true;
}

bool ShoppingCart::RemoveItem(string itemName) {

	int removeIndex = 0;

	for (ItemToPurchase item : items) {
		if (item.GetName == itemName) {

			items.erase(items.begin() + (removeIndex));

			return true;
		}
		removeIndex++;
	}
	return false;
}

bool ShoppingCart::UpdateQuantity(string itemName, int newQuantity) {
	int updateIndex = 0;

	for (ItemToPurchase item : items) {
		if (item.GetName == itemName) {

			items.at(updateIndex).SetQuantity(newQuantity);

			return true;
		}
		updateIndex++;
	}
	return false;
}

int ShoppingCart::GetItemsCount() {
	return items.size();
}

int ShoppingCart::GetTotalCost() {
	int totalCost = 0;

	for (ItemToPurchase item : items) {
		totalCost += item.GetPrice();
	}

	return totalCost;

}

void ShoppingCart::PrintTotals() {

	cout << endl << this->GetName << "'s Shopping Cart - " << this->GetDate <<endl;
	cout << "Number of Items: " << this->GetItemsCount << endl << endl;

	for (ItemToPurchase item : items) {
		item.PrintCost();
	}

	cout << endl << "Total: " << this->GetTotalCost;
}

void ShoppingCart::PrintDescriptions() {

	cout << endl << this->GetName << "'s Shopping Cart - " << this->GetDate << endl << endl;
	cout << "Item Descriptions" << endl;

	for (ItemToPurchase item : items) {
		item.PrintDescription();
	}
}

