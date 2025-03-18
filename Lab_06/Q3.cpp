#include <iostream>
#include <vector>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int _id, string _name) : id(_id), name(_name) {}
    virtual void displayRole() = 0;
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int _id, string _name) : Employee(_id, _name) {}
    void takeOrder() override {
        cout << "Waiter " << name << " is taking an order." << endl;
    }
    void displayRole() override {
        cout << "Role: Waiter" << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int _id, string _name) : Employee(_id, _name) {}
    void prepareOrder() override {
        cout << "Chef " << name << " is preparing an order." << endl;
    }
    void displayRole() override {
        cout << "Role: Chef" << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int _id, string _name) : Employee(_id, _name) {}
    void generateBill() override {
        cout << "Cashier " << name << " is generating the bill." << endl;
    }
    void displayRole() override {
        cout << "Role: Cashier" << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int _id, string _name) : Employee(_id, _name) {}
    void takeOrder() override {
        cout << "Manager " << name << " is taking an order." << endl;
    }
    void generateBill() override {
        cout << "Manager " << name << " is generating the bill." << endl;
    }
    void displayRole() override {
        cout << "Role: Manager" << endl;
    }
};

class Menu {
protected:
    string name;
public:
    Menu(string _name) : name(_name) {}
    virtual double calculateTotal(double price, int quantity) = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    FoodMenu() : Menu("Food Menu") {}
    double calculateTotal(double price, int quantity) override {
        return price * quantity;
    }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu() : Menu("Beverage Menu") {}
    double calculateTotal(double price, int quantity) override {
        double tax = 0.1; 
        return (price * quantity) * (1 + tax);
    }
};

int main() {
    Waiter waiter(1, "John");
    Chef chef(2, "Gordon");
    Cashier cashier(3, "Sarah");
    Manager manager(4, "Alice");

    FoodMenu foodMenu;
    BeverageMenu beverageMenu;

    vector<Employee*> employees = {&waiter, &chef, &cashier, &manager};

    for (auto emp : employees) {
        emp->displayRole();
    }

    waiter.takeOrder();
    chef.prepareOrder();
    cashier.generateBill();
    manager.takeOrder();
    manager.generateBill();

    cout << "Total (Food): $" << foodMenu.calculateTotal(10, 3) << endl;
    cout << "Total (Beverage with tax): $" << beverageMenu.calculateTotal(5, 2) << endl;
    
    return 0;
}

