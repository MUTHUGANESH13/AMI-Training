/*
Program to delete a file using System calls
Author   : MUTHUGANESH S
Date     : 02/02/2026
Filename : Del.c
*/

//Header files
#include <unistd.h>

int main(){

    //delete file
    unlink("file.txt");

}