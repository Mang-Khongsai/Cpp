#include <iostream>
#include <string>
using namespace std;


class Student {
private:
    string name;     
    int rollNo;      
    float marks;      

public:
    
    Student(string n, int r, float m) : name(n), rollNo(r), marks(m) {}

   
    friend ostream& operator<<(ostream& out, const Student& s);
};


ostream& operator<<(ostream& out, const Student& s) {
    out << "Name: " << s.name << "\n";
    out << "Roll No: " << s.rollNo << "\n";
    out << "Marks: " << s.marks << "\n";
    return out;
}

int main() {
    Student student1("John Doe", 101, 85.5);

    cout << student1;

    return 0;
}
