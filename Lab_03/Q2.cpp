#include <iostream>
using namespace std;

class Date {
    public :
    int _month;
    int _day;
    int _year;

    void displayDate(){
        cout << _month << "/" << _day << "/" << _year << endl;
    };
};



int main(){
    Date date;
    int month, day, year;

    cout << "Enter month, day and year :"<<endl;
    cin >> month >> day >> year;

    date._month = month;
    date._day = day;
    date._year = year;

    date.displayDate();

}