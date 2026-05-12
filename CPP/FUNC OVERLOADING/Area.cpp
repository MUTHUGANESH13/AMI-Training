/*
*  Program to calculate area of different shapes using function overloading in C++
*  Author  : MUTHUGANESH S
*  Date    : 24/1/2026
*  Filename: Area.cpp    
*  retval  : void
*/

#include <iostream>
using namespace std;

// Function to calculate area of rectangle
void Area(int Length, int Breadth) {
    cout<< "Area of Rectangle: " << Length * Breadth << endl;
}

void Area(int Side) {
    cout<< "Area of Square: " << Side * Side << endl;
}

void Area(double Radius) {
    cout<< "Area of Circle: " << 3.14 * Radius * Radius << endl;
}

int main() {
    
    Area(10, 5);        // Rectangle
    Area(7);           // Square
    Area(3.5);         // Circle

    return 0;
}
