#include<iostream>
using namespace std;
int recurse(int num){
    if (num<=1){
        return num;
    } 
    else{
        return recurse(num-1);
    }
}
int main(){
    int num;
    cout <<"Enter num val: ";
    cin >>num;
    int val = recurse(num);
    cout <<"val: "<<val<<endl;
    return 0;
}