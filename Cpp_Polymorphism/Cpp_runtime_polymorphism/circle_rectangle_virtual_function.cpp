/*
You are tasked with creating a base class shape and two derived classes Circle
 and Rectangle. Each shape has a method to calculate the area. Use virtual functions 
 to calculate and display the area of each shape dynamically
*/

#include <iostream>
#include <cmath> // For M_PI
using namespace std;

// Base class
class Shape {
public:
    virtual double calculateArea() const {
        return 0.0; // Default implementation, if not overridden
    }

    virtual void displayArea() const {
        cout << "Area: " << calculateArea() << endl;
    }

    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return M_PI * radius * radius; // Area of a circle: πr²
    }

    void displayArea() const override {
        cout << "Circle's Area: " << calculateArea() << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width; // Area of a rectangle: length × width
    }

    void displayArea() const override {
        cout << "Rectangle's Area: " << calculateArea() << endl;
    }
};

// Main function
int main() {
    // Create Shape pointers to Circle and Rectangle
    Shape* shapes[2];

    // Dynamically allocate memory for Circle and Rectangle objects
    shapes[0] = new Circle(3); // Circle with radius 5.0
    shapes[1] = new Rectangle(3.0, 6.0); // Rectangle with length 4.0 and width 6.0

    // Display the area of each shape dynamically
    for (int i = 0; i < 2; ++i) {
        shapes[i]->displayArea();
    }

    // Clean up allocated memory
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

    return 0;
}
