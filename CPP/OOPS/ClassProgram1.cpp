/*
  Program to demonstrate a simple class in C++
  Author  : MUTHUGANESH S
  Date    : 21/1/2026
  Filename: ClassProgram.cpp
  retval  : void
*/

#include <iostream>
using namespace std;

// Class Declaration
class Student{
    public:
        //Members Variables
        int age;
        string name;
};

// Main Function
int main(void) {

    // Object Declaration
    Student S1;

    // Assigning values to member variables
    S1.age = 20;
    S1.name = "MUTHUGANESH S";

    // Displaying values
    cout << "Age : "<< S1.age <<"\nName : "<< S1.name << endl;

    return 0;
}