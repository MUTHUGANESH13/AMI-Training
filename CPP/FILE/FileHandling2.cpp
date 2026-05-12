/*
*  Program to demostrate file handling in C++
*  2. open and append more text to the file
*  Author  : MUTHUGANESH S
*  Date    : 28/1/2026
*  Filename: FileHandling2.cpp
*  retval  : void
*/

#include <iostream>
#include <fstream>  
using namespace std;

int main(){
    fstream File;
    string Text;

    File.open("Sample.txt", ios::app); // Open file in append mode
    if(!File){
        cout << "Error in opening file for appending..." << endl;
        return -1;
    }
    File << "\nWelcome to C++."; // Append text to file
    File.close(); // Close file
}