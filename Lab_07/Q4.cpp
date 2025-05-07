#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() const {
        cout << name << " " << id << " " << address << " " << phoneNumber << " " << email << endl;
    }

    virtual void updateInfo(string addr, string phone, string mail) {
        address = addr;
        phoneNumber = phone;
        email = mail;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    string course1, course2, course3;
    double gpa;
    int enrollmentYear;
public:
    Student(string n, string i, string addr, string phone, string mail, double g, int year, string c1, string c2, string c3)
        : Person(n, i, addr, phone, mail), gpa(g), enrollmentYear(year), course1(c1), course2(c2), course3(c3) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Student " << enrollmentYear << " GPA: " << gpa << " Courses: " << course1 << " " << course2 << " " << course3 << endl;
    }
};

class Professor : public Person {
private:
    string department, taught1, taught2;
    double salary;
public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, double sal, string t1, string t2)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal), taught1(t1), taught2(t2) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Professor " << department << " Salary: " << salary << " Teaches: " << taught1 << " " << taught2 << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;
public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Staff " << department << " Position: " << position << " Salary: " << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
public:
    Course(string id, string name, int c, string instr, string sched)
        : courseId(id), courseName(name), credits(c), instructor(instr), schedule(sched) {}

    void registerStudent(Student* student) {
        cout << "Registered student in " << courseName << endl;
    }

    void calculateGrades() {
        cout << "Grades calculated for " << courseName << endl;
    }

    void displayCourseInfo() {
        cout << courseId << " " << courseName << " " << credits << " " << instructor << " " << schedule << endl;
    }
};

int main() {
    Student s("John", "S101", "123 Street", "111-222", "john@mail.com", 3.5, 2022, "CS101", "MATH102", "ENG103");
    Professor p("Dr.Smith", "P202", "456 Avenue", "333-444", "smith@mail.com", "CS", 80000, "CS101", "CS102");
    Staff st("Anna", "ST303", "789 Blvd", "555-666", "anna@mail.com", "Admin", "Manager", 50000);
    Course c("CS101", "Intro to CS", 3, "Dr.Smith", "Mon-Wed");

    s.displayInfo();
    p.displayInfo();
    st.displayInfo();
    c.displayCourseInfo();
    c.registerStudent(&s);
    c.calculateGrades();

    return 0;
}
