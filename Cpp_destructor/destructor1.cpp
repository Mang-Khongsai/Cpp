/*
Write a c++ program that uses a class with a constructor to open
a file and a destructor to close the file. The program should write
a single line of text to the file and ensure the file is properly closed
automatically when the object goes out of scope
*/
#include<iostream>
#include<fstream> // for file I/O
#include<string> // for string type
using namespace std;

class FileHandle{
    private:
    ofstream file;
    string filename;

    public:
    FileHandle(const string &filename){
        file.open(filename);
            if(file.is_open()){
                file <<"This line is written"<<endl;
                cout <<"Text written into the file successfully!.."<<endl;
            }else{
                cout <<"Failed to open the file."<<endl;
            }
        
    }

    ~FileHandle(){
        if(file.is_open()){
            file.close(); // close the file 
            cout <<"File closed Successfully!.."<<endl;
        }
    }// Function to display content of the file
    void display() const {
        ifstream inputFile(filename);  // Open file for reading
        if (inputFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {  // Read each line
                cout << line << std::endl;  // Display the line
            }
            inputFile.close();  // Close the file after reading
        } else {
            cout << "Failed to open the file for reading." << std::endl;
        }
    }

};

int main(){
    FileHandle fileobj("example.txt");
    fileobj.display();
    return 0;
}