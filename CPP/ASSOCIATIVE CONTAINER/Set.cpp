/*
*  Program to demonstrate set
*  Author  : MUTHUGANESH S
*  Date    : 21/1/2026
*  Filename: Set.cpp
*  retval  : void
*/

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(void) {

    multiset<int> S1;
    int Size, Value;

    cout << "Enter the number of elements to insert in the set: ";
    cin >> Size;

    cout << "Enter the elements: " << endl;

    for (int i = 0; i < Size; i++) {
        cin >> Value;
        S1.insert(Value);// Inserting elements into the set
    }

    cout << "Elements in the set: " << endl;

    for (auto it = S1.begin(); it != S1.end(); it++) {
        cout << *it << " ";
    }

    cout<<"\nEnter the element to delete: ";
    cin >> Value;

    S1.erase(Value);// Deleting an element from the set

    cout<<"\nEnter the element to search: ";
    cin >> Value;

    if (S1.find(Value) != S1.end())
        cout << "YES" << endl;

    else
        cout << "NO" << endl;

    return 0;
}