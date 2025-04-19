#include <iostream>
using namespace std;

class Shape
{
public:
    virtual int getArea() = 0;
};

class Rectangle : public Shape {
    public : 
    int getArea() {
        int h, w;

        cout << "Enter Height and Width :" << endl;
        cin >> h >> w;
        cout << "The Area of Rectangle is : " << h*w << endl;
    }
};


class Triangle : public Shape {
    public : 
    int getArea() {
        int h, b;

        cout << "Enter Height and Breadth :" << endl;
        cin >> h >> b;
        cout << "The Area of Triangle is : " << (h*b)/2 << endl;
    }
};


int main() {

    Rectangle r1;
    Triangle t1;

    r1.getArea();
    t1.getArea();
};