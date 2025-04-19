#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(string m) : model(m), price(0.0) {}

    string getModel() const {
        return model;
    }

    double getPrice() const {
        return price;
    }

    void setModel(string m) {
        model = m;
    }

    virtual void setPrice(double p) = 0;
    virtual void display() const = 0;

    virtual ~Car() {}
};

class Color : public Car {
private:
    string color;

public:
    Color(string m, string c) : Car(m), color(c) {}

    void setPrice(double p) override {
        price = p;
    }

    void display() const override {
        cout << "Car Model: " << model << "\nColor: " << color << "\nPrice: $" << price << endl;
    }
};

class Company : public Car {
private:
    string company;

public:
    Company(string m, string comp) : Car(m), company(comp) {}

    void setPrice(double p) override {
        price = p;
    }

    void display() const override {
        cout << "Car Model: " << model << "\nCompany: " << company << "\nPrice: $" << price << endl;
    }
};

int main() {
    Color c1("Civic", "Red");
    c1.setPrice(25000);
    c1.display();

    cout << endl;

    Company c2("Corolla", "Toyota");
    c2.setPrice(23000);
    c2.display();

    return 0;
}
