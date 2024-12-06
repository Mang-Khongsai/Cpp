#include<iostream>
using namespace std;

int main(){
    int num = 10;

    cout <<"num: "<<num<<endl;
    // +=
    num += 5;
    cout <<"num+=5: "<<num<<endl;

    // -= 
    num -= 5;
    cout <<"num-=5: "<<num<<endl;

    // *=
    num *= 2;
    cout <<"num*=2: "<<num<<endl;

    // /=
    num /=5;
    cout <<"num/=5: "<<num<<endl;

    // %=
    num %= 2;
    cout <<"num%=2: "<<num<<endl;
    return 0;
}