#include<iostream>
using namespace std;

void change(int data);
int change1(int data);

int main(){
    int data = 5;
    cout <<"data: "<<data<<"\n\n";
    change(data);
    cout <<"data1: "<<data<<"\n\n";
    cout <<"data2: "<<change1(data);
    return 0;
}

void change(int data){
    data = 10;
}

int change1(int data){
    data = 10;
    return data;
}