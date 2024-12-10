#include <iostream>
using namespace std;

int main(){
int a = 25, b = 35, temp;
cout <<"Free Style"<<endl;
cout <<"a: "<<a<<"| b: "<<b<<endl;
temp = a;
a = b;
b = temp;
cout <<"a: "<<a<<"| b: "<<b<<endl;

cout <<"With Only 2 Variable"<<endl;
int x = 28, y = 37;
x = x + y;
y = x-y;
x = x-y;
cout <<"\na: "<<a<<"| b: "<<b<<endl;
return 0;
}
