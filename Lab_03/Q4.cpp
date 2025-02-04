#include <iostream>
using namespace std;

class Employee
{
public:
    string _firstName;
    string _lastName;
    double _salary = 0;
};

int main()
{
    Employee employee1, employee2;

    for (int i = 0; i < 2; i++)
    {
        string firstname, lastname;
        double salary;

        cout << "Enter first employee details ( firstname, lastname and salary ) :" << endl;
        cin >> firstname >> lastname >> salary;

        if (i == 0)
        {
            employee1._firstName = firstname;
            employee1._lastName = lastname;
            employee1._salary = salary;
        }
        else if (i == 1)
        {
            employee2._firstName = firstname;
            employee2._lastName = lastname;
            employee2._salary = salary;
        }
    };

     if (employee1._salary < 0){
            employee1._salary = 0; 
        }
        if (employee2._salary < 0){
            employee2._salary = 0; 
        }

    cout << "First Employee salary is : " << employee1._salary << endl
         << "Second Employee salary is : " << employee2._salary << endl;
    employee1._salary += employee1._salary * 0.1;
    employee2._salary += employee2._salary * 0.1;

    cout << "First Employee salary after 10% raise is : " << employee1._salary << endl
         << "Second Employee salary after 10% raise is : " << employee2._salary << endl;
}