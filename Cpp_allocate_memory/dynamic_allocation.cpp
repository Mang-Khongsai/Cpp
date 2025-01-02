#include<iostream>
using namespace std;

int main(){
    // dynamic or heap allocation
    // using new and delete

    //integer 
    int* ptr1 = new int;
    *ptr1 = 10;
    cout <<"ptr1: "<<ptr1<<"\n*ptr1: "<<*ptr1<<endl;

    int x = 20;
    cout <<"x: "<<x<<"\t&x: "<<&x<<endl;

    int *ptr = &x;
    cout <<"ptr: "<<ptr<<"\t*ptr: "<<*ptr<<endl;

    int **ptr2  = &ptr;
    cout <<"ptr2: "<<ptr2<<"\t**ptr2: "<<*ptr2<<"\t**ptr2: "<<**ptr2<<endl;

    
    return 0;
}