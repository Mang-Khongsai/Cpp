#include<iostream>
using namespace std;

class Parent{
    private:
    string name;
    int roll;

    public:
    Parent(string n, int r): name(n), roll(r){}
    

    public:
    void Print(){
        cout <<"Name: "<<name<<"\nRollno: "<<roll<<endl;
    }
    
};
int main(){
    Parent parent("Angelia", 29);

    parent.Print();
    return 0;
}