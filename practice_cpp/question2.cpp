#include <iostream>
using namespace std;

class Complex {
private:
    float real;       
    float imaginary;  

public:
    
    Complex(float r = 0, float i = 0) : real(r), imaginary(i) {}

    
    friend Complex operator+(const Complex& c1, const Complex& c2);

   
    void display() const {
        cout << real << " + " << imaginary << "i" << endl;
    }
};


Complex operator+(const Complex& c1, const Complex& c2) {
   
    float realResult = c1.real + c2.real;
    float imaginaryResult = c1.imaginary + c2.imaginary;

    
    return Complex(realResult, imaginaryResult);
}

int main() {
    
    Complex c1(3.5, 2.5);  // 3.5 + 2.5i
    Complex c2(1.5, 4.5);  // 1.5 + 4.5i

    
    cout << "First Complex Number: ";
    c1.display();
    cout << "Second Complex Number: ";
    c2.display();

    
    Complex result = c1 + c2;

    
    cout << "Sum of the two complex numbers: ";
    result.display();

    return 0;
}
