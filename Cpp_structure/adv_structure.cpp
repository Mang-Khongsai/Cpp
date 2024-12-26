#include<iostream>
using namespace std;

struct Person{
    string name;
    int age;
};

int main(){
    int n;
    cout <<"enter the size of n: ";
    cin >>n;
    Person person[n];
    cout <<"size: "<<n<<endl;


    //int size = sizeof(person)/sizeof(person[0]);
    //cout <<"size: "<<size<<endl;
    
    // input section
    // for(int i=0;i<size;i++){
    for(int i=0;i<n;i++){
        cout <<(i+1)<<". Name: ";
        cin >>person[i].name;
        cout <<(i+1)<<". Age: ";
        cin >>person[i].age;
        cout<<endl;
    }
    // output section 
    cout <<"\n-------------LIST OF NAMES-------------"<<endl;
    //for(int i=0;i<size;i++){
    for(int i=0;i<n;i++){
        cout <<"\t\t"<<(i+1)<<"Name: "<<person[i].name<<endl;
        cout <<"\t\t"<<(i+1)<<"Age: "<<person[i].age<<endl;
        cout <<endl;
    }
    return 0;
}