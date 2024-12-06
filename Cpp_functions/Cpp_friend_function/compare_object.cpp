#include<iostream>
using namespace std;

class Number{

    private:
    double num1;
    double num2;
    public:
    Number(double no1, double no2): num1(no1), num2(no2){}

    friend double compare(Number n);
};

double compare(Number n){
    if (n.num1>n.num2) return (n.num1);
    else return n.num2;
}
int main(){
    double first, second;
    cout <<"enter first number: ";
    cin >>first;
    cout <<"enter second number: ";
    cin >>second;
    Number num(first, second);
    cout <<"The larger number is: "<<compare(num);
    return 0;
}