/*
*  Program to demonstrate the use of classes and multiple objects in C++
*  Author  : MUTHUGANESH S
*  Date    : 21/1/2026
*  Filename: ClassProgram4.cpp
*  retval  : void
*/

#include <iostream>
using namespace std;    

// Class Declaration
class Student {
    public:
        int age;
        string name;
        void setDetails(int age, string name) {
            this->age = age;
            this->name = name;
        }
        void display() {
            cout << "Age : "<< age <<"\nName : "<< name << endl;
        }
};  

int main(void) {
    // Object Declaration
    Student S1, S2, S3;

    // Assigning values to member variables
    S1.setDetails(20, "MUTHUGANESH S");
    S2.setDetails(21, "Magesh K");
    S3.setDetails(22, "Yogesh L");

    // Displaying values
    cout<< "Details of Student 1:\n";
    S1.display();
    cout<< "Details of Student 2:\n";
    S2.display();
    cout<< "Details of Student 3:\n";
    S3.display();

    return 0;
}