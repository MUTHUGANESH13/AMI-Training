/*
*  Program to demonstrate the use of classes and Pointer to Object in C++
*  Author  : MUTHUGANESH S
*  Date    : 21/1/2026
*  Filename: ClassProgram3.cpp
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

// Main Function
int main(void) {

    // Object Declaration
    Student S1;

    // Pointer to Object
    Student *ptr;

    // Assigning address of S1 to ptr
    ptr = &S1;

    // Using pointer to set values
    ptr->setDetails(20, "MUTHUGANESH S");

    // Using pointer to display values
    cout<< "Using Pointer to Object:\n";
    ptr->display();

    cout<< "\nUsing Object Directly:\n";
    S1.display(); // Directly using object to display values

    return 0;
}