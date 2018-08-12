// OnlineShoppingCart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ItemToPurchase.h"
#include <iostream>
#include <sstream>
using namespace std;

string latestStringInput;
double latestDoubleInput;
int latestIntInput;

int main()
{
	ItemToPurchase itemOne;
	ItemToPurchase itemTwo;

	cout << "Item 1" << endl;
	cout << "Enter the item name: ";
	getline(cin, latestStringInput);
	itemOne.SetName(latestStringInput);

	cout << endl << "Enter the item price: ";
	cin >> latestDoubleInput;
	itemOne.SetPrice(latestDoubleInput);

	cout << endl << "Enter the item quantity: ";
	cin >> latestIntInput;
	itemOne.SetQuantity(latestIntInput);
	cout << endl;

	cin.ignore();

	cout << "Item 2" << endl;
	cout << "Enter the item name: ";
	getline(cin, latestStringInput);
	itemTwo.SetName(latestStringInput);

	cout << endl << "Enter the item price: ";
	cin >> latestDoubleInput;
	itemTwo.SetPrice(latestDoubleInput);

	cout << endl << "Enter the item quantity: ";
	cin >> latestIntInput;
	itemTwo.SetQuantity(latestIntInput);
	cout << endl;


	cout << itemOne.GetName() << " " << itemOne.GetQuantity() << " @ $";
	cout << itemOne.GetPrice() << " = $" << ((double) itemOne.GetPrice())*(itemOne.GetQuantity()) << endl;

	cout << itemTwo.GetName() << " " <<  itemTwo.GetQuantity() << " @ $";
	cout << itemTwo.GetPrice() << " = $" << ((double) itemTwo.GetPrice())*(itemTwo.GetQuantity()) << endl;

	cout << "Total: $" << (itemOne.GetPrice()*((double) itemOne.GetQuantity())) + (itemTwo.GetPrice()*((double) itemTwo.GetQuantity()));

	while (true) {}

    return 0; 
}

