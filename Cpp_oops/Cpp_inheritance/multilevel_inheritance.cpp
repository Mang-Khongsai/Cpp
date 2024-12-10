#include<iostream>
using namespace std;
class Animal{
    public:
        void speak(){
            cout <<"Animal speaks"<<endl;
        }
};

class Dog:public Animal{
    public:
        void bark(){
            cout <<"Dog barks"<<endl;
        }
};

class Puppy:public Dog{
    public:
        void play(){
            cout <<"puppy plays"<<endl;
       }
};



int main(){
Puppy puppy;
puppy.speak();
puppy.bark();
puppy.play();
return 0;
}
