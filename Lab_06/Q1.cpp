#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNo, double bal) : accountNumber(accNo), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "❌ Insufficient funds. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << ". New balance: $" << balance << endl;
        }
    }

    virtual void displayAccountInfo() const {
        cout << "Account #" << accountNumber << " | Balance: $" << balance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, double bal, double rate) 
        : BankAccount(accNo, bal), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "💰 Interest Applied: $" << interest << ". New balance: $" << balance << endl;
    }

    void displayAccountInfo() const override {
        cout << "[Savings] "; 
        BankAccount::displayAccountInfo();
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, double bal, double limit) 
        : BankAccount(accNo, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "❌ Overdraft limit exceeded. Withdrawal denied." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << ". New balance: $" << balance << endl;
        }
    }

    void displayAccountInfo() const override {
        cout << "[Checking] ";
        BankAccount::displayAccountInfo();
    }
};

class BusinessAccount : public BankAccount {
private:
    double taxRate;

public:
    BusinessAccount(int accNo, double bal, double tax) 
        : BankAccount(accNo, bal), taxRate(tax) {}

    void deposit(double amount) override {
        double tax = amount * taxRate;
        balance += (amount - tax);
        cout << "📉 Tax Withheld: $" << tax << ". Net deposit: $" << (amount - tax) << ". New balance: $" << balance << endl;
    }

    void displayAccountInfo() const override {
        cout << "[Business] ";
        BankAccount::displayAccountInfo();
    }
};

class User {
protected:
    string name;

public:
    User(string n) : name(n) {}
    virtual void performOperations(BankAccount& account) = 0;
    virtual ~User() {}
};

class Customer : public User {
public:
    Customer(string n) : User(n) {}

    void performOperations(BankAccount& account) override {
        cout << "👤 Customer: " << name << " performing operations." << endl;
        account.deposit(500);
        account.withdraw(200);
    }
};

class Employee : public User {
public:
    Employee(string n) : User(n) {}
};

class Teller : public Employee {
public:
    Teller(string n) : Employee(n) {}

    void performOperations(BankAccount& account) override {
        cout << "🏦 Teller: " << name << " assisting a transaction." << endl;
        account.deposit(1000);
        account.withdraw(700);
    }
};

class Manager : public Employee {
public:
    Manager(string n) : Employee(n) {}

    void performOperations(BankAccount& account) override {
        cout << "👔 Manager: " << name << " managing accounts." << endl;
        account.deposit(5000);
        account.withdraw(3000);
    }
};

int main() {
    SavingsAccount savings(1001, 2000, 0.05);
    CheckingAccount checking(1002, 1500, 500);
    BusinessAccount business(1003, 5000, 0.10);

    Customer customer("Alice");
    Teller teller("Bob");
    Manager manager("Charlie");

    vector<BankAccount*> accounts = {&savings, &checking, &business};

    cout << "\n🏦 Account Details:\n";
    for (auto acc : accounts) {
        acc->displayAccountInfo();
    }

    vector<User*> users = {&customer, &teller, &manager};

    cout << "\n🔄 Users Performing Operations:\n";
    for (auto user : users) {
        user->performOperations(savings);
    }

    return 0;
}
