#include <iostream>
using namespace std;

class Vehicle {
public:
    int horsepower;
    int seats;
    int speakers;

    void updateHorsepower(int hp) const {
        const_cast<Vehicle*>(this)->horsepower = hp;
    }

    void updateSeating(int count) const {
        const_cast<Vehicle*>(this)->seats = count;
    }

    void updateSpeakers(int count) const {
        const_cast<Vehicle*>(this)->speakers = count;
    }

    void showDetails() const {
        cout << "Horsepower: " << horsepower << endl;
        cout << "Seats: " << seats << endl;
        cout << "Speakers: " << speakers << endl;
    }
};

int main() {
    Vehicle car;

    car.updateHorsepower(300);
    car.updateSeating(5);
    car.updateSpeakers(6);

    car.showDetails();

    return 0;
}
