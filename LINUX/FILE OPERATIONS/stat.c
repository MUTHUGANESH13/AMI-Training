/*
Program to get size and permissions of a file
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : stat.c
*/

//Header files
#include <sys/stat.h>
#include <stdio.h>

int main(){

struct stat s;

//get size and permissions
stat("file.txt",&s);

printf("Size:%ld\n",s.st_size);
printf("Permissions:%o\n",s.st_mode);

}