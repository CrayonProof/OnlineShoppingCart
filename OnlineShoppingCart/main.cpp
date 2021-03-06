// OnlineShoppingCart.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

void GetLineNotWS(string& inpString);
void DisplayMenu();

string latestStringInput;
double latestDoubleInput;
int latestIntInput;
bool quit;
ShoppingCart cart;

void GetLineNotWS(string& inpString) {

	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos) {
		getline(cin, inpString);
	}
}

void EnterSelection() {

	cout << "Enter option: ";
	GetLineNotWS(latestStringInput);
	cout << endl;

	if (latestStringInput == "quit") {
		quit = true;
	}
	else if (latestStringInput == "add") {

		string itemNameSet;
		string itemDescriptionSet;
		double itemPriceSet;
		int itemQuantitySet;

		cout << "Enter the item name: ";
		GetLineNotWS(itemNameSet);
		cout << "Enter the item description: ";
		GetLineNotWS(itemDescriptionSet);
		cout << "Enter the item price: ";
		cin >> itemPriceSet;
		cout << "Enter the item quantity: ";
		cin >> itemQuantitySet;

		if (cart.AddItem(ItemToPurchase(itemNameSet, itemDescriptionSet, itemPriceSet, itemQuantitySet))) {

		}
		else {
			cout << endl << "	Item is already in cart. Nothing added." << endl;
		}

	}
	else if (latestStringInput == "remove") {

		cout << "Enter name of the item to remove: ";
		GetLineNotWS(latestStringInput);

		if (!(cart.RemoveItem(latestStringInput))) {
			
			cout << "Item not found in cart. Nothing removed." << endl;
		}
	}
	else if (latestStringInput == "change") {

		cout << "Enter the item name: ";
		GetLineNotWS(latestStringInput);
		cout << "Enter the new quantity: ";
		cin >> latestIntInput;

		if (!(cart.UpdateQuantity(latestStringInput, latestIntInput))) {
			
			cout << "Item not found in cart. Nothing modified." << endl;
		}
	}
	else if (latestStringInput == "descriptions") {

		if (!cart.PrintDescriptions()) {
			cout << "Shopping cart is empty." << endl;
		}
	}
	else if (latestStringInput == "cart") {

		if (!cart.PrintTotals()) {
			cout << "Shopping cart is empty." << endl;
		}
	}
	else {

		DisplayMenu();
	}
}

void DisplayMenu() {

	cout << "MENU" << endl;
	cout << "add - Add item to cart" << endl;
	cout << "remove - Remove item from cart" << endl;
	cout << "change - Change item quantity" << endl;
	cout << "descriptions - Output items' descriptions" << endl;
	cout << "cart - Output shopping cart" << endl;
	cout << "options - Print the options menu" << endl;
	cout << "quit - Quit" << endl;
}

int main()
{
	std::cout << std::fixed;
    std::cout << std::setprecision(2);

	quit = false;

	cout << "Enter Customer's Name: ";
	GetLineNotWS(latestStringInput);
	cart.SetName(latestStringInput);

	cout << "Enter Today's Date: ";
	GetLineNotWS(latestStringInput);
	cart.SetDate(latestStringInput);

	while (!quit) {

		EnterSelection();
	}

	cout << endl << "Goodbye.";
	return 0;
}

