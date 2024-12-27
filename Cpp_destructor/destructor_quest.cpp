#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int roll_number;
    int* marks;  // Dynamically allocated array for marks
    int num_subjects;  // Number of subjects

public:
    // Constructor: Initializes the student's details and allocates memory for marks
    Student(const string& name, int roll_number, int num_subjects) 
        : name(name), roll_number(roll_number), num_subjects(num_subjects) {
        marks = new int[num_subjects];  // Dynamically allocate memory for marks
    }

    // Destructor: Frees dynamically allocated memory for marks
    ~Student() {
        delete[] marks;  // Free the allocated memory for marks
    }

    // Copy constructor: Creates a deep copy of the student object
    Student(const Student& other) 
        : name(other.name), roll_number(other.roll_number), num_subjects(other.num_subjects) {
        marks = new int[num_subjects];  // Allocate new memory for marks
        for (int i = 0; i < num_subjects; ++i) {
            marks[i] = other.marks[i];  // Copy marks from the other student
        }
    }

    // Assignment operator overloading: Handles deep copying during assignment
    Student& operator=(const Student& other) {
        if (this != &other) {  // Prevent self-assignment
            // Free the current memory
            delete[] marks;

            // Copy the basic details
            name = other.name;
            roll_number = other.roll_number;
            num_subjects = other.num_subjects;

            // Allocate new memory for marks
            marks = new int[num_subjects];
            for (int i = 0; i < num_subjects; ++i) {
                marks[i] = other.marks[i];  // Copy marks from the other student
            }
        }
        return *this;  // Return the current object to support chained assignment
    }

    // Method to input marks for the student
    void inputMarks() {
        cout << "Enter marks for " << name << " (Roll Number: " << roll_number << "):\n";
        for (int i = 0; i < num_subjects; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    // Method to display the student's information and marks
    void display() const {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Marks: ";
        for (int i = 0; i < num_subjects; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create a Student object
    Student student1("John Doe", 101, 3);
    student1.inputMarks();  // Input marks for student1
    student1.display();  // Display student1 details

    // Create a copy of student1 using the copy constructor
    Student student2 = student1;
    student2.display();  // Display student2 details

    // Assign student1 to student3 using overloaded assignment operator
    Student student3("Jane Doe", 102, 3);  // Create a new student
    student3 = student1;  // Assign student1's details to student3
    student3.display();  // Display student3 details

    return 0;
}
