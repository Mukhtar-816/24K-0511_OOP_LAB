#include <iostream>
using namespace std;

class Invoice
{
    public :
    string partNumber;
    string partDescription;
    int itemsPurchased;
    double pricePerItem;

    Invoice(string number, string description, int items, double priceperitem) : partNumber(number), partDescription(description), itemsPurchased(items), pricePerItem(priceperitem)
    {
        if (itemsPurchased < 0)
        {
            itemsPurchased = 0;
        };

        if (pricePerItem < 0)
        {
            pricePerItem = 0.0;
        };
    };

    double getInvoiceAmount()
    {
        return itemsPurchased * pricePerItem;
    };
};


int main() {
    Invoice invoice("0001", "Grocery", 3, 100 );

    cout << "The Total Amount is : " << invoice.getInvoiceAmount() << endl;
    
}