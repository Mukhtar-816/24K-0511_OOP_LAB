#include <iostream>
using namespace std;

class Account {

    public :

    int accountBalance;

    Account () { accountBalance = 0;};

    void addCredit(int balance){
        accountBalance += balance;
    };

    void getDebit(int val){
        accountBalance -= val;
    };

    void getBalance(){
        cout << "The current Balance is : " << accountBalance << endl;
    };
};

int main(){
    Account account;

    account.addCredit(1000);
    account.getDebit(500);
    account.getBalance();
};