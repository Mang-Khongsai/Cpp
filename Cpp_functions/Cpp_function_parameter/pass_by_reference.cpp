#include<iostream>
using namespace std;

void change(int &data);

int main(){
    int data=10;
    cout <<"data: "<<data<<endl;
    change(data);
    cout <<"data1: "<<data<<endl;
    return 0;
}

void change(int &data){
    data = 20;
}