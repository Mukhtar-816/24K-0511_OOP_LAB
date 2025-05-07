#include <iostream>
#include <string>
#include <vector>
using namespace std;

class bankaccount {
public:
    string accnum;
    float balance;
    string holder;
    char type;

    bankaccount(string num, float b, string h, char t)
        : accnum(num), balance(b), holder(h), type(t) {}

    virtual void withdraw(float amount) {
        if (amount < 0 || amount > balance) {
            cout << "Invalid entry" << endl;
        } else {
            balance -= amount;
            cout << "Withdraw successful. New balance: " << balance << endl;
        }
    }

    virtual void deposit(float amount) {
        if (amount < 0) {
            cout << "Invalid entry" << endl;
        } else {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        }
    }

    virtual void calculateinterest(float t) {
        float r = 2.0;
        float interest = (balance * t * r) / 100;
        cout << "Interest: " << interest << endl;
    }

    virtual void printinfo() {
        cout << "Account Number: " << accnum << endl;
        cout << "Balance: " << balance << endl;
        cout << "Holder: " << holder << endl;
        cout << "Type: " << type << endl;
    }

    virtual ~bankaccount() {}
};

class Savings : public bankaccount {
public:
    float interestrate;
    float minbal;

    Savings(string num, float b, string name, float rate, float min)
        : bankaccount(num, b, name, 's'), interestrate(rate), minbal(min) {}

    void withdraw(float amount) override {
        if (balance - amount < minbal) {
            cout << "Withdrawal denied: Cannot go below minimum balance of $" << minbal << endl;
        } else {
            balance -= amount;
            cout << "Withdraw successful. New balance: " << balance << endl;
        }
    }

    void calculateinterest(float t) override {
        float interest = (balance * interestrate * t) / 100;
        cout << "Savings Interest: " << interest << endl;
    }
};

class checking : public bankaccount {
public:
    checking(string num, float b, string name)
        : bankaccount(num, b, name, 'c') {}

    void calculateinterest(float t) override {
        cout << "No interest on checking accounts." << endl;
    }
};

class fixeddeposit : public bankaccount {
public:
    string date;
    float rate;

    fixeddeposit(string num, float b, string h, string d, float r)
        : bankaccount(num, b, h, 'f'), date(d), rate(r) {}

    void withdraw(float amount) override {
        cout << "Withdrawals aren't allowed before this date: " << date << endl;
    }

    void calculateinterest(float t) override {
        float interest = (balance * t * rate) / 100;
        cout << "Fixed Deposit Interest: " << interest << endl;
    }
};

int main() {
    Savings s("SAV001", 1000, "Alice", 4.0, 500);
    checking c("CHK001", 2000, "Bob");
    fixeddeposit fd("FD001", 5000, "Charlie", "2025-12-31", 5.5);

    s.deposit(200);
    s.withdraw(800);
    s.calculateinterest(1);
    s.printinfo();

    cout << "\n";

    c.deposit(500);
    c.withdraw(1000);
    c.calculateinterest(1);
    c.printinfo();

    cout << "\n";

    fd.calculateinterest(1);
    fd.withdraw(1000);
    fd.printinfo();

    return 0;
}
