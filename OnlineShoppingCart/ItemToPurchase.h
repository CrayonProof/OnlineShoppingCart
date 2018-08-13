#include <string>
using namespace std;

class ItemToPurchase
{
public:
	ItemToPurchase();
	~ItemToPurchase();
	void SetName(string name);
	string GetName();
	void SetPrice(double price);
	double GetPrice();
	void SetQuantity(int quantity);
	int GetQuantity();
	string GetRundown();
	void SetDescription(string description);
	string GetDescription();
	void PrintCost();
	void PrintDescription();
private:
	string itemName;
	double itemPrice;
	int itemQuantity;
	string itemDescription;
};
