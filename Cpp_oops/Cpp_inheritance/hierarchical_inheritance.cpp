#include<iostream>
using namespace std;

class Domestic{
    public:
    void status(){
        cout <<" Domestic animal"<<endl;
    }
};

class Dog: public Domestic{
    public:
    void bark(){
        cout <<"dog barks"<<endl;
    }
};

class Cat: public Domestic{
    public:
    void sound(){
        cout <<"cat say meow"<<endl;
    }
};

int main(){
    Dog dog;
    dog.status();
    dog.bark();

    cout <<"\n";
    Cat cat;
    cat.status();
    cat.sound();
    return 0;
}