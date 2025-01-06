#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Friend function declaration
    friend Complex multiply(const Complex &c1, const Complex &c2);

    // Display function
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Friend function definition
Complex multiply(const Complex &c1, const Complex &c2) {
    double realPart = c1.real * c2.real - c1.imag * c2.imag;
    double imagPart = c1.real * c2.imag + c1.imag * c2.real;
    return Complex(realPart, imagPart);
}

int main() {
    Complex c1(3, 4); // First complex number: 3 + 4i
    Complex c2(1, 2); // Second complex number: 1 + 2i

    cout << "First Complex Number: ";
    c1.display();
    cout << "Second Complex Number: ";
    c2.display();

    Complex result = multiply(c1, c2);
    cout << "Multiplication Result: ";
    result.display();

    return 0;
}
