#include <iostream>
using namespace std;


class Circle {

    public :
    double radius, area, circumference, Pi;


    Circle(int r) : radius(r), Pi(3.1415){}; //constructor

    double getArea(){
        return area = Pi * radius * radius;
    };

    double getPerimeter(){
        return circumference = 2 * Pi * radius;
    };

};

int main() {
    Circle circle(6.3);

    cout << "The circle Area is : " << circle.getArea() << endl << "The circle Perimeter is : " << circle.getPerimeter() << endl;

}
