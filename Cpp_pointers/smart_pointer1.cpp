
#include<iostream>
#include<memory> //for unique_ptr

class MyClass{
    public:
    MyClass(int value): value(value){
        cout <<"MyClass created with value: "<< value<<endl;
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

int main(){
    unique_ptr<MyClass>ptr = make_unique<MyClass>(10);
    ptr->display()

    return 0;
}