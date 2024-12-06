#include<iostream>
using namespace std;

class Rectangle{
    private:
    double length;
    protected:
    double breadth;
    
    public:
    Rectangle(double l, double b){
        length = l;
        breadth = b;
    }

    friend void Area(Rectangle r);
};

void Area(Rectangle r){
    cout <<"Area: "<<(r.length)*(r.breadth)<<endl;
}

int main(){
    double le, br;
    cout <<"length: ";
    cin >>le;
    cout <<"breadth: ";
    cin >>br;

    Rectangle rect(le, br);
    Area(rect);
    return 0;
}