#include <iostream>
#include <string>
using namespace std;

struct Subject {
    string name;
};

struct Student {
    int id;
    Subject subjects[5]; // Fixed size array for subjects
};

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    Student* students = new Student[N];

    for (int i = 0; i < N; i++) {
        cout << "Enter ID for student " << (i + 1) << ": ";
        cin >> students[i].id;

        cout << "Enter subjects for student " << (i + 1) << " (up to 5 subjects):" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "Subject " << (j + 1) << ": ";
            cin >> students[i].subjects[j].name;
        }
    }

    cout << "\nStudent Details:\n";
    for (int i = 0; i < N; i++) {
        cout << "ID: " << students[i].id << endl;
        cout << "Subjects: ";
        for (int j = 0; j < 5; j++) {
            cout << students[i].subjects[j].name << " ";
        }
        cout << endl;
    }

    delete[] students;
    return 0;
}
