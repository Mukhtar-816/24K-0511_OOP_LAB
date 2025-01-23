#include <iostream>
using namespace std;


float calculateBill(int units, float *bill, float *charges_per_unit){
    if (units <= 199 ){
        *bill = units * 16.20;
        *charges_per_unit = 16.20;
    }
    else if (units >= 200 && units < 300){
        *bill = units * 20.10;
        *charges_per_unit = 20.10;
    }
    else if (units >= 300 && units < 500){
        *bill = units * 27.10;
        *charges_per_unit = 27.10;
    }
    else if (units >= 500){
        *bill = units * 35.90;
        *charges_per_unit = 35.90;
    }
    else {
        cout << "Invalid input";
    }

};

int main(){
    string name;
    int id, units_consumed = 0;
    float bill = 0, charges_per_unit = 0;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your ID: ";
    cin >> id;

    cout << "Enter units consumed: ";
    cin >> units_consumed;

    calculateBill(units_consumed, &bill, &charges_per_unit);
    float Total_bill = bill + (bill > 18000 ? 0.15 * bill : 0);

    cout << "Customer ID : "<< id << endl;
    cout << "Customer Name : "<< name << endl;
    cout << "Units Consumed : "<<units_consumed<<endl;
    cout << "Amount Charges @"<<charges_per_unit<<" per unit : "<< bill << endl;
    bill > 18000 ? cout << "Surcharge Amount : " << 0.15 * bill << endl : cout << "Surcharge Amount : 0" << endl;
    cout << "Net Amount Paid By the Customer : " << Total_bill  << endl;

}