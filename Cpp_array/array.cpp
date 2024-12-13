#include<iostream>
using namespace std;

int main(){
    string cars[5] = {"Ford", "Volvo", "BMW", "Toyota", "Hyundai"};

    //1. access items by index
    cout << cars[0]<<"\n\n";

    int size = sizeof(cars)/sizeof(cars[0]);
    // 2. for loop
    for(int i=0;i < size; i++){
        cout <<cars[i]<<" ";
    }
    cout <<endl;

    // 3. 
    return 0;
}
