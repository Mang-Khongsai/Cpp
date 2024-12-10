#include <iostream>
#include <cmath>
using namespace std;


class Shape {
public:
    
    virtual float area() const = 0;  
    virtual ~Shape() {} 
};


class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    
    Rectangle(float l, float w) : length(l), width(w) {}

    
    float area() const override {
        return length * width;
    }
};


class Circle : public Shape {
private:
    float radius;

public:
   
    Circle(float r) : radius(r) {}

    
    float area() const override {
        return M_PI * radius * radius; 
    }
};

int main() {
    
    Rectangle rect(10, 5);
    Circle circ(7);

    
    Shape* shapePtr;

    
    shapePtr = &rect;
    cout << "Area of Rectangle: " << shapePtr->area() << endl;

    
    shapePtr = &circ;
    cout << "Area of Circle: " << shapePtr->area() << endl;

    return 0;
}
