#include<iostream>
using namespace std;

inline int square(int a){
    return a*a;
}


int main(){
    int n;
    cout <<"size: ";
    cin >>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cout <<"["<<i+1<<"]: ";
        cin >>arr[i];
    }

    cout<<"\nSQUARE OF A NUMBERS ARE: "<<endl;
    cout <<"--------------------------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout <<"square of "<<arr[i]<<" is: "<<square(arr[i])<<endl;
    }
    cout <<"--------------------------------------------"<<endl;
    return 0;
}