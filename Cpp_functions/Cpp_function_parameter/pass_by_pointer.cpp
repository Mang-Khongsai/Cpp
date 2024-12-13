#include<iostream>
using namespace std;
void change(int *data);

int main(){
    int data = 10;

    cout<<"before changing: "<<data<<endl;
    change(&data);
    cout <<"after changing: "<<data<<endl;
}

void change(int *data){
    *data = 20;
}