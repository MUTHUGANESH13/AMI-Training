/*
Program to list directory using System calls
Author   : MUTHUGANESH S
Date     : 02/02/2026
Filename : Dir.c
*/

//Header files
#include <dirent.h>
#include <stdio.h>

int main(){

//open directory
DIR *d=opendir(".");

//d is a pointer to directory
struct dirent *dir;

while((dir=readdir(d))!=NULL)
printf("%s\n",dir->d_name);

//close directory
closedir(d);

}