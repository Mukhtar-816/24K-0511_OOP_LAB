#include <iostream>
using namespace std;

class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}
    virtual void display() {
        cout << "Price: $" << price << endl;
    }
};

class Car : public Vehicles {
protected:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;
public:
    Car(double p, int sc, int nd, string ft) : Vehicles(p), seatingCapacity(sc), numberOfDoors(nd), fuelType(ft) {}
    void display() override {
        cout << "Price: $" << price << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicles {
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;
public:
    Motorcycle(double p, int nc, int ng, int nw) : Vehicles(p), numberOfCylinders(nc), numberOfGears(ng), numberOfWheels(nw) {}
    void display() override {
        cout << "Price: $" << price << endl;
        cout << "Number of Cylinders: " << numberOfCylinders << endl;
        cout << "Number of Gears: " << numberOfGears << endl;
        cout << "Number of Wheels: " << numberOfWheels << endl;
    }
};

class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int sc, int nd, string ft, string mt) : Car(p, sc, nd, ft), modelType(mt) {}
    void display() override {
        Car::display();
        cout << "Model Type: " << modelType << endl;
        cout << "-------------------------" << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int nc, int ng, int nw, string mt) : Motorcycle(p, nc, ng, nw), makeType(mt) {}
    void display() override {
        Motorcycle::display();
        cout << "Make Type: " << makeType << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    Audi audiCar(50000, 5, 4, "Petrol", "A6");
    Yamaha yamahaBike(15000, 2, 6, 2, "YZF-R1");
    
    audiCar.display();
    yamahaBike.display();
    
    return 0;
}
