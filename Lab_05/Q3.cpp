#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cafe {
public:
    string cafeName;
    string items[5] = {"Coffee", "Tea", "Pastry", "Sandwich", "Muffin"};
    double itemPrices[5] = {2.5, 1.8, 3.0, 4.0, 2.2};
    vector<string> currentOrders;

    void placeOrder(string itemName) {
        bool found = false;
        for (int i = 0; i < 5; ++i) {
            if (items[i] == itemName) {
                currentOrders.push_back(itemName);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item not available!" << endl;
        }
    }

    void serveOrder() {
        if (currentOrders.empty()) {
            cout << "No pending orders" << endl;
        } else {
            cout << currentOrders.front() << " is served!" << endl;
            currentOrders.erase(currentOrders.begin());
        }
    }

    void showOrders() {
        if (currentOrders.empty()) {
            cout << "No orders to display." << endl;
        } else {
            cout << "Orders: ";
            for (const auto& item : currentOrders) {
                cout << item << " ";
            }
            cout << endl;
        }
    }

    double calculateTotal() {
        double total = 0;
        for (const auto& item : currentOrders) {
            for (int i = 0; i < 5; ++i) {
                if (items[i] == item) {
                    total += itemPrices[i];
                    break;
                }
            }
        }
        return total;
    }

    string lowestPriceItem() {
        int minIdx = 0;
        for (int i = 1; i < 5; ++i) {
            if (itemPrices[i] < itemPrices[minIdx]) {
                minIdx = i;
            }
        }
        return items[minIdx];
    }

    void showDrinks() {
        cout << "Available drinks: Coffee, Tea" << endl;
    }

    void showFoods() {
        cout << "Available foods: Pastry, Sandwich, Muffin" << endl;
    }
};

int main() {
    Cafe cafe;
    cafe.placeOrder("Coffee");
    cafe.placeOrder("Pastry");
    cafe.placeOrder("Tea");
    cafe.placeOrder("Burger");
    cafe.showOrders();
    cafe.serveOrder();
    cafe.showOrders();
    cout << "Amount due: $" << cafe.calculateTotal() << endl;
    cout << "Least expensive item: " << cafe.lowestPriceItem() << endl;
    cafe.showDrinks();
    cafe.showFoods();
    return 0;
}
