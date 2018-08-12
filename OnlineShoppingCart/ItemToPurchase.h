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
private:
	string itemName;
	double itemPrice;
	int itemQuantity;
};
