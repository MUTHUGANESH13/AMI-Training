/*
*  Program to caluculate sum of array in template
*  Author  : MUTHUGANESH S
*  Date    : 3/2/2026
*  Filename: ArraySum.cpp
*  retval  : void
*/

#include <iostream>
using namespace std;

// template function definition
template <typename T>

// Function to calculate sum of array elements
T ArraySum(T Array[], int Size) {
    T sum = 0;
    for (int i = 0; i < Size; i++) {
        sum += Array[i];
    }
    return sum;
}

int main(){

    //Integer array
    int IntArray[] = {1, 2, 3, 4, 5};
    cout<<"Sum of Integer Array : "<<ArraySum(IntArray, 5)<<endl;

    //Float array
    float FloatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout<<"Sum of Float Array : "<<ArraySum(FloatArray, 5)<<endl;

    //Double array
    double DoubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55};
    cout<<"Sum of Double Array : "<<ArraySum(DoubleArray, 5)<<endl;

    return 0;
}