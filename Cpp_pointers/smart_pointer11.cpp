#include<iostream>
#include<memory> // for unique_ptr

using namespace std;

class MyClass {
public:
    MyClass(int value) : value(value) {
        cout << "MyClass created with value: " << value << endl;
    }

    ~MyClass() { // Corrected destructor
        cout << "MyClass destroyed with value: " << value << endl;
    }

    void display() {
        cout << "value: " << value << endl;
    }

private:
    int value;
};

int main() {
    // Creating a unique_ptr to manage MyClass instance
    unique_ptr<MyClass> ptr = make_unique<MyClass>(10);
    
    // Corrected: Calling display method with parentheses
    ptr->display();

    // When ptr goes out of scope, MyClass destructor will be called automatically
    return 0;
}
