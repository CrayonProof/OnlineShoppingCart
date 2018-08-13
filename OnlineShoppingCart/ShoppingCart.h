#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

#pragma once
class ShoppingCart
{
public:
	ShoppingCart();
	ShoppingCart(string customerName, string date);
	~ShoppingCart();
	string GetName();
	string GetDate();
	bool AddItem(ItemToPurchase item);
	bool RemoveItem(string itemName);
	bool UpdateQuantity(string itemName, int newQuantity);
	int GetItemsCount();
	int GetTotalCost();
	void PrintTotals();
	void PrintDescriptions();

private:
	string customerName;
	string date;
	vector<ItemToPurchase> items;
};

