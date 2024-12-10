#include<iostream>
using namespace std;

class Calculator{
    public:
    float add(float a, float b){
        return a+b;
    }

    float subtract(float a,float b){
        return a-b;
    }

    float multiply(float a, float b){
        return a*b;
    }

    float divide(float a, float b){
        if (b!=0){
            return a/b;
        }
        else{
            cout <<"A number cannot be divide by Zero!..";
            return 0;
        }
    }
};

int main(){
Calculator cal;

 float (Calculator::*operation)(float, float) = nullptr;
    
    
float num1, num2;
int choice;

cout << "Enter two numbers: ";
cin >> num1 >> num2;

    
cout << "\nSelect operation: \n";
cout << "1. Add\n";
cout << "2. Subtract\n";
cout << "3. Multiply\n";
cout << "4. Divide\n";
cout << "Enter your choice: ";
cin >> choice;

    
    switch (choice) {
        case 1:
            operation = &Calculator::add;
            break;
        case 2:
            operation = &Calculator::subtract;
            break;
        case 3:
            operation = &Calculator::multiply;
            break;
        case 4:
            operation = &Calculator::divide;
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    // Call the selected operation using the function pointer
    float result = (cal.*operation)(num1, num2);
    cout << "Result: " << result << endl;

    return 0;
}