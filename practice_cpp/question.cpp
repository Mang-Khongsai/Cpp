#include<iostream>
using namespace std;

class B;

class A {
    private:
        int varA;

    public:
        A(int a) : varA(a) {}

        friend int calculateSum(const A& objA, const B& objB);
};

class B {
    private:
        int varB;

    public:
        B(int b) : varB(b) {}

    
        friend int calculateSum(const A& objA, const B& objB);
};

int calculateSum(const A& objA, const B& objB) {
    return objA.varA + objB.varB;
}

int main() {
    A f(20);
    B s(30);

    int summ = calculateSum(f, s);
    cout << "Sum of the two private attributes is: " << summ << endl;
    return 0;
}
