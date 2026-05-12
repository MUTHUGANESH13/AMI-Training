/*
*  Program to demonstrate all arithmetic operators overloading in C++
*  Author  : MUTHUGANESH S
*  Date    : 27/1/2026    
*  Filename: Overloading.cpp
*  retval  : void
*/

#include <iostream>
using namespace std;

class Number{
private:
    int Value;
public:
    Number(int v){
        Value = v;
    }
    
    // Overloading + operator
    void operator +(const Number &num){
        Value = this->Value + num.Value;
    }

    // Overloading - operator
    void operator -(const Number &num){
        Value = this->Value - num.Value;
    }

    // Overloading * operator
    void operator *(const Number &num){
        Value = this->Value * num.Value;
    }

    // Overloading / operator
    void operator /(const Number &num){
        Value = this->Value / num.Value;
    }

    // Overloading % operator
    void operator %(const Number &num){
        Value = this->Value % num.Value;
    }   

    Number operator ==(const Number &num){
        return Number(this->Value == num.Value);
    }

    void display(){
        cout << "Value: " << Value << endl;
    }
};

int main(){
    Number num1(20);
    Number num2(10);

    num1 + num2;
    cout << "After Addition: ";
    num1.display();

    num1 - num2;
    cout << "After Subtraction: ";
    num1.display();

    num1 * num2;
    cout << "After Multiplication: ";
    num1.display();

    num1 / num2;
    cout << "After Division: ";
    num1.display();

    num1 % num2;
    cout << "After Modulus: ";
    num1.display();

    Number result = num1 == num2;
    cout << "After Equality Check: ";
    result.display();

    return 0;
}