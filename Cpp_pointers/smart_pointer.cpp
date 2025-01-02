#include<iostream>
using namespace std;

class MyClass{
    public:
    MyClass(int value): value(value){
        cout <<"MyClass created with value: "<<value<<endl;
    }

    ~MyClass(){
        cout <<"MyClass destroyed."<<endl;
    }

    void display(){
        cout <<"value: "<<value<<endl;
    }
    private:
    int value;
};


// 3 types of smart pointers
    // 1. unique pointer
    // 2. shared pointer
    // 3. weak pointer
int main(){
    // create a new object of MyClass using dynamnic memory allocation(new keyword)
    MyClass *ptr = new MyClass(10); 

    // this line calls the display function of the MyClass object using the pointer ptr.
    // the -> operator is used to access members(functions or variables) of an object through a pointer
    ptr->display(); //

    delete ptr;

    return 0;
}
