#include<iostream>
using namespace std;

int main(){
    // Arithmetic operator
    // addition +
    float first, second;
    cout <<"Enter first and second input: ";
    cin >>first>>second;

    // addition
    cout <<"first + second: "<<(first + second)<<endl;

    // subtraction - 
    cout <<"second - first: "<<(second - first) <<endl;

    // multiplication
    cout <<"first X second: "<<(first*second)<<endl;

    // division
    cout <<"second / first: "<<(second/first)<<endl;

    // remainder or modulus
    int firstn = static_cast<int>(first);
    int secondn = static_cast<int>(second);
    cout <<"remainder: second%first:"<<(secondn % firstn)<<endl;

    // increment var++ and ++var
    firstn++;
    cout <<"first++: "<<(firstn)<<"     ++first: "<<(++firstn)<<endl;

    // decrement var--
    cout <<"first--: "<<(firstn--)<<"    --firstn: "<<(--firstn)<<endl;

    // decrement
    return 0;
}