// destructor is used to destroy the objects that is already been created by the constructor
// A class can have only one destructor 
// No return type, not even void.
// it is a simple function with the same name as class, ~(destructor) 
// function name of Constructor and Destructor will be the same only destructor will have ~
#include<iostream>
using namespace std;

class ClassName{
    private:
    int* ptr;

    public:
    ClassName(int value){
        ptr = new int(value);
        cout <<"Constructor: Memory allocated for value"<<*ptr<<endl;
    }
    ~ClassName(){
        // destructor
        delete ptr;
        cout <<"destructor memory deallocated"<<endl;
        
    }
    void display() const{
        cout <<"value: "<<*ptr<<endl;
    }
};

int main(){
    ClassName obj(24);
    obj.display();
    // Destructor is automatically called when object is out of scope
    return 0;
}