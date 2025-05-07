#include <iostream>
using namespace std;

class Student {
public:
    int roll_no;
    Student(int roll) : roll_no(roll) {}
    void displayRollNo() const {
        cout << "Roll No: " << roll_no << endl;
    }
};

int main() {
    int roll;
    cout << "Enter roll number: ";
    cin >> roll;
    Student student(roll);
    student.displayRollNo();
    return 0;
}
