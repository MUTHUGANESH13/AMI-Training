/*
*  Program to demostrate file handling in C++
*  4. open file and print content after 20th charater
*  Author  : MUTHUGANESH S
*  Date    : 28/1/2026
*  Filename: FileHandling4.cpp
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
    File.seekg(20, ios::beg); // Move pointer to 20th character
    while(getline(File, Text)){
        cout << Text << endl;
    }
    File.close(); // Close file
}