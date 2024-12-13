#include<iostream>
using namespace std;

struct Animal{
    string name;
    int age;
};



int main(){
    // Create a structure variable
    Animal domestic;
    domestic.name = "dog";
    domestic.age = 3;
    cout <<"Name: "<<domestic.name<<endl;
    cout <<"Age: "<<domestic.age<<endl;

    domestic.name = "cat";
    domestic.age = 2;
    cout <<"Name: "<<domestic.name<<endl;
    cout <<"Age: "<<domestic.age<<endl;
    return 0;
}