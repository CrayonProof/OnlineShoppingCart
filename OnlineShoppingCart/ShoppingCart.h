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
	void SetName(string customerName);
	void SetDate(string date);
	string GetName();
	string GetDate();
	bool AddItem(ItemToPurchase item);
	bool RemoveItem(string itemName);
	bool UpdateQuantity(string itemName, int newQuantity);
	int GetItemsCount();
	double GetTotalCost();
	bool PrintTotals();
	bool PrintDescriptions();

private:
	string customerName;
	string date;
	vector<ItemToPurchase> items;
};

