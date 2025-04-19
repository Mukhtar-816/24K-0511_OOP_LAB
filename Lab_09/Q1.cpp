#include <iostream>
using namespace std;
const double DAY_MAX_LIM = 10000.0;

class Wallet
{
private:
    double balance;
    double day_max_transactions = 0;

public:
    Wallet(double user_balance) : balance(user_balance)
    {
        if (user_balance < 0)
        {
            this->balance = 0;
        };
    };

    bool deposit(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid Amount";
            return false;
        }

        if (day_max_transactions >= DAY_MAX_LIM)
        {
            cout << "Today's Transaction Limit has already Reached." << endl;
            return false;
        };

        balance += amount;
        day_max_transactions += amount;
    };

    bool withDraw(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid Amount" << endl;
            return false;
        }

        if (day_max_transactions >= DAY_MAX_LIM)
        {
            cout << "Today's Transaction Limit has already Reached." << endl;
            return false;
        };

        if (amount > balance)
        {
            cout << "Insufficient Balance" << endl;
            return false;
        }

        balance -= amount;
        day_max_transactions += amount;
    }

    double getBalance() const
    {
        return balance;
    };

    void resetLimit() 
    {
        day_max_transactions = 0;
    };
};

class User
{
private:
    string userID;
    string userName;
    Wallet userWallet;

public:
    User(string uid, string name) : userID(uid), userName(name), userWallet(0) {};

    bool deposit(double amount)
    {
        return userWallet.deposit(amount);
    };

    bool withDraw(double amount)
    {
        return userWallet.withDraw(amount);
    };

    void getBalance()
    {
        cout << "The balance is :" << userWallet.getBalance() << endl;
    };

    void resetLimit()
    {
        userWallet.resetLimit();
        cout << "The Limit has been reset.";
    };
};

int main()
{
    User user1("123", "John"), user2("456", "Ali");

    user1.deposit(2000);
    user1.deposit(3000);
    user1.withDraw(5600);
    user1.getBalance();

    user2.deposit(2000);
    user2.deposit(3000);
    user2.withDraw(4500);
    user2.getBalance();

    return 0;
}