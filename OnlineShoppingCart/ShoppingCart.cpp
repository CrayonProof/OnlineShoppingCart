#include "stdafx.h"
#include "ShoppingCart.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

string customerName;
string date;
vector<ItemToPurchase> items;


ShoppingCart::ShoppingCart()
{
	cout << fixed << setprecision(2);

	customerName = "none";
	date = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customerName, string date)
{
	cout << fixed << setprecision(2);

	this->customerName = customerName;
	this->date = date;
}


ShoppingCart::~ShoppingCart()
{
}

void ShoppingCart::SetName(string customerName) {
	this->customerName = customerName;
}

void ShoppingCart::SetDate(string date) {
	this->date = date;
}

string ShoppingCart::GetName() {
	return customerName;
}

string ShoppingCart::GetDate() {
	return date;
}

bool ShoppingCart::AddItem(ItemToPurchase item) {

	for (ItemToPurchase itemToCompare : items) {
		if (itemToCompare.GetName() == item.GetName()) {

			return false;
		}
	}
	items.resize(items.size() + 1);
	items.at(items.size() - 1) = item;
	return true;
}

bool ShoppingCart::RemoveItem(string itemName) {

	int removeIndex = 0;

	for (ItemToPurchase item : items) {
		if (item.GetName() == itemName) {

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
		if (item.GetName() == itemName) {

			items.at(updateIndex).SetQuantity(newQuantity);

			return true;
		}
		updateIndex++;
	}
	return false;
}

int ShoppingCart::GetItemsCount() {

	cout << fixed << setprecision(2);

	int totalCount = 0;

	for (ItemToPurchase item : items) {
		totalCount += item.GetQuantity();
	}

	return totalCount;
}

double ShoppingCart::GetTotalCost() {
	double totalCost = 0.00;

	for (ItemToPurchase item : items) {
		totalCost = totalCost + ((double )item.GetQuantity()) * item.GetPrice();
	}

	return totalCost;

}

bool ShoppingCart::PrintTotals() {

	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	cout << endl << this->GetName() << "'s Shopping Cart - " << this->GetDate() << endl;

	if (this->items.size() > 0) {

		cout << "Number of Items: " << this->GetItemsCount() << endl << endl;

		for (ItemToPurchase item : items) {
			item.PrintCost();
		}

		cout << endl << "Total: $" << this->GetTotalCost() << endl << endl;

		return true;
	}
	else {
		return false;
	}
}

bool ShoppingCart::PrintDescriptions() {

	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	cout << endl << this->GetName() << "'s Shopping Cart - " << this->GetDate() << endl << endl;

	if (this->items.size() > 0) {

		cout << "Item Descriptions" << endl;

		for (ItemToPurchase item : items) {
			item.PrintDescription();
		}

		return true;
	}
	else {
		return false;
	}

}

