/*
*  Program to create a simple calculator using templates
*  Author  : MUTHUGANESH S
*  Date    : 3/2/2026    
*  Filename: SimpleCalculator.cpp
*  retval  : void
*/

#include <iostream>
using namespace std;

// Template class definition
template <class T>

// Simple Calculator class
class Calculator {
public:
    T Add(T a, T b) {
        return a + b;
    }

    T Subtract(T a, T b) {
        return a - b;
    }

    T Multiply(T a, T b) {
        return a * b;
    }

    T Divide(T a, T b) {
        return a / b;
    }
};

int main() {

    Calculator<int> calcInt; // Integer Calculator object
    Calculator<float> calcFloat; // Float Calculator object
    Calculator<double> calcDouble; // Double Calculator object

    int a = 10, b = 5;
    float c = 10.5, d = 5.5;
    double e = 10.55, f = 5.55;

    cout << "Integer Addition: " << calcInt.Add(a, b) << endl;
    cout << "Integer Subtraction: " << calcInt.Subtract(a, b) << endl;
    cout << "Integer Multiplication: " << calcInt.Multiply(a, b) << endl;
    cout << "Integer Division: " << calcInt.Divide(a, b) << endl;

    cout << "\nFloat Addition: " << calcFloat.Add(c, d) << endl;
    cout << "Float Subtraction: " << calcFloat.Subtract(c, d) << endl;
    cout << "Float Multiplication: " << calcFloat.Multiply(c, d) << endl;
    cout << "Float Division: " << calcFloat.Divide(c, d) << endl;

    cout << "\nDouble Addition: " << calcDouble.Add(e, f) << endl;
    cout << "Double Subtraction: " << calcDouble.Subtract(e, f) << endl;
    cout << "Double Multiplication: " << calcDouble.Multiply(e, f) << endl;
    cout << "Double Division: " << calcDouble.Divide(e, f) << endl;

    return 0;
}