#include <iostream>
#include <memory>  // for unique_ptr

using namespace std;

// Class definition
class MyClass {
public:
    // Constructor
    MyClass(int value) : value(value) {
        cout << "MyClass created with value: " << value << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "MyClass destroyed with value: " << value << endl;
    }

    // Method to display the value
    void display() const {
        cout << "Value inside MyClass: " << value << endl;
    }

private:
    int value;
};

int main() {
    // Create a unique_ptr to manage the object of MyClass
    unique_ptr<MyClass> ptr = make_unique<MyClass>(42);

    // Using the object managed by unique_ptr
    cout << "Using the object..." << endl;
    ptr->display();

    // The object will be automatically destroyed when ptr goes out of scope

    return 0;
}
