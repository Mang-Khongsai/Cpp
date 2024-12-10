#include<iostream>
using namespace std;

class Animal{
    public:
    void run(){
        cout <<"animal run fast"<<endl;
    }
};

class Bird{
    public:
    void fly(){
        cout <<"bird fly high"<<endl;
    }
};

class Jet:public Bird{
    public:
    void status(){
        cout <<"Jet imitate Bird"<<endl;
    }
};

class AnimalBird: public Jet, public Animal{
    public:
    void stats(){
        cout <<"This inherit animal, bird and Jet"<<endl;
    }
};
int main(){
    AnimalBird ab;
    ab.run();
    ab.fly();
    ab.status();
    ab.stats();
    return 0;
}