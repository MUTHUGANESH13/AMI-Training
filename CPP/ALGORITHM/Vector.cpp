/*
*  Program to rotate elements of vector
*  Author  : MUTHUGANESH S
*  Date    : 05/2/2026
*  Filename: Vector.cpp
*  retval  : void
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to display elements of vector
void Display(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl<<endl;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5};
    int k;
    cout<<"Enter number of positions to rotate: ";
    cin>>k;

    cout<<"Right Rotate by "<<k<<" positions: ";
    rotate(v.begin(), v.end()-k, v.end());
    Display(v);

    cout<<"Left Rotate by "<<k<<" positions: ";
    rotate(v.begin(), v.begin() + k, v.end());
    Display(v);
    cout<<"Reverse vector: ";
    reverse(v.begin(), v.end());
    Display(v);

    return 0;
}