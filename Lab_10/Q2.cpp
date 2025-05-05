#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Employee
{
    int id;
    string name;
    string designation;
    int years;

    string to_string() const
    {
        return std::to_string(id) + "," + name + "," + designation + "," + std::to_string(years);
    }
};

vector<Employee> readData(string filename)
{
    ifstream file(filename);
    vector<Employee> employees;
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        Employee emp;

        getline(ss, token, ',');
        emp.id = stoi(token);
        getline(ss, emp.name, ',');
        getline(ss, emp.designation, ',');
        getline(ss, token, ',');
        emp.years = stoi(token);

        employees.push_back(emp);
    }

    file.close();
    return employees;
}

void writeData(string filename, const vector<Employee> &employees)
{
    ofstream file(filename);
    for (const auto &emp : employees)
    {
        file << emp.to_string() << endl;
    }
    file.close();
}

int main()
{
    string filename = "employees.txt";

    vector<Employee> initial = {
        {1, "Alice", "manager", 3},
        {2, "Bob", "developer", 1},
        {3, "Charlie", "manager", 1},
        {4, "Daisy", "manager", 5},
        {5, "Eve", "tester", 4}};
    writeData(filename, initial);

    vector<Employee> all = readData(filename);
    vector<Employee> filtered;
    for (auto &emp : all)
    {
        if (emp.designation == "manager" && emp.years >= 2)
        {
            filtered.push_back(emp);
        }
    }

    cout << "Query A - Managers with >=2 years:" << endl;
    for (const auto &emp : filtered)
    {
        cout << emp.to_string() << endl;
    }

    writeData(filename, filtered);
    cout << "\nQuery B - File overwritten with filtered data." << endl;

    vector<Employee> updated = readData(filename);
    for (auto &emp : updated)
    {
        emp.id += 100;
        emp.years += 1;
    }
    writeData(filename, updated);
    cout << "\nQuery C - Filtered data updated and written back with incremented IDs/years." << endl;

    return 0;
}
