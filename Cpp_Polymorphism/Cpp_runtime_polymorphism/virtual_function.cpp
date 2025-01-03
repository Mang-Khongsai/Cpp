#include<iostream>
using namespace std;


class Animal{
    public:
    virtual void sound(){
        cout <<"Animal makes a sound\n";
    }
};


class Dog: public Animal{
    public:
    void sound() override{
        cout <<"Dog barks\n";
    }
};

int main(){
    Animal* animal = new Dog();
    animal->sound(); // calls Dog's sound() because of virtual function
    delete animal;
    return 0;
}