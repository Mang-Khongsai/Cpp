#include<iostream>
using namespace std;
class Dog{
    public:
    void bark(){
        cout <<"Dog bark"<<endl;
    }
};

class Puppy{
    public:
    void play(){
        cout <<"puppy play"<<endl;
    }

};

class Pet:public Dog, public Puppy{
    public:
    void home(){
        cout <<"dog and puppy are home pet animal:"<<endl;
    }

};
int main(){
    Pet pet;
    pet.home();
    pet.bark();
    pet.play();
return 0;
}
