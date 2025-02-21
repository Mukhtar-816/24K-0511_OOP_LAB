#include <iostream>
#include <vector>
using namespace std;

class MenuItem {
public:
    string name, type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string n) : name(n) {}

    void addMenuItem(string itemName, string type, double price) {
        menu.push_back(MenuItem(itemName, type, price));
    }

    string addOrder(string itemName) {
        for (MenuItem &item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (string &order : orders) {
            for (MenuItem &item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items in the menu";
        MenuItem *cheapest = &menu[0];
        for (MenuItem &item : menu) {
            if (item.price < cheapest->price) {
                cheapest = &item;
            }
        }
        return cheapest->name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (MenuItem &item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (MenuItem &item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    CoffeeShop shop("Cafe Delight");

    shop.addMenuItem("Espresso", "drink", 2.50);
    shop.addMenuItem("Latte", "drink", 3.00);
    shop.addMenuItem("Croissant", "food", 2.75);
    shop.addMenuItem("Muffin", "food", 2.25);

    cout << shop.addOrder("Espresso") << endl;
    cout << shop.addOrder("Muffin") << endl;
    cout << shop.addOrder("Burger") << endl;

    cout << "Orders: ";
    for (string &order : shop.listOrders()) {
        cout << order << ", ";
    }
    cout << endl;

    cout << "Due amount: $" << shop.dueAmount() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks only: ";
    for (string &drink : shop.drinksOnly()) {
        cout << drink << ", ";
    }
    cout << endl;

    cout << "Food only: ";
    for (string &food : shop.foodOnly()) {
        cout << food << ", ";
    }
    cout << endl;

    return 0;
}
