#include <iostream>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int creditHours) = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() {
        return researchTopic;
    }

    double getTuition(string status, int creditHours) override {
        if (status == "undergraduate")
            return 200 * creditHours;
        else if (status == "graduate")
            return 300 * creditHours;
        else if (status == "doctoral")
            return 400 * creditHours;
        else {
            cout << "Invalid status." << endl;
            return 0;
        }
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("Machine Learning");
    cout << "Research Topic: " << gs.getResearchTopic() << endl;

    string status;
    int credits;

    cout << "Enter student status (undergraduate/graduate/doctoral): ";
    cin >> status;
    cout << "Enter credit hours: ";
    cin >> credits;

    double tuition = gs.getTuition(status, credits);
    cout << "Tuition fee: $" << tuition << endl;

    return 0;
}
