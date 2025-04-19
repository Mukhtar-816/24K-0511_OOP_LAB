#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Passenger;

class Flight {
private:
    string flightNumber, departure, arrival;
    int capacity, bookedSeats;
    vector<string> bookedPassengers;

    bool isPassengerBooked(const string& passengerID) {
        for (const string& id : bookedPassengers) {
            if (id == passengerID) return true;
        }
        return false;
    }

public:
    Flight(string num, string from, string to, int cap)
        : flightNumber(num), departure(from), arrival(to), capacity(cap), bookedSeats(0) {}

    bool bookSeat(const string& passengerID) {
        if (bookedSeats >= capacity) {
            cout << "Booking failed: Flight " << flightNumber << " is full.\n";
            return false;
        }
        if (isPassengerBooked(passengerID)) {
            cout << "Passenger already booked on flight " << flightNumber << ".\n";
            return false;
        }
        bookedPassengers.push_back(passengerID);
        bookedSeats++;
        cout << "Seat booked on flight " << flightNumber << " for passenger " << passengerID << ".\n";
        return true;
    }

    bool cancelSeat(const string& passengerID) {
        for (size_t i = 0; i < bookedPassengers.size(); ++i) {
            if (bookedPassengers[i] == passengerID) {
                bookedPassengers.erase(bookedPassengers.begin() + i);
                bookedSeats--;
                cout << "Seat canceled for passenger " << passengerID << " on flight " << flightNumber << ".\n";
                return true;
            }
        }
        cout << "Cannot cancel: Passenger not found on flight " << flightNumber << ".\n";
        return false;
    }

    bool upgradeSeat(const string& passengerID) {
        if (!isPassengerBooked(passengerID)) {
            cout << "Cannot upgrade: Passenger " << passengerID << " not booked on flight " << flightNumber << ".\n";
            return false;
        }
        cout << "Seat upgraded for passenger " << passengerID << " on flight " << flightNumber << ".\n";
        return true;
    }

    void showFlightDetails() const {
        cout << "Flight: " << flightNumber << " | From: " << departure << " | To: " << arrival << "\n";
        cout << "Capacity: " << capacity << " | Booked: " << bookedSeats << "\n";
    }

    friend class Passenger;
};

class Passenger {
private:
    string passengerID, name;

public:
    Passenger(string id, string n) : passengerID(id), name(n) {}

    void requestBooking(Flight& flight) {
        flight.bookSeat(passengerID);
    }

    void requestCancellation(Flight& flight) {
        flight.cancelSeat(passengerID);
    }

    void requestUpgrade(Flight& flight) {
        flight.upgradeSeat(passengerID);
    }

    void showInfo() const {
        cout << "Passenger: " << name << " | ID: " << passengerID << endl;
    }
};

int main() {
    Flight f1("PK101", "Karachi", "Islamabad", 2);
    Flight f2("PK202", "Lahore", "Peshawar", 1);

    Passenger p1("P001", "Ali");
    Passenger p2("P002", "Sara");
    Passenger p3("P003", "Zain");

    f1.showFlightDetails();

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1);

    p1.requestUpgrade(f1);
    p3.requestUpgrade(f1);

    p2.requestCancellation(f1);
    p3.requestBooking(f1);

    f1.showFlightDetails();

    return 0;
}
