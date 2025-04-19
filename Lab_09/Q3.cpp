#include <iostream>
using namespace std;

class PatientRecord
{
private:
    string history, currentTreatment;
    friend class Doctor;

    void updateMedicalHistory(string data){
        this->history = data;
    };

public:
    string name;
    int ID;
    string DOB;
    bool billPaid;

    PatientRecord(string patientHistory, string patientCurrentTreatment, string patientName, int patientID, string patientDOB) : billPaid(0), history(patientHistory), currentTreatment(patientCurrentTreatment), name(patientName), ID(patientID), DOB(patientDOB) {};

    void getPublicData()
    {
        cout << "The patient details : " << endl;
        cout << "ID : " << ID << endl
             << "Name : " << name << endl
             << "Date of Birth : " << DOB << endl;
    };

    void getMedicalData()
    {
        cout << "The patient details : " << endl;
        cout << "History : " << history << endl
             << "current Treament : " << currentTreatment << endl;
    };

    void addBillingDetails(bool paid){
        this->billPaid = paid;
    }

};


class Doctor {
    public : 
    Doctor() {};

    void updateMedicalHistory(PatientRecord &record, string data){
        record.updateMedicalHistory(data);
    }
};


class Billing {
    private:
    bool PatientBillPaid;
    PatientRecord *record;

    public :
    Billing(bool Paid, PatientRecord &Record) : PatientBillPaid(Paid), record(&Record) {};

    void addBillingDetails(bool paid){
        record->addBillingDetails(paid);
    }

};


int main(){
    PatientRecord p1("Patient had fever", "Patient is being treated for cancer currently.", "John", 0742, "01/11/2003");

    Doctor D1;
    D1.updateMedicalHistory(p1, "The Pateint had asthma.");

    Billing B1(true, p1);
    // B1.updateMedicalHistory see it is inaccessable for Billing class .
    B1.addBillingDetails(true);
}