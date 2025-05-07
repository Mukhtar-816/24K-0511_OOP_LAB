#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual void convertToBase() const {
        cout << "Base Conversion: " << amount * exchangeRate << " USD (base)" << endl;
    }

    virtual void convertTo(const Currency& target) const {
        double baseAmount = amount * exchangeRate;
        double converted = baseAmount / target.exchangeRate;
        cout << "Converted Amount: " << target.currencySymbol << converted << " (" << target.currencyCode << ")" << endl;
    }

    virtual void displayCurrency() const {
        cout << "Currency: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt)
        : Currency(amt, "USD", "$", 1.0) {}

    void convertToBase() const override {
        cout << "USD is already base currency: $" << amount << endl;
    }

    void displayCurrency() const override {
        cout << "US Dollars: $" << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt)
        : Currency(amt, "EUR", "€", 1.1) {}

    void convertToBase() const override {
        cout << "Euro to Base USD: $" << amount * exchangeRate << endl;
    }

    void displayCurrency() const override {
        cout << "Euros: €" << amount << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt)
        : Currency(amt, "INR", "₹", 0.012) {}

    void convertToBase() const override {
        cout << "Rupee to Base USD: $" << amount * exchangeRate << endl;
    }

    void displayCurrency() const override {
        cout << "Indian Rupees: ₹" << amount << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee inr(5000);

    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();
    cout << "--------------------------" << endl;

    eur.convertToBase();
    inr.convertToBase();
    cout << "--------------------------" << endl;

    eur.convertTo(inr);
    inr.convertTo(usd);

    return 0;
}
