/*
*  Program to demostrate file handling in C++
*  1.Create ,open and write text to a file
*  Author  : MUTHUGANESH S
*  Date    : 28/1/2026
*  Filename: FileHandling1.cpp
*  retval  : void
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream File;
    string Text;

    File.open("Sample.txt", ios::out); // Open file in write mode
    if(!File){
        cout << "Error in creating file..." << endl;
        return -1;
    }

    File << "Hello World!"; // Write text to file
    File.close(); // Close file
}