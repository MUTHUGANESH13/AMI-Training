/*
*  Program to demonstrate virtual functions in C++
*  3. open and read text from the file
*  Author  : MUTHUGANESH S
*  Date    : 28/1/2026
*  Filename: FileHandling3.cpp
*  retval  : void
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream File;
    string Text;

    File.open("Sample.txt", ios::in); // Open file in read mode
    if(!File){
        cout << "Error in opening file for reading..." << endl;
        return -1;
    }
    while(getline(File, Text)){
        cout << Text << endl;
    }
    File.close(); // Close file
}