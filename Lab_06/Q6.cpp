#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int rollNumber;
    string department;
public:
    Student(string n, int r, string d) : name(n), rollNumber(r), department(d) {}
    void display() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Department: " << department << endl;
    }
};

class Marks : public Student {
protected:
    int courseMarks[3];
public:
    Marks(string n, int r, string d, int m1, int m2, int m3) : Student(n, r, d) {
        courseMarks[0] = m1;
        courseMarks[1] = m2;
        courseMarks[2] = m3;
    }
    void display() {
        Student::display();
        cout << "Marks Obtained:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Course " << i + 1 << ": " << courseMarks[i] << endl;
        }
    }
};

class Result : public Marks {
public:
    Result(string n, int r, string d, int m1, int m2, int m3) : Marks(n, r, d, m1, m2, m3) {}
    void display() {
        Marks::display();
        int totalMarks = courseMarks[0] + courseMarks[1] + courseMarks[2];
        double averageMarks = totalMarks / 3.0;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    Result student1("John Doe", 101, "Computer Science", 85, 90, 88);
    student1.display();
    return 0;
}