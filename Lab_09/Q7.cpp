#include <iostream>
using namespace std;

class Person {
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual void bonus() = 0;
    virtual ~Person() {}
};

class Admin : virtual public Person {
protected:
    string name;
    int id;
    double salary;
public:
    void getData() override {
        cout << "Enter Admin Name: ";
        cin >> name;
        cout << "Enter Admin ID: ";
        cin >> id;
        cout << "Enter Admin Salary: ";
        cin >> salary;
    }

    void displayData() override {
        cout << "Admin Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }

    void bonus() override {
        cout << "Admin Bonus: " << salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
protected:
    string accName;
    int accId;
    double accSalary;
public:
    void getData() override {
        cout << "Enter Accountant Name: ";
        cin >> accName;
        cout << "Enter Accountant ID: ";
        cin >> accId;
        cout << "Enter Accountant Salary: ";
        cin >> accSalary;
    }

    void displayData() override {
        cout << "Accountant Name: " << accName << ", ID: " << accId << ", Salary: " << accSalary << endl;
    }

    void bonus() override {
        cout << "Accountant Bonus: " << accSalary * 0.08 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        Admin::getData();
        Account::getData();
    }

    void displayData() override {
        Admin::displayData();
        Account::displayData();
    }

    void bonus() override {
        Admin::bonus();
        Account::bonus();
    }
};

int main() {
    Person* p;

    Master m;
    p = &m;
    p->getData();
    p->displayData();
    p->bonus();

    return 0;
}
