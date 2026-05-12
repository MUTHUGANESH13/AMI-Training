/*
*  Program to demonstrate the use of Member Functions in a Class
*  Author  : MUTHUGANESH S
*  Date    : 21/1/2026
*  Filename: ClassProgram2.cpp
*  retval  : void
*/

#include <iostream>
using namespace std;

// Class Declaration
class Student {
    //By default members are private

    // Member Variables
    int Age;
    string Name;

    public:// Access Specifier

    // Member Function to set values
    void setDetails(int a, string n) {
        Age = a;
        Name = n;
    }
    // Member Functions
    void display() {
        cout << "Age : "<< Age <<"\nName : "<< Name << endl;
    }
};

// Main Function
int main(void) {

    // Object Declaration
    Student S1;

    // Assigning values to member variables
    S1.setDetails(20, "MUTHUGANESH S");

    // Displaying values
    S1.display();

    return 0;
}