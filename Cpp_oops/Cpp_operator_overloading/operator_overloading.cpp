#include<iostream>
using namespace std;

class complex{
    public:
    int real, imag;
    
    complex(int r=0, int i=0): real(r), imag(i){}

    complex operator+(const complex& other){
        complex temp;
        temp.real = this->real + other.real;
        temp.imag = this->imag + other.imag;
        return temp;
    }

    void display(){
        cout <<real <<"+"<<imag<<"i"<<endl;
    }
};

int main(){
        complex c1(3, 4), c2(5,6);
        complex c3 = c1+c2;

        c3.display();
    return 0;
    }
