#include<iostream>
using namespace std;
class Animal{
public:  
    void speak(){
	 cout <<"Animal speaks"<<endl;
     }
};

class Dog: public Animal{
public:
     void bark(){
        cout <<"dog barks"<<endl;
      }
};
int main(){
Dog dog;
dog.speak();  // dog can call animal method because class dog inherit from class animal
dog.bark();  // dog owns method
return 0;
}
