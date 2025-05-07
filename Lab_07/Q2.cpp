#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Shape {
protected:
    float x, y;
    string color;
    float borderThickness;

public:
    Shape(float xpos, float ypos, string c, float bt = 1.0f)
        : x(xpos), y(ypos), color(c), borderThickness(bt) {}

    virtual void draw() const {
        cout << "Drawing generic Shape at (" << x << ", " << y << ")" << endl;
    }

    virtual float calculateArea() const = 0;
    virtual float calculatePerimeter() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float xpos, float ypos, string c, float r, float bt = 1.0f)
        : Shape(xpos, ypos, c, bt), radius(r) {}

    void draw() const override {
        cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << endl;
    }

    float calculateArea() const override {
        return M_PI * radius * radius;
    }

    float calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    float width, height;

public:
    Rectangle(float xpos, float ypos, string c, float w, float h, float bt = 1.0f)
        : Shape(xpos, ypos, c, bt), width(w), height(h) {}

    void draw() const override {
        cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << endl;
    }

    float calculateArea() const override {
        return width * height;
    }

    float calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

int main() {
    Circle c1(0, 0, "Red", 10);
    Rectangle r1(5, 5, "Blue", 20, 10);

    Shape* s1 = &c1;
    Shape* s2 = &r1;

    s1->draw();
    cout << "Area: " << s1->calculateArea() << endl;
    cout << "Perimeter: " << s1->calculatePerimeter() << endl;
    cout << "------------------------" << endl;

    s2->draw();
    cout << "Area: " << s2->calculateArea() << endl;
    cout << "Perimeter: " << s2->calculatePerimeter() << endl;

    return 0;
}
