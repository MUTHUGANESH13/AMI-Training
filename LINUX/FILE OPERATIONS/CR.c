/*
Program to Create and remove directory using System calls
Author   : MUTHUGANESH S
Date     : 02/02/2026
Filename : Dir.c
*/

#include <stdio.h>
#include <direct.h>

int main(){

    mkdir("testdir");

    rmdir("testdir");

    return 0;
}